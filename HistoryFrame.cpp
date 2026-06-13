#include "HistoryFrame.h"

HistoryFrame::HistoryFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, "History", wxDefaultPosition, wxSize(400, 600))
{
	historyPanel = new wxPanel(this);
	historyTextCtrl = new wxTextCtrl(historyPanel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);

	wxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(historyTextCtrl, 1, wxEXPAND, 10);
	historyPanel->SetSizer(sizer);
	this->Bind(wxEVT_CLOSE_WINDOW, &HistoryFrame::OnClose, this);

	historyTextCtrl->SetFont(wxFontInfo(wxSize(0, 18)));
	historyTextCtrl->SetCanFocus(false);
}

void HistoryFrame::saveHistory(const std::string& expression, const std::string& output)
{
	historyTextCtrl->AppendText(expression + " = \n" + output + "\n\n");
}
void HistoryFrame::OnClose(wxCloseEvent & event)
{
	Hide();
}