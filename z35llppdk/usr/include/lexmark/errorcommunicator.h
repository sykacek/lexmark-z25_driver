/**************************************************************************
 * errorcommunicator.h - class declaration of ErrorCommunicator class.
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
#ifndef ERROR_COMMUNICATOR_H
#define ERROR_COMMUNICATOR_H

/**
 * This is an abstract class that is responsible for implementing dispatching mechanism for reporting printer errors that occurred during a print job.
 *  This also contains the function that asks/receives user decision from the client whether to continue or abort the print job as a result of the reported errors.
 *
 */
class ErrorCommunicator{

public:
		///Enumerated Error messages that can be passed to the GUI or application.
		/**
		 *
		 * PrinterError defines an enumerated list of the various error messages that can be reported to the GUI.
		 * Some of these errors are critical which includes communication errors, paper jam, carrier stall, etc.
		 * while others can be ignored during printing (top cover open, etc.).
		 *
		 */
		enum PrinterError
		{
			ERR_NONE,			/**< Operetion results in No errors. */
			ERR_PRINTER_RESET,		/**< The printer was reset. This usually happens after a power
							  on operation.
							  */
			ERR_PAPER_JAM_TOP,		/**< Paper jam on the top tray. */
			ERR_PAPER_JAM_SIDE,		/**< Paper jam on the side tray. */
			ERR_PAPER_JAM_EXIT,		/**< Paper jam on the exit tray. */
			ERR_PAPER_OUT_AUTO,		/**< Out of paper, using the Auto feed mechanism. */
			ERR_PAPER_OUT_MANUAL,		/**< Out of paper, using the Manual feed mechanism. */
			ERR_CARTRIDGE_ERROR,		/**< Cartridge Error, usually happens when the cartridges
							  are shorted.
							 */
      ERR_CARTRIDGE_COLOR_INK_LOW, 	/**< cartridge color ink is low */
      ERR_CARTRIDGE_BLACK_INK_LOW,        /**< cartridge black ink is low */
      ERR_CARTRIDGE_BOTH_INK_LOW,   /**< cartridge color and black ink is low */
//
			ERR_CARRIER_STALL,		/**< The cartridge carries is stalled. */
			ERR_COMMUNICATION_ERROR,	/**< Printer gets communication errors. This may a result of
							  an offline condition or the connection to the printer is
							  broken.
							  */
			ERR_UNEXPECTED_ERROR,		/**< An unexpected error occured */
			ERR_COVER_OPEN,                    /**< The printer cover is open */
//			ERR_SERVICE_PRINTER_UNKNOWN,	/**< An unknown error occured, printer needs servicing. */
//			ERR_SERVICE_PRINTER_PAPER,	/**< An unknown error occured, paper feed mechanism needs servicing */
//			ERR_SERVICE_PRINTER_DATA,		/**< Data error occured */
//			ERR_SERVICE_PRINTER_USB,		/**< Error Sending data to the USB port */
      ERR_DEVICE_FAILURE,

      ERR_MISSING_COLOR_CARTRIDGE,
      ERR_MISSING_BLACK_CARTRIDGE,
      ERR_MISSING_BOTH_CARTRIDGES,

			ERR_INVALID_COLOR_CARTRIDGE,	/**< Printer has an invalid color cartridge installed */
			ERR_INVALID_BLACK_CARTRIDGE,	/**< Printer has an invalid black cartridge installed */
			ERR_INVALID_BOTH_CARTRIDGES,	/**< Both cartridges installed are invalid */
			ERR_CARTRIDGES_SWAPPED,	/**< The cartridges are swapped or in the wrong position */
			ERR_CARTRIDGE_ALIGN_FAILED,	/**< Cartridge align operation failed */
			ERR_WRONG_PAPER_SIZE,		/**< Wrong paper size */
			ERR_UNSUPPORTED_PRINTER,	/**< Unrecognized or unsupported printer installed */
			ERR_JOB_CANCELLED,		/**< Error occured in cancelling job */
			ERR_OUT_OF_MEMORY,		/**< An out of memory error occured */
		};

		///The response that can be passed to the driver after an error is reported.
		/**
		 * UserDecision is an enumerated list of reponses that can be queried from the GUI or application whether
		 * the printing is to continue or aborted.
		 *
		 */
		enum UserDecision
		{
			ABORT,				/**< Print Job aborted */
			CONTINUE,			/**< Print Job is to continue after errors */
			NOT_ANSWERED			/**< The error prompt to the application or GUI wasn't answered */
		};

public:
	/** Callback function to notify the client (GUI or an application) any printer errors occurred in the driver during printing.
	 *   This function is called by an EI_Alarm of the ErrorInterface class that is called by the print system when a printer error occurred.
	 *
	 * @return none
	 * @param error (in) Type of PrinterError
	 *
	 */
	virtual void EC_ReportError(PrinterError error) = 0;

	/** Callback function that will query the client for a decision whether to abort or continue the print job .
	 *  This function is called by an EI_IsJobCancelled function of the ErrorInterface class which is called after the EI_Alarm function.
     *
	 * @return UserDecision Possible values are: 0=ABORT, 1=CONTINUE, or 2=NOT_ANSWERED
	 * @param none
	 *
	 */
	virtual UserDecision EC_GetUserDecision() = 0;

}; // class ErrorCommunicator;
#endif // ERROR_COMMUNICATOR_H
