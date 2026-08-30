/**************************************************************************
 * alignmentdata.h - class declaration of the abstract class AlignmentData.
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
#ifndef ALIGNMENT_DATA_H
#define ALIGNMENT_DATA_H

class AlignmentData
{
	public:

		enum AD_AlignmentType
		{
			AD_MANUAL_ALIGN,
			AD_AUTO_ALIGN,
			AD_CANCEL_ALIGN
		};

		enum AD_ErrCode
		{
			AD_SUCCESS,
			AD_READ_DATA_FAILED,
			AD_OUT_OF_MEMORY,
			AD_ALIGNMENT_TYPE_NOT_SUPPORTED
		};


	public:

		virtual AD_ErrCode AD_GetData(
			AD_AlignmentType AlignType,
			unsigned char** AlignData,
			unsigned long* Size) = 0;
};

#endif // ALIGNMENT_DATA_H
