/*
Yang, Jian (ph.D)
fsword73@hotmail.com
Copyright 2003
Direct3D9 wrapper
Version: 0.1: implement all wrappered Direct3D9 interface.
*/


#include <windows.h>
#include "Direct3D9.h"

NewIDirect3DQuery9::NewIDirect3DQuery9(NewIDirect3DDevice9 *pDevice, IDirect3DQuery9 *pQuery)
{
	m_refCount		= 1;
	m_pd3dDevice	= pDevice;
	m_pd3dQuery		= pQuery;
}

HRESULT __stdcall NewIDirect3DQuery9::QueryInterface(REFIID iid, void ** ppvObject)
{
	return m_pd3dQuery->QueryInterface(iid, ppvObject);
}


ULONG	__stdcall NewIDirect3DQuery9::AddRef(void)
{
	m_refCount++;
	m_refCount = m_pd3dQuery->AddRef();
	return m_refCount;
}

ULONG	__stdcall NewIDirect3DQuery9::Release(void)
{
	m_refCount--;
	m_refCount = m_pd3dQuery->Release();
	if(m_refCount <=0)
	{
		m_pd3dDevice->RemoveNewQuery(this); 
		delete this;
		return 0;
	}

	return m_refCount;
}

HRESULT __stdcall NewIDirect3DQuery9::GetDevice(IDirect3DDevice9** ppDevice)
{
	return m_pd3dDevice->GetDevice(ppDevice); 
}

D3DQUERYTYPE __stdcall NewIDirect3DQuery9::GetType()
{
	return m_pd3dQuery->GetType();
}

DWORD   __stdcall NewIDirect3DQuery9::GetDataSize()
{
	return m_pd3dQuery->GetDataSize();
}

HRESULT __stdcall NewIDirect3DQuery9::Issue(DWORD dwIssueFlags)
{
	return m_pd3dQuery->Issue(dwIssueFlags);
}

HRESULT __stdcall NewIDirect3DQuery9::GetData(void* pData,DWORD dwSize,DWORD dwGetDataFlags)
{
	return m_pd3dQuery->GetData( pData, dwSize, dwGetDataFlags);
}
