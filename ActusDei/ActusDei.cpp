// ActusDei.cpp : Defines the entry point for the application.

#include "framework.h"
#include "ActusDei.h"

#include "Engine.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    Engine game;

    if (!game.Initialize(hInstance, nCmdShow))
    {
        // TODO: Handle this shit
        return -1;
    }

    game.Run();
    game.Shutdown();

    return (int)0;
}