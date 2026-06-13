#include "MainFrame.h"
#include<string>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	createControls();
	styleControls();
	setSizers();
	bindControls();
}

void MainFrame::createControls()
{
	panel = new wxPanel(this);

	historyButton = new wxButton(panel, wxID_ANY, "History", wxDefaultPosition, wxSize(100, 50));
	inputField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(400, 200));
	inputField->SetFocus();

	powerButton = new wxButton(panel, wxID_ANY, "^", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	openBracketButton = new wxButton(panel, wxID_ANY, "(", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	closedBracketButton = new wxButton(panel, wxID_ANY, ")", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	clearButton = new wxButton(panel, wxID_ANY, "CE", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);

	sevenButton = new wxButton(panel, wxID_ANY, "7", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	eightButton = new wxButton(panel, wxID_ANY, "8", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	nineButton = new wxButton(panel, wxID_ANY, "9", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	plusButton = new wxButton(panel, wxID_ANY, "+", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);

	fourButton = new wxButton(panel, wxID_ANY, "4", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	fiveButton = new wxButton(panel, wxID_ANY, "5", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	sixButton = new wxButton(panel, wxID_ANY, "6", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	minusButton = new wxButton(panel, wxID_ANY, "-", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);

	oneButton = new wxButton(panel, wxID_ANY, "1", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	twoButton = new wxButton(panel, wxID_ANY, "2", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	threeButton = new wxButton(panel, wxID_ANY, "3", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	multiplyButton = new wxButton(panel, wxID_ANY, "*", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);

	zeroButton = new wxButton(panel, wxID_ANY, "0", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	decimalButton = new wxButton(panel, wxID_ANY, ".", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	divisionButton = new wxButton(panel, wxID_ANY, "/", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);
	equalButton = new wxButton(panel, wxID_ANY, "=", wxDefaultPosition, wxSize(100, 75), wxBORDER_NONE);

	if(!historyFrame)
		historyFrame = new HistoryFrame("History");
}

void MainFrame::styleControls()
{
	wxFont inputFont(wxFontInfo(wxSize(0, 24)));
	wxFont buttonFont(wxFontInfo(wxSize(0, 16)));
	wxFont decimalButtonFont(wxFontInfo(wxSize(0, 24)));

	historyButton->SetFont(buttonFont);
	inputField->SetFont(inputFont);
	zeroButton->SetFont(buttonFont);
	oneButton->SetFont(buttonFont);
	twoButton->SetFont(buttonFont);
	threeButton->SetFont(buttonFont);
	fourButton->SetFont(buttonFont);
	fiveButton->SetFont(buttonFont);
	sixButton->SetFont(buttonFont);
	sevenButton->SetFont(buttonFont);
	eightButton->SetFont(buttonFont);
	nineButton->SetFont(buttonFont);
	plusButton->SetFont(buttonFont);
	minusButton->SetFont(buttonFont);
	multiplyButton->SetFont(buttonFont);
	divisionButton->SetFont(buttonFont);
	decimalButton->SetFont(decimalButtonFont);
	equalButton->SetFont(buttonFont);
	powerButton->SetFont(buttonFont);
	openBracketButton->SetFont(buttonFont);
	closedBracketButton->SetFont(buttonFont);
	clearButton->SetFont(buttonFont);

	panel->SetBackgroundColour(wxColour(255, 255, 255));
	historyButton->SetBackgroundColour(wxColour(255, 255, 255));
	zeroButton->SetBackgroundColour(wxColour(240, 248, 255));
	oneButton->SetBackgroundColour(wxColour(240, 248, 255));
	twoButton->SetBackgroundColour(wxColour(240, 248, 255));
	threeButton->SetBackgroundColour(wxColour(240, 248, 255));
	fourButton->SetBackgroundColour(wxColour(240, 248, 255));
	fiveButton->SetBackgroundColour(wxColour(240, 248, 255));
	sixButton->SetBackgroundColour(wxColour(240, 248, 255));
	sevenButton->SetBackgroundColour(wxColour(240, 248, 255));
	eightButton->SetBackgroundColour(wxColour(240, 248, 255));
	nineButton->SetBackgroundColour(wxColour(240, 248, 255));
	plusButton->SetBackgroundColour(wxColour(240, 248, 255));
	minusButton->SetBackgroundColour(wxColour(240, 248, 255));
	multiplyButton->SetBackgroundColour(wxColour(240, 248, 255));
	divisionButton->SetBackgroundColour(wxColour(240, 248, 255));
	decimalButton->SetBackgroundColour(wxColour(240, 248, 255));
	equalButton->SetBackgroundColour(wxColour(240, 248, 255));
	powerButton->SetBackgroundColour(wxColour(240, 248, 255));
	openBracketButton->SetBackgroundColour(wxColour(240, 248, 255));
	closedBracketButton->SetBackgroundColour(wxColour(240, 248, 255));
	clearButton->SetBackgroundColour(wxColour(240, 248, 255));
}

void MainFrame::setSizers()
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* topRow = new wxBoxSizer(wxHORIZONTAL);
	topRow->AddStretchSpacer();
	topRow->Add(historyButton, 0, wxALIGN_CENTER_VERTICAL);
	mainSizer->Add(topRow, wxSizerFlags().Proportion(0).Expand());

	mainSizer->Add(inputField, wxSizerFlags().Proportion(1).Expand());

	wxBoxSizer* zerothRow = new wxBoxSizer(wxHORIZONTAL);
	zerothRow->Add(powerButton, wxSizerFlags().Proportion(1));
	zerothRow->Add(openBracketButton, wxSizerFlags().Proportion(1));
	zerothRow->Add(closedBracketButton, wxSizerFlags().Proportion(1));
	zerothRow->Add(clearButton, wxSizerFlags().Proportion(1));
	mainSizer->Add(zerothRow, wxSizerFlags().Expand());

	wxBoxSizer* firstRow = new wxBoxSizer(wxHORIZONTAL);
	firstRow->Add(sevenButton, wxSizerFlags().Proportion(1));
	firstRow->Add(eightButton, wxSizerFlags().Proportion(1));
	firstRow->Add(nineButton, wxSizerFlags().Proportion(1));
	firstRow->Add(plusButton, wxSizerFlags().Proportion(1));
	mainSizer->Add(firstRow, wxSizerFlags().Expand());

	wxBoxSizer* secondRow = new wxBoxSizer(wxHORIZONTAL);
	secondRow->Add(fourButton, wxSizerFlags().Proportion(1));
	secondRow->Add(fiveButton, wxSizerFlags().Proportion(1));
	secondRow->Add(sixButton, wxSizerFlags().Proportion(1));
	secondRow->Add(minusButton, wxSizerFlags().Proportion(1));
	mainSizer->Add(secondRow, wxSizerFlags().Expand());

	wxBoxSizer* thirdRow = new wxBoxSizer(wxHORIZONTAL);
	thirdRow->Add(oneButton, wxSizerFlags().Proportion(1));
	thirdRow->Add(twoButton, wxSizerFlags().Proportion(1));
	thirdRow->Add(threeButton, wxSizerFlags().Proportion(1));
	thirdRow->Add(multiplyButton, wxSizerFlags().Proportion(1));
	mainSizer->Add(thirdRow, wxSizerFlags().Expand());

	wxBoxSizer* fourthRow = new wxBoxSizer(wxHORIZONTAL);
	fourthRow->Add(zeroButton, wxSizerFlags().Proportion(1));
	fourthRow->Add(decimalButton, wxSizerFlags().Proportion(1));
	fourthRow->Add(divisionButton, wxSizerFlags().Proportion(1));
	fourthRow->Add(equalButton, wxSizerFlags().Proportion(1));
	mainSizer->Add(fourthRow, wxSizerFlags().Expand());

	wxGridSizer* outerSpacer = new wxGridSizer(1);
	outerSpacer->Add(mainSizer, wxSizerFlags().Expand().Border(wxALL, 2));

	panel->SetSizer(outerSpacer);
	outerSpacer->SetSizeHints(this);
}

void MainFrame::bindControls()
{
	powerButton->Bind(wxEVT_BUTTON, &MainFrame::onPowerButtonClicked, this);
	openBracketButton->Bind(wxEVT_BUTTON, &MainFrame::onOpenButtonClicked, this);
	closedBracketButton->Bind(wxEVT_BUTTON, &MainFrame::onClosedButtonClicked, this);
	clearButton->Bind(wxEVT_BUTTON, &MainFrame::onClearButtonClicked, this);
	oneButton->Bind(wxEVT_BUTTON, &MainFrame::onButton1Clicked, this);
	twoButton->Bind(wxEVT_BUTTON, &MainFrame::onButton2Clicked, this);
	threeButton->Bind(wxEVT_BUTTON, &MainFrame::onButton3Clicked, this);
	fourButton->Bind(wxEVT_BUTTON, &MainFrame::onButton4Clicked, this);
	fiveButton->Bind(wxEVT_BUTTON, &MainFrame::onButton5Clicked, this);
	sixButton->Bind(wxEVT_BUTTON, &MainFrame::onButton6Clicked, this);
	sevenButton->Bind(wxEVT_BUTTON, &MainFrame::onButton7Clicked, this);
	eightButton->Bind(wxEVT_BUTTON, &MainFrame::onButton8Clicked, this);
	nineButton->Bind(wxEVT_BUTTON, &MainFrame::onButton9Clicked, this);
	zeroButton->Bind(wxEVT_BUTTON, &MainFrame::onButton0Clicked, this);
	plusButton->Bind(wxEVT_BUTTON, &MainFrame::onButtonPlusClicked, this);
	minusButton->Bind(wxEVT_BUTTON, &MainFrame::onButtonMinusClicked, this);
	multiplyButton->Bind(wxEVT_BUTTON, &MainFrame::onButtonMultiplyClicked, this);
	divisionButton->Bind(wxEVT_BUTTON, &MainFrame::onButtonDivisionClicked, this);
	equalButton->Bind(wxEVT_BUTTON, &MainFrame::onButtonEqualClicked, this);
	decimalButton->Bind(wxEVT_BUTTON, &MainFrame::onButtonDecimalClicked, this);

	historyButton->Bind(wxEVT_BUTTON, &MainFrame::onHistoryButtonClicked, this);

	this->Bind(wxEVT_CHAR_HOOK, &MainFrame::onKeyEvent, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
}

void MainFrame::onButton1Clicked(wxCommandEvent& evt)
{
	inputField->AppendText("1");
}

void MainFrame::onButton2Clicked(wxCommandEvent& evt)
{
	inputField->AppendText("2");
}

void MainFrame::onButton3Clicked(wxCommandEvent& evt)
{
	inputField->AppendText("3");
}

void MainFrame::onButton4Clicked(wxCommandEvent& evt)
{
	inputField->AppendText("4");
}

void MainFrame::onButton5Clicked(wxCommandEvent& evt)
{
	inputField->AppendText("5");
}

void MainFrame::onButton6Clicked(wxCommandEvent& evt)
{
	inputField->AppendText("6");
}

void MainFrame::onButton7Clicked(wxCommandEvent& evt)
{
	inputField->AppendText("7");
}

void MainFrame::onButton8Clicked(wxCommandEvent& evt)
{
	inputField->AppendText("8");
}

void MainFrame::onButton9Clicked(wxCommandEvent& evt)
{
	inputField->AppendText("9");
}

void MainFrame::onButton0Clicked(wxCommandEvent& evt)
{
	inputField->AppendText("0");
}

void MainFrame::onButtonPlusClicked(wxCommandEvent& evt)
{
	inputField->AppendText("+");
}

void MainFrame::onButtonMinusClicked(wxCommandEvent& evt)
{
	inputField->AppendText("-");
}

void MainFrame::onButtonMultiplyClicked(wxCommandEvent& evt)
{
	inputField->AppendText("*");
}

void MainFrame::onButtonDivisionClicked(wxCommandEvent& evt)
{
	inputField->AppendText("/");
}

void MainFrame::onButtonEqualClicked(wxCommandEvent& evt)
{
	std::string str = inputField->GetValue().ToStdString();
	std::string ans = calculate(str);

	while (ans.back() == '0')
		ans.pop_back();
	if (ans.back() == '.') 
		ans.pop_back();

	historyFrame->saveHistory(str, ans);

	long pos = inputField->GetInsertionPoint();
	inputField->SetValue(ans);
	inputField->SetInsertionPoint(std::max(pos, (long)ans.size()));
}

void MainFrame::onButtonDecimalClicked(wxCommandEvent& evt)
{
	inputField->AppendText(".");
}

void MainFrame::onPowerButtonClicked(wxCommandEvent& evt)
{
	inputField->AppendText("^");
}

void MainFrame::onOpenButtonClicked(wxCommandEvent& evt)
{
	inputField->AppendText("(");
}

void MainFrame::onClosedButtonClicked(wxCommandEvent& evt)
{
	inputField->AppendText(")");
}

void MainFrame::onClearButtonClicked(wxCommandEvent& evt)
{
	inputField->Clear();
}

void MainFrame::onHistoryButtonClicked(wxCommandEvent& evt)
{
	historyFrame->Show();
}

void MainFrame::OnClose(wxCloseEvent& event)
{
	if (historyFrame)
		historyFrame->Destroy();

	event.Skip();
}

void MainFrame::onKeyEvent(wxKeyEvent& evt)
{
	int keyCode = evt.GetKeyCode();
	int isShift = evt.ShiftDown();
	if (evt.ShiftDown() && evt.GetKeyCode() == '6')
	{
		inputField->AppendText("^");
		return;
	}
	else if (evt.ShiftDown() && evt.GetKeyCode() == '9')
	{
		inputField->AppendText("(");
		return;
	}
	else if (evt.ShiftDown() && evt.GetKeyCode() == '0')
	{
		inputField->AppendText(")");
		return;
	}
	else if (evt.ShiftDown() && evt.GetKeyCode() == '=')
	{
		inputField->AppendText("+");
		return;
	}


	switch (keyCode) {
		case WXK_TAB:
			return;
		case '1':
		case WXK_NUMPAD1:
			inputField->AppendText("1");
			break;
		case '2':
		case WXK_NUMPAD2:
			inputField->AppendText("2");
			break;
		case '3':
		case WXK_NUMPAD3:
			inputField->AppendText("3");
			break;
		case '4':
		case WXK_NUMPAD4:
			inputField->AppendText("4");
			break;
		case '5':
		case WXK_NUMPAD5:
			inputField->AppendText("5");
			break;
		case '6':
		case WXK_NUMPAD6:
			inputField->AppendText("6");
			break;
		case '7':
		case WXK_NUMPAD7:
			inputField->AppendText("7");
			break;
		case '8':
		case WXK_NUMPAD8:
			inputField->AppendText("8");
			break;
		case '9':
		case WXK_NUMPAD9:
			inputField->AppendText("9");
			break;
		case '0':
		case WXK_NUMPAD0:
			inputField->AppendText("0");
			break;
		case WXK_NUMPAD_ADD:
		case '+':
			inputField->AppendText("+");
			break;
		case '-':
		case WXK_NUMPAD_SUBTRACT:
			inputField->AppendText("-");
			break;
		case '*':
		case WXK_NUMPAD_MULTIPLY:
			inputField->AppendText("*");
			break;
		case '/':
		case WXK_NUMPAD_DIVIDE:
			inputField->AppendText("/");
			break;
		case WXK_NUMPAD_DECIMAL:
			inputField->AppendText(".");
			break;
		case WXK_BACK:
		case WXK_DELETE:
		{
			wxString str = inputField->GetValue();
			if (!str.IsEmpty())
			{
				long pos = inputField->GetInsertionPoint(); // save cursor position

				str.RemoveLast();
				inputField->SetValue(str);

				inputField->SetInsertionPoint(pos - 1); // restore cursor
			}
			break;
		}
		case '=':
		case WXK_NUMPAD_ENTER:
		case WXK_RETURN:
		{
			std::string str = inputField->GetValue().ToStdString();
			std::string ans = calculate(str);
			while (ans.back() == '0')
				ans.pop_back();
			if (ans.back() == '.') 
				ans.pop_back();

			historyFrame->saveHistory(str, ans);

			long pos = inputField->GetInsertionPoint();
			inputField->SetValue(ans);
			inputField->SetInsertionPoint(ans.size());
			return;
		}
		default :
			break;
	}
}