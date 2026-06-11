#include <cmath>
#include <d3d9.h>
#define M_PI 3.14159265358979323846264338327950288419716939937510
// ============================================================
// Vector types
// ============================================================
class Vector2 {
public:
    double x, y;
    Vector2() : x(0.f), y(0.f) {}
    Vector2(double _x, double _y) : x(_x), y(_y) {}
};
class Vector3 {
public:
    double x, y, z;
    Vector3() : x(0.f), y(0.f), z(0.f) {}
    Vector3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator+(const Vector3& v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
    Vector3 operator-(Vector3 v) { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator*(double scalar) const { return Vector3(x * scalar, y * scalar, z * scalar); }
    inline double dot(Vector3 v) { return x * v.x + y * v.y + z * v.z; }
    inline double distance(Vector3 v) { return double(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0) + powf(v.z - z, 2.0))); }
};
// ============================================================
// Camera struct
// ============================================================
struct Camera {
    Vector3 location;
    Vector3 rotation;
    float fov;
};
// ============================================================
// Rotation data read from memory (engine's internal representation)
// Offsets: A = 0x0, B = 0x20, C = 0x1D0
// ============================================================
struct RotationData {
    double A;          // 0x00
    char pad1[24];     // 0x08
    double B;          // 0x20
    char pad2[424];    // 0x28
    double C;          // 0x1D0
};
// ============================================================
// to_matrix — Euler angles (degrees) to 4x4 rotation matrix
// ============================================================
D3DMATRIX to_matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0)) {
    float radpitch = (rot.x * M_PI / 180);
    float radyaw   = (rot.y * M_PI / 180);
    float radroll  = (rot.z * M_PI / 180);
    float sp = sinf(radpitch), cp = cosf(radpitch);
    float sy = sinf(radyaw),   cy = cosf(radyaw);
    float sr = sinf(radroll),  cr = cosf(radroll);
    D3DMATRIX matrix{};
    matrix.m[0][0] = cp * cy;
    matrix.m[0][1] = cp * sy;
    matrix.m[0][2] = sp;
    matrix.m[0][3] = 0.f;
    matrix.m[1][0] = sr * sp * cy - cr * sy;
    matrix.m[1][1] = sr * sp * sy + cr * cy;
    matrix.m[1][2] = -sr * cp;
    matrix.m[1][3] = 0.f;
    matrix.m[2][0] = -(cr * sp * cy + sr * sy);
    matrix.m[2][1] = cy * sr - cr * sp * sy;
    matrix.m[2][2] = cr * cp;
    matrix.m[2][3] = 0.f;
    matrix.m[3][0] = origin.x;
    matrix.m[3][1] = origin.y;
    matrix.m[3][2] = origin.z;
    matrix.m[3][3] = 1.f;
    return matrix;
}
// ============================================================
// GetViewAngles
//
// Reads the camera location, rotation, and FOV from memory.
// Rotation is stored as 3 doubles (A, B, C) in a padded struct
// and converted to pitch/yaw using asin/atan2.
//
// Required offsets:
//   UWorld + LocationPointer -> pointer to Vector3 (camera pos)
//   UWorld + RotationPointer -> pointer to RotationData
//   PlayerController + FOV  -> float (multiplied by 90)
// ============================================================
Camera GetViewAngles() {
    auto locPtr = memory.read<uintptr_t>(cache::uworld + offsets::core::LocationPointer);
    auto rotPtr = memory.read<uintptr_t>(cache::uworld + offsets::core::RotationPointer);
    RotationData rot = memory.read<RotationData>(rotPtr);
    Vector3 loc      = memory.read<Vector3>(locPtr);
    Vector3 angles;
    angles.x = asin(rot.C) * 180.0 / M_PI;           // pitch
    angles.y = atan2(-rot.A, rot.B) * 180.0 / M_PI;   // yaw
    angles.z = 0;                                       // roll (unused)
    float fov = memory.read<float>(cache::player_controller + offsets::core::FOV) * 90.f;
    return { loc, angles, fov };
}
// ============================================================
// project_world_to_screen
//
// Projects a 3D world position onto 2D screen coordinates.
//
// 1. Builds a rotation matrix from the camera's Euler angles
// 2. Extracts the 3 axis vectors (forward, right, up)
// 3. Computes the delta between world_location and camera
// 4. Dot-products delta with each axis -> camera-space coords
// 5. Perspective divides using FOV and screen dimensions
//
// Requires:
//   cache::local_camera  (filled by GetViewAngles)
//   settings::screen_center_x / screen_center_y
// ============================================================
Vector2 project_world_to_screen(Vector3 world_location) {
    D3DMATRIX temp_matrix = to_matrix(cache::local_camera.rotation);
    Vector3 vaxisx = Vector3(temp_matrix.m[0][0], temp_matrix.m[0][1], temp_matrix.m[0][2]);
    Vector3 vaxisy = Vector3(temp_matrix.m[1][0], temp_matrix.m[1][1], temp_matrix.m[1][2]);
    Vector3 vaxisz = Vector3(temp_matrix.m[2][0], temp_matrix.m[2][1], temp_matrix.m[2][2]);
    Vector3 vdelta       = world_location - cache::local_camera.location;
    Vector3 vtransformed = Vector3(vdelta.dot(vaxisy), vdelta.dot(vaxisz), vdelta.dot(vaxisx));
    if (vtransformed.z < 1.f)
        vtransformed.z = 1.f;
    return Vector2(
        settings::screen_center_x + vtransformed.x * (settings::screen_center_x / tanf(cache::local_camera.fov * M_PI / 360)) / vtransformed.z,
        settings::screen_center_y - vtransformed.y * (settings::screen_center_x / tanf(cache::local_camera.fov * M_PI / 360)) / vtransformed.z
    );
}
