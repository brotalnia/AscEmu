/*
 * AscEmu Framework based on ArcEmu MMORPG Server
 * Copyright (C) 2014-2017 AscEmu Team <http://www.ascemu.org>
 * Copyright (C) 2008-2012 ArcEmu Team <http://www.ArcEmu.org/>
 * Copyright (C) 2005-2007 Ascent Team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _ADDONMGR_H
#define _ADDONMGR_H

#include "WorldPacket.h"
#include "Server/WorldSession.h"

struct AddonEntry
{
    std::string name;
    uint64 crc;
    bool banned;
    bool isNew;
    bool showinlist;
};

typedef std::map<std::string, AddonEntry*> KnownAddons;
typedef KnownAddons::iterator KnownAddonsItr;

typedef std::map<std::string, ByteBuffer> AddonData;
typedef AddonData::iterator AddonDataItr;

class AddonMgr : public Singleton < AddonMgr >
{
    public:

        AddonMgr();
        ~AddonMgr();

        void LoadFromDB();
        void SaveToDB();

        void SendAddonInfoPacket(WorldPacket* source, uint32 pos, WorldSession* m_session);
        bool AppendPublicKey(WorldPacket& data, std::string & AddonName, uint32 CRC);

    private:

        bool IsAddonBanned(uint64 crc, std::string name = "");
        bool IsAddonBanned(std::string name, uint64 crc = 0);
        bool ShouldShowInList(std::string name);

        KnownAddons mKnownAddons;
        AddonData mAddonData;
};

#define sAddonMgr AddonMgr::getSingleton()

#endif      // _ADDONMGR_H
