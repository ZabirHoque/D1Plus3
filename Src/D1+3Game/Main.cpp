#include "D1+3GamePCH.h"

LRESULT CALLBACK MainWindowCallback(
	_In_ HWND hwnd,
	_In_ UINT uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
	)
{
	LRESULT Result = 0;

	switch (uMsg)
	{
		case WM_ACTIVATEAPP:
			OutputDebugStringA("WM_ACTIVATEAPP\n");
			break;
		case WM_CLOSE:
			OutputDebugStringA("WM_CLOSE\n");
			exit(0);
			break;
		case WM_DESTROY:
			OutputDebugStringA("WM_DESTROY\n");
			break;
		case WM_PAINT:
		{
			PAINTSTRUCT Paint;
			HDC DeviceContext = BeginPaint(hwnd, &Paint);
			int x = Paint.rcPaint.left;
			int y = Paint.rcPaint.top;
			int vert = Paint.rcPaint.bottom - Paint.rcPaint.top;
			int horiz = Paint.rcPaint.right - Paint.rcPaint.left;
			PatBlt(DeviceContext, x, y, horiz, vert, WHITENESS);
			EndPaint(hwnd, &Paint);
		} break;
		case WM_SIZE:
				OutputDebugStringA("WM_SIZE\n");
				break;
		default:
			Result = DefWindowProc(hwnd, uMsg, wParam, lParam);
			break;
	}
	
	return(Result);
}

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE /*hPrevInstance*/,
	_In_ LPSTR     /*lpCmdLine*/,
	_In_ int       /*nCmdShow*/
	)
{
	WNDCLASS WindowClass = {};
	WindowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
	WindowClass.lpfnWndProc = MainWindowCallback;
	WindowClass.hInstance = hInstance;
	// HICON hIcon;
	WindowClass.lpszClassName = TEXT("D1+3WindowClass");
	
	if (RegisterClass(&WindowClass))
	{
		HWND WindowHandle = CreateWindowEx(
			0,
			WindowClass.lpszClassName,
			L"D1+3",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			0,
			0,
			hInstance,
			0);
		if (WindowHandle)
		{
			MSG Message;
			while (GetMessage(&Message, 0, 0, 0) > 0)
			{
				TranslateMessage(&Message);
				DispatchMessage(&Message);
			}
		}
	}

	return 0;
}
