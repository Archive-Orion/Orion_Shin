#include "../ChatServer/ServerForm.h"
#include <iostream>
#pragma once

namespace ChatMain {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	using namespace OpenCvSharp;

	/// <summary>
	/// RegisterForm에 대한 요약입니다.
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnSave;
	protected:

	protected:
	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::TextBox^ txtName;

	private: OpenCvSharp::UserInterface::PictureBoxIpl^ picPhoto;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


	protected:





	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->picPhoto = (gcnew OpenCvSharp::UserInterface::PictureBoxIpl());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPhoto))->BeginInit();
			this->SuspendLayout();
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(322, 274);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(75, 23);
			this->btnSave->TabIndex = 9;
			this->btnSave->Text = L"저장";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &RegisterForm::btnSave_Click);
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Location = System::Drawing::Point(12, 277);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(37, 15);
			this->lblName->TabIndex = 8;
			this->lblName->Text = L"이름";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(55, 274);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(168, 25);
			this->txtName->TabIndex = 7;
			// 
			// picPhoto
			// 
			this->picPhoto->Location = System::Drawing::Point(15, 12);
			this->picPhoto->Name = L"picPhoto";
			this->picPhoto->Size = System::Drawing::Size(450, 240);
			this->picPhoto->TabIndex = 10;
			this->picPhoto->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 33;
			this->timer1->Tick += gcnew System::EventHandler(this, &RegisterForm::timer1_Tick);
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 313);
			this->Controls->Add(this->picPhoto);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->lblName);
			this->Controls->Add(this->txtName);
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
			this->Load += gcnew System::EventHandler(this, &RegisterForm::RegisterForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		CvCapture^ capture;
		IplImage^ src;

	private: System::Void RegisterForm_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			capture = CvCapture::FromCamera(CaptureDevice::DShow, 0);
			capture->SetCaptureProperty(CaptureProperty::FrameWidth, 450);
			capture->SetCaptureProperty(CaptureProperty::FrameHeight, 240);
		}
		catch (Exception ^ ex) {
			timer1->Enabled = false;
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		try {
			src = capture->QueryFrame();
			picPhoto->ImageIpl = src;
		}
		catch (Exception ^ ex) {}
	}

	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			String^ dir = "../ChatServer/Photo";
			DirectoryInfo^ di = gcnew DirectoryInfo(dir);

			if (String::IsNullOrWhiteSpace(txtName->Text)) {
				MessageBox::Show("이름을 입력해주세요");
			}
			else {
				if (di->Exists == false) {
					di->Create();
				}
				Cv::SaveImage("../ChatServer/Photo/" + txtName->Text + ".jpg", src);
				MessageBox::Show("회원가입 완료!");
			}
		}
		catch (Exception ^ ex) {}
	}
};
}
