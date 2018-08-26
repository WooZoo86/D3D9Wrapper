/*
Yang, Jian (ph.D)
fsword73@hotmail.com
Copyright 2003
Direct3D9 wrapper
Version: 0.1: implement all wrappered Direct3D9 interface.
*/


#include <windows.h>
#include "hooksys.h"


HMODULE  g_hd3d9 =NULL;

Proto_Direct3DCreate9 pDirect3DCreate9 = NULL;


BOOL OpenMSD3D9()
{
	char szFileName[512];
	UINT ret;

	if(g_hd3d9 && pDirect3DCreate9)
		return TRUE;

	ret = GetSystemDirectory(szFileName, 256);
	if(ret <= 0)
	{
		return FALSE;
	}

	strcat(szFileName, "\\d3d9.dll");
	g_hd3d9 = LoadLibrary(szFileName);
	if(g_hd3d9 == NULL)
	{
		return FALSE;
	}

	pDirect3DCreate9 = (Proto_Direct3DCreate9)GetProcAddress(g_hd3d9, "Direct3DCreate9");

	if(pDirect3DCreate9 == NULL)
	{
		return FALSE;
	}
	return TRUE;
}


BOOL CloseMSD3D9()
{
	BOOL ret = TRUE;
	pDirect3DCreate9 = NULL;

	if(g_hd3d9)
	{
		ret = FreeLibrary(g_hd3d9);
	}
	g_hd3d9 = NULL;

	return ret;	
}