/**************************************************************************
 * portmonitor.h - class declaration of the abstract module PortMonitor.
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
#ifndef PORTMONITOR_H
#define PORTMONITOR_H


/**
 * The portstatus enumerated type are the values that are passed to the callback function
 * to determine the status of the port. In calling the callback function (PM_EventCallback),
 * the callback function needs to know whether there is a pending data waiting to be read,
 * a port error has occured, or other errors which may occur during the read operation.
 */
enum PM_Status{
	PM_STAT_READPENDING, 	/**< Data is available on the port */
	PM_STAT_PORTCLOSED,	/**< The port is closed, reading and writing will fail */
	PM_STAT_PORTBUSY,	/**< The port is currenly busy, read/write on the port will fail */
	PM_STAT_PORTERROR,	/**< The port is in an error condition, read/write on the port will fail */
};

/**
 * The PM_EventCallback defines the callback function that is registered to the PortMonitor
 * class.
 */
typedef int (*PM_EventCallback)(PM_Status portstat);	

/**
 * The PortMonitor class is an abstract base class which encapsulates the communication
 * channel between the communications channel to the printer device. This class is responsible
 * for opening and closing the port, reading, writing and other low level communications to the 
 * printer.
 *
 * This class must be implemented by the LDK user to implement the communications layer to the
 * USB connected printer, a parallel port connected printer, or a networked printer device.
 *
 * @short The class responsible for low-level communications with the printer.
 */	

class PortMonitor
{

/** Public methods: */
public:
	
		
		/**
		 * The PM_Error enumerated type, returned by calling the methods of the PortMonitor class.
		 */
		enum PM_Error{
			PM_ERR_FAILED = -1,	/**< A call to the PortMonitor's method failed */
			PM_ERR_SUCCESS,		/**< A call to the PortMonitor's method succeeded */
		};


    /**
      * PM_Open opens the communication channel between the host PC and the printer. For
      * optimal printing, the device must be opened with read and write capability
      * enabled - this allows reading of status messages and other information which can
      * be quiried from the printer.  The PM_Open() function opens the device
      * previously set in the constructor
      *
      * @see PM_Close() @return int - 0 if successfull, -1
      * - if errors occurred 
      */
    virtual PM_Error PM_Open( ) = 0;

    /**
      * PM_Close closes the communication channel between the host PC and the printer. 
      * @see PM_Open 
      * @return int - 0 if successfull, -1 - if errors occured
      */
    virtual PM_Error PM_Close(  ) = 0;

    /**
      * PM_Read is a function used to read size bytes from the communication channel to
      * the location pointed by buffer. A typical read operation usually follows after a
      * write operation to determine whether errors has occured on the printer. 
      * @see PM_Write() 
      * @return long - The number of bytes read, or a negative number if the
      * read operation resulted in an error or a timeout value has reached. 
      * @param buffer 
      * 	(in) The location where data read from the port are stored.
      * @param size
      * 	(in) The requested number of bytes read.
      *        
      */
    virtual long PM_Read( unsigned char * buffer, unsigned long size ) = 0;

    /**
      * The function writes size bytes from buffer to the communication channel. This
      * function must check for the validity of the parameters passed (i.e. NULL pointer
      * as parameters). 
      * @see PM_Open() 
      * @return int - the number of bytes written, or a negative number if the read operation 
      * resulted in an error or a timeout value has
      * reached.
      * @param buffer
      *        (in) The location of the data to write
      * @param size
      *        (in) The number of bytes to write
      */
    virtual long PM_Write( unsigned char * buffer, unsigned long size ) = 0;

    /**
      * The PM_RegisterEventCallback function is used to register a callback function.
      * The pfnCallback will be called whenever data in the port becomes available, or an
      * error in the port is detected.  @return int - Returns 0 if successfull, -1 if the
      * operation encountered errors.
      * @param pfnCallback
      *        (in) The callback function pointer which will be called if data in the port
      *        becomes available or a port error has occured.
      */
    virtual PM_Error PM_RegisterEventCallback( PM_EventCallback pfnCallback ) = 0;

    /**
      * The PM_UnregisterEventCallback function disables the callback mechanism in
      * watching the communications port.   @return int - Returns 0 if successfull, -1 if
      * the operation encountered errors. 
      */
    virtual PM_Error PM_UnregisterEventCallback(  ) = 0;

    /**
      * The PM_WaitForData function is an alternative to the PM_WaitTime function. This
      * function continually waits for a data in the port and returns when data is
      * available or a timeout value has reached.  @return int - 0 if operation succeeded
      * and data is waiting to be read, -1 if the timeout value has reached or other
      * errors occured.
      * @param timeout
      *        (in) The number of clock ticks to wait before a timeout occurs.
      */
    virtual PM_Error PM_WaitForData( long timeout ) = 0;


};





#endif // PORTMONITOR_H
