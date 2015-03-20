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
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Timer^  timer1;

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
			this->components = (gcnew System::ComponentModel::Container());
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// commandLineTextBox
			// 
			this->commandLineTextBox->BackColor = System::Drawing::Color::MistyRose;
			this->commandLineTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.900001F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->commandLineTextBox->Location = System::Drawing::Point(57, 211);
			this->commandLineTextBox->Multiline = true;
			this->commandLineTextBox->Name = L"commandLineTextBox";
			this->commandLineTextBox->Size = System::Drawing::Size(1004, 43);
			this->commandLineTextBox->TabIndex = 0;
			this->commandLineTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &architectureGUI::inputTextBox_KeyPress);
			// 
			// feedbackTextBox
			// 
			this->feedbackTextBox->BackColor = System::Drawing::Color::Azure;
			this->feedbackTextBox->Location = System::Drawing::Point(1090, 409);
			this->feedbackTextBox->Multiline = true;
			this->feedbackTextBox->Name = L"feedbackTextBox";
			this->feedbackTextBox->Size = System::Drawing::Size(533, 834);
			this->feedbackTextBox->TabIndex = 1;
			// 
			// displayTodayTextBox
			// 
			this->displayTodayTextBox->BackColor = System::Drawing::Color::LemonChiffon;
			this->displayTodayTextBox->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->displayTodayTextBox->Location = System::Drawing::Point(57, 328);
			this->displayTodayTextBox->Multiline = true;
			this->displayTodayTextBox->Name = L"displayTodayTextBox";
			this->displayTodayTextBox->Size = System::Drawing::Size(488, 533);
			this->displayTodayTextBox->TabIndex = 2;
			// 
			// logoPictureBox
			// 
			this->logoPictureBox->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"logoPictureBox.Image")));
			this->logoPictureBox->Location = System::Drawing::Point(1129, 30);
			this->logoPictureBox->Name = L"logoPictureBox";
			this->logoPictureBox->Size = System::Drawing::Size(517, 215);
			this->logoPictureBox->TabIndex = 3;
			this->logoPictureBox->TabStop = false;
			// 
			// displayUpcomingTextBox
			// 
			this->displayUpcomingTextBox->BackColor = System::Drawing::Color::LemonChiffon;
			this->displayUpcomingTextBox->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->displayUpcomingTextBox->Location = System::Drawing::Point(571, 328);
			this->displayUpcomingTextBox->Multiline = true;
			this->displayUpcomingTextBox->Name = L"displayUpcomingTextBox";
			this->displayUpcomingTextBox->Size = System::Drawing::Size(490, 533);
			this->displayUpcomingTextBox->TabIndex = 4;
			// 
			// todayLabel
			// 
			this->todayLabel->AutoSize = true;
			this->todayLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->todayLabel->Location = System::Drawing::Point(56, 282);
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
			this->upcomingLabel->Location = System::Drawing::Point(564, 283);
			this->upcomingLabel->Name = L"upcomingLabel";
			this->upcomingLabel->Size = System::Drawing::Size(227, 42);
			this->upcomingLabel->TabIndex = 6;
			this->upcomingLabel->Text = L"UPCOMING";
			// 
			// displayMiscellaneousTextBox
			// 
			this->displayMiscellaneousTextBox->BackColor = System::Drawing::Color::Honeydew;
			this->displayMiscellaneousTextBox->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->displayMiscellaneousTextBox->Location = System::Drawing::Point(63, 939);
			this->displayMiscellaneousTextBox->Multiline = true;
			this->displayMiscellaneousTextBox->Name = L"displayMiscellaneousTextBox";
			this->displayMiscellaneousTextBox->Size = System::Drawing::Size(998, 304);
			this->displayMiscellaneousTextBox->TabIndex = 7;
			// 
			// miscellaneousLabel
			// 
			this->miscellaneousLabel->AutoSize = true;
			this->miscellaneousLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->miscellaneousLabel->Location = System::Drawing::Point(387, 891);
			this->miscellaneousLabel->Name = L"miscellaneousLabel";
			this->miscellaneousLabel->Size = System::Drawing::Size(330, 42);
			this->miscellaneousLabel->TabIndex = 8;
			this->miscellaneousLabel->Text = L"MISCELLANEOUS";
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(57, 169);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(346, 39);
			this->textBox1->TabIndex = 9;
			this->textBox1->Text = L"Enter Command:";
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(1090, 364);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(230, 39);
			this->textBox2->TabIndex = 10;
			this->textBox2->Text = L"Feedback";
			// 
			// architectureGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1961, 1279);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->miscellaneousLabel);
			this->Controls->Add(this->displayMiscellaneousTextBox);
			this->Controls->Add(this->upcomingLabel);
			this->Controls->Add(this->todayLabel);
			this->Controls->Add(this->displayUpcomingTextBox);
			this->Controls->Add(this->logoPictureBox);
			this->Controls->Add(this->displayTodayTextBox);
			this->Controls->Add(this->feedbackTextBox);
			this->Controls->Add(this->commandLineTextBox);
			this->Name = L"architectureGUI";
			this->Padding = System::Windows::Forms::Padding(50, 0, 50, 20);
			this->Text = L"architectureGUI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void inputTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 String^ input;
				 
				 input = commandLineTextBox->Text;
				 if (e->KeyChar == (char)13) {
					 std::string content = msclr::interop::marshal_as< std::string >(input);
					 commandLineTextBox->Text = "";
					 std:: string feedback = logic->determineCommand(content);
					 
					 String^ output = gcnew String(feedback.c_str());
					 feedbackTextBox->Text = output;

					 std:: vector<std:: string> taskList = storage->retrieveMasterTaskList();
					 int totalTaskList = taskList.size();
					 String^ display = "";
					 String^ displaySystem ;
					 std:: string displayString;
					
					 for (int i=0; i<totalTaskList; i++) {
						 displaySystem = gcnew String(taskList[i].c_str());
						 display = display + displaySystem;

						 if (i != totalTaskList) {
							 display = display + "\r\n";
						 }
					}
					 
					 displayTodayTextBox->Text = display;
				 }			 
			
			 }
	
};
}