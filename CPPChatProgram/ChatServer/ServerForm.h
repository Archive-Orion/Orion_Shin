#pragma once

namespace ChatServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace FormatterText;
	using namespace System::Collections::Generic;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Threading;

	/// <summary>
	/// ServerForm에 대한 요약입니다.
	/// </summary>
	public ref class ServerForm : public System::Windows::Forms::Form
	{
	public:
		ServerForm(void)
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
		~ServerForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ btnConnect;

	private: System::Windows::Forms::RichTextBox^ txtMain;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;

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
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->txtMain = (gcnew System::Windows::Forms::RichTextBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(198, 12);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(89, 23);
			this->btnConnect->TabIndex = 1;
			this->btnConnect->Text = L"서버 켜기";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &ServerForm::btnConnect_Click);
			// 
			// txtMain
			// 
			this->txtMain->Location = System::Drawing::Point(12, 45);
			this->txtMain->Name = L"txtMain";
			this->txtMain->Size = System::Drawing::Size(458, 246);
			this->txtMain->TabIndex = 3;
			this->txtMain->Text = L"";
			this->txtMain->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ServerForm::txtMain_KeyPress);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &ServerForm::backgroundWorker1_DoWork);
			// 
			// ServerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 303);
			this->Controls->Add(this->txtMain);
			this->Controls->Add(this->btnConnect);
			this->Name = L"ServerForm";
			this->Text = L"ServerForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ServerForm::ServerForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &ServerForm::ServerForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		static Socket^ server;
		static List<Socket^>^ listClient = gcnew List<Socket^>();
		static IPEndPoint^ IP;
		static Thread^ threadClient;

	private: System::Void txtMain_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		e->Handled = true;
	}
	private: System::Void btnConnect_Click(System::Object^ sender, System::EventArgs^ e) {
		IP = gcnew IPEndPoint(IPAddress::Loopback, 2016);

		backgroundWorker1->WorkerSupportsCancellation = true;
		backgroundWorker1->RunWorkerAsync();
	}

	private: static void client(Object^ obj) {
		Socket^ socket = (Socket^)obj;
		while (true) {
			try {
				array<unsigned char>^ buff = gcnew array <unsigned char>(1024);
				int temp = socket->Receive(buff);

				for each (Socket ^ sock in listClient) {
					try {
						sock->Send(buff, buff->Length, SocketFlags::None);
					}
					catch(Exception^ ex) {}
				}
			}
			catch (Exception ^ ex) {
				listClient->Remove(socket);
				return;
			}
		}
	}

	private: void addTextToMainTextBox(String^ text, System::Drawing::Font^ font, System::Drawing::Color^ color) {
		txtMain->SelectionFont = font;
		txtMain->SelectionColor = (Color)color;
		txtMain->AppendText(text + "\n");
	}
	private: System::Void ServerForm_Load(System::Object^ sender, System::EventArgs^ e) {
		server = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::IP);
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		server->Bind(IP);
		server->Listen(10);
		String^ text = "서버가 동작하고 있습니다.";
		System::Drawing::Font^ font = gcnew System::Drawing::Font("맑은 고딕", 9, FontStyle::Bold);
		System::Drawing::Color^ color = Color::Red;
		addTextToMainTextBox(text, font, color);

		while (true) {
			Socket^ clientAccept = server->Accept();
			listClient->Add(clientAccept);

			threadClient = gcnew Thread(gcnew ParameterizedThreadStart(ChatServer::ServerForm::client));
			threadClient->IsBackground = true;
			threadClient->Start(clientAccept);

			String^ textTemp = "클라이언트가 접속했습니다." + clientAccept->RemoteEndPoint->ToString();
			System::Drawing::Font^ fontTemp = gcnew System::Drawing::Font("맑은 고딕", 9, FontStyle::Bold);
			System::Drawing::Color^ colorTemp = Color::Red;
			addTextToMainTextBox(textTemp, fontTemp, colorTemp);
		}
	}
	private: System::Void ServerForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		if (backgroundWorker1->IsBusy) {
			backgroundWorker1->CancelAsync();
		}
	}
	private: System::Void lblAddress_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}