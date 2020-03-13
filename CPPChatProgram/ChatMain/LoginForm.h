#include "../ChatClient/ClientForm.h"
#pragma once

namespace ChatMain {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace OpenCvSharp;

	/// <summary>
	/// LoginForm�� ���� ����Դϴ�.
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ btnCapture;
	private: System::Windows::Forms::Timer^ timer1;
	private: OpenCvSharp::UserInterface::PictureBoxIpl^ picLogin;


	private: System::ComponentModel::IContainer^ components;




	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnCapture = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->picLogin = (gcnew OpenCvSharp::UserInterface::PictureBoxIpl());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLogin))->BeginInit();
			this->SuspendLayout();
			// 
			// btnCapture
			// 
			this->btnCapture->Location = System::Drawing::Point(203, 278);
			this->btnCapture->Name = L"btnCapture";
			this->btnCapture->Size = System::Drawing::Size(75, 23);
			this->btnCapture->TabIndex = 1;
			this->btnCapture->Text = L"ĸ��";
			this->btnCapture->UseVisualStyleBackColor = true;
			this->btnCapture->Click += gcnew System::EventHandler(this, &LoginForm::btnCapture_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 33;
			this->timer1->Tick += gcnew System::EventHandler(this, &LoginForm::timer1_Tick);
			// 
			// picLogin
			// 
			this->picLogin->Location = System::Drawing::Point(12, 12);
			this->picLogin->Name = L"picLogin";
			this->picLogin->Size = System::Drawing::Size(450, 240);
			this->picLogin->TabIndex = 2;
			this->picLogin->TabStop = false;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 313);
			this->Controls->Add(this->picLogin);
			this->Controls->Add(this->btnCapture);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &LoginForm::LoginForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picLogin))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		CvCapture^ capture;
		IplImage^ src;

	private: System::Void btnCapture_Click(System::Object^ sender, System::EventArgs^ e) {
		if (true) {
			this->Hide();
			ChatClient::ClientForm^ Cform = gcnew ChatClient::ClientForm();
			Cform->Show();
		}
		else {
			MessageBox::Show("�α��� ����!");
		}
	}
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			capture = CvCapture::FromCamera(CaptureDevice::DShow, 0);
			capture->SetCaptureProperty(CaptureProperty::FrameWidth, 450);
			capture->SetCaptureProperty(CaptureProperty::FrameHeight, 240);
		}
		catch(Exception^ ex) {
			timer1->Enabled = false;
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		try {
			src = capture->QueryFrame();
			picLogin->ImageIpl = src;
		}
		catch(Exception^ ex){}
	}
	private: System::Void LoginForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		try {
			Cv::ReleaseImage(src);
		}
		catch(Exception^ ex) {}
	}
};
}
