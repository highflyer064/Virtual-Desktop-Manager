// VirtualDesktop.h

#pragma once
#include <Windows.h>
#include <objbase.h>
#include <wrl/client.h>
#include <ObjectArray.h>
#include "ApplicationView.h"
using namespace Microsoft::WRL;

struct IVirtualDesktop;

struct __declspec(uuid("c179334c-4295-40d3-bea1-c654d965605a")) IVirtualDesktopManagerInternal : IUnknown {
    virtual HRESULT GetCount(UINT* count) = 0;
    virtual HRESULT MoveViewToDesktop(IApplicationView* pView, IVirtualDesktop* pDesktop) = 0;
    virtual HRESULT CanViewMoveDesktops(IApplicationView* pView, int* canMove) = 0;
    virtual HRESULT GetCurrentDesktop(IVirtualDesktop** desktop) = 0;
    virtual HRESULT GetDesktops(IObjectArray** desktops) = 0;
    virtual HRESULT GetAdjacentDesktop(IVirtualDesktop* desktop, int direction, IVirtualDesktop** adjacentDesktop) = 0;
    virtual HRESULT SwitchDesktop(IVirtualDesktop* desktop) = 0;
    virtual HRESULT CreateDesktopW(IVirtualDesktop** desktop) = 0;
    virtual HRESULT RemoveDesktop(IVirtualDesktop* desktop, IVirtualDesktop* fallbackDesktop) = 0;
    virtual HRESULT FindDesktop(GUID* desktopId, IVirtualDesktop** desktop) = 0;
};

struct __declspec(uuid("ff72ffdd-be7e-43fc-9c03-ad81681e88e4")) IVirtualDesktop : IUnknown {
    virtual HRESULT GetID(GUID* id) = 0;
};
