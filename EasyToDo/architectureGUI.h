#pragma once
#include <string>
#include <vector>
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
		Parser* parser;
		architectureLogic* logic;
		 architectureStorage* storage;
		 architectureInputFeedback* inputFeedback;
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
	private: System::Windows::Forms::RichTextBox^  colourLegend;

	private: System::Windows::Forms::RichTextBox^  displayHelp;

			
	public:
		architectureGUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			parser = new Parser();
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
			this->displayHelp = (gcnew System::Windows::Forms::RichTextBox());
			this->colourLegend = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logoPictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// commandLineTextBox
			// 
			this->commandLineTextBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Append;
			this->commandLineTextBox->BackColor = System::Drawing::Color::WhiteSmoke;
			this->commandLineTextBox->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.900001F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->commandLineTextBox->Location = System::Drawing::Point(741, 120);
			this->commandLineTextBox->Multiline = true;
			this->commandLineTextBox->Name = L"commandLineTextBox";
			this->commandLineTextBox->Size = System::Drawing::Size(1099, 51);
			this->commandLineTextBox->TabIndex = 0;
			this->commandLineTextBox->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &architectureGUI::commandLineTextBox_KeyUp);
			// 
			// feedbackTextBox
			// 
			this->feedbackTextBox->BackColor = System::Drawing::Color::AliceBlue;
			this->feedbackTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->feedbackTextBox->Location = System::Drawing::Point(741, 230);
			this->feedbackTextBox->Multiline = true;
			this->feedbackTextBox->Name = L"feedbackTextBox";
			this->feedbackTextBox->ReadOnly = true;
			this->feedbackTextBox->Size = System::Drawing::Size(1099, 311);
			this->feedbackTextBox->TabIndex = 1;
			// 
			// displayTodayTextBox
			// 
			this->displayTodayTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->displayTodayTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->displayTodayTextBox->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->displayTodayTextBox->Location = System::Drawing::Point(48, 611);
			this->displayTodayTextBox->Multiline = true;
			this->displayTodayTextBox->Name = L"displayTodayTextBox";
			this->displayTodayTextBox->ReadOnly = true;
			this->displayTodayTextBox->Size = System::Drawing::Size(734, 731);
			this->displayTodayTextBox->TabIndex = 2;
			// 
			// logoPictureBox
			// 
			this->logoPictureBox->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"logoPictureBox.Image")));
			this->logoPictureBox->Location = System::Drawing::Point(1873, 190);
			this->logoPictureBox->Name = L"logoPictureBox";
			this->logoPictureBox->Size = System::Drawing::Size(508, 252);
			this->logoPictureBox->TabIndex = 3;
			this->logoPictureBox->TabStop = false;
			// 
			// displayUpcomingTextBox
			// 
			this->displayUpcomingTextBox->BackColor = System::Drawing::SystemColors::Window;
			this->displayUpcomingTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->displayUpcomingTextBox->Font = (gcnew System::Drawing::Font(L"Rockwell", 9.900001F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->displayUpcomingTextBox->Location = System::Drawing::Point(827, 611);
			this->displayUpcomingTextBox->Multiline = true;
			this->displayUpcomingTextBox->Name = L"displayUpcomingTextBox";
			this->displayUpcomingTextBox->ReadOnly = true;
			this->displayUpcomingTextBox->Size = System::Drawing::Size(783, 731);
			this->displayUpcomingTextBox->TabIndex = 4;
			// 
			// todayLabel
			// 
			this->todayLabel->AutoSize = true;
			this->todayLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->todayLabel->Location = System::Drawing::Point(21, 596);
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
			this->upcomingLabel->Location = System::Drawing::Point(799, 596);
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
			this->displayMiscellaneousTextBox->Location = System::Drawing::Point(1646, 611);
			this->displayMiscellaneousTextBox->Multiline = true;
			this->displayMiscellaneousTextBox->Name = L"displayMiscellaneousTextBox";
			this->displayMiscellaneousTextBox->ReadOnly = true;
			this->displayMiscellaneousTextBox->Size = System::Drawing::Size(743, 731);
			this->displayMiscellaneousTextBox->TabIndex = 7;
			// 
			// miscellaneousLabel
			// 
			this->miscellaneousLabel->AutoSize = true;
			this->miscellaneousLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 11.1F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->miscellaneousLabel->Location = System::Drawing::Point(1627, 596);
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
			this->commandLabel->Location = System::Drawing::Point(741, 73);
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
			this->feedbackLabel->Location = System::Drawing::Point(741, 190);
			this->feedbackLabel->Name = L"feedbackLabel";
			this->feedbackLabel->Size = System::Drawing::Size(159, 39);
			this->feedbackLabel->TabIndex = 10;
			this->feedbackLabel->Text = L"Feedback";
			// 
			// monthCalendar
			// 
			this->monthCalendar->Location = System::Drawing::Point(74, 104);
			this->monthCalendar->Name = L"monthCalendar";
			this->monthCalendar->ShowToday = false;
			this->monthCalendar->TabIndex = 11;
			this->monthCalendar->TabStop = false;
			this->monthCalendar->TitleBackColor = System::Drawing::Color::AliceBlue;
			// 
			// todayRichTextBox
			// 
			this->todayRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->todayRichTextBox->Location = System::Drawing::Point(61, 641);
			this->todayRichTextBox->Name = L"todayRichTextBox";
			this->todayRichTextBox->Size = System::Drawing::Size(711, 686);
			this->todayRichTextBox->TabIndex = 12;
			this->todayRichTextBox->Text = L"";
			// 
			// upcomingRichTextBox
			// 
			this->upcomingRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->upcomingRichTextBox->Location = System::Drawing::Point(838, 641);
			this->upcomingRichTextBox->Name = L"upcomingRichTextBox";
			this->upcomingRichTextBox->Size = System::Drawing::Size(756, 686);
			this->upcomingRichTextBox->TabIndex = 13;
			this->upcomingRichTextBox->Text = L"";
			// 
			// miscellaneousRichTextBox
			// 
			this->miscellaneousRichTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->miscellaneousRichTextBox->Location = System::Drawing::Point(1655, 641);
			this->miscellaneousRichTextBox->Name = L"miscellaneousRichTextBox";
			this->miscellaneousRichTextBox->Size = System::Drawing::Size(718, 686);
			this->miscellaneousRichTextBox->TabIndex = 14;
			this->miscellaneousRichTextBox->Text = L"";
			// 
			// displayHelp
			// 
			this->displayHelp->BackColor = System::Drawing::Color::White;
			this->displayHelp->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->displayHelp->Location = System::Drawing::Point(21, 42);
			this->displayHelp->Name = L"displayHelp";
			this->displayHelp->Size = System::Drawing::Size(709, 558);
			this->displayHelp->TabIndex = 15;
			this->displayHelp->Text = L"";
			this->displayHelp->Visible = false;
			// 
			// colourLegend
			// 
			this->colourLegend->BackColor = System::Drawing::Color::White;
			this->colourLegend->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->colourLegend->Location = System::Drawing::Point(74, 104);
			this->colourLegend->Name = L"colourLegend";
			this->colourLegend->Size = System::Drawing::Size(633, 455);
			this->colourLegend->TabIndex = 16;
			this->colourLegend->Text = L"";
			this->colourLegend->Visible = false;
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
			this->Controls->Add(this->colourLegend);
			this->Controls->Add(this->displayHelp);
			this->Controls->Add(this->monthCalendar);
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

private: System::Void commandLineTextBox_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			   String^ input;
			   String^ storeLastInput;
			  
			   input = commandLineTextBox->Text;
				 if (e->KeyCode == Keys::Enter) {
					 displayHelp->Visible = false;
					 colourLegend->Visible = false;
					 if (input != "") {
						 String^ inputWithNoNewCharacter = removeNewLineCharacter(input);
						 std::string content = msclr::interop::marshal_as< std::string >(inputWithNoNewCharacter);
						 commandLineTextBox->Clear();
						 parser->pushUserInput(content);

						 std:: vector<std:: string> feedbackList = inputFeedback->retrieveFeedbackList();
						 String^ feedbackSystem;
						 String^ feedback = "";

						 int totalFeedback = feedbackList.size();
						 std:: vector<std:: string>::iterator iter;
/*
						 for (iter = feedbackList.end() - 1; iter != feedbackList.begin(); iter--) {
							 feedbackSystem = gcnew String((*iter).c_str());
							 feedback = feedback + feedbackSystem;

							 if (iter != feedbackList.begin()) {
								 feedback = feedback + "\r\n";
							 }
						 }
						 */
						 for (int i=totalFeedback; i>0; i--) {
							 feedbackSystem = gcnew String(feedbackList[i-1].c_str());
							 feedback = feedback + feedbackSystem;

							 if (i != 0) {
								 feedback = feedback + "\r\n";
							 }
						 } 
						 feedbackTextBox->Text = feedback;

						 displayToday();
						 displayUpcoming();
						 displayMiscellaneous(); 
					 }
					 
				 }
				 else if (e->KeyCode == Keys::F1) {
					  colourLegend->Visible = false;
					 if (displayHelp->Visible == false) {
						 displayUserGuide();

						 displayHelp->Visible = true;
					 }
					 else {
						 displayHelp->Visible = false;
					 }
				 }
				 else if (e->KeyCode == Keys::F2) {
					 //add a color legend
					 displayHelp->Visible = false;
					 if (colourLegend->Visible == false) {
						 displayColourguide();
						 colourLegend->Visible = true;
					 }
					 else {
						 colourLegend->Visible = false;
					 }
				 }
				 //only can get the last input ? 
				 else if (e->KeyCode == Keys::Up) {
					 commandLineTextBox->Clear();

					 std:: vector<std:: string> inputHistory = inputFeedback->retrieveInputList();
					 std:: string lastInputString;
					 std:: vector<std:: string>::iterator iter = inputHistory.end();
					 iter--;
					 lastInputString = (*iter);
					 inputHistory.pop_back();
					 String^ lastInput = gcnew String(lastInputString.c_str());
					 commandLineTextBox->Text = lastInput;					 
				 } else {

					 String^ searchString = removeNewLineCharacter(input);
					 displayToday();
					 displayUpcoming();
					 displayMiscellaneous();
					 if (input->Length>2) {
						 quickSearch(searchString);
					 }						 
				 }
		 }

		 	 void quickSearch(String^ searchString){
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

				 int indexMiscellaneous=0;
				 while (indexMiscellaneous<miscellaneousRichTextBox->Text->LastIndexOf(searchString)) {
					 miscellaneousRichTextBox->Find(searchString,indexMiscellaneous,miscellaneousRichTextBox->TextLength, System::Windows::Forms::RichTextBoxFinds::None);
					 miscellaneousRichTextBox->SelectionBackColor = Color::Yellow;
					 indexMiscellaneous = miscellaneousRichTextBox->Text->IndexOf(searchString, indexMiscellaneous) + 1;
				 }
			 }

			 String^ removeNewLineCharacter(String^ input) {
				 std::string content = msclr::interop::marshal_as< std::string >(input);
				 if ( content.length()>2) {
					 size_t pos = 0;
					 while ( ( pos = content.find ("\r\n",pos) ) != std::string::npos ) {
						 content.erase ( pos, 2 );
					 }
				 }
				 String^ searchString = gcnew String(content.c_str());

				 return searchString;
			 }

			 std:: vector<std:: string> retrieveTaskList(std:: vector<TASK> taskList){
				std:: vector<std:: string> taskListString;
				 
				 storage->updateTaskID(taskList);
				 std:: vector<TASK>::iterator iter;
				 for(iter = taskList.begin(); iter != taskList.end(); iter++) {
					 std:: stringstream ss;
					 ss << iter->taskID;


					 boost::posix_time::time_facet* facet = new boost::posix_time::time_facet("%Y-%b-%d %H:%M");
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

			 void displayToday() {
				
				  std:: vector<TASK> todayTaskList = storage->retrieveTodayTaskList();
				  std:: vector<std:: string> todayList = retrieveTaskList(todayTaskList);
				
				 String^ displayToday = "";

				 todayRichTextBox->Clear();
				  

				 int totalTodayTaskList = todayList.size();

				 for (int i=0; i<totalTodayTaskList; i++) {
					 displayToday = gcnew String(todayList[i].c_str());
					
					 if (overDueTask(todayTaskList, i)) {

						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
						 todayRichTextBox->SelectionColor = Color::Red;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";

					 } else if (newTaskAdded(todayTaskList, i)) {

						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
						 todayRichTextBox->SelectionColor = Color::DeepSkyBlue;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";

					 } else if (clashingTask(todayTaskList, i)) {

						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Italic);
						 todayRichTextBox->SelectionColor = Color::OrangeRed;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";

					 } else if (checkDone(todayTaskList,i)) {

						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
						 todayRichTextBox->SelectionColor = Color::CornflowerBlue;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";

					 } else {

						 todayRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular );
						 todayRichTextBox->SelectionColor = Color::Black;
						 todayRichTextBox->SelectedText = displayToday + "\r\n";

					 }
				 }
			 }

			 void displayUpcoming() {

				 std:: vector<TASK> upcomingTaskList = storage->retrieveUpcomingTaskList();
				 std:: vector<std:: string> upcomingList = retrieveTaskList(upcomingTaskList);
				 int totalUpcomingTaskList = upcomingTaskList.size();
				 String^ displayUpcoming = "";

				 upcomingRichTextBox->Clear();
				 for (int i=0; i<totalUpcomingTaskList; i++) {
					 displayUpcoming = gcnew String(upcomingList[i].c_str());

					 if (newTaskAdded(upcomingTaskList, i)) {

						 upcomingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
						 upcomingRichTextBox->SelectionColor = Color::DeepSkyBlue;
						 upcomingRichTextBox->SelectedText = displayUpcoming + "\r\n";

					 } else if (clashingTask(upcomingTaskList, i)) {

						 upcomingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Italic);
						 upcomingRichTextBox->SelectionColor = Color::OrangeRed;
						 upcomingRichTextBox->SelectedText = displayUpcoming + "\r\n";

					 } else if (checkDone(upcomingTaskList, i)) {

						 upcomingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
						 upcomingRichTextBox->SelectionColor = Color::CornflowerBlue;
						 upcomingRichTextBox->SelectedText = displayUpcoming + "\r\n";

					 } else {

						 upcomingRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular );
						 upcomingRichTextBox->SelectionColor = Color::Black;
						 upcomingRichTextBox->SelectedText = displayUpcoming + "\r\n";
					 }
				 }
			 }
			
			 bool overDueTask(std:: vector<TASK> todayTaskList, int i) {
				 if ((checkOverdue(todayTaskList,i) && checkNewTask(todayTaskList,i) && checkClash(todayTaskList,i)) ||
						 (checkOverdue(todayTaskList,i) && checkNewTask(todayTaskList,i)) || ((todayTaskList,i) && checkClash(todayTaskList,i)) ||
						 checkOverdue(todayTaskList,i)) {
							 return true;
				 } else {
					 return false;
				 }
			 }

			 bool clashingTask(std:: vector<TASK> taskList, int i) {
				 if ( checkClash(taskList,i) && checkNewTask(taskList,i) || checkClash(taskList,i)) {
					 return true;
				 } else {
					 return false;
				 }
			 }

			  bool newTaskAdded( std:: vector<TASK> taskList, int i) {
				  if ( checkNewTask(taskList, i ) && !checkClash(taskList, i) && !checkOverdue(taskList, i)
					  && !checkDone(taskList, i)) {
						  return true;
				  } else {
					  return false;
				  }
			 }

			 bool checkDone(std:: vector<TASK> taskList, int i) {
				 if (taskList[i].done == true) {
					 return true;
				 }
				 else {
					 return false;
				 }
			 }
			 			

			 bool checkOverdue(std:: vector<TASK> taskList, int i) {
				 if (taskList[i].overdue == true) {
					 return true;
				 }
				 else {
					 return false;
				 }
			 }

			 bool checkClash(std:: vector<TASK> taskList, int i) {
				 if (taskList[i].clash == true) {
					 return true;
				 }
				 else {
					 return false;
				 }
			 }

			 bool checkNewTask(std:: vector<TASK> taskList, int i) {
				 if (taskList[i].newTask == true) {
					 return true;
				 }
				 else {
					 return false;
				 }
			 }


			 void displayMiscellaneous() {
				 std:: vector<TASK> miscTaskList = storage->retrieveFloatingTaskList();
				 std:: vector<std:: string> miscList = retrieveTaskList(miscTaskList);
				 int totalMiscellaneousTaskList = miscTaskList.size();
				 String^ displayMisc = "";

				 miscellaneousRichTextBox->Clear();
				 for (int i=0; i<totalMiscellaneousTaskList; i++) {
					 displayMisc = gcnew String(miscList[i].c_str());
					 
					 if ( checkDone(miscTaskList, i)) {
						 miscellaneousRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Strikeout);
						 miscellaneousRichTextBox->SelectionColor = Color::CornflowerBlue;
						 miscellaneousRichTextBox->SelectedText = displayMisc + "\r\n";
					 } else	if ( checkNewTask(miscTaskList, i)) {
						 miscellaneousRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular);
						 miscellaneousRichTextBox->SelectionColor = Color::DeepSkyBlue;
						 miscellaneousRichTextBox->SelectedText = displayMisc + "\r\n";
					 } else {
						 miscellaneousRichTextBox->SelectionFont = gcnew System::Drawing::Font( "Rockwell",10, System::Drawing::FontStyle::Regular );
						 miscellaneousRichTextBox->SelectionColor = Color::Black;
						 miscellaneousRichTextBox->SelectedText = displayMisc + "\r\n";
					 }
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
						 displayHelp->AppendText("undo ");
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
				 colourLegend->AppendText("task is over due" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Italic);
				 colourLegend->SelectionColor = Color::OrangeRed;
				 colourLegend->AppendText("these two tasks clashes" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Strikeout);
				 colourLegend->SelectionColor = Color::CornflowerBlue;
				 colourLegend->AppendText("task is done" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 colourLegend->SelectionColor = Color::DeepSkyBlue;
				 colourLegend->AppendText("task was just added" + "\r\n");

				 colourLegend->SelectionFont = gcnew System::Drawing::Font( "Arial", 9, System::Drawing::FontStyle::Regular);
				 colourLegend->SelectionColor = Color::Black;
				 colourLegend->AppendText("a normal upcoming task" + "\r\n");

			 }
};
}