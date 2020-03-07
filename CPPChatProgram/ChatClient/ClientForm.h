#pragma once

namespace ChatClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Runtime::Serialization;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::Runtime::Serialization::Formatters;
	using namespace System::Threading;
	using namespace FormatterText;
	using namespace System::IO;

	/// <summary>
	/// ClientForm에 대한 요약입니다.
	/// </summary>
	public ref class ClientForm : public System::Windows::Forms::Form
	{
	public:
		ClientForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			CheckForIllegalCrossThreadCalls = false;
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~ClientForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblAddress;
	protected:
	private: System::Windows::Forms::Button^ btnConnect;
	private: System::Windows::Forms::TextBox^ txtAddress;
	private: System::Windows::Forms::RichTextBox^ txtMain;
	private: System::Windows::Forms::LinkLabel^ lblFont;
	private: System::Windows::Forms::LinkLabel^ lblColor;
	private: System::Windows::Forms::RichTextBox^ txtSend;
	private: System::Windows::Forms::Button^ btnSend;
	private: System::Windows::Forms::FontDialog^ fontDialog1;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;

	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblAddress = (gcnew System::Windows::Forms::Label());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->txtMain = (gcnew System::Windows::Forms::RichTextBox());
			this->lblFont = (gcnew System::Windows::Forms::LinkLabel());
			this->lblColor = (gcnew System::Windows::Forms::LinkLabel());
			this->txtSend = (gcnew System::Windows::Forms::RichTextBox());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// lblAddress
			// 
			this->lblAddress->AutoSize = true;
			this->lblAddress->Location = System::Drawing::Point(13, 13);
			this->lblAddress->Name = L"lblAddress";
			this->lblAddress->Size = System::Drawing::Size(55, 15);
			this->lblAddress->TabIndex = 0;
			this->lblAddress->Text = L"IP 주소";
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(395, 13);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(75, 23);
			this->btnConnect->TabIndex = 1;
			this->btnConnect->Text = L"연결";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &ClientForm::btnConnect_Click);
			// 
			// txtAddress
			// 
			this->txtAddress->Location = System::Drawing::Point(74, 13);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(315, 25);
			this->txtAddress->TabIndex = 2;
			// 
			// txtMain
			// 
			this->txtMain->Location = System::Drawing::Point(12, 45);
			this->txtMain->Name = L"txtMain";
			this->txtMain->Size = System::Drawing::Size(458, 196);
			this->txtMain->TabIndex = 3;
			this->txtMain->Text = L"";
			// 
			// lblFont
			// 
			this->lblFont->AutoSize = true;
			this->lblFont->Location = System::Drawing::Point(13, 248);
			this->lblFont->Name = L"lblFont";
			this->lblFont->Size = System::Drawing::Size(52, 15);
			this->lblFont->TabIndex = 4;
			this->lblFont->TabStop = true;
			this->lblFont->Text = L"글씨체";
			this->lblFont->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ClientForm::lblFont_LinkClicked);
			// 
			// lblColor
			// 
			this->lblColor->AutoSize = true;
			this->lblColor->Location = System::Drawing::Point(71, 248);
			this->lblColor->Name = L"lblColor";
			this->lblColor->Size = System::Drawing::Size(67, 15);
			this->lblColor->TabIndex = 5;
			this->lblColor->TabStop = true;
			this->lblColor->Text = L"글씨색깔";
			this->lblColor->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ClientForm::lblColor_LinkClicked);
			// 
			// txtSend
			// 
			this->txtSend->Location = System::Drawing::Point(12, 266);
			this->txtSend->Name = L"txtSend";
			this->txtSend->Size = System::Drawing::Size(377, 35);
			this->txtSend->TabIndex = 6;
			this->txtSend->Text = L"";
			// 
			// btnSend
			// 
			this->btnSend->Location = System::Drawing::Point(395, 278);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(75, 23);
			this->btnSend->TabIndex = 7;
			this->btnSend->Text = L"전송";
			this->btnSend->UseVisualStyleBackColor = true;
			this->btnSend->Click += gcnew System::EventHandler(this, &ClientForm::btnSend_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &ClientForm::backgroundWorker1_DoWork);
			// 
			// ClientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 313);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->txtSend);
			this->Controls->Add(this->lblColor);
			this->Controls->Add(this->lblFont);
			this->Controls->Add(this->txtMain);
			this->Controls->Add(this->txtAddress);
			this->Controls->Add(this->btnConnect);
			this->Controls->Add(this->lblAddress);
			this->Name = L"ClientForm";
			this->Text = L"ClientForm";
			this->Load += gcnew System::EventHandler(this, &ClientForm::ClientForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		Socket^ client;
		IPEndPoint^ IP;
		Thread^ clientThread;

	private: System::Void lblFont_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		if (fontDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			txtSend->Font = fontDialog1->Font;
		}
	}
	private: System::Void lblColor_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			txtSend->ForeColor = colorDialog1->Color;
		}
	}
	private: System::Void ClientForm_Load(System::Object^ sender, System::EventArgs^ e) {
		client = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::IP);
	}
private: System::Void btnConnect_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		IP = gcnew IPEndPoint(IPAddress::Parse(txtAddress->Text), 2016);
		client->Connect(IP);

		backgroundWorker1->RunWorkerAsync();
	}
	catch (Exception ^ ex) {
		MessageBox::Show(ex->Message);
	}
}
private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	while (true) {
		array<unsigned char>^ buf = gcnew array<unsigned char>(1024);
		int temp = client->Receive(buf);
		FormatterText::StructChat^ str = gcnew FormatterText::StructChat();

		str = Deserialize(buf);
		addText(str->textChat, str->myFont, str->myColor);
	}
}
	private: void addText(String^ text, System::Drawing::Font^ font, System::Drawing::Color^ color) {
		txtMain->SelectionFont = font;
		txtMain->SelectionColor = (Color)color;
		txtMain->AppendText(text + "\n");
		txtMain->ScrollToCaret();
	}

	public: array<unsigned char, 1>^ Serialize(FormatterText::StructChat^ str) {
		MemoryStream^ ms = gcnew MemoryStream();
		BinaryFormatter^ bf = gcnew BinaryFormatter();
		bf->Serialize(ms, str);
		return ms->ToArray();
	}

	public: FormatterText::StructChat^ Deserialize(array<unsigned char>^ buff) {
		MemoryStream^ ms = gcnew MemoryStream(buff);
		BinaryFormatter^ bf = gcnew BinaryFormatter();
		return (FormatterText::StructChat^)bf->Deserialize(ms);
	}
private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {
	FormatterText::StructChat^ str = gcnew FormatterText::StructChat();

	str->textChat = txtSend->Text;
	str->myColor = txtSend->ForeColor;
	str->myFont = txtSend->Font;

	array<unsigned char>^ buf = gcnew array<unsigned char>(1024);
	MemoryStream^ ms = gcnew MemoryStream();
	BinaryFormatter^ bf = gcnew BinaryFormatter();
	bf->Serialize(ms, str);
	buf = ms->ToArray();
	client->Send(buf, buf->Length, SocketFlags::None);
}
};
}
