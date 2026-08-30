/**************************************************************************
 * mediamanager.h - class declaration of the MediaManager module.
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
#ifndef	MEDIA_MANAGER_H
#define MEDIA_MANAGER_H

class PrinterDevice;

class MediaManager 
{

	public:

		enum MM_ErrCode
		{
			MM_SUCCESS,
			MM_INVALID_PAPER_TYPE,
			MM_INVALID_PAPER_SIZE,
			MM_INVALID_PAPER_TRAY,
			MM_INVALID_PAPER_MARGINS,
			MM_CALIBRATION_FAILED,
			MM_PRINTER_ERROR
		};

		enum MM_MediaType
 		{
			MM_PLAIN_PAPER,
			MM_COATED_PAPER,
			MM_PHOTO_PAPER,
			MM_TRANSPARENCY,
			MM_GREETING_CARD,
			MM_IRON_ON_TRANSFER,
			MM_AUTOMATIC,
			MM_MAX_PAPER_TYPE
		};

		enum MM_MediaSize
		{
			MM_PAPER_LETTER,
			MM_PAPER_LEGAL,
			MM_PAPER_A2,
			MM_PAPER_A4,
			MM_PAPER_A5,
			MM_PAPER_A6,
			MM_PAPER_B5,
			MM_PAPER_C5,
			MM_PAPER_DL,
			MM_PAPER_L,
			MM_PAPER_2L,
			MM_PAPER_CHOK_3,
			MM_PAPER_CHOK_4,
			MM_PAPER_CHOK_40,
			MM_PAPER_KAKG_3,
			MM_PAPER_KAKG_4,
			MM_PAPER_KAKG_5,
			MM_PAPER_KAKG_6,
			MM_PAPER_HAGAKI,
			MM_PAPER_CUSTOM,
			MM_EXECUTIVE,
			MM_STATEMENT,
			MM_INDEX_4X6,
			MM_INDEX_3X5,
			MM_POSTCARD_4X6,
			MM_PHOTO_4X6,
			MM_ENVELOPE_9,
			MM_ENVELOPE_10,
			MM_ENVELOPE_B5,
			MM_ENVELOPE_C5,
			MM_ENVELOPE_C6,
			MM_ENVELOPE_DL,
			MM_ENVELOPE_6_3_4,
			MM_ENVELOPE_7_3_4,
			MM_ENVELOPE_MONARCH,
			MM_ENVELOPE_CUSTOM,
			MM_BANNER_LETTER,
			MM_BANNER_A4,
			MM_BANNER_CUSTOM,
			MM_US_HALF_LETTER,
			MM_US_BARONIAL_ENVELOPE,
			MM_US_CARD_5X8,
			MM_EK_PH_001,
			MM_EK_PH_011,
	                MM_MAX_PAPER_SIZE
		};

		enum MM_MediaTray
		{
			MM_FRONT_TRAY,
			MM_REAR_TRAY,
			MM_MAX_PAPER_TRAY
		};

		typedef struct
		{
			unsigned int Top;
			unsigned int Bottom;
			unsigned int Left;
			unsigned int Right;
		} MM_MediaMargins;


	public:

		MediaManager(
			PrinterDevice * pPrinter);
		MM_ErrCode MM_SetSize(
			MM_MediaSize PaperSize, 
			MM_MediaTray PaperTray);
		MM_ErrCode MM_SetType(
			MM_MediaType PaperType, 
			MM_MediaType DetectedType, 
			MM_MediaTray PaperTray); 
		MM_ErrCode MM_SetTray(
			MM_MediaTray PaperTray);
		MM_ErrCode MM_SetMargins(
			MM_MediaMargins PaperMargins);
		MM_MediaSize MM_GetSize(
			MM_MediaTray PaperTray);
		MM_MediaType MM_GetType(
			MM_MediaTray PaperTray);
		MM_MediaTray MM_GetTray();
		void MM_GetMargins(
			MM_MediaMargins & PaperMargins);
		bool * MM_GetSupportedParameters();

		
	protected:
	
		void MM_Initialize(
			char * PrinterID);
		
	private:

		void MM_NotifyError(MM_ErrCode error);
		MM_MediaSize m_PaperSize[MM_MAX_PAPER_TRAY];
		MM_MediaType m_PaperType[MM_MAX_PAPER_TRAY];
		MM_MediaType m_DetectedPaperType[MM_MAX_PAPER_TRAY];
		MM_MediaTray m_PaperTray;
		MM_MediaMargins m_PaperMargins[MM_MAX_PAPER_SIZE];
		bool m_MediaSizeSupported[MM_MAX_PAPER_SIZE];
		bool m_MediaTraySupported[MM_MAX_PAPER_TRAY];
		bool m_MediaSensorSupported[MM_MAX_PAPER_TRAY];
		PrinterDevice * m_Printer;
		bool m_SupportedParameters[MM_MAX_PAPER_TRAY][MM_MAX_PAPER_SIZE][MM_MAX_PAPER_TYPE];	


	public:
		friend class IdlePrinterState;
};




#endif // MEDIA_MANAGER_H
