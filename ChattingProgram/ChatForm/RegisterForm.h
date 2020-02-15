#pragma once

namespace ChatForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ box_Photo;
	private: System::Windows::Forms::Button^ btn_Photo;
	private: System::Windows::Forms::Button^ btn_SignUp;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->box_Photo = (gcnew System::Windows::Forms::PictureBox());
			this->btn_Photo = (gcnew System::Windows::Forms::Button());
			this->btn_SignUp = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->box_Photo))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(0, 226);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 25);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"이름";
			// 
			// box_Photo
			// 
			this->box_Photo->Location = System::Drawing::Point(0, 1);
			this->box_Photo->Name = L"box_Photo";
			this->box_Photo->Size = System::Drawing::Size(280, 219);
			this->box_Photo->TabIndex = 1;
			this->box_Photo->TabStop = false;
			// 
			// btn_Photo
			// 
			this->btn_Photo->Location = System::Drawing::Point(127, 227);
			this->btn_Photo->Name = L"btn_Photo";
			this->btn_Photo->Size = System::Drawing::Size(75, 23);
			this->btn_Photo->TabIndex = 2;
			this->btn_Photo->Text = L"사진캡쳐";
			this->btn_Photo->UseVisualStyleBackColor = true;
			// 
			// btn_SignUp
			// 
			this->btn_SignUp->Location = System::Drawing::Point(208, 227);
			this->btn_SignUp->Name = L"btn_SignUp";
			this->btn_SignUp->Size = System::Drawing::Size(75, 23);
			this->btn_SignUp->TabIndex = 3;
			this->btn_SignUp->Text = L"가입";
			this->btn_SignUp->UseVisualStyleBackColor = true;
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->btn_SignUp);
			this->Controls->Add(this->btn_Photo);
			this->Controls->Add(this->box_Photo);
			this->Controls->Add(this->textBox1);
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->box_Photo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
