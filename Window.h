#pragma once

#include <Windows.h>

class Window
{

public:

	Window();

	virtual ~Window();

	// init the window
	bool init();

	// release the window
	bool release();

	bool broadcast();

	bool isRun();

	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();

protected:

	HWND m_hwnd;

	bool m_is_run;
};

