#pragma once
#include<wx/wx.h>
#include<stack>
#include "Calculation.h"
#include "HistoryFrame.h"

class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
private:
	wxPanel* panel;
	wxButton* historyButton;
	wxTextCtrl* inputField;
	wxButton* zeroButton;
	wxButton* oneButton;
	wxButton* twoButton;
	wxButton* threeButton;
	wxButton* fourButton;
	wxButton* fiveButton;
	wxButton* sixButton;
	wxButton* sevenButton;
	wxButton* eightButton;
	wxButton* nineButton;
	wxButton* plusButton;
	wxButton* minusButton;
	wxButton* multiplyButton;
	wxButton* divisionButton;
	wxButton* equalButton;
	wxButton* decimalButton;
	wxButton* powerButton;
	wxButton* openBracketButton;
	wxButton* closedBracketButton;
	wxButton* clearButton;
	HistoryFrame* historyFrame = nullptr;

	void createControls();	
	void styleControls();
	void setSizers();
	void bindControls();

	void onButton1Clicked(wxCommandEvent& evt);
	void onButton2Clicked(wxCommandEvent& evt);
	void onButton3Clicked(wxCommandEvent& evt);
	void onButton4Clicked(wxCommandEvent& evt);
	void onButton5Clicked(wxCommandEvent& evt);
	void onButton6Clicked(wxCommandEvent& evt);
	void onButton7Clicked(wxCommandEvent& evt);
	void onButton8Clicked(wxCommandEvent& evt);
	void onButton9Clicked(wxCommandEvent& evt);
	void onButton0Clicked(wxCommandEvent& evt);
	void onButtonPlusClicked(wxCommandEvent& evt);
	void onButtonMinusClicked(wxCommandEvent& evt);
	void onButtonMultiplyClicked(wxCommandEvent& evt);
	void onButtonDivisionClicked(wxCommandEvent& evt);
	void onButtonEqualClicked(wxCommandEvent& evt);
	void onButtonDecimalClicked(wxCommandEvent& evt);
	void onPowerButtonClicked(wxCommandEvent& evt);
	void onOpenButtonClicked(wxCommandEvent& evt);
	void onClosedButtonClicked(wxCommandEvent& evt);
	void onClearButtonClicked(wxCommandEvent& evt);

	void onHistoryButtonClicked(wxCommandEvent& evt);
	void OnClose(wxCloseEvent& event);

	void onKeyEvent(wxKeyEvent& evt);
};