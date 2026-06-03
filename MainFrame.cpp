#include "MainFrame.h"
#include "App.h"
#include<string>
#include<stack>

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

	inputField = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(400, 200));
	sevenButton = new wxButton(panel, wxID_ANY, "7", wxPoint(0, 400), wxSize(100, 75), wxBORDER_NONE);
	eightButton = new wxButton(panel, wxID_ANY, "8", wxPoint(100, 400), wxSize(100, 75), wxBORDER_NONE);
	nineButton = new wxButton(panel, wxID_ANY, "9", wxPoint(200, 400), wxSize(100, 75), wxBORDER_NONE);
	plusButton = new wxButton(panel, wxID_ANY, "+", wxPoint(300, 400), wxSize(100, 75), wxBORDER_NONE);

	fourButton = new wxButton(panel, wxID_ANY, "4", wxPoint(0, 475), wxSize(100, 75), wxBORDER_NONE);
	fiveButton = new wxButton(panel, wxID_ANY, "5", wxPoint(100, 475), wxSize(100, 75), wxBORDER_NONE);
	sixButton = new wxButton(panel, wxID_ANY, "6", wxPoint(200, 475), wxSize(100, 75), wxBORDER_NONE);
	minusButton = new wxButton(panel, wxID_ANY, "-", wxPoint(300, 475), wxSize(100, 75), wxBORDER_NONE);

	oneButton = new wxButton(panel, wxID_ANY, "1", wxPoint(0, 550), wxSize(100, 75), wxBORDER_NONE);
	twoButton = new wxButton(panel, wxID_ANY, "2", wxPoint(100, 550), wxSize(100, 75), wxBORDER_NONE);
	threeButton = new wxButton(panel, wxID_ANY, "3", wxPoint(200, 550), wxSize(100, 75), wxBORDER_NONE);
	multiplyButton = new wxButton(panel, wxID_ANY, "*", wxPoint(300, 550), wxSize(100, 75), wxBORDER_NONE);

	zeroButton = new wxButton(panel, wxID_ANY, "0", wxPoint(0, 625), wxSize(100, 75), wxBORDER_NONE);
	decimalButton = new wxButton(panel, wxID_ANY, ".", wxPoint(100, 625), wxSize(100, 75), wxBORDER_NONE);
	divisionButton = new wxButton(panel, wxID_ANY, "/", wxPoint(200, 625), wxSize(100, 75), wxBORDER_NONE);
	equalButton = new wxButton(panel, wxID_ANY, "=", wxPoint(300, 625), wxSize(100, 75), wxBORDER_NONE);
}

void MainFrame::styleControls()
{
	wxFont inputFont(wxFontInfo(wxSize(0, 24)));
	wxFont buttonFont(wxFontInfo(wxSize(0, 16)));
	wxFont decimalButtonFont(wxFontInfo(wxSize(0, 24)));

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

	panel->SetBackgroundColour(wxColour(240, 240, 255));
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
}

void MainFrame::setSizers()
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	mainSizer->Add(inputField, wxSizerFlags().Proportion(1).Expand());

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

	this->Bind(wxEVT_CHAR_HOOK, &MainFrame::onKeyEvent, this);
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
	calculate();
}

void MainFrame::onButtonDecimalClicked(wxCommandEvent& evt)
{
	inputField->AppendText(".");
}

void MainFrame::onKeyEvent(wxKeyEvent& evt)
{
	int keyCode = evt.GetKeyCode();

	switch (keyCode) {
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
		case WXK_TAB :
		{
			wxWindow* window = (wxWindow*) evt.GetEventObject();
			window->Navigate();
		}
		case '=':
		case WXK_RETURN:
		case WXK_NUMPAD_ENTER:
			calculate();
			break;
		default :
			break;
	}
}
int MainFrame::precedence(char op)
{
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

long double MainFrame::apply(long double a, long double b, char op)
{
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/') return a / b;
	return 0;
}

void MainFrame::calculate()
{
	std::string str = inputField->GetValue().ToStdString();
	if(str.empty()) return;

	bool isValid=1;
	char prev='a';
	for (char ch : str) {
		if (prev != 'a' && !isdigit(ch) && !isdigit(prev)){
			isValid=0;
			break;
		}
		else if (prev == 'a' && (ch == '-' || ch == '+' || ch == '/' || ch == '*')) {
			isValid=0;
			break;
		}
		prev=ch;
	}
	if(!isdigit(str.back()))
		isValid=0;

	if (!isValid) {
		long pos = inputField->GetInsertionPoint();
		inputField->SetValue("0");
		inputField->SetInsertionPoint(pos - 1);
		return;
	}
	std::stack<long double> values;
	std::stack<char> ops;

	for (long i = 0; i < (long)str.size(); i++)
	{
		char c = str[i];

		if (isdigit(c) || c == '.')
		{
			std::string num = "";
			while (i < str.size() && (isdigit(str[i]) || str[i] == '.'))
			{
				num += str[i];
				i++;
			}
			i--;
			long double value = std::stold(num);
			values.push(value);
		}
		else
		{
			while (!ops.empty() && precedence(ops.top()) >= precedence(c))
			{
				auto b = values.top(); values.pop();
				auto a = values.top(); values.pop();

				char op = ops.top(); ops.pop();

				values.push(apply(a, b, op));
			}
			ops.push(c);
		}
	}
	while (!ops.empty())
	{
		auto b = values.top(); values.pop();
		auto a = values.top(); values.pop();

		char op = ops.top(); ops.pop();

		values.push(apply(a, b, op));
	}
	std::string ans = std::to_string(values.top());
	while(ans.back()=='0')
	{
		ans.pop_back();
		if (ans.back() == '.') {
			ans.pop_back();
			break;
		}
	}
	long pos = inputField->GetInsertionPoint();
	inputField->SetValue(ans);
	inputField->SetInsertionPoint(std::max(pos, (long)ans.size()));
}