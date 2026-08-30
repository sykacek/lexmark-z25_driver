/**************************************************************************
 * printerdevice.h - class declaration of the PrinterDevice module.
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
#ifndef PRINTER_DEVICE_H
#define PRINTER_DEVICE_H

#include "cartridgemanager.h"
#include "cleaningdata.h"
#include "alignmentdata.h"
#include "cartridgeuserinterface.h"
#include "mediamanager.h"
#include "portmonitor.h"
#include "clock.h"


class PrinterState;
class Communications;
class ErrorManager;
class ErrorInterface;

class PrinterDevice
{
	public:

	enum PD_ErrCode
	{
		PD_SUCCESS,
		PD_INVALID_ID,
		PD_INVALID_STATE,
		PD_CARTRIDGE_ERROR,
		PD_MEDIA_ERROR,
		PD_COMMUNICATION_ERROR,
		PD_USER_ABORT,
		PD_MEMORY_ERROR,
		PD_BIDI_DISABLED
	};

	enum PD_State
	{
		PD_IDLE,
		PD_PRINT,
		PD_CANCEL,
		PD_MAX_STATE
	};

	public:

	PrinterDevice(
		PortMonitor * PrinterPort,
		Clock * Timer,
		CleaningData * CartridgeCleaning,
		AlignmentData * CartridgeAlignment,
		CartridgeUserInterface * UserInterface,
		ErrorInterface * ErrorMessages,
		char * PrinterModel,
		unsigned int BidiFlag);
	~PrinterDevice();
	void PD_GetIPAddress(
		char * IPAddress);
	void PD_GetPrinterID(
		char * PrinterID);
	void PD_SetIPAddress(
		char * IPAddress);
	int PD_GetPrinterStatus();
		
	PD_ErrCode PD_StartPrint();
	PD_ErrCode PD_EndPrint();
	PD_ErrCode PD_CancelPrint();
	PD_ErrCode PD_SendData(
		unsigned char * PrintData,
		unsigned long LengthOfData);
	PD_ErrCode PD_GetUpdate();
    	PD_ErrCode PD_AlignCartridges();
    	PD_ErrCode PD_CleanCartridges();

	
  	protected:
    
	PD_ErrCode PD_SendUpdate();
		void PD_ChangeState(
		PD_State State);
    
		
	private:

	void PD_NotifyError(
		PD_ErrCode Error);	

		
	public:

	CartridgeManager m_Cartridges;
	MediaManager m_Media;


	private:

	ErrorManager * m_Error;
	Communications * m_Comm;
	PrinterState * m_States[PD_MAX_STATE];
	PrinterState *  m_ActiveState;
	char m_PrinterModel[255];
	unsigned char m_IPAddress[4];
	int m_Status;
    
		
	public:
		
	friend class PrinterState;
	friend class IdlePrinterState;
	friend class PrintPrinterState;
	friend class CancelPrinterState;
	friend class CartridgeManager;
	friend class MediaManager;
};


#endif // PRINTER_DEVICE_H

