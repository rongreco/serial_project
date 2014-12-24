#pragma once

namespace Serial_project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::IO::Ports;//added

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			findports();                                                           //added
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  readbutton;
	private: System::Windows::Forms::Button^  closebutton;
	private: System::Windows::Forms::ComboBox^  baudcomboBox;
	private: System::Windows::Forms::ComboBox^  portcomboBox;
	private: System::Windows::Forms::RichTextBox^  textBox;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::IO::Ports::SerialPort^  serialPort;

	private: System::ComponentModel::IContainer^  components;


	protected: 

	protected: 

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
			this->readbutton = (gcnew System::Windows::Forms::Button());
			this->closebutton = (gcnew System::Windows::Forms::Button());
			this->baudcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->portcomboBox = (gcnew System::Windows::Forms::ComboBox());
			this->textBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->serialPort = (gcnew System::IO::Ports::SerialPort(this->components));
			this->SuspendLayout();
			// 
			// readbutton
			// 
			this->readbutton->Location = System::Drawing::Point(472, 36);
			this->readbutton->Name = L"readbutton";
			this->readbutton->Size = System::Drawing::Size(105, 29);
			this->readbutton->TabIndex = 0;
			this->readbutton->Text = L"Start Reading";
			this->readbutton->UseVisualStyleBackColor = true;
			this->readbutton->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// closebutton
			// 
			this->closebutton->Location = System::Drawing::Point(472, 188);
			this->closebutton->Name = L"closebutton";
			this->closebutton->Size = System::Drawing::Size(105, 28);
			this->closebutton->TabIndex = 1;
			this->closebutton->Text = L"Close";
			this->closebutton->UseVisualStyleBackColor = true;
			this->closebutton->Click += gcnew System::EventHandler(this, &Form1::closebutton_Click);
			// 
			// baudcomboBox
			// 
			this->baudcomboBox->FormattingEnabled = true;
			this->baudcomboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"9600", L"115200"});
			this->baudcomboBox->Location = System::Drawing::Point(320, 136);
			this->baudcomboBox->Name = L"baudcomboBox";
			this->baudcomboBox->Size = System::Drawing::Size(121, 21);
			this->baudcomboBox->TabIndex = 2;
			this->baudcomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::portcomboBox_SelectedIndexChanged);
			// 
			// portcomboBox
			// 
			this->portcomboBox->FormattingEnabled = true;
			this->portcomboBox->Location = System::Drawing::Point(320, 44);
			this->portcomboBox->Name = L"portcomboBox";
			this->portcomboBox->Size = System::Drawing::Size(121, 21);
			this->portcomboBox->TabIndex = 3;
			this->portcomboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::portcomboBox_SelectedIndexChanged_1);
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(23, 36);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(273, 96);
			this->textBox->TabIndex = 4;
			this->textBox->Text = L"";
			this->textBox->TextChanged += gcnew System::EventHandler(this, &Form1::label_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"OUTPUT";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(317, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"COM Port";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(317, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Baud Rate";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(589, 242);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->portcomboBox);
			this->Controls->Add(this->baudcomboBox);
			this->Controls->Add(this->closebutton);
			this->Controls->Add(this->readbutton);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: void func(String^ s){ this->textBox->AppendText(s);}
	private:
    static void DataReceivedHandler(
                        Object^ sender,
                        SerialDataReceivedEventArgs^ e)
    {
        SerialPort^ sp = (SerialPort^)sender;
        String^ indata = sp->ReadExisting();
        //Console::WriteLine("Data Received:");
        //Console::Write(indata);
		String^ fileName = "textfile.txt";

   StreamWriter^ sw = gcnew StreamWriter(fileName);
   sw->WriteLine(indata);
		
		
    }
#pragma endregion                        
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { //START BUTTON
				 try{
					 this->baudcomboBox->Enabled =false;
					 this->portcomboBox->Enabled =false;
					 this->serialPort->PortName=this->portcomboBox->Text;
					 this->serialPort->BaudRate=Int32::Parse(this->baudcomboBox->Text);
					 if(!this->serialPort->IsOpen) this->serialPort->Open();
					 serialPort->DataReceived += gcnew SerialDataReceivedEventHandler(DataReceivedHandler);
					 this->textBox->AppendText(ReadAllText("@c:\Users\rishabhraj281\Documents\Visual Studio 2010\Projects\Serial_project"));

				 }
				 catch(UnauthorizedAccessException^){
					 this->textBox->Text="UnauthorizedAccess";
				 }
			 }
	private: System::Void portcomboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void portcomboBox_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void findports(Void){                     //added
				 array<Object^>^ objectarray= SerialPort::GetPortNames();
				 this->portcomboBox->Items->AddRange(objectarray);
			 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
//private: System::Void label_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	//	 }
//private: System::Void label_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		// }
private: System::Void closebutton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->serialPort->Close();
			 this->readbutton->Enabled=false;
			 this->textBox->Enabled = false;
		 }
};

};

