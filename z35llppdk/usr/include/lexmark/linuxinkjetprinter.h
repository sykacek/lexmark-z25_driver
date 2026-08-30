/**************************************************************************
 * linuxinkjetprinter.h - class declaration of LinuxInkjetPrinter class.
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
#ifndef LINUX_INKJET_PRINTER_H
#define LINUX_INKJET_PRINTER_H


class PortMonitor;
class CartridgeUserInterface;
class ErrorCommunicator;
class LinuxErrorInterface;
class PrinterDevice;
class LinuxCleaningData;
class LinuxAlignmentData;
class LinuxClock;

class LinuxInkjetPrinter
{
	protected:
		
	LinuxInkjetPrinter();

	
	public:

	static LinuxInkjetPrinter * GetInstance();
	bool RegisterClasses(
		ErrorCommunicator* ErrorComm,
		PortMonitor* PrinterPort,
		CartridgeUserInterface* CartridgeUserInterface,
		char * UtilitiesFolder,
		char * PrinterModel,
		unsigned int BidiFlag);
	virtual ~LinuxInkjetPrinter();

	PrinterDevice * m_pPrinterDevice;

      	
	private:
	
	static LinuxInkjetPrinter* m_pLinuxInkjetPrinter;
	LinuxErrorInterface * m_pLinuxErrorInterface;
	LinuxClock * m_pLinuxClock;
	LinuxCleaningData * m_pLinuxCleaningData;
	LinuxAlignmentData * m_pLinuxAlignmentData;
};

#endif
