#pragma once
#include<wx/wx.h>

class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
private:
	wxPanel* panel;
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

	void onKeyEvent(wxKeyEvent& evt);

	void calculate();
	int precedence(char op);
	long double apply(long double a, long double b, char op);
};