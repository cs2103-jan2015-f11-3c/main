// @author A0115188A
#pragma once
#include <string>
#include <vector>
#include <stack>
#include <msclr/marshal_cppstd.h>

#include "E2DParser.h"
#include "E2DInputFeedback.h"
#include "E2DStorage.h"

namespace E2DUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for E2DUI
	/// </summary>
	public ref class E2DUI : public System::Windows::Forms::Form
	{
	public:
		E2DParser* parser;
		E2DInputFeedback* inputFeedback;
	private: System::Windows::Forms::Label^  helpGuide;
	private: System::Windows::Forms::RichTextBox^  shortcutMenu;
	public: 
		E2DStorage* storage;

		E2DUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			parser = new E2DParser();
			inputFeedback = new E2DInputFeedback();
			storage = new E2DStorage();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~E2DUI(void)
		{
			if (components)
			{
				delete components;
				delete parser;
				delete inputFeedback;
				delete storage;
			}
		}
	private: System::Windows::Forms::TextBox^  commandLineTextBox;
	private: System::Windows::Forms::TextBox^  feedbackTextBox;
	private: System::Windows::Forms::TextBox^  todayBorder;
	private: System::Windows::Forms::RichTextBox^  todayRichTextBox;
	private: System::Windows::Forms::Label^  todayLabel;
	private: System::Windows::Forms::Label^  upcomingLabel;

	private: System::Windows::Forms::RichTextBox^  upcomingRichTextBox;
	private: System::Windows::Forms::TextBox^  upcomingBorder;
	private: System::Windows::Forms::Label^  floatingLabel;

	private: System::Windows::Forms::RichTextBox^  floatingRichTextBox;
	private: System::Windows::Forms::TextBox^  floatingBorder;
	private: System::Windows::Forms::TextBox^  feedbackTextBoxMin;
	private: System::Windows::Forms::Label^  floatingLabelMin;

	private: System::Windows::Forms::RichTextBox^  floatingRichTextBoxMin;
	private: System::Windows::Forms::TextBox^  floatingBorderMin;


	private: System::Windows::Forms::Label^  upcomingLabelMin;
	private: System::Windows::Forms::RichTextBox^  upcomingRichTextBoxMin;


	private: System::Windows::Forms::TextBox^  upcomingBorderMin;

	private: System::Windows::Forms::Label^  todayLabelMin;

	private: System::Windows::Forms::RichTextBox^  todayRichTextBoxMin;
	private: System::Windows::Forms::TextBox^  todayBorderMin;
	private: System::Windows::Forms::RichTextBox^  userGuide;


	private: System::Windows::Forms::RichTextBox^  colourLegend;
	private: System::Windows::Forms::MonthCalendar^  monthCalendar;
	private: System::Windows::Forms::PictureBox^  logoPictureBox;


	protected: 


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(E2DUI::typeid));
			this->commandLineTextBox = (gcnew System::Windows::Forms::TextBox());
			this->feedbackTextBox = (gcnew System::Windows::Forms::TextBox());
			this->todayBorder = (gcnew System::Windows::Forms::TextBox());
			this->todayRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->todayLabel = (gcnew System::Windows::Forms::Label());
			this->upcomingLabel = (gcnew System::Windows::Forms::Label());
			this->upcomingRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->upcomingBorder = (gcnew System::Windows::Forms::TextBox());
			this->floatingLabel = (gcnew System::Windows::Forms::Label());
			this->floatingRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->floatingBorder = (gcnew System::Windows::Forms::TextBox());
			this->feedbackTextBoxMin = (gcnew System::Windows::Forms::TextBox());
			this->floatingLabelMin = (gcnew System::Windows::Forms::Label());
			this->floatingRichTextBoxMin = (gcnew System::Windows::Forms::RichTextBox());
			this->floatingBorderMin = (gcnew System::Windows::Forms::TextBox());
			this->upcomingLabelMin = (gcnew System::Windows::Forms::Label());
			this->upcomingRichTextBoxMin = (gcnew System::Windows::Forms::RichTextBox());
			this->upcomingBorderMin = (gcnew System::Windows::Forms::TextBox());
			this->todayLabelMin = (gcnew System::Windows::Forms::Label());
			this->todayRichTextBoxMin = (gcnew System::Windows::Forms::RichTextBox());
			this->todayBorderMin = (gcnew System::Windows::Forms::TextBox());
			this->userGuide = (gcnew System::Windows::Forms::RichTextBox());
			this->colourLegend = (gcnew System::Windows::Forms::RichTextBox());
			this->monthCalendar = (gcnew System::Windows::Forms::MonthCalendar());
			this->logoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->helpGuide = (gcnew System::Windows::Forms::Label());
			this->shortcutMenu = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// commandLineTextBox
			// 
			this->commandLineTextBox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->commandLineTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.900001F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->commandLineTextBox->ForeColor = System::Drawing::Color::Black;
			this->commandLineTextBox->Location = System::Drawing::Point(829, 106);
			this->commandLineTextBox->Multiline = true;
			this->commandLineTextBox->Name = L"commandLineTextBox";
			this->commandLineTextBox->Size = System::Drawing::Size(1099, 58);
			this->commandLineTextBox->TabIndex = 0;
			this->commandLineTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &E2DUI::commandLineTextBox_KeyDown);
			this->commandLineTextBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &E2DUI::commandLineTextBox_KeyUp);
			// 
			// feedbackTextBox
			// 
			this->feedbackTextBox->BackColor = System::Drawing::Color::AliceBlue;
			this->feedbackTextBox->Location = System::Drawing::Point(829, 200);
			this->feedbackTextBox->Multiline = true;
			this->feedbackTextBox->Name = L"feedbackTextBox";
			this->feedbackTextBox->Size = System::Drawing::Size(1099, 359);
			this->feedbackTextBox->TabIndex = 1;
			// 
			// todayBorder
			// 
			this->todayBorder->Location = System::Drawing::Point(63, 696);
			this->todayBorder->Multiline = true;
			this->todayBorder->Name = L"todayBorder";
			this->todayBorder->Size = System::Drawing::Size(818, 754);
			this->todayBorder->TabIndex = 2;
			// 
			// todayRichTextBox
			// 
			this->todayRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->todayRichTextBox->Location = System::Drawing::Point(82, 728);
			this->todayRichTextBox->Name = L"todayRichTextBox";
			this->todayRichTextBox->Size = System::Drawing::Size(781, 711);
			this->todayRichTextBox->TabIndex = 3;
			this->todayRichTextBox->Text = L"";
			// 
			// todayLabel
			// 
			this->todayLabel->AutoSize = true;
			this->todayLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->todayLabel->Location = System::Drawing::Point(74, 672);
			this->todayLabel->Name = L"todayLabel";
			this->todayLabel->Size = System::Drawing::Size(158, 46);
			this->todayLabel->TabIndex = 4;
			this->todayLabel->Text = L"TODAY";
			// 
			// upcomingLabel
			// 
			this->upcomingLabel->AutoSize = true;
			this->upcomingLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->upcomingLabel->Location = System::Drawing::Point(951, 672);
			this->upcomingLabel->Name = L"upcomingLabel";
			this->upcomingLabel->Size = System::Drawing::Size(241, 46);
			this->upcomingLabel->TabIndex = 7;
			this->upcomingLabel->Text = L"UPCOMING";
			// 
			// upcomingRichTextBox
			// 
			this->upcomingRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->upcomingRichTextBox->Location = System::Drawing::Point(959, 728);
			this->upcomingRichTextBox->Name = L"upcomingRichTextBox";
			this->upcomingRichTextBox->Size = System::Drawing::Size(781, 711);
			this->upcomingRichTextBox->TabIndex = 6;
			this->upcomingRichTextBox->Text = L"";
			// 
			// upcomingBorder
			// 
			this->upcomingBorder->Location = System::Drawing::Point(940, 696);
			this->upcomingBorder->Multiline = true;
			this->upcomingBorder->Name = L"upcomingBorder";
			this->upcomingBorder->Size = System::Drawing::Size(818, 754);
			this->upcomingBorder->TabIndex = 5;
			// 
			// floatingLabel
			// 
			this->floatingLabel->AutoSize = true;
			this->floatingLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->floatingLabel->Location = System::Drawing::Point(1798, 663);
			this->floatingLabel->Name = L"floatingLabel";
			this->floatingLabel->Size = System::Drawing::Size(220, 46);
			this->floatingLabel->TabIndex = 10;
			this->floatingLabel->Text = L"FLOATING";
			// 
			// floatingRichTextBox
			// 
			this->floatingRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->floatingRichTextBox->Location = System::Drawing::Point(1806, 719);
			this->floatingRichTextBox->Name = L"floatingRichTextBox";
			this->floatingRichTextBox->Size = System::Drawing::Size(781, 711);
			this->floatingRichTextBox->TabIndex = 9;
			this->floatingRichTextBox->Text = L"";
			// 
			// floatingBorder
			// 
			this->floatingBorder->Location = System::Drawing::Point(1787, 687);
			this->floatingBorder->Multiline = true;
			this->floatingBorder->Name = L"floatingBorder";
			this->floatingBorder->Size = System::Drawing::Size(818, 754);
			this->floatingBorder->TabIndex = 8;
			// 
			// feedbackTextBoxMin
			// 
			this->feedbackTextBoxMin->BackColor = System::Drawing::Color::AliceBlue;
			this->feedbackTextBoxMin->Location = System::Drawing::Point(829, 197);
			this->feedbackTextBoxMin->Multiline = true;
			this->feedbackTextBoxMin->Name = L"feedbackTextBoxMin";
			this->feedbackTextBoxMin->Size = System::Drawing::Size(1099, 77);
			this->feedbackTextBoxMin->TabIndex = 11;
			// 
			// floatingLabelMin
			// 
			this->floatingLabelMin->AutoSize = true;
			this->floatingLabelMin->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->floatingLabelMin->Location = System::Drawing::Point(1798, 285);
			this->floatingLabelMin->Name = L"floatingLabelMin";
			this->floatingLabelMin->Size = System::Drawing::Size(220, 46);
			this->floatingLabelMin->TabIndex = 20;
			this->floatingLabelMin->Text = L"FLOATING";
			// 
			// floatingRichTextBoxMin
			// 
			this->floatingRichTextBoxMin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->floatingRichTextBoxMin->Location = System::Drawing::Point(1806, 325);
			this->floatingRichTextBoxMin->Name = L"floatingRichTextBoxMin";
			this->floatingRichTextBoxMin->Size = System::Drawing::Size(781, 1156);
			this->floatingRichTextBoxMin->TabIndex = 19;
			this->floatingRichTextBoxMin->Text = L"";
			// 
			// floatingBorderMin
			// 
			this->floatingBorderMin->Location = System::Drawing::Point(1787, 293);
			this->floatingBorderMin->Multiline = true;
			this->floatingBorderMin->Name = L"floatingBorderMin";
			this->floatingBorderMin->Size = System::Drawing::Size(818, 1199);
			this->floatingBorderMin->TabIndex = 18;
			// 
			// upcomingLabelMin
			// 
			this->upcomingLabelMin->AutoSize = true;
			this->upcomingLabelMin->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->upcomingLabelMin->Location = System::Drawing::Point(951, 294);
			this->upcomingLabelMin->Name = L"upcomingLabelMin";
			this->upcomingLabelMin->Size = System::Drawing::Size(241, 46);
			this->upcomingLabelMin->TabIndex = 17;
			this->upcomingLabelMin->Text = L"UPCOMING";
			// 
			// upcomingRichTextBoxMin
			// 
			this->upcomingRichTextBoxMin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->upcomingRichTextBoxMin->Location = System::Drawing::Point(959, 334);
			this->upcomingRichTextBoxMin->Name = L"upcomingRichTextBoxMin";
			this->upcomingRichTextBoxMin->Size = System::Drawing::Size(781, 1156);
			this->upcomingRichTextBoxMin->TabIndex = 16;
			this->upcomingRichTextBoxMin->Text = L"";
			// 
			// upcomingBorderMin
			// 
			this->upcomingBorderMin->Location = System::Drawing::Point(940, 302);
			this->upcomingBorderMin->Multiline = true;
			this->upcomingBorderMin->Name = L"upcomingBorderMin";
			this->upcomingBorderMin->Size = System::Drawing::Size(818, 1199);
			this->upcomingBorderMin->TabIndex = 15;
			// 
			// todayLabelMin
			// 
			this->todayLabelMin->AutoSize = true;
			this->todayLabelMin->Font = (gcnew System::Drawing::Font(L"Rockwell", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->todayLabelMin->Location = System::Drawing::Point(74, 294);
			this->todayLabelMin->Name = L"todayLabelMin";
			this->todayLabelMin->Size = System::Drawing::Size(158, 46);
			this->todayLabelMin->TabIndex = 14;
			this->todayLabelMin->Text = L"TODAY";
			// 
			// todayRichTextBoxMin
			// 
			this->todayRichTextBoxMin->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->todayRichTextBoxMin->Location = System::Drawing::Point(82, 334);
			this->todayRichTextBoxMin->Name = L"todayRichTextBoxMin";
			this->todayRichTextBoxMin->Size = System::Drawing::Size(781, 1156);
			this->todayRichTextBoxMin->TabIndex = 13;
			this->todayRichTextBoxMin->Text = L"";
			// 
			// todayBorderMin
			// 
			this->todayBorderMin->Location = System::Drawing::Point(63, 302);
			this->todayBorderMin->Multiline = true;
			this->todayBorderMin->Name = L"todayBorderMin";
			this->todayBorderMin->Size = System::Drawing::Size(818, 1199);
			this->todayBorderMin->TabIndex = 12;
			// 
			// userGuide
			// 
			this->userGuide->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->userGuide->Location = System::Drawing::Point(20, 20);
			this->userGuide->Name = L"userGuide";
			this->userGuide->Size = System::Drawing::Size(793, 630);
			this->userGuide->TabIndex = 21;
			this->userGuide->Text = L"";
			// 
			// colourLegend
			// 
			this->colourLegend->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->colourLegend->Location = System::Drawing::Point(82, 114);
			this->colourLegend->Name = L"colourLegend";
			this->colourLegend->Size = System::Drawing::Size(639, 454);
			this->colourLegend->TabIndex = 22;
			this->colourLegend->Text = L"";
			// 
			// monthCalendar
			// 
			this->monthCalendar->Location = System::Drawing::Point(107, 118);
			this->monthCalendar->Name = L"monthCalendar";
			this->monthCalendar->ShowToday = false;
			this->monthCalendar->TabIndex = 23;
			// 
			// logoPictureBox
			// 
			this->logoPictureBox->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"logoPictureBox.Image")));
			this->logoPictureBox->Location = System::Drawing::Point(2005, 197);
			this->logoPictureBox->Name = L"logoPictureBox";
			this->logoPictureBox->Size = System::Drawing::Size(600, 353);
			this->logoPictureBox->TabIndex = 24;
			this->logoPictureBox->TabStop = false;
			// 
			// helpGuide
			// 
			this->helpGuide->AutoSize = true;
			this->helpGuide->Font = (gcnew System::Drawing::Font(L"Calibri", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->helpGuide->Location = System::Drawing::Point(958, 66);
			this->helpGuide->Name = L"helpGuide";
			this->helpGuide->Size = System::Drawing::Size(970, 37);
			this->helpGuide->TabIndex = 25;
			this->helpGuide->Text = L"Press F1 for user guide. Press F2 for shortcuts menu. Press F3 for colour legend." 
				L"";
			// 
			// shortcutMenu
			// 
			this->shortcutMenu->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->shortcutMenu->Location = System::Drawing::Point(66, 33);
			this->shortcutMenu->Name = L"shortcutMenu";
			this->shortcutMenu->Size = System::Drawing::Size(655, 612);
			this->shortcutMenu->TabIndex = 26;
			this->shortcutMenu->Text = L"";
			// 
			// E2DUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(2710, 1683);
			this->Controls->Add(this->shortcutMenu);
			this->Controls->Add(this->colourLegend);
			this->Controls->Add(this->helpGuide);
			this->Controls->Add(this->logoPictureBox);
			this->Controls->Add(this->feedbackTextBoxMin);
			this->Controls->Add(this->floatingLabel);
			this->Controls->Add(this->floatingRichTextBox);
			this->Controls->Add(this->floatingBorder);
			this->Controls->Add(this->upcomingLabel);
			this->Controls->Add(this->upcomingRichTextBox);
			this->Controls->Add(this->upcomingBorder);
			this->Controls->Add(this->todayLabel);
			this->Controls->Add(this->todayRichTextBox);
			this->Controls->Add(this->todayBorder);
			this->Controls->Add(this->commandLineTextBox);
			this->Controls->Add(this->todayLabelMin);
			this->Controls->Add(this->todayRichTextBoxMin);
			this->Controls->Add(this->todayBorderMin);
			this->Controls->Add(this->upcomingLabelMin);
			this->Controls->Add(this->upcomingRichTextBoxMin);
			this->Controls->Add(this->upcomingBorderMin);
			this->Controls->Add(this->floatingLabelMin);
			this->Controls->Add(this->floatingRichTextBoxMin);
			this->Controls->Add(this->floatingBorderMin);
			this->Controls->Add(this->feedbackTextBox);
			this->Controls->Add(this->userGuide);
			this->Controls->Add(this->monthCalendar);
			this->Name = L"E2DUI";
			this->Padding = System::Windows::Forms::Padding(30);
			this->Text = L"E2DUI";
			this->Load += gcnew System::EventHandler(this, &E2DUI::E2DUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void E2DUI_Load(System::Object^  sender, System::EventArgs^  e) {
				  // this signifies that the user has used the program before
				 if (storage->loadProgram()) {
					  displayMax();
					 displayOutput();

					 // this signifies the user is new to the program
				 } else {
					 MessageBox::Show("Welcome to EasyToDo!");
					 displayMax();
				 }
			 }

			 // displayMin refers to display with minimize features
			 void displayMin() {
				 monthCalendar->Visible = false;
				 logoPictureBox->Visible = false;
				 helpGuide->Visible = false;
				 userGuide->Visible = false;
				 shortcutMenu->Visible = false;
				 colourLegend->Visible = false;
				 feedbackTextBox->Visible = false;
				 todayLabel->Visible = false;
				 todayBorder->Visible = false;
				 todayRichTextBox->Visible = false;
				 upcomingLabel->Visible = false;
				 upcomingBorder->Visible = false;
				 upcomingRichTextBox->Visible = false;
				 floatingLabel->Visible = false;
				 floatingBorder->Visible = false;
				 floatingRichTextBox->Visible = false;

				 feedbackTextBoxMin->Visible = true;
				 todayLabelMin->Visible = true;
				 todayBorderMin->Visible = true;
				 todayRichTextBoxMin->Visible = true;
				 upcomingLabelMin->Visible = true;
				 upcomingBorderMin->Visible = true;
				 upcomingRichTextBoxMin->Visible = true;
				 floatingLabelMin->Visible = true;
				 floatingBorderMin->Visible = true;
				 floatingRichTextBoxMin->Visible = true;
				 
				 commandLineTextBox->Clear();
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
				 floatingLabel->Visible = true;
				 floatingBorder->Visible = true;
				 floatingRichTextBox->Visible = true;

				 userGuide->Visible = false;
				 shortcutMenu->Visible = false;
				 colourLegend->Visible = false;
				 shortcutMenu->Visible = false;
				 feedbackTextBoxMin->Visible = false;
				 todayLabelMin->Visible = false;
				 todayBorderMin->Visible = false;
				 todayRichTextBoxMin->Visible = false;
				 upcomingLabelMin->Visible = false;
				 upcomingBorderMin->Visible = false;
				 upcomingRichTextBoxMin->Visible = false;
				 floatingLabelMin->Visible = false;
				 floatingBorderMin->Visible = false;
				 floatingRichTextBoxMin->Visible = false;

				 commandLineTextBox->Clear();
			 }

			 bool isDisplayMaxValid() {
				 if (feedbackTextBoxMin->Visible == false) {
					 return true;
				 } else {
					 return false;
				 }
			 }


private: System::Void commandLineTextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			  // user can press Ctrl+Z for undo as a shortcut
				 if (e->KeyCode == Keys::Z && (e->Control)) {
					 parser->pushUserInput("undo");
					  displayOutput();

					 // user can press Ctrl+Z to toggle between the two types of screen
				 } else if (e->KeyCode == Keys::M && (e->Control)) {
					 if (feedbackTextBox->Visible == true) {
						 displayMin();
						 displayOutput();

					 } else {
						 displayMax();
						 displayOutput();				 
					 }
				 }
		 }

private: System::Void commandLineTextBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			  String^ input;

				 input = commandLineTextBox->Text;
				 if (e->KeyCode == Keys::Enter) {

					 userGuide->Visible = false;
					 colourLegend->Visible = false;
					 shortcutMenu->Visible - false;
					 commandLineTextBox->Clear();

					 String^ inputWithNoNewCharacter = removeNewLineCharacter(input);
					 std::string content = systemToStdConverter(inputWithNoNewCharacter);
					 parser->pushUserInput(content);
					 
					 displayOutput();
					 // user can press F1 for built-in user guide
					 // and press it again to make it disappear
					 // only avaliable in the displayMax
				 } else if (e->KeyCode == Keys::F1) { 
					 colourLegend->Visible = false;
					 shortcutMenu->Visible = false;

					 if (userGuide->Visible == false && isDisplayMaxValid()) {
						 displayUserGuide();

						 userGuide->Visible = true;
					 }
					 else {
						 userGuide->Visible = false;
					 }
					 
					 // user can press F2 for built-in shortcut menu
					 // and press it again to make it disappear
					 // only avaliable in the displayMax
				 } else if (e->KeyCode == Keys::F2) { 
					 userGuide->Visible = false;
					 colourLegend->Visible = false;

					 if (shortcutMenu->Visible == false && isDisplayMaxValid()) {
						 displayShortcutMenu();
						 shortcutMenu->Visible = true;
					 }
					 else {
						 shortcutMenu->Visible = false;
					 }

					 // user can press F3 for built-in colour legend
					 // and press it again to make it disappear
					 // only avaliable in the displayMax
				 } else if (e->KeyCode == Keys::F3) {
					 userGuide->Visible = false;
					 shortcutMenu->Visible = false;

					 if (colourLegend->Visible == false && isDisplayMaxValid()) {
						 displayColourLegend();
						 colourLegend->Visible = true;
					 }
					 else {
						 colourLegend->Visible = false;
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
				 } else if (input->Length > 2) {
					 String^ searchString = removeNewLineCharacter(input);

					 if (isQuickSearchActivated(searchString)) {

						 displayOutput();
						 searchString = retrieveSearchItem(searchString);

						 quickSearch(searchString);

					 } 
				 } else {
					 displayOutput();
				 }
		 }

		 std:: string systemToStdConverter(String^ system) {
				 if (system->Length > 0) {
					 return msclr::interop::marshal_as< std::string >(system);
				 }
			 }

			 String^ stdToSystemConverter(std:: string string) {
				 if (string.length() > 0) {
					 return gcnew String(string.c_str());
				 }
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

			  void displayOutput() {
					 displayFeedback();
					 displayToday();
					 displayUpcoming();
					 displayFloating();
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
				 } else if (totalFeedback == 1) {
					 iter = feedbackList.begin();
					 feedback = stdToSystemConverter(*iter);
				 }

				 if (isDisplayMaxValid()) {
					 feedbackTextBox->Text = feedback;
				 } else {
					 feedbackTextBoxMin->Text = feedback;
				 }
			 }

			  // this function will take in the taskList of type TASK
			 // and converts it to std::string to display accordingly, depends if it is a timed, deadline or misc task
			 // uses time_facet to display the start time and end time accordingly
			 std:: vector<std:: string> TASKtoStringTaskListConverter(std:: vector<TASK> taskList){
				 std:: vector<std:: string> taskListString;

				 storage->updateTaskID(taskList);
				 std:: vector<TASK>::iterator iter;
				 for(iter = taskList.begin(); iter != taskList.end(); iter++) {
					 assert(iter->taskDescriptionList != "");
					 std:: stringstream ss;
					 ss << iter->taskID;

					 boost::posix_time::time_facet* faced = new boost::posix_time::time_facet("%A, %Y-%b-%d");
					 boost::posix_time::time_facet* facet = new boost::posix_time::time_facet("%A, %Y-%b-%d %H:%M");
					 boost::posix_time::time_facet* facetEnd = new boost::posix_time::time_facet("%H:%M");

					// either floating or dateline
					 if((iter->endTime).is_not_a_date_time()) {
						 // this is a floating
						 if((iter->startDateTime).is_not_a_date_time()) {
							 ss << ". " << iter->taskDescriptionList;
						 } else if((iter->startTime) == time_duration(hours(23) + minutes(59))) { // this is a all day task
							 ss.imbue(std:: locale(std:: locale::classic(), faced));
							 ss << ". [" << iter->startDateTime << "] " << iter->taskDescriptionList; 
						 } else { // this is a dateline task
							 ss.imbue(std:: locale(std:: locale::classic(), facet));
							 ss << ". [" << iter->startDateTime << "] " << iter->taskDescriptionList; 
						 }
					 } else if(iter->startDateTime.date() != iter->endDateTime.date()) { // this is a time task with diff startDate and endDate

						 ss.imbue(std:: locale(std:: locale::classic(), facet));
						 ss << ". [" << iter->startDateTime << "-";
						 ss.imbue(std:: locale(std:: locale::classic(), facet));
						 ss << iter->endDateTime << "] " << iter->taskDescriptionList;

					 } else if(iter->startDateTime.date() == iter->endDateTime.date()) { // this is a time task with the same startDate and endDate

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
				 std:: vector<std:: string> todayList = TASKtoStringTaskListConverter(todayTaskList);

				 String^ displayToday = "";

				 todayRichTextBox->Clear();
				 todayRichTextBoxMin->Clear();


				 int totalTodayTaskList = todayList.size();
				 if (totalTodayTaskList > 0 ) {
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
			 }

			 // in displayUpcoming, done will always take the top precedence, followed by clash and then new
			 // for example, if task A is both done and clash, it will appear as done
			 // for example, if task B is both clash and new, it will appear as clash
			 void displayUpcoming() {

				 std:: vector<TASK> upcomingTaskList = storage->retrieveUpcomingTaskList();
				 std:: vector<std:: string> upcomingList = TASKtoStringTaskListConverter(upcomingTaskList);
				 int totalUpcomingTaskList = upcomingTaskList.size();
				 String^ displayUpcoming = "";

				 upcomingRichTextBox->Clear();
				 upcomingRichTextBoxMin->Clear();

				 if (totalUpcomingTaskList > 0) {
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
			 }

			 // in displayFloating, done will always take the top precedence, followed by new
			 // done and new are mutually exclusive so it won't happen together
				 void displayFloating() {
					 std:: vector<TASK> floatingTaskList = storage->retrieveFloatingTaskList();
					 std:: vector<std:: string> floatingList = TASKtoStringTaskListConverter(floatingTaskList);
					 int totalfloatingTaskList = floatingTaskList.size();
					 String^ displayFloating = "";

					 floatingRichTextBox->Clear();
					 floatingRichTextBoxMin->Clear();

					 if (totalfloatingTaskList > 0) {
					 if (isDisplayMaxValid()) {
						 for (int i=0; i<totalfloatingTaskList; i++) {
							 displayFloating = stdToSystemConverter(floatingList[i]);

							 if ( isTaskDone(floatingTaskList, i)) {

								 floatingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
								 floatingRichTextBox->SelectionColor = Color::CornflowerBlue;
								 floatingRichTextBox->SelectedText = displayFloating + "\r\n";

							 } else	if ( isTaskNew(floatingTaskList, i)) {

								 floatingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
								 floatingRichTextBox->SelectionColor = Color::DeepSkyBlue;
								 floatingRichTextBox->SelectedText = displayFloating + "\r\n";

							 } else {

								 floatingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular );
								 floatingRichTextBox->SelectionColor = Color::Black;
								 floatingRichTextBox->SelectedText = displayFloating + "\r\n";

							 }
						 }
					 } else {
						 for (int i=0; i<totalfloatingTaskList; i++) {
							 displayFloating = stdToSystemConverter(floatingList[i]);

							 if ( isTaskDone(floatingTaskList, i)) {

								 floatingRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
								 floatingRichTextBoxMin->SelectionColor = Color::CornflowerBlue;
								 floatingRichTextBoxMin->SelectedText = displayFloating + "\r\n";

							 } else	if ( isTaskNew(floatingTaskList, i)) {

								 floatingRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
								 floatingRichTextBoxMin->SelectionColor = Color::DeepSkyBlue;
								 floatingRichTextBoxMin->SelectedText = displayFloating + "\r\n";

							 } else {

								 floatingRichTextBoxMin->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular );
								 floatingRichTextBoxMin->SelectionColor = Color::Black;
								 floatingRichTextBoxMin->SelectedText = displayFloating + "\r\n";

							 }
						 }
					 }
					 }
				 }

				 bool isTaskDone(std:: vector<TASK> taskList, int i) {
					 assert(taskList[i].taskDescriptionList != "");
					 if (taskList[i].done == true) {
					 return true;
				 }
				 else {
					 return false;
				 }
			 }


			 bool isTaskOverdue(std:: vector<TASK> taskList, int i) {
				 assert(taskList[i].taskDescriptionList != "");
				 if (taskList[i].overdue == true) {
					 return true;
				 }
				 else {
					 return false;
				 }
			 }

			 bool isTaskClash(std:: vector<TASK> taskList, int i) {
				 assert(taskList[i].taskDescriptionList != "");
				 if (taskList[i].clash == true) {
					 return true;
				 }
				 else {
					 return false;
				 }
			 }

			 bool isTaskNew(std:: vector<TASK> taskList, int i) {
				 assert(taskList[i].taskDescriptionList != "");
				 if (taskList[i].newTask == true) {
					 return true;
				 }
				 else {
					 return false;
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
				 assert(searchString != "");
				 std:: string search = systemToStdConverter(searchString);
				 search = search.substr(2);
				 return stdToSystemConverter(search);
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

					 int indexFloating=0;
					 while (indexFloating<floatingRichTextBox->Text->LastIndexOf(searchString)) {
						 floatingRichTextBox->Find(searchString,indexFloating,floatingRichTextBox->TextLength, System::Windows::Forms::RichTextBoxFinds::None);
						 floatingRichTextBox->SelectionBackColor = Color::Yellow;
						 indexFloating = floatingRichTextBox->Text->IndexOf(searchString, indexFloating) + 1;
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

					 int indexFloating=0;
					 while (indexFloating<floatingRichTextBoxMin->Text->LastIndexOf(searchString)) {
						 floatingRichTextBoxMin->Find(searchString,indexFloating,floatingRichTextBoxMin->TextLength, System::Windows::Forms::RichTextBoxFinds::None);
						 floatingRichTextBoxMin->SelectionBackColor = Color::Yellow;
						 indexFloating = floatingRichTextBoxMin->Text->IndexOf(searchString, indexFloating) + 1;
					 }
				 }
			 }

		 void displayUserGuide() {
				 userGuide->Clear();

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Candara", 10, System::Drawing::FontStyle::Bold);
				 userGuide->SelectionAlignment = HorizontalAlignment::Center;
				 userGuide->SelectionColor = Color::LightSlateGray;
				 userGuide->AppendText("HELP FOR NEW USERS" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 userGuide->SelectionAlignment = HorizontalAlignment::Left;
				 userGuide->AppendText("add ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 userGuide->AppendText("<taskDesc> ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 userGuide->AppendText("on/by/from ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 userGuide->AppendText("<date> <startTime> ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 userGuide->AppendText("to ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 userGuide->AppendText("<endTime>" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-add meet ivy on 30 mar 14:00" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-add swimming training from 1 apr 4 to 6pm" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-add buy Amy's 21st gift" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 userGuide->AppendText("delete ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 userGuide->AppendText("<taskType> <taskID>" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-delete floating 1" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 userGuide->AppendText("update ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 userGuide->AppendText("<taskType> <taskID> <add format> " + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-update upcoming 2 meet ivy for dinner from 14 mar 14:00 to 16:00" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 userGuide->AppendText("done ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 userGuide->AppendText("<taskType> <taskID> " + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-done today 3" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Bold);
				 userGuide->AppendText("clear ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Regular);
				 userGuide->AppendText("<taskType> " + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-clear all" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 userGuide->AppendText("undo" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 userGuide->AppendText("filter ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 userGuide->AppendText("<taskDate>/<taskTime>" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-filter 14 May" + "\r\n");

				  userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-filter 18:00" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 userGuide->AppendText("search ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 userGuide->AppendText("<taskDesc>" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-search meet ivy" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 userGuide->AppendText("display" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
				 userGuide->AppendText("save ");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 userGuide->AppendText("<fileDirectory> <fileName>" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-save C:\\Users\\Ivy\\Desktop\\ EasyToDo.txt" + "\r\n");

				 userGuide->SelectionFont = gcnew System::Drawing::Font( "Arial", 8, System::Drawing::FontStyle::Italic);
				 userGuide->AppendText("-save (default settings)");
			 }
		 void displayShortcutMenu() {
			 shortcutMenu->Clear();

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Candara", 10, System::Drawing::FontStyle::Bold);
			 shortcutMenu->SelectionAlignment = HorizontalAlignment::Center;
			 shortcutMenu->SelectionColor = Color::LightSlateGray;
			 shortcutMenu->AppendText("SHORTCUT" + "\r\n");

			  shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->SelectionAlignment = HorizontalAlignment::Left;
			 shortcutMenu->SelectionColor = Color::Black;
			 shortcutMenu->AppendText("- a");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" for add" + "\r\n");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("- del");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" for delete" + "\r\n");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("- d");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" for done" + "\r\n");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("- up");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" for update" + "\r\n");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("- clr");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText("for clear" + "\r\n");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("- src");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" for search" + "\r\n");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("- fil");


			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" for filter" + "\r\n");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("- dis");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" for display" + "\r\n");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText("- Press ");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("up and down");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" the retreieve the last/recent input" + "\r\n");

			  shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText("- Press ");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("Ctrl+M");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" to toggle between the two screens" + "\r\n");

			  shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText("- Press ");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("\"s \"");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" followed by the search item to quicksearch" + "\r\n");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText("- Press ");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("Ctrl+Z");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" to undo" + "\r\n");

			  shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText("- Press ");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Bold);
			 shortcutMenu->AppendText("Esc");

			 shortcutMenu->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
			 shortcutMenu->AppendText(" to exit");

		 }

		 void displayColourLegend(){
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

			 }
};
}
