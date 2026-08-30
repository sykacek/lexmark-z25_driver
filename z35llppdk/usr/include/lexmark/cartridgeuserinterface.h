/*********************************************************************************************
 * cartridgeuserinterface.h - class declaration of the abstract module CartridgeUserInterface.
 * Copyright (C) 2003 Lexmark International, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is  distributed in the hope that it will  be useful,
 * but WITHOUT ANY WARRANTY;  without  even the implied  warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License at http://www.gnu.org/licenses/licenses.html
 * for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation,Inc.,59 Temple Place - Suite 330,Boston,MA 02111-1307,USA.
 *
 ********************************************************************************************/
#ifndef CARTRIDGE_USER_INTERFACE_H
#define CARTRIDGE_USER_INTERFACE_H


#include "cartridgemanager.h"
#include "alignmentdata.h"

class CartridgeUserInterface
{
	public:

	virtual void CUI_VerifyCartridge(
		CartridgeManager::CM_CartridgeID & LeftID,
		CartridgeManager::CM_CartridgeID & RightID,
		CartridgeManager::CM_CartridgeAge & LeftAge,
		CartridgeManager::CM_CartridgeAge & RightAge) = 0;
	virtual void CUI_GetAlignmentType(
		AlignmentData::AD_AlignmentType & AlignType) = 0;
	virtual void CUI_GetAlignmentValues(
		CartridgeManager::CM_CartridgeAlignment & Left,
		CartridgeManager::CM_CartridgeAlignment & Right) = 0;
};

#endif // CARTRIDGE_USER_INTERFACE_H
