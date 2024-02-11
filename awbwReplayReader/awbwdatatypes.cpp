#include "awbwReplayReader/awbwdatatypes.h"

std::map<qint32, QString> AwbwDataTypes::UNITID_MAP =
    {{1, "INFANTRY"},
     {2, "MECH"},
     {3, "HEAVY_TANK"},
     {4, "LIGHT_TANK"},
     {5, "RECON"},
     {6, "APC"},
     {7, "ARTILLERY"},
     {8, "ROCKETTHROWER"},
     {9, "FLAK"},
     {10, "MISSILE"},
     {11, "FIGHTER"},
     {12, "BOMBER"},
     {13, "K_HELI"},
     {14, "T_HELI"},
     {15, "BATTLESHIP"},
     {16, "CRUISER"},
     {17, "LANDER"},
     {18, "SUBMARINE"},
     {28, "BLACK_BOAT"},
     {29, "AIRCRAFTCARRIER"},
     {30, "STEALTHBOMBER"},
     {46, "NEOTANK"},
     {960900, "PIPERUNNER"},
     {968731, "BLACK_BOMB"},
     {1141438, "MEGATANK"},
     };
std::map<QString, qint32> AwbwDataTypes::FACTION_MAP =
    {{"os", 0},
     {"bm", 1},
     {"ge", 2},
     {"yc", 3},
     {"bh", 4},
     {"rf", 5},
     {"gs", 6},
     {"bd", 7},
     {"ab", 8},
     {"js", 9},
     {"ci", 10},
     {"pc", 11},
     {"tg", 12},
     {"pl", 13},
     {"ar", 14},
     {"wn", 15},
     };

std::map<qint32, qint32> AwbwDataTypes::COUNTRYID_PLAYERID_MAP =
    {{1, 0},
     {2, 1},
     {3, 2},
     {4, 3},
     {5, 4},
     {6, 5},
     {7, 6},
     {8, 7},
     {9, 8},
     {10, 9},
     {16, 10},
     {17, 11},
     {19, 12},
     {20, 13},
     {21, 14},
     {22, 15},
     };

std::map<qint32, AwbwDataTypes::TileInfo> AwbwDataTypes::TERRAIN_BUILDING_DATA =
    {{std::numeric_limits<quint32>::max(), {"TELEPORTTILE", AwbwDataTypes::TERRAIN_OWNER}},
     {0, {"PLAINS", AwbwDataTypes::TERRAIN_OWNER}},
     {1, {"PLAINS", AwbwDataTypes::TERRAIN_OWNER}},
     {2, {"MOUNTAIN", AwbwDataTypes::TERRAIN_OWNER}},
     {3, {"FOREST", AwbwDataTypes::TERRAIN_OWNER}},
     {4, {"RIVER", AwbwDataTypes::TERRAIN_OWNER}},
     {5, {"RIVER", AwbwDataTypes::TERRAIN_OWNER}},
     {6, {"RIVER", AwbwDataTypes::TERRAIN_OWNER}},
     {7, {"RIVER", AwbwDataTypes::TERRAIN_OWNER}},
     {8, {"RIVER", AwbwDataTypes::TERRAIN_OWNER}},
     {9, {"RIVER", AwbwDataTypes::TERRAIN_OWNER}},
     {10, {"RIVER", AwbwDataTypes::TERRAIN_OWNER}},
     {11, {"RIVER", AwbwDataTypes::TERRAIN_OWNER}},
     {12, {"RIVER", AwbwDataTypes::TERRAIN_OWNER}},
     {13, {"RIVER", AwbwDataTypes::TERRAIN_OWNER}},
     {14, {"RIVER", AwbwDataTypes::TERRAIN_OWNER}},
     {15, {"STREET", AwbwDataTypes::TERRAIN_OWNER}},
     {16, {"STREET", AwbwDataTypes::TERRAIN_OWNER}},
     {17, {"STREET", AwbwDataTypes::TERRAIN_OWNER}},
     {18, {"STREET", AwbwDataTypes::TERRAIN_OWNER}},
     {19, {"STREET", AwbwDataTypes::TERRAIN_OWNER}},
     {20, {"STREET", AwbwDataTypes::TERRAIN_OWNER}},
     {21, {"STREET", AwbwDataTypes::TERRAIN_OWNER}},
     {22, {"STREET", AwbwDataTypes::TERRAIN_OWNER}},
     {23, {"STREET", AwbwDataTypes::TERRAIN_OWNER}},
     {24, {"STREET", AwbwDataTypes::TERRAIN_OWNER}},
     {25, {"STREET", AwbwDataTypes::TERRAIN_OWNER}},
     {26, {"BRIDGE1", AwbwDataTypes::TERRAIN_OWNER}},
     {27, {"BRIDGE1", AwbwDataTypes::TERRAIN_OWNER}},
     {28, {"SEA", AwbwDataTypes::TERRAIN_OWNER}},
     {29, {"BEACH", AwbwDataTypes::TERRAIN_OWNER}},
     {30, {"BEACH", AwbwDataTypes::TERRAIN_OWNER}},
     {31, {"BEACH", AwbwDataTypes::TERRAIN_OWNER}},
     {32, {"BEACH", AwbwDataTypes::TERRAIN_OWNER}},
     {33, {"REAF", AwbwDataTypes::TERRAIN_OWNER}},
     {101, {"PIPELINE", AwbwDataTypes::TERRAIN_OWNER}},
     {102, {"PIPELINE", AwbwDataTypes::TERRAIN_OWNER}},
     {103, {"PIPELINE", AwbwDataTypes::TERRAIN_OWNER}},
     {104, {"PIPELINE", AwbwDataTypes::TERRAIN_OWNER}},
     {105, {"PIPELINE", AwbwDataTypes::TERRAIN_OWNER}},
     {106, {"PIPELINE", AwbwDataTypes::TERRAIN_OWNER}},
     {107, {"PIPELINE", AwbwDataTypes::TERRAIN_OWNER}},
     {108, {"PIPELINE", AwbwDataTypes::TERRAIN_OWNER}},
     {109, {"PIPELINE", AwbwDataTypes::TERRAIN_OWNER}},
     {110, {"PIPELINE", AwbwDataTypes::TERRAIN_OWNER}},
     {113, {"WELD", AwbwDataTypes::TERRAIN_OWNER}},
     {114, {"WELD", AwbwDataTypes::TERRAIN_OWNER}},
     {115, {"DESTROYEDWELD", AwbwDataTypes::TERRAIN_OWNER}},
     {116, {"DESTROYEDWELD", AwbwDataTypes::TERRAIN_OWNER}},
     {195, {"TELEPORTTILE", AwbwDataTypes::TERRAIN_OWNER}},
     // buildings
     {34, {"TOWN", AwbwDataTypes::NEUTRAL_OWNER}},
     {35, {"FACTORY", AwbwDataTypes::NEUTRAL_OWNER}},
     {36, {"AIRPORT", AwbwDataTypes::NEUTRAL_OWNER}},
     {37, {"HARBOUR", AwbwDataTypes::NEUTRAL_OWNER}},
     {111, {"SILO_ROCKET", AwbwDataTypes::NEUTRAL_OWNER}},
     {112, {"SILO", AwbwDataTypes::NEUTRAL_OWNER}},
     {133, {"TOWER", AwbwDataTypes::NEUTRAL_OWNER}},
     {145, {"LABOR", AwbwDataTypes::NEUTRAL_OWNER}},

     {38, {"TOWN", 0}},
     {39, {"FACTORY", 0}},
     {40, {"AIRPORT", 0}},
     {41, {"HARBOUR", 0}},
     {42, {"HQ", 0}},
     {134, {"TOWER", 0}},
     {146, {"LABOR", 0}},

     {43, {"TOWN", 1}},
     {44, {"FACTORY", 1}},
     {45, {"AIRPORT", 1}},
     {46, {"HARBOUR", 1}},
     {47, {"HQ", 1}},
     {129, {"TOWER", 1}},
     {140, {"LABOR", 1}},

     {48, {"TOWN", 2}},
     {49, {"FACTORY", 2}},
     {50, {"AIRPORT", 2}},
     {51, {"HARBOUR", 2}},
     {52, {"HQ", 2}},
     {131, {"TOWER", 2}},
     {142, {"LABOR", 2}},

     {53, {"TOWN", 3}},
     {54, {"FACTORY", 3}},
     {55, {"AIRPORT", 3}},
     {56, {"HARBOUR", 3}},
     {57, {"HQ", 3}},
     {136, {"TOWER", 3}},
     {148, {"LABOR", 3}},

     {91, {"TOWN", 4}},
     {92, {"FACTORY", 4}},
     {93, {"AIRPORT", 4}},
     {94, {"HARBOUR", 4}},
     {95, {"HQ", 4}},
     {128, {"TOWER", 4}},
     {139, {"LABOR", 4}},

     {81, {"TOWN", 5}},
     {82, {"FACTORY", 5}},
     {83, {"AIRPORT", 5}},
     {84, {"HARBOUR", 5}},
     {85, {"HQ", 5}},
     {135, {"TOWER", 5}},
     {147, {"LABOR", 5}},

     {86, {"TOWN", 6}},
     {87, {"FACTORY", 6}},
     {88, {"AIRPORT", 6}},
     {89, {"HARBOUR", 6}},
     {90, {"HQ", 6}},
     {137, {"TOWER", 6}},
     {143, {"LABOR", 6}},

     {96, {"TOWN", 7}},
     {97, {"FACTORY", 7}},
     {98, {"AIRPORT", 7}},
     {99, {"HARBOUR", 7}},
     {100, {"HQ", 7}},
     {130, {"TOWER", 7}},
     {141, {"LABOR", 7}},

     {119, {"TOWN", 8}},
     {118, {"FACTORY", 8}},
     {117, {"AIRPORT", 8}},
     {121, {"HARBOUR", 8}},
     {120, {"HQ", 8}},
     {127, {"TOWER", 8}},
     {138, {"LABOR", 8}},

     {124, {"TOWN", 9}},
     {123, {"FACTORY", 9}},
     {122, {"AIRPORT", 9}},
     {126, {"HARBOUR", 9}},
     {125, {"HQ", 9}},
     {132, {"TOWER", 9}},
     {144, {"LABOR", 9}},

     {151, {"TOWN", 10}},
     {150, {"FACTORY", 10}},
     {149, {"AIRPORT", 10}},
     {155, {"HARBOUR", 10}},
     {153, {"HQ", 10}},
     {152, {"TOWER", 10}},
     {154, {"LABOR", 10}},

     {158, {"TOWN", 11}},
     {157, {"FACTORY", 11}},
     {156, {"AIRPORT", 11}},
     {162, {"HARBOUR", 11}},
     {160, {"HQ", 11}},
     {159, {"TOWER", 11}},
     {161, {"LABOR", 11}},

     {165, {"TOWN", 12}},
     {164, {"FACTORY", 12}},
     {163, {"AIRPORT", 12}},
     {169, {"HARBOUR", 12}},
     {167, {"HQ", 12}},
     {166, {"TOWER", 12}},
     {168, {"LABOR", 12}},

     {172, {"TOWN", 13}},
     {171, {"FACTORY", 13}},
     {170, {"AIRPORT", 13}},
     {176, {"HARBOUR", 13}},
     {174, {"HQ", 13}},
     {173, {"TOWER", 13}},
     {175, {"LABOR", 13}},

     {183, {"TOWN", 14}},
     {182, {"FACTORY", 14}},
     {181, {"AIRPORT", 14}},
     {187, {"HARBOUR", 14}},
     {185, {"HQ", 14}},
     {184, {"TOWER", 14}},
     {186, {"LABOR", 14}},

     {190, {"TOWN", 15}},
     {189, {"FACTORY", 15}},
     {188, {"AIRPORT", 15}},
     {194, {"HARBOUR", 15}},
     {192, {"HQ", 15}},
     {191, {"TOWER", 15}},
     {193, {"LABOR", 15}},
     };
std::map<QString, QString> AwbwDataTypes::UNIT_ID_ID_MAP =
    {{ "infantry", "INFANTRY" },
     { "mech", "MECH" },
     { "md.tank", "HEAVY_TANK" },
     { "tank", "LIGHT_TANK" },
     { "recon", "RECON" },
     { "apc", "APC" },
     { "artillery", "ARTILLERY" },
     { "rocket", "ROCKETTHROWER" },
     { "anti-air", "FLAK" },
     { "missile", "MISSILE" },
     { "fighter", "FIGHTER" },
     { "bomber", "BOMBER" },
     { "b-copter", "K_HELI" },
     { "t-copter", "T_HELI" },
     { "battleship", "BATTLESHIP" },
     { "cruiser", "CRUISER" },
     { "lander", "LANDER" },
     { "sub", "SUBMARINE" },
     { "black boat", "BLACK_BOAT" },
     { "carrier", "AIRCRAFTCARRIER" },
     { "stealth", "STEALTHBOMBER" },
     { "neotank", "NEOTANK" },
     { "piperunner", "PIPERUNNER" },
     { "black bomb", "BLACK_BOMB" },
     { "mega tank", "MEGATANK" },
     };
std::map<qint32, QString> AwbwDataTypes::CO_MAP =
    {{1, "CO_ANDY"},
     {7, "CO_MAX"},
     {8, "CO_SAMI"},
     {17, "CO_HACHI"},
     {22, "CO_JAKE"},
     {24, "CO_NELL"},
     {28, "CO_RACHEL"},

     {2, "CO_GRIT"},
     {9, "CO_OLAF"},
     {15, "CO_COLIN"},
     {19, "CO_SASHA"},

     {5, "CO_DRAKE"},
     {10, "CO_EAGLE"},
     {14, "CO_JESS"},
     {27, "CO_JAVIER"},

     {3, "CO_KANBEI"},
     {13, "CO_SENSEI"},
     {18, "CO_SONJA"},
     {20, "CO_GRIMM"},

     {11, "CO_ADDER"},
     {12, "CO_HAWKE"},
     {16, "CO_LASH"},
     {21, "CO_KOAL"},
     {23, "CO_KINDLE"},
     {25, "CO_FLAK"},
     {26, "CO_JUGGER"},
     {29, "CO_STURM"},
     {30, "CO_VON_BOLT"},
     {31, ""},
     };
