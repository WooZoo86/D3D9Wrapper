/*
Yang, Jian (ph.D)
fsword73@hotmail.com
Copyright 2003
Direct3D9 wrapper
Version: 0.1: implement all wrappered Direct3D9 interface.
*/


#include <windows.h>
#include "Direct3D9.h"

#include "hooksys.h"

NewIDirect3D9::NewIDirect3D9()
{
	m_refCount   = 1;
	m_pDirect3D9 = (IDirect3D9*)pDirect3DCreate9(D3D_SDK_VERSION);
}

HRESULT __stdcall NewIDirect3D9::QueryInterface(REFIID iid, void ** ppvObject)
{
	return  m_pDirect3D9->QueryInterface(iid, ppvObject);
}

ULONG	__stdcall NewIDirect3D9::AddRef(void)
{	
	m_refCount ++; 
	m_refCount = m_pDirect3D9->AddRef();
	return m_refCount;
}

ULONG	__stdcall NewIDirect3D9::Release(void)
{
	m_refCount--; 
	m_refCount = m_pDirect3D9->Release();	
	if(m_refCount <= 0)
	{			
		delete this;
		return 0;
	}
	return m_refCount;
}

/*** IDirect3D9 methods ***/
HRESULT __stdcall NewIDirect3D9::RegisterSoftwareDevice(void* pInitializeFunction)
{
	return m_pDirect3D9->RegisterSoftwareDevice(pInitializeFunction);
}


UINT    __stdcall NewIDirect3D9::GetAdapterCount()
{
	
	return m_pDirect3D9->GetAdapterCount();
}

HRESULT  __stdcall NewIDirect3D9::GetAdapterIdentifier(UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER9* pIdentifier)
{
	return m_pDirect3D9->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
}

UINT    __stdcall NewIDirect3D9::GetAdapterModeCount(UINT Adapter,D3DFORMAT Format) 
{
	return m_pDirect3D9->GetAdapterModeCount(Adapter,Format);
}

HRESULT __stdcall NewIDirect3D9::EnumAdapterModes(UINT Adapter,D3DFORMAT Format,UINT Mode,D3DDISPLAYMODE* pMode)
{
	return m_pDirect3D9->EnumAdapterModes(Adapter, Format, Mode, pMode);
}


HRESULT __stdcall NewIDirect3D9::GetAdapterDisplayMode(UINT Adapter,D3DDISPLAYMODE* pMode)
{
	return m_pDirect3D9->GetAdapterDisplayMode( Adapter, pMode);
}


HRESULT __stdcall NewIDirect3D9::CheckDeviceType(UINT iAdapter,D3DDEVTYPE DevType,D3DFORMAT DisplayFormat,D3DFORMAT BackBufferFormat,BOOL bWindowed)
{
	return m_pDirect3D9->CheckDeviceType(iAdapter,DevType,DisplayFormat,BackBufferFormat,bWindowed);
}

HRESULT __stdcall NewIDirect3D9::CheckDeviceFormat(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat)
{
	return m_pDirect3D9->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat,Usage, RType,CheckFormat);
}

HRESULT __stdcall NewIDirect3D9::CheckDeviceMultiSampleType(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType,DWORD* pQualityLevels)
{
	return m_pDirect3D9->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
}

HRESULT __stdcall NewIDirect3D9::CheckDepthStencilMatch(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat)
{
	return m_pDirect3D9->CheckDepthStencilMatch( Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

HRESULT __stdcall NewIDirect3D9::CheckDeviceFormatConversion(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SourceFormat,D3DFORMAT TargetFormat)
{
	return m_pDirect3D9->CheckDeviceFormatConversion( Adapter, DeviceType, SourceFormat, TargetFormat);
}

HRESULT __stdcall NewIDirect3D9::GetDeviceCaps(UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS9* pCaps)
{
	return m_pDirect3D9->GetDeviceCaps(Adapter, DeviceType, pCaps);
}

HMONITOR  __stdcall NewIDirect3D9::GetAdapterMonitor(UINT Adapter)
{
	return m_pDirect3D9->GetAdapterMonitor(Adapter);
}

HRESULT __stdcall NewIDirect3D9::CreateDevice(UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface)
{
	HRESULT hr;
	IDirect3DDevice9* pd3device9 = NULL;

	hr = m_pDirect3D9->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, &pd3device9);
	if(pd3device9)
	{
		*ppReturnedDeviceInterface = new NewIDirect3DDevice9(this, pd3device9);
	}
	return hr;
}