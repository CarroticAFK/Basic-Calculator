#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
	MainFrame* mainframe = new MainFrame("To Do List");
	mainframe->SetClientSize(400, 400);
	mainframe->Show();
	mainframe->Center();

	return true;
}