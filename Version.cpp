/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//  NppFileMagic - file(1) and libmagic(3) inspired plugin for Notepad++   //
//  Copyright (c) 2015 Frank Fesevur                                       //
//                                                                         //
//  This program is free software; you can redistribute it and/or modify   //
//  it under the terms of the GNU General Public License as published by   //
//  the Free Software Foundation; either version 2 of the License, or      //
//  (at your option) any later version.                                    //
//                                                                         //
//  This program is distributed in the hope that it will be useful,        //
//  but WITHOUT ANY WARRANTY; without even the implied warranty of         //
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           //
//  GNU General Public License for more details.                           //
//                                                                         //
//  You should have received a copy of the GNU General Public License      //
//  along with this program; if not, write to the Free Software            //
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.              //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "NPP/PluginInterface.h"
#include "NppFileMagic.h"
#include "Version.h"

/////////////////////////////////////////////////////////////////////////////
//

Version::Version()
{
	int curVer[VERSION_DIGITS] = { VERSION_NUMBER };
	for (int i = 0; i < VERSION_DIGITS; i++)
		_version[i] = curVer[i];
}

Version::Version(BYTE version[VERSION_DIGITS])
{
	for (int i = 0; i < VERSION_DIGITS; i++)
		_version[i] = version[i];
}

Version::Version(LPCWSTR version)
{
	// Spilt the version in the seperate numbers
	int numRead = swscanf(version, L"%d.%d.%d.%d", &_version[0], &_version[1], &_version[2], &_version[3]);

	// Set the items not read to 0
	for (int i = numRead; i < VERSION_DIGITS; i++)
		_version[i] = 0;
}

///////////////////////////////////////////////////////////////////////////
// Copy-Constructor

Version::Version(const Version& copy)
{
	for (int i = 0; i < VERSION_DIGITS; i++)
		_version[i] = copy._version[i];
}

///////////////////////////////////////////////////////////////////////////
// Overload of '==' operator

bool Version::operator==(const Version chkVersion) const
{
	for (int i = 0; i < VERSION_DIGITS; i++)
	{
		if (_version[i] != chkVersion._version[i])
			return false;
	}
	return true;
}

///////////////////////////////////////////////////////////////////////////
// Overload of '>' operator

bool Version::operator>(const Version chkVersion) const
{
	for (int i = 0; i < VERSION_DIGITS; i++)
	{
		if (_version[i] > chkVersion._version[i])
			return true;
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////
// Overload of '<' operator

bool Version::operator<(const Version chkVersion) const
{
	for (int i = 0; i < VERSION_DIGITS; i++)
	{
		if (_version[i] < chkVersion._version[i])
			return true;
	}
	return false;
}
