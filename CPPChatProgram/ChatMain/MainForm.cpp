#include "MainForm.h"
#include "LoginForm.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ChatMain::MainForm form;
	ChatMain::LoginForm Lform;
	ChatMain::RegisterForm Rform;

	Application::Run(% form);
}