#pragma once
#include <Unknwn.h>  // For IUnknown
#include <ObjectArray.h>
#pragma comment(lib, "Ole32.lib")

struct IApplicationView;

struct __declspec(uuid("1841c6d7-4f9d-42c0-af41-8747538f10e5")) IApplicationView : IUnknown {
    virtual HRESULT SetFocus() = 0;
    virtual HRESULT SwitchTo() = 0;
    virtual HRESULT TryInvokeBack(HANDLE hCallback) = 0;
    virtual HRESULT GetThumbnailWindow(HWND* hwnd) = 0;
    virtual HRESULT GetMonitor(HMONITOR* hMon) = 0;
    virtual HRESULT GetVisibility(int* visible) = 0;
    virtual HRESULT SetCloak(UINT32 cloakType, int unknown) = 0;
    virtual HRESULT GetPosition(REFIID guid, void** position) = 0;
    virtual HRESULT SetPosition(void* position) = 0;
    virtual HRESULT InsertAfterWindow(HWND hwnd) = 0;
    virtual HRESULT GetExtendedFramePosition(RECT* rect) = 0;
    virtual HRESULT GetAppUserModelId(PWSTR* id) = 0;
    virtual HRESULT SetAppUserModelId(PCWSTR id) = 0;
    virtual HRESULT IsEqualByAppUserModelId(PCWSTR id, int* equal) = 0;
    virtual HRESULT GetViewState(DWORD* state) = 0;
    virtual HRESULT SetViewState(DWORD state) = 0;
    virtual HRESULT GetNeediness(int* neediness) = 0;
    virtual HRESULT GetLastActivationTimestamp(DWORD* timestamp) = 0;
    virtual HRESULT SetLastActivationTimestamp(DWORD timestamp) = 0;
    virtual HRESULT GetVirtualDesktopId(GUID* id) = 0;
    virtual HRESULT SetVirtualDesktopId(REFGUID id) = 0;
    virtual HRESULT GetShowInSwitchers(int* show) = 0;
    virtual HRESULT SetShowInSwitchers(int show) = 0;
    virtual HRESULT GetScaleFactor(UINT* scale) = 0;
    virtual HRESULT CanReceiveInput(int* canReceive) = 0;
    virtual HRESULT GetCompatibilityPolicyType(int* policy) = 0;
    virtual HRESULT SetCompatibilityPolicyType(int policy) = 0;
    virtual HRESULT GetSizeConstraints(HMONITOR monitor, SIZE* minSize, SIZE* maxSize) = 0;
    virtual HRESULT GetSizeConstraintsForDpi(UINT dpi, SIZE* minSize, SIZE* maxSize) = 0;
    virtual HRESULT SetSizeConstraintsForDpi(const UINT* dpi, const SIZE* minSize, const SIZE* maxSize) = 0;
    virtual HRESULT OnMinSizePreferencesUpdated(HWND hwnd) = 0;
    virtual HRESULT ApplyOperation(void* operation) = 0;
    virtual HRESULT IsTray(int* isTray) = 0;
    virtual HRESULT IsInHighZOrderBand(int* isHigh) = 0;
    virtual HRESULT IsSplashScreenPresented(int* isSplash) = 0;
    virtual HRESULT Flash() = 0;
    virtual HRESULT GetRootSwitchableOwner(IApplicationView** view) = 0;
    virtual HRESULT EnumerateOwnershipTree(IObjectArray** views) = 0;
    virtual HRESULT GetEnterpriseId(PWSTR* enterpriseId) = 0;
    virtual HRESULT IsMirrored(int* isMirrored) = 0;
};
