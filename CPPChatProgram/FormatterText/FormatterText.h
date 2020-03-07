using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::Runtime::Serialization::Formatters;
#pragma once

using namespace System;

namespace FormatterText {

	[Serializable]

	public ref class StructChat
	{
		// TODO: 여기에 이 클래스에 대한 메서드를 추가합니다.
	public:
		String^ textChat;
		System::Drawing::Color^ myColor;
		System::Drawing::Font^ myFont;

	public: StructChat() {
		textChat = "";
		myColor = Color::Green;
		myFont = gcnew System::Drawing::Font("맑은 고딕", 9, FontStyle::Regular);
	}

	public: StructChat(String^ text, System::Drawing::Font^ font, Color^ color) {
		textChat = text;
		myColor = color;
		myFont = font;
	}

	public: void GetObjectData(SerializationInfo^ info, StreamingContext^ context) {
		info->AddValue("text", textChat);
		info->AddValue("font", myFont);
		info->AddValue("color", myColor);
	}

	public: StructChat(SerializationInfo^ info, StreamingContext^ context) {
		textChat = (String^)info->GetValue("text", String::typeid);
		myFont = (System::Drawing::Font^)info->GetValue("font", System::Drawing::Font::typeid);
		myColor = (System::Drawing::Color^)info->GetValue("color", System::Drawing::Color::typeid);
	}
	};
}
