# Copyright (C) 2014-2017 AscEmu Team <http://www.ascemu.org>

set(PATH_PREFIX GameWotLK)

set(SRC_GAMELK_FILES
    ${PATH_PREFIX}/Network/Opcodes.cpp
    ${PATH_PREFIX}/Network/Opcodes.h
)

source_group(GameWotLK FILES ${SRC_GAMELK_FILES})
unset(PATH_PREFIX)
