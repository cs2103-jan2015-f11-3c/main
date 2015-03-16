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
		architectureLogic* head;
		architectureStorage* tail;

	public:
		architectureGUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			head = new architectureLogic();
			tail = new architectureStorage();
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
				delete head;
				delete tail;
			}
		}
	private: System::Windows::Forms::TextBox^  inputTextBox;
	protected: 
	private: System::Windows::Forms::TextBox^  outputTextBox;
	private: System::Windows::Forms::TextBox^  displayTextBox;
	private: System::Windows::Forms::PictureBox^  pictureBox1;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(architectureGUI::typeid));
			this->inputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->outputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->displayTextBox = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// inputTextBox
			// 
			this->inputTextBox->BackColor = System::Drawing::Color::LavenderBlush;
			this->inputTextBox->Location = System::Drawing::Point(47, 98);
			this->inputTextBox->Name = L"inputTextBox";
			this->inputTextBox->Size = System::Drawing::Size(905, 38);
			this->inputTextBox->TabIndex = 0;
			this->inputTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &architectureGUI::inputTextBox_KeyPress);
			// 
			// outputTextBox
			// 
			this->outputTextBox->BackColor = System::Drawing::Color::Gainsboro;
			this->outputTextBox->Location = System::Drawing::Point(47, 176);
			this->outputTextBox->Multiline = true;
			this->outputTextBox->Name = L"outputTextBox";
			this->outputTextBox->Size = System::Drawing::Size(905, 860);
			this->outputTextBox->TabIndex = 1;
			// 
			// displayTextBox
			// 
			this->displayTextBox->BackColor = System::Drawing::Color::Gainsboro;
			this->displayTextBox->Location = System::Drawing::Point(1012, 281);
			this->displayTextBox->Multiline = true;
			this->displayTextBox->Name = L"displayTextBox";
			this->displayTextBox->Size = System::Drawing::Size(606, 755);
			this->displayTextBox->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1080, 51);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(517, 215);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// architectureGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1663, 1279);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->displayTextBox);
			this->Controls->Add(this->outputTextBox);
			this->Controls->Add(this->inputTextBox);
			this->Name = L"architectureGUI";
			this->Padding = System::Windows::Forms::Padding(50, 0, 50, 20);
			this->Text = L"architectureGUI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void inputTextBox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
				 String^ input;
						 
				 input = inputTextBox->Text;
				 if (e->KeyChar == (char)13) {
					 std::string content = msclr::interop::marshal_as< std::string >(input);
					 inputTextBox->Text = "";
					 std:: string num = head->determineCommand(content);
					 
					 String^ output = gcnew String(num.c_str());
					
					 outputTextBox->Text = input;
					 
					 std:: vector<std:: string> taskList = tail->retrieveVector();
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
					 
					 displayTextBox->Text = display;
					 input = input->Remove(0);
				 }
			
			 }
	};
}