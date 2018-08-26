/*
Yang, Jian (ph.D)
fsword73@hotmail.com
Copyright 2003
Direct3D9 wrapper
Version: 0.1: implement all wrappered Direct3D9 interface.
*/



#include <windows.h>
#include "Direct3D9.h"


NewIDirect3DStateBlock9::NewIDirect3DStateBlock9(NewIDirect3DDevice9 * pDevice, IDirect3DStateBlock9 *pStateBlock)
{
	m_refCount = 0;
	m_pd3dDevice = pDevice;
	m_pd3dStateBlock = pStateBlock;
}

HRESULT __stdcall NewIDirect3DStateBlock9::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pd3dStateBlock->QueryInterface(iid, ppvObject);
}

ULONG	__stdcall NewIDirect3DStateBlock9::AddRef(void)
{
	m_refCount++;
	m_refCount = m_pd3dStateBlock->AddRef();
	return m_refCount ;
}

ULONG	__stdcall NewIDirect3DStateBlock9::Release(void)
{
	m_refCount--;
	m_refCount = m_pd3dStateBlock->Release();
	if(m_refCount <=0)
	{
		m_pd3dDevice->RemoveNewStateBlock(this); 
		delete this;
		return 0;
	}
	return m_refCount;
}



HRESULT __stdcall NewIDirect3DStateBlock9::GetDevice(IDirect3DDevice9** ppDevice) 
{
	return m_pd3dDevice->GetDevice(ppDevice);
}
HRESULT __stdcall NewIDirect3DStateBlock9::Capture() 
{
	return m_pd3dStateBlock->Capture(); 
}

HRESULT __stdcall NewIDirect3DStateBlock9::Apply() 
{
	return m_pd3dStateBlock->Apply();
}
