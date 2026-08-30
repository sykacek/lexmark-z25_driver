/**************************************************************************
 * cartridgemanager.h - class declaration of the CartridgeManager module.
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
 **************************************************************************/
#ifndef CARTRIDGE_MANAGER_H
#define CARTRIDGE_MANAGER_H

#include "alignmentdata.h"
#include "cleaningdata.h"

class PrinterDevice;
class CartridgeUserInterface;

class CartridgeManager
{

	public:

		enum CM_ErrCode
		{
			CM_SUCCESS,
			CM_MISSING_FIRST_CARTRIDGE,
			CM_MISSING_SECOND_CARTRIDGE,
			CM_MISSING_BOTH_CARTRIDGES,
			CM_INVALID_FIRST_CARTRIDGE,
			CM_INVALID_SECOND_CARTRIDGE,
			CM_INVALID_BOTH_CARTRIDGES,
			CM_CARTRIDGES_SWAPPED,
			CM_CHANGE_CARTRIDGE_FAILED,
			CM_ALIGN_CARTRIDGE_FAILED,
			CM_CLEAN_CARTRIDGE_FAILED,
			CM_PRINTER_ERROR
		};

		enum CM_CartridgeID
		{
			CM_STANDARD_COLOR,
			CM_HIGH_COLOR,
			CM_LOW_COLOR,
			CM_STANDARD_BLACK,
			CM_HIGH_BLACK,
			CM_LOW_BLACK,
			CM_PHOTO,
			CM_MISSING_ID,
			CM_INVALID_ID
		};

		enum CM_CartridgeAge
		{
			CM_NEW,
			CM_OLD
		};

		typedef struct
		{
			long DraftBidi;
			long NormalBidi;
			long SkewAdjust;
			long SkewPattern;
			long Horizontal;
			long Vertical;
		} CM_CartridgeAlignment;

		typedef struct
		{
			long InkUsed;
			long Threshold;
			long Capacity;
		} CM_Color;

		typedef struct
		{
			CM_Color Black;
			CM_Color Cyan;
			CM_Color Magenta;
			CM_Color Yellow;
			CM_Color PhotoBlack;
			CM_Color PhotoCyan;
			CM_Color PhotoMagenta;
		} CM_InkInfo;
			
		typedef struct
		{
			CM_CartridgeID PhysicalID;
			CM_CartridgeID LogicalID;
			CM_CartridgeID SavedID;
			CM_CartridgeAlignment Alignment;
			CM_InkInfo Ink;
			short ChangeFlag;
		} CM_CartridgeInfo;


	public:

		CartridgeManager(
			CartridgeUserInterface * pCartridgeInterface,
			AlignmentData * pAlignData,
			CleaningData * pCleanData,
			PrinterDevice * pPrinter);
		void CM_GetConfiguration(
			CM_CartridgeInfo & LeftCartridge,
			CM_CartridgeInfo & RightCartridge);
		void CM_GetInkInformation(
			CM_InkInfo & Left,
			CM_InkInfo & Right);
		bool * CM_GetSupportedCartridges();
		void CM_UpdateInkLevels(
			CM_InkInfo Ink);
		CM_ErrCode CM_ChangeCartridge(
			CM_CartridgeID & LeftID,
			CM_CartridgeID & RightID,
			CM_CartridgeAge & LeftAge,
			CM_CartridgeAge & RightAge);

	protected:

		void CM_GetAlignment(
			CM_CartridgeAlignment & Left,
			CM_CartridgeAlignment & Right);
		CM_ErrCode CM_AlignCartridge();
		CM_ErrCode CM_CleanNozzles();
		void CM_SetInkInformation(
			CM_InkInfo Left,
			CM_InkInfo Right);
		void CM_SetConfiguration(
			CM_CartridgeInfo LeftCartridge,
			CM_CartridgeInfo RightCartridge);
		void CM_SetAlignment(
			CM_CartridgeAlignment Left,
			CM_CartridgeAlignment Right);

	private:
		
  		void CM_NotifyError(CM_ErrCode Error);


	private:

		CM_CartridgeInfo m_LeftCartridge;
		CM_CartridgeInfo m_RightCartridge;
		CM_InkInfo m_InkInfo;
		AlignmentData::AD_AlignmentType m_AlignType;
		CartridgeUserInterface * m_CartridgeInterface;
		AlignmentData * m_AlignData;
		CleaningData * m_CleanData;
		PrinterDevice * m_Printer;
		bool m_SupportedCartridges[2][7];	// For now, at most 2 possible cartridge slots
							// and at most 7 possible cartridges 

	public:

		friend class PrinterDevice;
		friend class IdlePrinterState;
};


#endif // CARTRIDGE_MANAGER_H
	
