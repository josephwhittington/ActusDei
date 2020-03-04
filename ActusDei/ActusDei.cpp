// ActusDei.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ActusDei.h"

#include "Utils.h"
#include "System.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    // TODO: Place code here.
    ADSystem::Window window(hInstance, nCmdShow, 1080, 768);

    if (!window.InitializeWindows())
    {
        return false;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ACTUSDEI));

    MSG msg;

    // Main message loop:
    while (true)
    {
		PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		if (msg.message == WM_QUIT)
			break;

		if (GetAsyncKeyState(VK_ESCAPE)) break;
    }

    return (int) msg.wParam;
}