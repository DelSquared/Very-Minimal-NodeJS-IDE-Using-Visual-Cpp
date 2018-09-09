#include <iostream>
#include <string>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include "MyForm.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	NodeIDE::MyForm form;
	Application::Run(%form);
}

