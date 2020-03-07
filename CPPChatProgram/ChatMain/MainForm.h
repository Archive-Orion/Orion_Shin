#include "LoginForm.h"
#include "RegisterForm.h"
#pragma once

namespace ChatMain {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm�� ���� ����Դϴ�.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnLogin;
	protected:
	private: System::Windows::Forms::Button^ btnSignUp;

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnSignUp = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(95, 137);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 0;
			this->btnLogin->Text = L"�α���";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MainForm::btnLogin_Click);
			// 
			// btnSignUp
			// 
			this->btnSignUp->Location = System::Drawing::Point(295, 137);
			this->btnSignUp->Name = L"btnSignUp";
			this->btnSignUp->Size = System::Drawing::Size(75, 23);
			this->btnSignUp->TabIndex = 1;
			this->btnSignUp->Text = L"ȸ������";
			this->btnSignUp->UseVisualStyleBackColor = true;
			this->btnSignUp->Click += gcnew System::EventHandler(this, &MainForm::btnSignUp_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 313);
			this->Controls->Add(this->btnSignUp);
			this->Controls->Add(this->btnLogin);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		LoginForm^ Lform = gcnew LoginForm();
		Lform->ShowDialog();
		
	}
	private: System::Void btnSignUp_Click(System::Object^ sender, System::EventArgs^ e) {
		RegisterForm^ Rform = gcnew RegisterForm();
		Rform->ShowDialog();
	}
	};
}
