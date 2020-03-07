#pragma once

namespace ChatMain {

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
	private: System::Windows::Forms::Button^ btnName;
	protected:
	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::Button^ btnCapture;
	private: System::Windows::Forms::PictureBox^ boxPhoto;

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
			this->btnName = (gcnew System::Windows::Forms::Button());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->btnCapture = (gcnew System::Windows::Forms::Button());
			this->boxPhoto = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxPhoto))->BeginInit();
			this->SuspendLayout();
			// 
			// btnName
			// 
			this->btnName->Location = System::Drawing::Point(395, 273);
			this->btnName->Name = L"btnName";
			this->btnName->Size = System::Drawing::Size(75, 23);
			this->btnName->TabIndex = 9;
			this->btnName->Text = L"저장";
			this->btnName->UseVisualStyleBackColor = true;
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
			this->txtName->Location = System::Drawing::Point(55, 277);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(153, 25);
			this->txtName->TabIndex = 7;
			// 
			// btnCapture
			// 
			this->btnCapture->Location = System::Drawing::Point(395, 105);
			this->btnCapture->Name = L"btnCapture";
			this->btnCapture->Size = System::Drawing::Size(75, 23);
			this->btnCapture->TabIndex = 6;
			this->btnCapture->Text = L"캡쳐";
			this->btnCapture->UseVisualStyleBackColor = true;
			// 
			// boxPhoto
			// 
			this->boxPhoto->Location = System::Drawing::Point(12, 11);
			this->boxPhoto->Name = L"boxPhoto";
			this->boxPhoto->Size = System::Drawing::Size(377, 240);
			this->boxPhoto->TabIndex = 5;
			this->boxPhoto->TabStop = false;
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 313);
			this->Controls->Add(this->btnName);
			this->Controls->Add(this->lblName);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->btnCapture);
			this->Controls->Add(this->boxPhoto);
			this->Name = L"RegisterForm";
			this->Text = L"RegisterForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
