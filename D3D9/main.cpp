/*
Yang, Jian (ph.D)
fsword73@hotmail.com
Copyright 2003
Direct3D9 wrapper
Version: 0.1: implement all wrappered Direct3D9 interface.
*/


//main.cpp : Defines the entry point for the DLL application.
//
#include <windows.h>
#include "hooksys.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{	
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:		
			//
			break;
		case DLL_THREAD_ATTACH:		
			break;

		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			CloseMSD3D9();
			break;
	}
	return TRUE;

}

