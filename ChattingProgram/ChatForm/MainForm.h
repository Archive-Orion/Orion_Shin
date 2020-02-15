#include "RegisterForm.h"
#pragma once

namespace ChatForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm에 대한 요약입니다.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_Login;
	private: System::Windows::Forms::Button^ btn_Register;
	protected:


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
			this->btn_Login = (gcnew System::Windows::Forms::Button());
			this->btn_Register = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_Login
			// 
			this->btn_Login->Location = System::Drawing::Point(100, 81);
			this->btn_Login->Name = L"btn_Login";
			this->btn_Login->Size = System::Drawing::Size(75, 23);
			this->btn_Login->TabIndex = 0;
			this->btn_Login->Text = L"로그인";
			this->btn_Login->UseVisualStyleBackColor = true;
			this->btn_Login->Click += gcnew System::EventHandler(this, &MainForm::btn_Login_Click);
			// 
			// btn_Register
			// 
			this->btn_Register->Location = System::Drawing::Point(100, 135);
			this->btn_Register->Name = L"btn_Register";
			this->btn_Register->Size = System::Drawing::Size(75, 23);
			this->btn_Register->TabIndex = 1;
			this->btn_Register->Text = L"회원가입";
			this->btn_Register->UseVisualStyleBackColor = true;
			this->btn_Register->Click += gcnew System::EventHandler(this, &MainForm::btn_Register_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->btn_Register);
			this->Controls->Add(this->btn_Login);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_Login_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btn_Register_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		RegisterForm^ form = gcnew RegisterForm();
		form->ShowDialog();
	}
	};
}
