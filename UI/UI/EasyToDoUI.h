#pragma once

namespace UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EasyToDoUI
	/// </summary>
	public ref class EasyToDoUI : public System::Windows::Forms::Form
	{
	public:
		EasyToDoUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EasyToDoUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  outputBox;
	protected: 

	protected: 

	private: System::Windows::Forms::Label^  welcomeMessage;
	private: System::Windows::Forms::Button^  generateOutput;


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
			this->outputBox = (gcnew System::Windows::Forms::TextBox());
			this->welcomeMessage = (gcnew System::Windows::Forms::Label());
			this->generateOutput = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// outputBox
			// 
			this->outputBox->Location = System::Drawing::Point(58, 147);
			this->outputBox->Multiline = true;
			this->outputBox->Name = L"outputBox";
			this->outputBox->ReadOnly = true;
			this->outputBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outputBox->Size = System::Drawing::Size(501, 397);
			this->outputBox->TabIndex = 0;
			// 
			// welcomeMessage
			// 
			this->welcomeMessage->AutoSize = true;
			this->welcomeMessage->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->welcomeMessage->Location = System::Drawing::Point(49, 95);
			this->welcomeMessage->Name = L"welcomeMessage";
			this->welcomeMessage->Size = System::Drawing::Size(359, 49);
			this->welcomeMessage->TabIndex = 1;
			this->welcomeMessage->Text = L"Welcome to EasyToDo!";
			// 
			// generateOutput
			// 
			this->generateOutput->Font = (gcnew System::Drawing::Font(L"Harrington", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->generateOutput->Location = System::Drawing::Point(580, 498);
			this->generateOutput->Name = L"generateOutput";
			this->generateOutput->Size = System::Drawing::Size(158, 45);
			this->generateOutput->TabIndex = 2;
			this->generateOutput->Text = L"Enter";
			this->generateOutput->UseVisualStyleBackColor = true;
			this->generateOutput->Click += gcnew System::EventHandler(this, &EasyToDoUI::generateOutput_Click);
			// 
			// EasyToDoUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(972, 697);
			this->Controls->Add(this->generateOutput);
			this->Controls->Add(this->welcomeMessage);
			this->Controls->Add(this->outputBox);
			this->Name = L"EasyToDoUI";
			this->Text = L"EasyToDoUI";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void generateOutput_Click(System::Object^  sender, System::EventArgs^  e) {
			MessageBox::Show("Hello World!");
			 }
	};
}
