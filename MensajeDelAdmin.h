#pragma once

namespace TFExtinctHero {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MensajeDelAdmin
	/// </summary>
	public ref class MensajeDelAdmin : public System::Windows::Forms::Form
	{
	public:
		MensajeDelAdmin(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MensajeDelAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(66, 85);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(142, 65);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"Aqui concluye el \r\nprimer nivel";
			// 
			// MensajeDelAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->textBox1);
			this->Name = L"MensajeDelAdmin";
			this->Text = L"MensajeDelAdmin";
			this->Load += gcnew System::EventHandler(this, &MensajeDelAdmin::MensajeDelAdmin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MensajeDelAdmin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
