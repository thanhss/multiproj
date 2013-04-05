#include "stdafx.h"
#include "main.h"
#include "../Classes/MPApplication.h"
#include "CCEGLView.h"
#include "MPKeyboard.h"

USING_NS_CC;

void onKeyUpDown(UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_KEYUP)
	{
		if (wParam == 'W') MPKeyboard::wUp();
	}
	else if (message == WM_KEYDOWN)
	{
		if (wParam == 'W') MPKeyboard::wDown();
	}
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // create the application instance
    MPApplication app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
    eglView->setViewName("Multiproj");
    eglView->setFrameSize(2048, 1536);
    // The resolution of ipad3 is very large. In general, PC's resolution is smaller than it.
    // So we need to invoke 'setFrameZoomFactor'(only valid on desktop(win32, mac, linux)) to make the window smaller.
    eglView->setFrameZoomFactor(0.4f);

	eglView->setAccelerometerKeyHook(onKeyUpDown);

    return CCApplication::sharedApplication()->run();
}
