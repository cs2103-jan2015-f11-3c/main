#pragma once
#include <string>
#include <vector>
#include <stack>
#include <msclr/marshal_cppstd.h>
#include "architectureParser.h"
#include "architectureLogic.h"
#include "architectureStorage.h"
#include "architectureInputFeedback.h"

namespace UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for architectureGUI
	/// </summary>
	public ref class architectureGUI : public System::Windows::Forms::Form
	{
	private:
		architectureParser* parser;
		architectureLogic* logic;
		architectureStorage* storage;
		architectureInputFeedback* inputFeedback;
	private: System::Windows::Forms::TextBox^  upcomingBorder;




	private: System::Windows::Forms::Label^  todayLabel;
	private: System::Windows::Forms::Label^  upcomingLabel;
	private: System::Windows::Forms::TextBox^  miscBorder;



	private: System::Windows::Forms::Label^  miscLabel;


	private: System::Windows::Forms::TextBox^  commandLabel;
	private: System::Windows::Forms::TextBox^  feedbackLabel;
	private: System::Windows::Forms::MonthCalendar^  monthCalendar;
	private: System::Windows::Forms::RichTextBox^  todayRichTextBox;
	private: System::Windows::Forms::RichTextBox^  upcomingRichTextBox;
	private: System::Windows::Forms::RichTextBox^  miscRichTextBox;

	private: System::Windows::Forms::RichTextBox^  colourLegend;
	private: System::Windows::Forms::Label^  helpGuide;
	private: System::Windows::Forms::TextBox^  commandLineTextBox;
	private: System::Windows::Forms::TextBox^  feedbackTextBox;
	private: System::Windows::Forms::TextBox^  todayBorder;

	private: System::Windows::Forms::TextBox^  feedbackTextBoxMin;
	private: System::Windows::Forms::RichTextBox^  miscRichTextBoxMin;

	private: System::Windows::Forms::RichTextBox^  upcomingRichTextBoxMin;

	private: System::Windows::Forms::RichTextBox^  todayRichTextBoxMin;

	private: System::Windows::Forms::Label^  miscLabelMin;

	private: System::Windows::Forms::Label^  upcomingLabelMin;

	private: System::Windows::Forms::Label^  todayLabelMin;
	private: System::Windows::Forms::TextBox^  upcomingBorderMin;


	private: System::Windows::Forms::TextBox^  todayBorderMin;
	private: System::Windows::Forms::TextBox^  miscBorderMin;







	private: System::Windows::Forms::RichTextBox^  displayHelp;


	public:
		architectureGUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			parser = new architectureParser();
			logic = new architectureLogic();
			storage = new architectureStorage();
			inputFeedback = new architectureInputFeedback();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~architectureGUI()
		{
			if (components)
			{
				delete components;
				delete parser;
				delete logic;
				delete storage;
				delete inputFeedback;
			}
		}

	private: System::Windows::Forms::PictureBox^  logoPictureBox;
	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(architectureGUI::typeid));
			this->commandLineTextBox = (gcnew System::Windows::Forms::TextBox());
			this->feedbackTextBox = (gcnew System::Windows::Forms::TextBox());
			this->todayBorder = (gcnew System::Windows::Forms::TextBox());
			this->logoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->upcomingBorder = (gcnew System::Windows::Forms::TextBox());
			this->todayLabel = (gcnew System::Windows::Forms::Label());
			this->upcomingLabel = (gcnew System::Windows::Forms::Label());
			this->miscBorder = (gcnew System::Windows::Forms::TextBox());
			this->miscLabel = (gcnew System::Windows::Forms::Label());
			this->commandLabel = (gcnew System::Windows::Forms::TextBox());
			this->feedbackLabel = (gcnew System::Windows::Forms::TextBox());
			this->monthCalendar = (gcnew System::Windows::Forms::MonthCalendar());
			this->todayRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->upcomingRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->miscRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->displayHelp = (gcnew System::Windows::Forms::RichTextBox());
			this->colourLegend = (gcnew System::Windows::Forms::RichTextBox());
			this->helpGuide = (gcnew System::Windows::Forms::Label());
			this->feedbackTextBoxMin = (gcnew System::Windows::Forms::TextBox());
			this->miscRichTextBoxMin = (gcnew System::Windows::Forms::RichTextBox());
			this->upcomingRichTextBoxMin = (gcnew System::Windows::Forms::RichTextBox());
			this->todayRichTextBoxMin = (gcnew System::Windows::Forms::RichTextBox());
			this->miscLabelMin = (gcnew System::Windows::Forms::Label());
			this->upcomingLabelMin = (gcnew System::Windows::Forms::Label());
			this->todayLabelMin = (gcnew System::Windows::Forms::Label());
			this->upcomingBorderMin = (gcnew System::Windows::Forms::TextBox());
			this->todayBorderMin = (gcnew System::Windows::Forms::TextBox());
			this->miscBorderMin = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// commandLineTextBox
			// 
			this->commandLineTextBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Append;
			this->commandLineTextBox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->commandLineTextBox->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.900001F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->commandLineTextBox->Location = System::Drawing::Point(798, 122);
			this->commandLineTextBox->Multiline = true;
			this->commandLineTextBox->Name = L"commandLineTextBox";
			this->commandLineTextBox->Size = System::Drawing::Size(1164, 51);
			this->commandLineTextBox->TabIndex = 0;
			this->commandLineTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &architectureGUI::commandLineTextBox_KeyDown);
			this->commandLineTextBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &architectureGUI::commandLineTextBox_KeyUp);
			// 
			// feedbackTextBox
			// 
			this->feedbackTextBox->BackColor = System::Drawing::Color::AliceBlue;
			this->feedbackTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->feedbackTextBox->Location = System::Drawing::Point(798, 230);
			this->feedbackTextBox->Multiline = true;
			this->feedbackTextBox->Name = L"feedbackTextBox";
			this->feedbackTextBox->ReadOnly = true;
			this->feedbackTextBox->Size = System::Drawing::Size(1164, 435);
			this->feedbackTextBox->TabIndex = 1;
			// 
			// todayBorder
			// 
			this->todayBorder->BackColor = System::Drawing::SystemColors::Window;
			this->todayBorder->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->todayBorder->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->todayBorder->Location = System::Drawing::Point(48, 694);
			this->todayBorder->Multiline = true;
			this->todayBorder->Name = L"todayBorder";
			this->todayBorder->ReadOnly = true;
			this->todayBorder->Size = System::Drawing::Size(829, 774);
			this->todayBorder->TabIndex = 2;
			// 
			// logoPictureBox
			// 
			this->logoPictureBox->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"logoPictureBox.Image")));
			this->logoPictureBox->Location = System::Drawing::Point(2054, 192);
			this->logoPictureBox->Name = L"logoPictureBox";
			this->logoPictureBox->Size = System::Drawing::Size(508, 252);
			this->logoPictureBox->TabIndex = 3;
			this->logoPictureBox->TabStop = false;
			// 
			// upcomingBorder
			// 
			this->upcomingBorder->BackColor = System::Drawing::SystemColors::Window;
			this->upcomingBorder->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->upcomingBorder->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->upcomingBorder->Location = System::Drawing::Point(906, 694);
			this->upcomingBorder->Multiline = true;
			this->upcomingBorder->Name = L"upcomingBorder";
			this->upcomingBorder->ReadOnly = true;
			this->upcomingBorder->Size = System::Drawing::Size(878, 774);
			this->upcomingBorder->TabIndex = 4;
			// 
			// todayLabel
			// 
			this->todayLabel->AutoSize = true;
			this->todayLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->todayLabel->Location = System::Drawing::Point(21, 679);
			this->todayLabel->Name = L"todayLabel";
			this->todayLabel->Size = System::Drawing::Size(150, 42);
			this->todayLabel->TabIndex = 5;
			this->todayLabel->Text = L"TODAY";
			// 
			// upcomingLabel
			// 
			this->upcomingLabel->AutoSize = true;
			this->upcomingLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->upcomingLabel->Location = System::Drawing::Point(878, 679);
			this->upcomingLabel->Name = L"upcomingLabel";
			this->upcomingLabel->Size = System::Drawing::Size(227, 42);
			this->upcomingLabel->TabIndex = 6;
			this->upcomingLabel->Text = L"UPCOMING";
			// 
			// miscBorder
			// 
			this->miscBorder->BackColor = System::Drawing::SystemColors::Window;
			this->miscBorder->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->miscBorder->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->miscBorder->Location = System::Drawing::Point(1812, 694);
			this->miscBorder->Multiline = true;
			this->miscBorder->Name = L"miscBorder";
			this->miscBorder->ReadOnly = true;
			this->miscBorder->Size = System::Drawing::Size(838, 774);
			this->miscBorder->TabIndex = 7;
			// 
			// miscLabel
			// 
			this->miscLabel->AutoSize = true;
			this->miscLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->miscLabel->Location = System::Drawing::Point(1793, 679);
			this->miscLabel->Name = L"miscLabel";
			this->miscLabel->Size = System::Drawing::Size(330, 42);
			this->miscLabel->TabIndex = 8;
			this->miscLabel->Text = L"MISCELLANEOUS";
			// 
			// commandLabel
			// 
			this->commandLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->commandLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->commandLabel->Location = System::Drawing::Point(798, 75);
			this->commandLabel->Name = L"commandLabel";
			this->commandLabel->Size = System::Drawing::Size(332, 39);
			this->commandLabel->TabIndex = 9;
			this->commandLabel->Text = L"Enter Command:";
			// 
			// feedbackLabel
			// 
			this->feedbackLabel->BackColor = System::Drawing::SystemColors::Window;
			this->feedbackLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->feedbackLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackLabel->Location = System::Drawing::Point(798, 190);
			this->feedbackLabel->Name = L"feedbackLabel";
			this->feedbackLabel->Size = System::Drawing::Size(224, 39);
			this->feedbackLabel->TabIndex = 10;
			this->feedbackLabel->Text = L"Feedback";
			// 
			// monthCalendar
			// 
			this->monthCalendar->Location = System::Drawing::Point(84, 133);
			this->monthCalendar->Name = L"monthCalendar";
			this->monthCalendar->ShowToday = false;
			this->monthCalendar->TabIndex = 11;
			this->monthCalendar->TabStop = false;
			this->monthCalendar->TitleBackColor = System::Drawing::Color::AliceBlue;
			// 
			// todayRichTextBox
			// 
			this->todayRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->todayRichTextBox->Location = System::Drawing::Point(61, 724);
			this->todayRichTextBox->Name = L"todayRichTextBox";
			this->todayRichTextBox->Size = System::Drawing::Size(806, 729);
			this->todayRichTextBox->TabIndex = 12;
			this->todayRichTextBox->Text = L"";
			// 
			// upcomingRichTextBox
			// 
			this->upcomingRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->upcomingRichTextBox->Location = System::Drawing::Point(917, 724);
			this->upcomingRichTextBox->Name = L"upcomingRichTextBox";
			this->upcomingRichTextBox->Size = System::Drawing::Size(851, 729);
			this->upcomingRichTextBox->TabIndex = 13;
			this->upcomingRichTextBox->Text = L"";
			// 
			// miscRichTextBox
			// 
			this->miscRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->miscRichTextBox->Location = System::Drawing::Point(1826, 724);
			this->miscRichTextBox->Name = L"miscRichTextBox";
			this->miscRichTextBox->Size = System::Drawing::Size(816, 729);
			this->miscRichTextBox->TabIndex = 17;
			this->miscRichTextBox->Text = L"";
			// 
			// displayHelp
			// 
			this->displayHelp->BackColor = System::Drawing::Color::White;
			this->displayHelp->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->displayHelp->Location = System::Drawing::Point(21, 14);
			this->displayHelp->Name = L"displayHelp";
			this->displayHelp->Size = System::Drawing::Size(743, 653);
			this->displayHelp->TabIndex = 15;
			this->displayHelp->Text = L"";
			this->displayHelp->Visible = false;
			// 
			// colourLegend
			// 
			this->colourLegend->BackColor = System::Drawing::Color::White;
			this->colourLegend->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->colourLegend->Location = System::Drawing::Point(48, 75);
			this->colourLegend->Name = L"colourLegend";
			this->colourLegend->Size = System::Drawing::Size(716, 564);
			this->colourLegend->TabIndex = 16;
			this->colourLegend->Text = L"";
			this->colourLegend->Visible = false;
			// 
			// helpGuide
			// 
			this->helpGuide->AutoSize = true;
			this->helpGuide->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpGuide->Location = System::Drawing::Point(1176, 78);
			this->helpGuide->Name = L"helpGuide";
			this->helpGuide->Size = System::Drawing::Size(791, 37);
			this->helpGuide->TabIndex = 18;
			this->helpGuide->Text = L"Press F1 for user guide. Press F2 for colour legend and shortcuts.";
			// 
			// feedbackTextBoxMin
			// 
			this->feedbackTextBoxMin->BackColor = System::Drawing::Color::AliceBlue;
			this->feedbackTextBoxMin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->feedbackTextBoxMin->Location = System::Drawing::Point(798, 230);
			this->feedbackTextBoxMin->Multiline = true;
			this->feedbackTextBoxMin->Name = L"feedbackTextBoxMin";
			this->feedbackTextBoxMin->ReadOnly = true;
			this->feedbackTextBoxMin->Size = System::Drawing::Size(1164, 70);
			this->feedbackTextBoxMin->TabIndex = 19;
			// 
			// miscRichTextBoxMin
			// 
			this->miscRichTextBoxMin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->miscRichTextBoxMin->Location = System::Drawing::Point(1826, 362);
			this->miscRichTextBoxMin->Name = L"miscRichTextBoxMin";
			this->miscRichTextBoxMin->Size = System::Drawing::Size(816, 1091);
			this->miscRichTextBoxMin->TabIndex = 28;
			this->miscRichTextBoxMin->Text = L"";
			// 
			// upcomingRichTextBoxMin
			// 
			this->upcomingRichTextBoxMin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->upcomingRichTextBoxMin->Location = System::Drawing::Point(917, 362);
			this->upcomingRichTextBoxMin->Name = L"upcomingRichTextBoxMin";
			this->upcomingRichTextBoxMin->Size = System::Drawing::Size(851, 1091);
			this->upcomingRichTextBoxMin->TabIndex = 27;
			this->upcomingRichTextBoxMin->Text = L"";
			// 
			// todayRichTextBoxMin
			// 
			this->todayRichTextBoxMin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->todayRichTextBoxMin->Location = System::Drawing::Point(61, 362);
			this->todayRichTextBoxMin->Name = L"todayRichTextBoxMin";
			this->todayRichTextBoxMin->Size = System::Drawing::Size(806, 1091);
			this->todayRichTextBoxMin->TabIndex = 26;
			this->todayRichTextBoxMin->Text = L"";
			// 
			// miscLabelMin
			// 
			this->miscLabelMin->AutoSize = true;
			this->miscLabelMin->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->miscLabelMin->Location = System::Drawing::Point(1793, 317);
			this->miscLabelMin->Name = L"miscLabelMin";
			this->miscLabelMin->Size = System::Drawing::Size(330, 42);
			this->miscLabelMin->TabIndex = 25;
			this->miscLabelMin->Text = L"MISCELLANEOUS";
			// 
			// upcomingLabelMin
			// 
			this->upcomingLabelMin->AutoSize = true;
			this->upcomingLabelMin->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->upcomingLabelMin->Location = System::Drawing::Point(882, 317);
			this->upcomingLabelMin->Name = L"upcomingLabelMin";
			this->upcomingLabelMin->Size = System::Drawing::Size(227, 42);
			this->upcomingLabelMin->TabIndex = 23;
			this->upcomingLabelMin->Text = L"UPCOMING";
			// 
			// todayLabelMin
			// 
			this->todayLabelMin->AutoSize = true;
			this->todayLabelMin->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->todayLabelMin->Location = System::Drawing::Point(21, 317);
			this->todayLabelMin->Name = L"todayLabelMin";
			this->todayLabelMin->Size = System::Drawing::Size(150, 42);
			this->todayLabelMin->TabIndex = 22;
			this->todayLabelMin->Text = L"TODAY";
			// 
			// upcomingBorderMin
			// 
			this->upcomingBorderMin->BackColor = System::Drawing::SystemColors::Window;
			this->upcomingBorderMin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->upcomingBorderMin->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->upcomingBorderMin->Location = System::Drawing::Point(906, 332);
			this->upcomingBorderMin->Multiline = true;
			this->upcomingBorderMin->Name = L"upcomingBorderMin";
			this->upcomingBorderMin->ReadOnly = true;
			this->upcomingBorderMin->Size = System::Drawing::Size(878, 1136);
			this->upcomingBorderMin->TabIndex = 21;
			// 
			// todayBorderMin
			// 
			this->todayBorderMin->BackColor = System::Drawing::SystemColors::Window;
			this->todayBorderMin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->todayBorderMin->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->todayBorderMin->Location = System::Drawing::Point(48, 332);
			this->todayBorderMin->Multiline = true;
			this->todayBorderMin->Name = L"todayBorderMin";
			this->todayBorderMin->ReadOnly = true;
			this->todayBorderMin->Size = System::Drawing::Size(829, 1136);
			this->todayBorderMin->TabIndex = 20;
			// 
			// miscBorderMin
			// 
			this->miscBorderMin->BackColor = System::Drawing::SystemColors::Window;
			this->miscBorderMin->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->miscBorderMin->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->miscBorderMin->Location = System::Drawing::Point(1812, 332);
			this->miscBorderMin->Multiline = true;
			this->miscBorderMin->Name = L"miscBorderMin";
			this->miscBorderMin->ReadOnly = true;
			this->miscBorderMin->Size = System::Drawing::Size(838, 1136);
			this->miscBorderMin->TabIndex = 24;
			// 
			// architectureGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(2961, 1562);
			this->Controls->Add(this->feedbackTextBoxMin);
			this->Controls->Add(this->feedbackTextBox);
			this->Controls->Add(this->displayHelp);
			this->Controls->Add(this->todayRichTextBoxMin);
			this->Controls->Add(this->todayLabelMin);
			this->Controls->Add(this->miscRichTextBox);
			this->Controls->Add(this->upcomingRichTextBox);
			this->Controls->Add(this->todayRichTextBox);
			this->Controls->Add(this->feedbackLabel);
			this->Controls->Add(this->commandLabel);
			this->Controls->Add(this->miscLabel);
			this->Controls->Add(this->upcomingLabel);
			this->Controls->Add(this->todayLabel);
			this->Controls->Add(this->upcomingBorder);
			this->Controls->Add(this->logoPictureBox);
			this->Controls->Add(this->todayBorder);
			this->Controls->Add(this->commandLineTextBox);
			this->Controls->Add(this->miscBorder);
			this->Controls->Add(this->helpGuide);
			this->Controls->Add(this->colourLegend);
			this->Controls->Add(this->monthCalendar);
			this->Controls->Add(this->miscRichTextBoxMin);
			this->Controls->Add(this->upcomingRichTextBoxMin);
			this->Controls->Add(this->miscLabelMin);
			this->Controls->Add(this->upcomingLabelMin);
			this->Controls->Add(this->upcomingBorderMin);
			this->Controls->Add(this->miscBorderMin);
			this->Controls->Add(this->todayBorderMin);
			this->Location = System::Drawing::Point(1655, 641);
			this->MaximizeBox = false;
			this->Name = L"architectureGUI";
			this->Padding = System::Windows::Forms::Padding(30);
			this->Text = L"EasyToDo";
			this->Load += gcnew System::EventHandler(this, &architectureGUI::architectureGUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// @author A0115188A
		// will load when the program is first run
	private: System::Void architectureGUI_Load(System::Object^  sender, System::EventArgs^  e) {

				 // this signifies that the user has used the program before
				 if (storage->loadProgram()) {
					 displayMax();
					 displayToday();
					 displayUpcoming();
					 displayMisc();

					 // this signifies the user is new to the program
				 } else {
					 MessageBox::Show("Welcome to EasyToDo!");
					 displayMax();
				 }
			 }

	private: System::Void commandLineTextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 // user can press ctrl+z for undo as a shortcut
				 if (e->KeyCode == Keys::Z && (e->Control)) {
					 parser->pushUserInput("undo");
					 displayFeedback();
					 displayToday();
					 displayUpcoming();
					 displayMisc();

				 // user can press ctrl+M to toggle between the two types of screen
				 } else if (e->KeyCode == Keys::M && (e->Control)) {
					 if (feedbackTextBox->Visible == true) {
						 displayMin();
						 displayFeedback();
						 displayToday();
						 displayUpcoming();
						 displayMisc();

					 } else {
						 displayMax();
						 displayFeedback();
						 displayToday();
						 displayUpcoming();
						 displayMisc();						 
					 }
				 }
					 
			 }

			 // displayMin refers to display with minimize features
			 void displayMin() {
				 monthCalendar->Visible = false;
				 logoPictureBox->Visible = false;
				 helpGuide->Visible = false;
				 displayHelp->Visible = false;
				 colourLegend->Visible = false;
				 feedbackTextBox->Visible = false;
				 todayLabel->Visible = false;
				 todayBorder->Visible = false;
				 todayRichTextBox->Visible = false;
				 upcomingLabel->Visible = false;
				 upcomingBorder->Visible = false;
				 upcomingRichTextBox->Visible = false;
				 miscLabel->Visible = false;
				 miscBorder->Visible = false;
				 miscRichTextBox->Visible = false;

				 feedbackTextBoxMin->Visible = true;
				 todayLabelMin->Visible = true;
				 todayBorderMin->Visible = true;
				 todayRichTextBoxMin->Visible = true;
				 upcomingLabelMin->Visible = true;
				 upcomingBorderMin->Visible = true;
				 upcomingRichTextBoxMin->Visible = true;
				 miscLabelMin->Visible = true;
				 miscBorderMin->Visible = true;
				 miscRichTextBoxMin->Visible = true;
			 }

			  // displayMax refers to display with maxmimum features
			 void displayMax() {
				 monthCalendar->Visible = true;
				 logoPictureBox->Visible = true;
				 helpGuide->Visible = true;
				 feedbackTextBox->Visible = true;
				 todayLabel->Visible = true;
				 todayBorder->Visible = true;
				 todayRichTextBox->Visible = true;
				 upcomingLabel->Visible = true;
				 upcomingBorder->Visible = true;
				 upcomingRichTextBox->Visible = true;
				 miscLabel->Visible = true;
				 miscBorder->Visible = true;
				 miscRichTextBox->Visible = true;

				 feedbackTextBoxMin->Visible = false;
				 todayLabelMin->Visible = false;
				 todayBorderMin->Visible = false;
				 todayRichTextBoxMin->Visible = false;
				 upcomingLabelMin->Visible = false;
				 upcomingBorderMin->Visible = false;
				 upcomingRichTextBoxMin->Visible = false;
				 miscLabelMin->Visible = false;
				 miscBorderMin->Visible = false;
				 miscRichTextBoxMin->Visible = false;
			 }

			 bool isDisplayMaxValid() {
				 if (feedbackTextBoxMin->Visible == false) {
					 return true;
				 } else {
					 return false;
				 }
			 }

			 // pre: user has some typed in some input in the commandline textbox
	private: System::Void commandLineTextBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 String^ input;

				 input = commandLineTextBox->Text;
				 if (e->KeyCode == Keys::Enter) {

					 displayHelp->Visible = false;
					 colourLegend->Visible = false;

					 String^ inputWithNoNewCharacter = removeNewLineCharacter(input);
					 if (inputWithNoNewCharacter != "") {
						 std::string content = systemToStdConverter(inputWithNoNewCharacter);
						 commandLineTextBox->Clear();
						 parser->pushUserInput(content);

						 displayFeedback();
						 displayToday();
						 displayUpcoming();
						 displayMisc(); 
					 }

					 // user can press F1 for in built user guide
					 // and press it again to make it disappear
					 // only avaliable in the displayMax
				 } else if (e->KeyCode == Keys::F1) { 
					 colourLegend->Visible = false;
					 if (isDisplayMaxValid()) {
						 if (displayHelp->Visible == false) {
							 displayUserGuide();

							 displayHelp->Visible = true;
						 }
						 else {
							 displayHelp->Visible = false;
						 }
					 }

					 // user can press F2 for in built colour legend and shortcut menu
					 // and press it again to make it disappear
					 // only avaliable in the displayMax
				 } else if (e->KeyCode == Keys::F2) { 
					 displayHelp->Visible = false;
					 if (isDisplayMaxValid()) {
						 if (colourLegend->Visible == false) {
							 displayColourguide();
							 colourLegend->Visible = true;
						 }
						 else {
							 colourLegend->Visible = false;
						 }
					 }

					 // user can press UP to obtain the last input
				 } else if (e->KeyCode == Keys::Up) { 
					 commandLineTextBox->Clear();

					 std:: stack<std:: string> inputHistory = inputFeedback->retrieveInputList();
					 if (!inputHistory.empty()) {
						 std:: string lastInputString = inputHistory.top();
						 String^ lastInput = stdToSystemConverter(lastInputString);
						 commandLineTextBox->Text = lastInput;

						 if (inputHistory.size() > 1) {
							 inputFeedback->removeFromMasterInputList();
						 }
					 }

					 // user can press down the obtain the recent input after the user had pressed up
				 } else if (e->KeyCode == Keys::Down) {
					 commandLineTextBox->Clear();

					 std:: stack<std:: string> inputHistoryDown = inputFeedback->retrieveInputListDown();
					 if (!inputHistoryDown.empty()) {
						 std:: string lastInputString;
						 lastInputString = inputHistoryDown.top();
						 String^ lastInput = stdToSystemConverter(lastInputString);
						 commandLineTextBox->Text = lastInput;
						 inputFeedback->removeFromMasterInputListDown();
					 }

					 // user can press ESC to exit the program
				 } else if (e->KeyCode == Keys::Escape) {
					 parser->pushUserInput("exit");

					 // if the input the user typed can be found in the display boxes, it will be highlighted in yellow
					 // only when the lenght of the input is more than 2 characters then it will be highlighted
				 } else {
					 String^ searchString = removeNewLineCharacter(input);

					 if (input->Length>2) {
						 if (isQuickSearchActivated(searchString)) {
							 displayToday();
							 displayUpcoming();
							 displayMisc();

							 searchString = retrieveSearchItem(searchString);
							 quickSearch(searchString);
						 }
					 }						 
				 }
			 }

			 bool isQuickSearchActivated(String^ searchString) {
				 std:: string search = systemToStdConverter(searchString);
				 if (search[0] == 's' && search[1] == ' ') {
					 return true;
				 } else {
					 return false;
				 }
			 }

			 String^ retrieveSearchItem(String^ searchString) {
				 std:: string search = systemToStdConverter(searchString);
				 search = search.substr(2);
				 return stdToSystemConverter(search);
			 }
			 std:: string systemToStdConverter(String^ system) {
				 return msclr::interop::marshal_as< std::string >(system);
			 }

			 String^ stdToSystemConverter(std:: string string) {
				 return gcnew String(string.c_str());
			 }

			 //goes through the whole string and removes any new line character (\n)
			 //each new line character has a size of 2
			 String^ removeNewLineCharacter(String^ input) {
				 std::string content = systemToStdConverter(input);
				 if ( content.length()>2) {
					 size_t pos = 0;
					 while ( ( pos = content.find ("\r\n",pos) ) != std::string::npos ) {
						 content.erase ( pos, 2 );
					 }
				 }
				 String^ searchString = stdToSystemConverter(content);

				 return searchString;
			 }

			 // obtains the feedback vector from the class architectureInputFeedback
			 // iterates from the back such that the most recent feedback will be displayed at the top
			 void displayFeedback() {
				 std:: vector<std:: string> feedbackList = inputFeedback->retrieveFeedbackList();
				 String^ feedbackSystem;
				 String^ feedback = "";

				 int totalFeedback = feedbackList.size();
				 std:: vector<std:: string>::iterator iter;

				 if (totalFeedback > 1) {
					 for (iter = feedbackList.end() - 1; iter != feedbackList.begin(); iter--) {
						 feedbackSystem = stdToSystemConverter(*iter);
						 feedback = feedback + feedbackSystem;

						 if (iter != feedbackList.begin()) {
							 feedback = feedback + "\r\n";
						 }
					 }
				 } else {
					 iter = feedbackList.begin();
					 feedback = stdToSystemConverter(*iter);
				 }
				 if (isDisplayMaxValid()) {
					 feedbackTextBox->Text = feedback;
				 } else {
					 feedbackTextBoxMin->Text = feedback;
				 }
			 }

			 // constantly iterates through the three display textboxes for any word that contains the exact same input
			 // any found input will be highlighted in yellow
			 void quickSearch(String^ searchString){
				 if (isDisplayMaxValid()) {
					 int indexToday=0;
					 while (indexToday<todayRichTextBox->Text->LastIndexOf(searchString)) {
						 todayRichTextBox->Find(searchString,indexToday,todayRichTextBox->TextLength, System::Windows::Forms::RichTextBoxFinds::None);
						 todayRichTextBox->SelectionBackColor = Color::Yellow;
						 indexToday = todayRichTextBox->Text->IndexOf(searchString, indexToday) + 1;
					 }

					 int indexUpcoming=0;
					 while (indexUpcoming<upcomingRichTextBox->Text->LastIndexOf(searchString)) {
						 upcomingRichTextBox->Find(searchString,indexUpcoming,upcomingRichTextBox->TextLength, System::Windows::Forms::RichTextBoxFinds::None);
						 upcomingRichTextBox->SelectionBackColor = Color::Yellow;
						 indexUpcoming = upcomingRichTextBox->Text->IndexOf(searchString, indexUpcoming) + 1;
					 }

					 int indexMisc=0;
					 while (indexMisc<miscRichTextBox->Text->LastIndexOf(searchString)) {
						 miscRichTextBox->Find(searchString,indexMisc,miscRichTextBox->TextLength, System::Windows::Forms::RichTextBoxFinds::None);
						 miscRichTextBox->SelectionBackColor = Color::Yellow;
						 indexMisc = miscRichTextBox->Text->IndexOf(searchString, indexMisc) + 1;
					 }
				 } else {
					 int indexToday=0;
					 while (indexToday<todayRichTextBoxMin->Text->LastIndexOf(searchString)) {
						 todayRichTextBoxMin->Find(searchString,indexToday,todayRichTextBoxMin->TextLength, System::Windows::Forms::RichTextBoxFinds::None);
						 todayRichTextBoxMin->SelectionBackColor = Color::Yellow;
						 indexToday = todayRichTextBoxMin->Text->IndexOf(searchString, indexToday) + 1;
					 }

					 int indexUpcoming=0;
					 while (indexUpcoming<upcomingRichTextBoxMin->Text->LastIndexOf(searchString)) {
						 upcomingRichTextBoxMin->Find(searchString,indexUpcoming,upcomingRichTextBoxMin->TextLength, System::Windows::Forms::RichTextBoxFinds::None);
						 upcomingRichTextBoxMin->SelectionBackColor = Color::Yellow;
						 indexUpcoming = upcomingRichTextBoxMin->Text->IndexOf(searchString, indexUpcoming) + 1;
					 }

					 int indexMisc=0;
					 while (indexMisc<miscRichTextBoxMin->Text->LastIndexOf(searchString)) {
						 miscRichTextBoxMin->Find(searchString,indexMisc,miscRichTextBoxMin->TextLength, System::Windows::Forms::RichTextBoxFinds::None);
						 miscRichTextBoxMin->SelectionBackColor = Color::Yellow;
						 indexMisc = miscRichTextBoxMin->Text->IndexOf(searchString, indexMisc) + 1;
					 }
				 }
			 }

			 // this function will take in the taskList of type TASK
			 // and converts it to std::string to display accordingly, depends if it is a timed, deadline or misc task
			 // uses time_facet to display the start time and end time accordingly
			 std:: vector<std:: string> retrieveTaskList(std:: vector<TASK> taskList){
				 std:: vector<std:: string> taskListString;

				 storage->updateTaskID(taskList);
				 std:: vector<TASK>::iterator iter;
				 for(iter = taskList.begin(); iter != taskList.end(); iter++) {
					 std:: stringstream ss;
					 ss << iter->taskID;

					 boost::posix_time::time_facet* facet = new boost::posix_time::time_facet("%A, %Y-%b-%d %H:%M");
					 boost::posix_time::time_facet* facetEnd = new boost::posix_time::time_facet("%H:%M");

					 if((iter->endTime).is_not_a_date_time()) {
						 if((iter->startDateTime).is_not_a_date_time()) {
							 ss << ". " << iter->taskDescriptionList;
						 } else {
							 ss.imbue(std:: locale(std:: locale::classic(), facet));
							 ss << ". [" << iter->startDateTime << "] " << iter->taskDescriptionList; 
						 }
					 } else {
						 ss.imbue(std:: locale(std:: locale::classic(), facet));
						 ss << ". [" << iter->startDateTime << "-";
						 ss.imbue(std:: locale(std:: locale::classic(), facetEnd));
						 ss << iter->endDateTime << "] " << iter->taskDescriptionList;
					 }

					 taskListString.push_back(ss.str());
				 }

				 return taskListString;
			 }

			 // in displayToday, done will always take the top precedence, followed by overdue, clash and then new
			 // for example, if task A is both done and overdue, it will appear as done
			 // for example, if task B is both overdue and clash, it will appear as overdue
			 // for example, if task C is both clash and new, it will appear as clash
			 void displayToday() {

				 std:: vector<TASK> todayTaskList = storage->retrieveTodayTaskList();
				 std:: vector<std:: string> todayList = retrieveTaskList(todayTaskList);

				 String^ displayToday = "";

				 todayRichTextBox->Clear();
				 todayRichTextBoxMin->Clear();


				 int totalTodayTaskList = todayList.size();
				 if (isDisplayMaxValid()) {
				 for (int i=0; i<totalTodayTaskList; i++) {
					 displayToday = stdToSystemConverter(todayList[i]);

					 if (isTaskDone(todayTaskList,i)) {

						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
						 todayRichTextBox->SelectionColor = Color::CornflowerBlue;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";

					 } else if (isTaskOverdue(todayTaskList, i)) {

						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
						 todayRichTextBox->SelectionColor = Color::Red;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";

					 } else if (isTaskClash(todayTaskList, i)) {

						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Underline);
						 todayRichTextBox->SelectionColor = Color::Coral;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";

					 } else if (isTaskNew(todayTaskList, i)) {

						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
						 todayRichTextBox->SelectionColor = Color::DeepSkyBlue;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";

					 } else {

						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular );
						 todayRichTextBox->SelectionColor = Color::Black;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";

					 }
				 }
				 } else {
					 for (int i=0; i<totalTodayTaskList; i++) {
					 displayToday = stdToSystemConverter(todayList[i]);

					 if (isTaskDone(todayTaskList,i)) {

						 todayRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
						 todayRichTextBoxMin->SelectionColor = Color::CornflowerBlue;
						 todayRichTextBoxMin->SelectedText = displayToday + "\r\n";

					 } else if (isTaskOverdue(todayTaskList, i)) {

						 todayRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
						 todayRichTextBoxMin->SelectionColor = Color::Red;
						 todayRichTextBoxMin->SelectedText = displayToday + "\r\n";

					 } else if (isTaskClash(todayTaskList, i)) {

						 todayRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Underline);
						 todayRichTextBoxMin->SelectionColor = Color::Coral;
						 todayRichTextBoxMin->SelectedText = displayToday + "\r\n";

					 } else if (isTaskNew(todayTaskList, i)) {

						 todayRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
						 todayRichTextBoxMin->SelectionColor = Color::DeepSkyBlue;
						 todayRichTextBoxMin->SelectedText = displayToday + "\r\n";

					 } else {

						 todayRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular );
						 todayRichTextBoxMin->SelectionColor = Color::Black;
						 todayRichTextBoxMin->SelectedText = displayToday + "\r\n";

					 }
				 }
				 }
			 }

			 // in displayUpcoming, done will always take the top precedence, followed by clash and then new
			 // for example, if task A is both done and clash, it will appear as done
			 // for example, if task B is both clash and new, it will appear as clash
			 void displayUpcoming() {

				 std:: vector<TASK> upcomingTaskList = storage->retrieveUpcomingTaskList();
				 std:: vector<std:: string> upcomingList = retrieveTaskList(upcomingTaskList);
				 int totalUpcomingTaskList = upcomingTaskList.size();
				 String^ displayUpcoming = "";

				 upcomingRichTextBox->Clear();
				 upcomingRichTextBoxMin->Clear();

				 if (isDisplayMaxValid()) {
					 for (int i=0; i<totalUpcomingTaskList; i++) {
						 displayUpcoming = stdToSystemConverter(upcomingList[i]);

						 if (isTaskDone(upcomingTaskList, i)) {

							 upcomingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
							 upcomingRichTextBox->SelectionColor = Color::CornflowerBlue;
							 upcomingRichTextBox->SelectedText = displayUpcoming + "\r\n";

						 } else if ( isTaskClash(upcomingTaskList, i) ) {

							 upcomingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Underline);
							 upcomingRichTextBox->SelectionColor = Color::Coral;
							 upcomingRichTextBox->SelectedText = displayUpcoming + "\r\n";

						 } else if (isTaskNew(upcomingTaskList, i)) {

							 upcomingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
							 upcomingRichTextBox->SelectionColor = Color::DeepSkyBlue;
							 upcomingRichTextBox->SelectedText = displayUpcoming + "\r\n";

						 } else {

							 upcomingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular );
							 upcomingRichTextBox->SelectionColor = Color::Black;
							 upcomingRichTextBox->SelectedText = displayUpcoming + "\r\n";
						 }
					 }
				 } else {
					 for (int i=0; i<totalUpcomingTaskList; i++) {
						 displayUpcoming = stdToSystemConverter(upcomingList[i]);

						 if (isTaskDone(upcomingTaskList, i)) {

							 upcomingRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
							 upcomingRichTextBoxMin->SelectionColor = Color::CornflowerBlue;
							 upcomingRichTextBoxMin->SelectedText = displayUpcoming + "\r\n";

						 } else if ( isTaskClash(upcomingTaskList, i) ) {

							 upcomingRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Underline);
							 upcomingRichTextBoxMin->SelectionColor = Color::Coral;
							 upcomingRichTextBoxMin->SelectedText = displayUpcoming + "\r\n";

						 } else if (isTaskNew(upcomingTaskList, i)) {

							 upcomingRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
							 upcomingRichTextBoxMin->SelectionColor = Color::DeepSkyBlue;
							 upcomingRichTextBoxMin->SelectedText = displayUpcoming + "\r\n";

						 } else {

							 upcomingRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular );
							 upcomingRichTextBoxMin->SelectionColor = Color::Black;
							 upcomingRichTextBoxMin->SelectedText = displayUpcoming + "\r\n";
						 }
					 }
				 }
			 }

			 // in displayMisc, done will always take the top precedence, followed by new
			 // done and new are mutually exclusive so it won't happen together
			 void displayMisc() {
				 std:: vector<TASK> miscTaskList = storage->retrieveFloatingTaskList();
				 std:: vector<std:: string> miscList = retrieveTaskList(miscTaskList);
				 int totalMiscTaskList = miscTaskList.size();
				 String^ displayMisc = "";

				 miscRichTextBox->Clear();
				 miscRichTextBoxMin->Clear();

				 if (isDisplayMaxValid()) {
					 for (int i=0; i<totalMiscTaskList; i++) {
						 displayMisc = stdToSystemConverter(miscList[i]);

						 if ( isTaskDone(miscTaskList, i)) {

							 miscRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
							 miscRichTextBox->SelectionColor = Color::CornflowerBlue;
							 miscRichTextBox->SelectedText = displayMisc + "\r\n";

						 } else	if ( isTaskNew(miscTaskList, i)) {

							 miscRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
							 miscRichTextBox->SelectionColor = Color::DeepSkyBlue;
							 miscRichTextBox->SelectedText = displayMisc + "\r\n";

						 } else {

							 miscRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular );
							 miscRichTextBox->SelectionColor = Color::Black;
							 miscRichTextBox->SelectedText = displayMisc + "\r\n";

						 }
					 }
				 } else {
					 for (int i=0; i<totalMiscTaskList; i++) {
						 displayMisc = stdToSystemConverter(miscList[i]);

						 if ( isTaskDone(miscTaskList, i)) {

							 miscRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
							 miscRichTextBoxMin->SelectionColor = Color::CornflowerBlue;
							 miscRichTextBoxMin->SelectedText = displayMisc + "\r\n";

						 } else	if ( isTaskNew(miscTaskList, i)) {

							 miscRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
							 miscRichTextBoxMin->SelectionColor = Color::DeepSkyBlue;
							 miscRichTextBoxMin->SelectedText = displayMisc + "\r\n";

						 } else {

							 miscRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular );
							 miscRichTextBoxMin->SelectionColor = Color::Black;
							 miscRichTextBoxMin->SelectedText = displayMisc + "\r\n";

						 }
					 }
				 }
			 }

			 bool isTaskDone(std:: vector<TASK> taskList, int i) {
				 if (taskList[i].done == true) {
					 return true;
				 }
				 else {
					 return false;
				 }
			 }


			 bool isTaskOverdue(std:: vector<TASK> taskList, int i) {
				 if (taskList[i].overdue == true) {
					 return true;
				 }
				 else {
					 return false;
				 }
			 }

			 bool isTaskClash(std:: vector<TASK> taskList, int i) {
				 if (taskList[i].clash == true) {
					 return true;
				 }
				 else {
					 return false;
				 }
			 }

			 bool isTaskNew(std:: vector<TASK> taskList, int i) {
				 if (taskList[i].newTask == true) {
					 return true;
				 }
				 else {
					 return false;
				 }
			 }

			 void displayUserGuide() {
				 displayHelp->Clear();

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Candara", 10, System::Drawing::FontStyle::Bold);
				 displayHelp->SelectionAlignment = HorizontalAlignment::Center;
				 displayHelp->SelectionColor = Color::LightSlateGray;
				 displayHelp->AppendText("HELP FOR NEW USERS" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 displayHelp->SelectionAlignment = HorizontalAlignment::Left;
				 displayHelp->AppendText("add ");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 displayHelp->AppendText("<taskDesc> ");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 displayHelp->AppendText("on/by/from ");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 displayHelp->AppendText("<date> <startTime> ");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 displayHelp->AppendText("to ");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 displayHelp->AppendText("<endTime>" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 displayHelp->AppendText("-add meet ivy on 30 mar 14:00" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 displayHelp->AppendText("-add swimming training from 1 apr 4 to 6pm" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 displayHelp->AppendText("-add buy Amy's 21st gift" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 displayHelp->AppendText("delete ");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 displayHelp->AppendText("<taskType> <taskID>" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 displayHelp->AppendText("-delete misc 1" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 displayHelp->AppendText("update ");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 displayHelp->AppendText("<taskType> <taskID> <add format> " + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 displayHelp->AppendText("-update upcoming 2 meet ivy for dinner from 14 mar 14:00 to 16:00" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 displayHelp->AppendText("done ");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 displayHelp->AppendText("<taskType> <taskID> " + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 displayHelp->AppendText("-done today 3" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Bold);
				 displayHelp->AppendText("clear ");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Regular);
				 displayHelp->AppendText("<taskType> " + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 displayHelp->AppendText("-clear all" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 displayHelp->AppendText("undo" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 displayHelp->AppendText("save ");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 displayHelp->AppendText("<fileDirectory> <fileName>" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 displayHelp->AppendText("-save C:\\Users\\Ivy\\Desktop\\ EasyToDo.txt" + "\r\n");

				 displayHelp->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 displayHelp->AppendText("-save (default settings)");
			 }

			 void displayColourguide(){
				 colourLegend->Clear();

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Candara", 10, System::Drawing::FontStyle::Bold);
				 colourLegend->SelectionAlignment = HorizontalAlignment::Center;
				 colourLegend->SelectionColor = Color::LightSlateGray;
				 colourLegend->AppendText("COLOUR LEGEND" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 colourLegend->SelectionAlignment = HorizontalAlignment::Left;
				 colourLegend->SelectionColor = Color::Red;
				 colourLegend->AppendText("overdue task" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Underline);
				 colourLegend->SelectionColor = Color::Coral;
				 colourLegend->AppendText("clashing tasks" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Strikeout);
				 colourLegend->SelectionColor = Color::CornflowerBlue;
				 colourLegend->AppendText("done task" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 colourLegend->SelectionColor = Color::DeepSkyBlue;
				 colourLegend->AppendText("new task" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 colourLegend->SelectionColor = Color::Black;
				 colourLegend->SelectionBackColor = Color::Yellow;
				 colourLegend->AppendText("quicksearch task" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 colourLegend->SelectionColor = Color::Black;
				 colourLegend->AppendText("a normal upcoming task" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Candara", 10, System::Drawing::FontStyle::Bold);
				 colourLegend->SelectionAlignment = HorizontalAlignment::Center;
				 colourLegend->SelectionColor = Color::LightSlateGray;
				 colourLegend->AppendText("SHORTCUT" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 colourLegend->SelectionAlignment = HorizontalAlignment::Left;
				 colourLegend->SelectionColor = Color::Black;
				 colourLegend->AppendText("-Press up and down the retreieve the last/recent input" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 colourLegend->AppendText("-Press Ctrl+M to toggle between the two screens" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 colourLegend->AppendText("-Press \"s \" followed by the search item to quicksearch" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 colourLegend->AppendText("-Press Ctrl+Z to undo" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 colourLegend->AppendText("-Press Esc to exit");
			 }



};
}