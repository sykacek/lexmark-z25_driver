/**************************************************************************
 * clock.h - class declaration of the Clock module.
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
#ifndef CLOCK_H
#define CLOCK_H



/**
  * class Clock
  * The Clock class is an abstract class for accessing time related functions. The
  * delay and timing functions are being defined in this class, which must be
  * implemented for different operating systems.
  */

class Clock
{

/** Public methods: */
public:
    /**
      * The CLK_ReadTime function reads the current system time represented and returned
      * in a long variable.  @return long - The current time represented as a long value
      */
    virtual long CLK_ReadTime(  ) = 0;

    /**
      * The CLK_WaitTime is a delay function, delaying the function for "timeToWait"
      * seconds before returning.  @return - None 
      * @param timeToWait
      *        This function delays execution for a specified "timeToWait" seconds before
      *        exiting. 
      */
    virtual void CLK_WaitTime( long timeToWait = 0 ) = 0;

    /**
      * The CLK_GetLastUpdate function returns the number of seconds/clock ticks has
      * passed since the last call to this function.  @return long - The number of clock
      * ticks has passed since the last call to CLK_GetLastUpdate.
      */
    virtual long CLK_GetLastUpdate(  ) = 0;

    /**
     * The CLK_SetUpdateThreshold() is used in conjuction with the CLK_GelLastUpdate function
     * for determining the number of times the Printer driver retrieves or updates the information
     * from the printer. On a typical printing scenario, getting information from the printer
     * is a lengthy process, which may contribute to delays. To solve this problem,  the printer 
     * driver stores this information in the cache  - requiring only to read the information
     * from the cache, rather than querying the information directly from the printer. 
     *
     * To keep the information in the cache updated, the printer driver constantly calls the 
     * CLK_GetLastUpdate and compare the values with the update threshold frequency to determine 
     * whether it needs to refresh the cache contents if necessary. This function sets the update
     * frequency value, returning the old frequency value.
     * @param updateFreq -  The new printer update frequency in clock ticks.
     * @return	- The old printer update frequency value
     */
     virtual long CLK_SetUpdateFrequency(long updateFreq) = 0; 
	 
	 virtual long CLK_GetUpdateFrequency(void) = 0;


};

#endif // CLOCK_H
