#include <Windows.h>
#include <ShObjIdl.h>
#include <iostream>

#pragma comment(lib, "Ole32.lib")
using namespace std;

int main() {
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    if (FAILED(hr)) 
    {
        cerr << "CoInitalizeEx failed: " << std::hex << hr << "\n";
        return 1;
    }

    IVirtualDesktopManager* pDesktopManager = nullptr;
    hr = CoCreateInstance(CLSID_VirtualDesktopManager, NULL, CLSCTX_ALL, IID_PPV_ARGS(&pDesktopManager));

    if (FAILED(hr)) {
        cerr << "Failed to get IVirtualDesktopManager: " << hex << hr << "\n";
        CoUninitialize();
        return 1;
    }

    HWND hwnd = GetForegroundWindow();
    if (!hwnd) {
        cerr << "No active window found. \n";
        pDesktopManager->Release();
        CoUninitialize();
        return 1;
    }

    GUID desktopId;
    BOOL onCurrentDesktop = FALSE;

    hr = pDesktopManager->IsWindowOnCurrentVirtualDesktop(hwnd, &onCurrentDesktop);
    if (SUCCEEDED(hr)) {
        cout << "Window is " << (onCurrentDesktop ? "" : "not") << "on current desktop.\n";
    }

    hr = pDesktopManager->GetWindowDesktopId(hwnd, &desktopId);
    if (SUCCEEDED(hr)) {
        LPOLESTR guidString;
        StringFromCLSID(desktopId, &guidString);
        wcout << L"Window is on desktop with ID: " << guidString << "\n";
    }
    else {
        cerr << "GetWindowDesktopId failed: " << hex << hr << "\n";
    }

    pDesktopManager->Release();
    CoUninitialize();

    char ch;
    cin >> ch;
    
    return 0;
}
