/**************************************************************************
 * printjobmanager.h - class declaration of the PrintJobManager module.
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
#ifndef PRINTJOB_MANAGER_H
#define PRINTJOB_MANAGER_H

#include <stdio.h>

#include "cartridgemanager.h"
#include "mediamanager.h"

class PrintJobState;

typedef struct IPC_Interface;

class PrintJobManager
{
	public:

	enum PJM_State
	{
		PJM_NOJOB,
		PJM_JOB_IN_PROGRESS,
		PJM_PRINTING,
		PJM_CANCELJOB,
		PJM_MAX_STATE,
	};

	enum PJM_ErrCode
	{
		PJM_SUCCESS,
		PJM_INVALID_STATE,
		PJM_MEMORY_ERROR,
		PJM_STARTDOC_FAILED,
		PJM_STARTPAGE_FAILED,
		PJM_SENDPIXELS_FAILED,
		PJM_ENDPAGE_FAILED,
		PJM_ENDDOC_FAILED,
		PJM_CANCELDOC_FAILED,
		PJM_MAX_ERROR_CODE
	};

	enum PJM_PrintColor
	{
		PJM_BLACK,
		PJM_COLOR
	};

	enum PJM_PrintQuality
	{
		PJM_QUICKPRINT,		
		PJM_NORMAL,	
		PJM_BETTER,
		PJM_BEST
	};

	typedef struct
	{
		unsigned char* ImageData; 	
		unsigned long NumOfRows;		
		unsigned long NumOfColumns;	
		unsigned long PaddedRowLength;	
		unsigned long XPosition;	
		unsigned long YPosition;	
	} PJM_PrintData;

	
	private:

	enum PJM_ColorQuality
	{
		PJM_GRAYSCALE,
		PJM_NATURAL,
		PJM_VIVID
	};

	enum PJM_ColorSpace
	{
		PJM_K_COLOR_SPACE,
		PJM_CMY_COLOR_SPACE,	
		PJM_CMYK_COLOR_SPACE,	
		PJM_CMYKcm_COLOR_SPACE
	};


	public:

	PrintJobManager(
		const char * PrinterModel,
		const char* UtilityFolder,
		FILE * OutputFile);
	~PrintJobManager();
	PJM_ErrCode PJM_StartDocument(
		PJM_PrintQuality ePrintQuality,
		PJM_PrintColor ePrintColor,
		CartridgeManager::CM_CartridgeInfo FirstCartridge,
		CartridgeManager::CM_CartridgeInfo SecondCartridge,
          	bool BorderlessPrintingFlag);
    	PJM_ErrCode PJM_StartPage(
		MediaManager::MM_MediaSize PaperSize,
		MediaManager::MM_MediaType PaperType,
          	MediaManager::MM_MediaTray PaperTray,
		MediaManager::MM_MediaMargins PaperMargins);
	PJM_ErrCode PJM_SendPixels(
		PJM_PrintData sPrintData);
	PJM_ErrCode PJM_EndPage(
		CartridgeManager::CM_InkInfo & DotsUsed);
	PJM_ErrCode PJM_EndDocument();
	PJM_ErrCode PJM_CancelDocument(
		CartridgeManager::CM_InkInfo & DotsUsed);
	int PJM_GetPrintResolution(
		PJM_PrintQuality PrintQuality);

	
	protected:
	
	void PJM_ChangeState(PJM_State State);

	
	private:
    	
	PrintJobState * m_States[PJM_MAX_STATE];
	PrintJobState * m_ActiveState;
  	IPC_Interface * m_ipcInterface;
	PJM_PrintQuality m_PrintQuality;
	char m_UtilityFolder[255];
	char m_PrinterModel[255];
	FILE * m_OutputFile;

	
	public:
	
	friend class NoJobState;
	friend class JobInProgressState;
	friend class PagePrintingState;
	friend class CancelJobState;
};

#endif // PRINTJOB_MANAGER_H
