inline RankData rank_process(uintptr_t hab)
{
	if (!hab)
		return { "Unranked", ImColor(255, 255, 255) };

	const int32_t tier = memory.read<int32_t>(hab + 0xD8 + 0x10);

	const ImColor col_bronze   = ImColor(205, 127, 50);
	const ImColor col_silver   = ImColor(192, 192, 192);
	const ImColor col_gold     = ImColor(255, 215, 0);
	const ImColor col_plat     = ImColor(0, 255, 255);
	const ImColor col_diamond  = ImColor(185, 242, 255);
	const ImColor col_elite    = ImColor(200, 200, 200);
	const ImColor col_champion = ImColor(255, 127, 80);
	const ImColor col_unreal   = ImColor(148, 0, 211);

	static const std::vector<RankData> ranks = {
		{ "Bronze 1",   col_bronze   },
		{ "Bronze 2",   col_bronze   },
		{ "Bronze 3",   col_bronze   },
		{ "Silver 1",   col_silver   },
		{ "Silver 2",   col_silver   },
		{ "Silver 3",   col_silver   },
		{ "Gold 1",     col_gold     },
		{ "Gold 2",     col_gold     },
		{ "Gold 3",     col_gold     },
		{ "Platinum 1", col_plat     },
		{ "Platinum 2", col_plat     },
		{ "Platinum 3", col_plat     },
		{ "Diamond 1",  col_diamond  },
		{ "Diamond 2",  col_diamond  },
		{ "Diamond 3",  col_diamond  },
		{ "Elite 1",    col_elite    },
		{ "Elite 2",    col_elite    },
		{ "Elite 3",    col_elite    },
		{ "Champion 1", col_champion  },
		{ "Champion 2", col_champion  },
		{ "Champion 3", col_champion  },
		{ "Unreal",     col_unreal   },
	};

	if (tier >= 0 && tier < static_cast<int32_t>(ranks.size()))
		return ranks[static_cast<size_t>(tier)];

	return { "Unranked", ImColor(255, 255, 255) };
}

const uintptr_t hab = memory.read<uintptr_t>(player_state + offsets::player::habanero);
current_rank = rank_process(hab);
