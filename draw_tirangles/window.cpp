#include <iostream>
#include <thread>
#include <vector>
#include <Windows.h>
#include "bitmap.hpp"

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

WNDCLASS wc = { sizeof(WNDCLASS) };

wc.hCursor = LoadCursor(0, IDC_ARROW);
wc.hInstance = GetModuleHandle(0);
wc.lpszClassName = L"EpicWindowClass";
wc.style = CS_HREDRAW | CS_VREDRAW;
wc.lpfnWndProc = windProc;

if (!RegisterClass(&wc)) { return 0; };



class Window
{
public:
	Window() {
	};

private:

};

Window::Window()
{
}

Window::~Window()
{
}