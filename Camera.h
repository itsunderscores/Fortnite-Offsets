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
