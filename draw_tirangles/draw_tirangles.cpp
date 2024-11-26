#include <iostream>
#include <thread>
#include <vector>
#include <Windows.h>
#include "bitmap.hpp"
#include "renderer.cpp"

//https://www.youtube.com/watch?v=k5wtuKWmV48





void resetWindowBuffer(GameWindowBuffer* gameWindowBuffer, BITMAPINFO* bitmapInfo, HWND wind)
{
    RECT rect = {};
    GetClientRect(wind, &rect);
    gameWindowBuffer->h = rect.bottom;
    gameWindowBuffer->w = rect.right;

    if (gameWindowBuffer->memory)
    {
        VirtualFree(gameWindowBuffer->memory, 0, MEM_RELEASE);
    }

    gameWindowBuffer->memory =
        (unsigned char*)VirtualAlloc(0, 4 * gameWindowBuffer->w * gameWindowBuffer->h,
            MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    bitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFO);
    bitmapInfo->bmiHeader.biWidth = gameWindowBuffer->w;
    bitmapInfo->bmiHeader.biHeight = -gameWindowBuffer->h;
    bitmapInfo->bmiHeader.biPlanes = 1;
    bitmapInfo->bmiHeader.biBitCount = 32;
    bitmapInfo->bmiHeader.biCompression = BI_RGB;
}

struct WindowStuff
{
    bool running = true;
    BITMAPINFO bitmapInfo = {};
};

WindowStuff windowStuff;
GameWindowBuffer gameWindowBuffer = {};


// this is the function that will process all of the windows' messages.
LRESULT windProc(HWND wind, UINT msg, WPARAM wp, LPARAM lp)
{
    LRESULT rez = 0;

    switch (msg)
    {
    case WM_CLOSE:
        windowStuff.running = false;
        break;
    case WM_SIZE:
    {
        resetWindowBuffer(&gameWindowBuffer, &windowStuff.bitmapInfo, wind);
    } break;

    case WM_PAINT:
    {
        PAINTSTRUCT Paint;
        HDC DeviceContext = BeginPaint(wind, &Paint);

        HDC hdc = GetDC(wind);

        StretchDIBits(hdc,
            0, 0, gameWindowBuffer.w, gameWindowBuffer.h,
            0, 0, gameWindowBuffer.w, gameWindowBuffer.h,
            gameWindowBuffer.memory,
            &windowStuff.bitmapInfo,
            DIB_RGB_COLORS,
            SRCCOPY
        );

        ReleaseDC(wind, hdc);

        EndPaint(wind, &Paint);
    } break;

    default:
        rez = DefWindowProc(wind, msg, wp, lp);
        break;
    }

    return rez;
}

HWND createWindow() {
    WNDCLASS wc = { sizeof(WNDCLASS) };

    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.hInstance = GetModuleHandle(0);
    wc.lpszClassName = L"EpicWindowClass";
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = windProc;

    if (!RegisterClass(&wc)) { return 0; };

    HWND wind = CreateWindowW(
        wc.lpszClassName,
        L"We have a Window!",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        0, 0, GetModuleHandle(0), 0
    );
}




int main()
{    
    HWND wind = createWindow();

    resetWindowBuffer(&gameWindowBuffer, &windowStuff.bitmapInfo, wind);
    triangle tri1 = { {100, 100}, {200, 100}, {100, 200}, {255,0,0} };
    KKK reality({tri1});

    while (windowStuff.running)
    {

        MSG msg = {};
        while (PeekMessage(&msg, wind, 0, 0, PM_REMOVE) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        gameWindowBuffer.clear();
        for (triangle t : reality.getMesh()) {
            gameWindowBuffer.draw_triangle(t);

        }
        InvalidateRect(wind, nullptr, FALSE);

        reality.update();
    }

    return 0;
}
