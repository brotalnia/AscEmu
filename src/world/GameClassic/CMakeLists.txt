# Copyright (C) 2014-2017 AscEmu Team <http://www.ascemu.org>

set(PATH_PREFIX GameClassic)

set(SRC_GAMECLASSIC_FILES
    ${PATH_PREFIX}/Network/Opcodes.cpp
    ${PATH_PREFIX}/Network/Opcodes.h
)

source_group(GameClassic FILES ${SRC_GAMECLASSIC_FILES})
unset(PATH_PREFIX)
