/*
Yang, Jian (ph.D)
fsword73@hotmail.com
Copyright 2003
Direct3D9 wrapper
Version: 0.1: implement all wrappered Direct3D9 interface.
status:  all Dx9SDK example can run correctly
*/

#include <stdio.h>
#include <d3d9.h>
#include "Direct3D9.h"
#include "hooksys.h"

extern "C" 
{

IDirect3D9 * WINAPI Direct3DCreate9(UINT SDKVersion)
{
	if (SDKVersion!=D3D_SDK_VERSION)
	{
		return NULL;
	}	
	
	OpenMSD3D9();

	NewIDirect3D9 *pNewd3d9 = new NewIDirect3D9 ();

	return pNewd3d9 ;

}
}  //extern "C"