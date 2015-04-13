// @author A0115188A
#include "E2DUI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	E2DUI::E2DUI mainWindow;
	Application::Run(%mainWindow);
}