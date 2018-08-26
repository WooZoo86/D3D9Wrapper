/*
Yang, Jian (ph.D)
fsword73@hotmail.com
Copyright 2003
Direct3D9 wrapper
Version: 0.1: implement all wrappered Direct3D9 interface.
*/



#include <windows.h>
#include "Direct3D9.h"

NewIDirect3DResource9::NewIDirect3DResource9(NewIDirect3DDevice9 *pDevice, IDirect3DResource9* pResource)
{
	m_refCount	  = 0;
	m_pd3dDevice  = pDevice;
	m_pd3dResource= pResource;
}


HRESULT __stdcall NewIDirect3DResource9::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pd3dResource->QueryInterface(iid, ppvObject);
}

ULONG	__stdcall NewIDirect3DResource9::AddRef(void)
{ 
	m_refCount++;
	m_refCount = m_pd3dResource->AddRef();
	return m_refCount;
}

ULONG	__stdcall NewIDirect3DResource9::Release(void)
{
	m_refCount--;
	m_refCount = m_pd3dResource->Release();
	if(m_refCount <=0)
	{
		m_pd3dDevice->RemoveNewResource(this); 
		delete this;
		return 0;
	}

	return m_refCount;
}

HRESULT __stdcall NewIDirect3DResource9::GetDevice(IDirect3DDevice9** ppDevice) 
{
	return m_pd3dDevice->GetDevice(ppDevice);
}

HRESULT __stdcall NewIDirect3DResource9::SetPrivateData(REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags) 
{
	return m_pd3dResource->SetPrivateData(refguid, pData, SizeOfData, Flags); 
}

HRESULT __stdcall NewIDirect3DResource9::GetPrivateData(REFGUID refguid,void* pData,DWORD* pSizeOfData) 
{
	return m_pd3dResource->GetPrivateData(refguid, pData, pSizeOfData); 
}

HRESULT __stdcall NewIDirect3DResource9::FreePrivateData(REFGUID refguid) 
{
	return m_pd3dResource->FreePrivateData(refguid); 
}

DWORD   __stdcall NewIDirect3DResource9::SetPriority(DWORD PriorityNew) 
{
	return m_pd3dResource->SetPriority(PriorityNew);
}

DWORD   __stdcall NewIDirect3DResource9::GetPriority() 
{
	return m_pd3dResource->GetPriority();
}

void    __stdcall NewIDirect3DResource9::PreLoad() 
{
	m_pd3dResource->PreLoad(); 
}

D3DRESOURCETYPE __stdcall NewIDirect3DResource9::GetType() 
{
	return m_pd3dResource->GetType() ;
}

