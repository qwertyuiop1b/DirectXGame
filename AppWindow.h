#pragma once
#include "Window.h"

class AppWindow: public Window
{
public:
	AppWindow();

	virtual ~AppWindow();

	// Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
};
