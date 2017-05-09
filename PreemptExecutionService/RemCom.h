/*
	Copyright (c) 2006 Talha Tariq [ talha.tariq@gmail.com ] 
	All rights are reserved.

	Permission to use, copy, modify, and distribute this software 
	for any purpose and without any fee is hereby granted, 
	provided this notice is included in its entirety in the 
	documentation and in the source files.

	This software and any related documentation is provided "as is" 
	without any warranty of any kind, either express or implied, 
	including, without limitation, the implied warranties of 
	merchantability or fitness for a particular purpose. The entire 
	risk arising out of use or performance of the software remains 
	with you. 

 	$Author:	Talha Tariq [ talha.tariq@gmail.com ]
				uses some code from xCmd by Zoltan Csizmadia
	$Revision:	Talha Tariq [ talha.tariq@gmail.com ] 	
	$Date: 2006/10/03 09:00:00 $ 		
	$Version History: $			- Added ProcComs binary as a local resource for local process impersonation and communication util
	$TODO:						- See destructor
	$Description: $				- RemCom is RAT [Remote Administration Tool] that lets you execute processes on remote windows systems, copy files, 
								  process there output and stream it back. It allows execution of remote shell commands directly with full interactive console
								- Declaration of RemCom Message and Response Classes	
	$Workfile: $				- RemCom.h
 */

#ifndef RemCom_H_INCLUDED
#define RemCom_H_INCLUDED
#include <windows.h>
#include <winsvc.h>
#include <tchar.h>
#include <lmcons.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>


#define SERVICENAME        _T("PreemptExecutionService")
#define LONGSERVICENAME    _T("Preempt execution service")

#define RemComSVCEXE     _T("PreemptExecutionService.exe")

#define RemComCOMM           _T("PreemptExecutionService_communicaton")
#define RemComSTDOUT         _T("PreemptExecutionService_stdout")
#define RemComSTDIN          _T("PreemptExecutionService_stdin")
#define RemComSTDERR         _T("PreemptExecutionService_stderr")

#define Out(x)       { _ftprintf( stdout, _T("%s"), x); fflush(stdout); }
#define Error(x)        { _ftprintf( stderr, _T("%s"), x); fflush(stderr); }

class RemComMessage
{
public:
   TCHAR szCommand[0x1000];
   TCHAR szWorkingDir[_MAX_PATH];
   DWORD dwPriority;
   DWORD dwProcessId;
   TCHAR szMachine[_MAX_PATH];
   BOOL  bNoWait;    
};

class RemComResponse
{
public:
   DWORD dwErrorCode;
   DWORD dwReturnCode;
};


#endif