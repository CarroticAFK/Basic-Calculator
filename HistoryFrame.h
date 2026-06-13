#pragma once
#include<wx/wx.h>
#include <wx/textctrl.h>
#include<string>

class HistoryFrame : public wxFrame {
public:
	HistoryFrame(const wxString& title);
	void saveHistory(const std::string& expression, const std::string& output);
private:
	wxPanel* historyPanel;
	wxTextCtrl* historyTextCtrl;

	void OnClose(wxCloseEvent& event);
};