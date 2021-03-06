/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//  NppFileSettings                                                        //
//  Copyright (c) 2015-2016 Frank Fesevur                                  //
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

#pragma once

#include "FileSettings.h"

class FileSettingsVim : public FileSettings
{
public:
	FileSettingsVim(const char* line);

	bool Parse();

private:
	const char* _line;

	int FindIntWorker(const char* var);
	int FindInt(const char* longvar, const char* shortvar);
	bool FindBool(const char* longvar, const char* shortvar);
	std::string FindStringWorker(const char* var);
	std::string FindString(const char* longvar, const char* shortvar);
};
