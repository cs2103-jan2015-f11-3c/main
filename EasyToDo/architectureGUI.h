#pragma once
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>
#include "architectureLogic.h"
#include "architectureStorage.h"

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
		architectureLogic* logic;
	private: System::Windows::Forms::TextBox^  displayUpcomingTextBox;

	private: System::Windows::Forms::Label^  todayLabel;
	private: System::Windows::Forms::Label^  upcomingLabel;
	private: System::Windows::Forms::TextBox^  displayMiscellaneousTextBox;



	private: System::Windows::Forms::Label^  miscellaneousLabel;
	private: System::Windows::Forms::TextBox^  commandLabel;
	private: System::Windows::Forms::TextBox^  feedbackLabel;
	private: System::Windows::Forms::MonthCalendar^  monthCalendar;
	private: System::Windows::Forms::RichTextBox^  todayRichTextBox;
	private: System::Windows::Forms::RichTextBox^  upcomingRichTextBox;
	private: System::Windows::Forms::RichTextBox^  miscellaneousRichTextBox;








			 architectureStorage* storage;

	public:
		architectureGUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			logic = new architectureLogic();
			storage = new architectureStorage();
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
				delete logic;
				delete storage;
			}
		}
	private: System::Windows::Forms::TextBox^  commandLineTextBox;
	private: System::Windows::Forms::TextBox^  feedbackTextBox;
	private: System::Windows::Forms::TextBox^  displayTodayTextBox;
	protected: 

	protected: 


	protected: 


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
			this->displayTodayTextBox = (gcnew System::Windows::Forms::TextBox());
			this->logoPictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->displayUpcomingTextBox = (gcnew System::Windows::Forms::TextBox());
			this->todayLabel = (gcnew System::Windows::Forms::Label());
			this->upcomingLabel = (gcnew System::Windows::Forms::Label());
			this->displayMiscellaneousTextBox = (gcnew System::Windows::Forms::TextBox());
			this->miscellaneousLabel = (gcnew System::Windows::Forms::Label());
			this->commandLabel = (gcnew System::Windows::Forms::TextBox());
			this->feedbackLabel = (gcnew System::Windows::Forms::TextBox());
			this->monthCalendar = (gcnew System::Windows::Forms::MonthCalendar());
			this->todayRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->upcomingRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->miscellaneousRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// commandLineTextBox
			// 
			this->commandLineTextBox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->commandLineTextBox->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.900001F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->commandLineTextBox->Location = System::Drawing::Point(728, 99);
			this->commandLineTextBox->Multiline = true;
			this->commandLineTextBox->Name = L"commandLineTextBox";
			this->commandLineTextBox->Size = System::Drawing::Size(1099, 52);
			this->commandLineTextBox->TabIndex = 0;
			this->commandLineTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &architectureGUI::inputTextBox_KeyPress);
			// 
			// feedbackTextBox
			// 
			this->feedbackTextBox->BackColor = System::Drawing::Color::AliceBlue;
			this->feedbackTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->feedbackTextBox->Location = System::Drawing::Point(728, 211);
			this->feedbackTextBox->Multiline = true;
			this->feedbackTextBox->Name = L"feedbackTextBox";
			this->feedbackTextBox->ReadOnly = true;
			this->feedbackTextBox->Size = System::Drawing::Size(1099, 264);
			this->feedbackTextBox->TabIndex = 1;
			// 
			// displayTodayTextBox
			// 
			this->displayTodayTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->displayTodayTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->displayTodayTextBox->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->displayTodayTextBox->Location = System::Drawing::Point(59, 515);
			this->displayTodayTextBox->Multiline = true;
			this->displayTodayTextBox->Name = L"displayTodayTextBox";
			this->displayTodayTextBox->ReadOnly = true;
			this->displayTodayTextBox->Size = System::Drawing::Size(721, 687);
			this->displayTodayTextBox->TabIndex = 2;
			// 
			// logoPictureBox
			// 
			this->logoPictureBox->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"logoPictureBox.Image")));
			this->logoPictureBox->Location = System::Drawing::Point(1874, 180);
			this->logoPictureBox->Name = L"logoPictureBox";
			this->logoPictureBox->Size = System::Drawing::Size(517, 215);
			this->logoPictureBox->TabIndex = 3;
			this->logoPictureBox->TabStop = false;
			// 
			// displayUpcomingTextBox
			// 
			this->displayUpcomingTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->displayUpcomingTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->displayUpcomingTextBox->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->displayUpcomingTextBox->Location = System::Drawing::Point(821, 515);
			this->displayUpcomingTextBox->Multiline = true;
			this->displayUpcomingTextBox->Name = L"displayUpcomingTextBox";
			this->displayUpcomingTextBox->ReadOnly = true;
			this->displayUpcomingTextBox->Size = System::Drawing::Size(763, 687);
			this->displayUpcomingTextBox->TabIndex = 4;
			// 
			// todayLabel
			// 
			this->todayLabel->AutoSize = true;
			this->todayLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->todayLabel->Location = System::Drawing::Point(32, 500);
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
			this->upcomingLabel->Location = System::Drawing::Point(793, 500);
			this->upcomingLabel->Name = L"upcomingLabel";
			this->upcomingLabel->Size = System::Drawing::Size(227, 42);
			this->upcomingLabel->TabIndex = 6;
			this->upcomingLabel->Text = L"UPCOMING";
			// 
			// displayMiscellaneousTextBox
			// 
			this->displayMiscellaneousTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->displayMiscellaneousTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->displayMiscellaneousTextBox->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->displayMiscellaneousTextBox->Location = System::Drawing::Point(1621, 515);
			this->displayMiscellaneousTextBox->Multiline = true;
			this->displayMiscellaneousTextBox->Name = L"displayMiscellaneousTextBox";
			this->displayMiscellaneousTextBox->ReadOnly = true;
			this->displayMiscellaneousTextBox->Size = System::Drawing::Size(712, 687);
			this->displayMiscellaneousTextBox->TabIndex = 7;
			// 
			// miscellaneousLabel
			// 
			this->miscellaneousLabel->AutoSize = true;
			this->miscellaneousLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->miscellaneousLabel->Location = System::Drawing::Point(1602, 500);
			this->miscellaneousLabel->Name = L"miscellaneousLabel";
			this->miscellaneousLabel->Size = System::Drawing::Size(330, 42);
			this->miscellaneousLabel->TabIndex = 8;
			this->miscellaneousLabel->Text = L"MISCELLANEOUS";
			// 
			// commandLabel
			// 
			this->commandLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->commandLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->commandLabel->Location = System::Drawing::Point(728, 54);
			this->commandLabel->Name = L"commandLabel";
			this->commandLabel->Size = System::Drawing::Size(267, 39);
			this->commandLabel->TabIndex = 9;
			this->commandLabel->Text = L"Enter Command:";
			// 
			// feedbackLabel
			// 
			this->feedbackLabel->BackColor = System::Drawing::SystemColors::Window;
			this->feedbackLabel->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->feedbackLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->feedbackLabel->Location = System::Drawing::Point(728, 171);
			this->feedbackLabel->Name = L"feedbackLabel";
			this->feedbackLabel->Size = System::Drawing::Size(159, 39);
			this->feedbackLabel->TabIndex = 10;
			this->feedbackLabel->Text = L"Feedback";
			// 
			// monthCalendar
			// 
			this->monthCalendar->Location = System::Drawing::Point(59, 65);
			this->monthCalendar->Name = L"monthCalendar";
			this->monthCalendar->ShowToday = false;
			this->monthCalendar->TabIndex = 11;
			this->monthCalendar->TabStop = false;
			// 
			// todayRichTextBox
			// 
			this->todayRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->todayRichTextBox->Location = System::Drawing::Point(72, 545);
			this->todayRichTextBox->Name = L"todayRichTextBox";
			this->todayRichTextBox->Size = System::Drawing::Size(698, 642);
			this->todayRichTextBox->TabIndex = 12;
			this->todayRichTextBox->Text = L"";
			// 
			// upcomingRichTextBox
			// 
			this->upcomingRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->upcomingRichTextBox->Location = System::Drawing::Point(832, 545);
			this->upcomingRichTextBox->Name = L"upcomingRichTextBox";
			this->upcomingRichTextBox->Size = System::Drawing::Size(736, 642);
			this->upcomingRichTextBox->TabIndex = 13;
			this->upcomingRichTextBox->Text = L"";
			// 
			// miscellaneousRichTextBox
			// 
			this->miscellaneousRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->miscellaneousRichTextBox->Location = System::Drawing::Point(1630, 545);
			this->miscellaneousRichTextBox->Name = L"miscellaneousRichTextBox";
			this->miscellaneousRichTextBox->Size = System::Drawing::Size(666, 642);
			this->miscellaneousRichTextBox->TabIndex = 14;
			this->miscellaneousRichTextBox->Text = L"";
			// 
			// architectureGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(2961, 1562);
			this->Controls->Add(this->miscellaneousRichTextBox);
			this->Controls->Add(this->upcomingRichTextBox);
			this->Controls->Add(this->todayRichTextBox);
			this->Controls->Add(this->monthCalendar);
			this->Controls->Add(this->feedbackLabel);
			this->Controls->Add(this->commandLabel);
			this->Controls->Add(this->miscellaneousLabel);
			this->Controls->Add(this->displayMiscellaneousTextBox);
			this->Controls->Add(this->upcomingLabel);
			this->Controls->Add(this->todayLabel);
			this->Controls->Add(this->displayUpcomingTextBox);
			this->Controls->Add(this->logoPictureBox);
			this->Controls->Add(this->displayTodayTextBox);
			this->Controls->Add(this->feedbackTextBox);
			this->Controls->Add(this->commandLineTextBox);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"architectureGUI";
			this->Padding = System::Windows::Forms::Padding(30);
			this->Text = L"architectureGUI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void inputTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 String^ input;

				 input = commandLineTextBox->Text;
				 if (e->KeyChar == (char)13 && input !="") {
					 std::string content = msclr::interop::marshal_as< std::string >(input);
					 commandLineTextBox->Text = "";
					 std:: vector<std:: string> feedbackList = logic->determineCommand(content);
					 String^ feedbackSystem;
					 String^ feedback = "";

					 int totalFeedback = feedbackList.size();

					 for (int i=totalFeedback; i>0; i--) {
						 feedbackSystem = gcnew String(feedbackList[i-1].c_str());
						 feedback = feedback + feedbackSystem;

						 if (i != 0) {
							 feedback = feedback + "\r\n";
						 }
					 }
					 feedbackTextBox->Text = feedback;

					 //TO STRIKE OUT
					 /* if (totalTodayTaskList == 2) {
					 displayTodayTextBox->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Strikeout, 
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
					 }
					 else {
					 displayTodayTextBox->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(0)));
					 }*/

					 // displayTodayTextBox->Text = "\r\n" + displayToday;

					 // richTextBox->Text = displayToday;

					 displayToday();
					 displayUpcoming();
					 displayMiscellaneous();
				 }			 

			 }
			 void displayToday() {
				 std:: vector<std:: string> todayTaskList = storage->retrieveTodayTaskList();
				 int totalTodayTaskList = todayTaskList.size();
				 String^ displayToday = "";
				 
				 todayRichTextBox->Clear();
				 for (int i=0; i<totalTodayTaskList; i++) {
					 displayToday = gcnew String(todayTaskList[i].c_str());

					 //bool variable for it to be considered done
					 if ( i==1) {
						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
						 todayRichTextBox->SelectionColor = Color::PowderBlue;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";
					 }
					 else {
						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Arial",10, System::Drawing::FontStyle::Italic );
						 todayRichTextBox->SelectionColor = Color::Black;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";

					 }
				 }
			 }
			 void displayUpcoming() {
				 std:: vector<std:: string> upcomingTaskList = storage->retrieveUpcomingTaskList();
				 int totalUpcomingTaskList = upcomingTaskList.size();
				 String^ displayUpcoming = "";
				
				 upcomingRichTextBox->Clear();
				 for (int i=0; i<totalUpcomingTaskList; i++) {
					 displayUpcoming = gcnew String(upcomingTaskList[i].c_str());
					 //bool variable for it to be considered done
					 if ( i==1) {
						 upcomingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
						 upcomingRichTextBox->SelectionColor = Color::PowderBlue;
						 upcomingRichTextBox->SelectedText = displayUpcoming + "\r\n";
					 }
					 else {
						 upcomingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Arial",10, System::Drawing::FontStyle::Italic );
						 upcomingRichTextBox->SelectionColor = Color::Black;
						 upcomingRichTextBox->SelectedText = displayUpcoming + "\r\n";
					 }
				 }
			 }

			 void displayMiscellaneous() {
				 std:: vector<std:: string> miscellaneousTaskList = storage->retrieveFloatingTaskList();
				 int totalMiscellaneousTaskList = miscellaneousTaskList.size();
				 String^ displayMiscellaneous = "";

				 miscellaneousRichTextBox->Clear();
				 for (int i=0; i<totalMiscellaneousTaskList; i++) {
					 displayMiscellaneous = gcnew String(miscellaneousTaskList[i].c_str());
					 //bool variable for it to be considered done
					 if ( i==1) {
						 miscellaneousRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
						 miscellaneousRichTextBox->SelectionColor = Color::PowderBlue;
						 miscellaneousRichTextBox->SelectedText = displayMiscellaneous + "\r\n";
					 }
					 else {
						 miscellaneousRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Arial",10, System::Drawing::FontStyle::Italic );
						 miscellaneousRichTextBox->SelectionColor = Color::Black;
						 miscellaneousRichTextBox->SelectedText = displayMiscellaneous + "\r\n";
					 }
				 }

			 }


	};
}