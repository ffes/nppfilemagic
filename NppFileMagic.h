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

#ifndef __NPPFILEMAGIC_H__
#define __NPPFILEMAGIC_H__

#include <string>
#include <map>
using namespace std;

extern HWND getCurrentHScintilla(int which);
extern LRESULT SendMsg(UINT Msg, WPARAM wParam = 0, LPARAM lParam = 0, int count = 1);
extern void Ansi2Unicode(LPWSTR wszStr, LPCSTR szStr, int iSize);
extern void MsgBox(const WCHAR* msg);
extern void MsgBox(const char* msg);
extern bool MsgBoxYesNo(const WCHAR* msg);
extern void MsgBoxf(const char* szFmt, ...);
extern void CenterWindow(HWND hDlg);
extern WCHAR* GetDlgText(HWND hDlg, UINT uID);

extern HINSTANCE g_hInst;
extern NppData g_nppData;
//extern FuncItem g_funcItem[];

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

#endif // __NPPFILEMAGIC_H__
