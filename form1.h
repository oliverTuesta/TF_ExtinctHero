#pragma once

namespace TFExtinctHero {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for form1
	/// </summary>
	public ref class form1 : public System::Windows::Forms::Form
	{
	public:
		form1(void)
		{
			InitializeComponent();
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Fondo Menu
			bmpFondoMenu = gcnew Bitmap("archivos/fondoMenu.png");
			fondoMenuX = fondoMenuY = 0;

		}

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		
		//Fondo Menu
		Bitmap^ bmpFondoMenu;
		int fondoMenuX, fondoMenuY;
	private: System::Windows::Forms::Panel^ panel1;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnPlay;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Timer^ tmrMenu;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->tmrMenu = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// btnPlay
			// 
			this->btnPlay->BackColor = System::Drawing::Color::Transparent;
			this->btnPlay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btnPlay->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnPlay->FlatAppearance->BorderSize = 0;
			this->btnPlay->Font = (gcnew System::Drawing::Font(L"Felix Titling", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPlay->Location = System::Drawing::Point(475, 350);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(250, 150);
			this->btnPlay->TabIndex = 0;
			this->btnPlay->Text = L"PLAY";
			this->btnPlay->UseVisualStyleBackColor = false;
			this->btnPlay->Click += gcnew System::EventHandler(this, &form1::btnPlay_Click);
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->BackColor = System::Drawing::Color::Transparent;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Old English Text MT", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->Location = System::Drawing::Point(254, 180);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(691, 165);
			this->lblTitle->TabIndex = 1;
			this->lblTitle->Text = L"Extinct Hero";
			this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblTitle->UseCompatibleTextRendering = true;
			// 
			// tmrMenu
			// 
			this->tmrMenu->Enabled = true;
			this->tmrMenu->Interval = 50;
			this->tmrMenu->Tick += gcnew System::EventHandler(this, &form1::tmrMenu_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1208, 729);
			this->panel1->TabIndex = 2;
			// 
			// form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1232, 753);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->btnPlay);
			this->Controls->Add(this->panel1);
			this->Name = L"form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"form1";
			this->Load += gcnew System::EventHandler(this, &form1::form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: Void form1_Load(Object^ sender, EventArgs^ e) {
		
	}
	Void tmrMenu_Tick(Object^ sender, EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);
		//Move & Draw
		buffer->Graphics->DrawImage(bmpFondoMenu, fondoMenuX, fondoMenuY, panel1->Width * 3, panel1->Height);
		buffer->Graphics->DrawImage(bmpFondoMenu, fondoMenuX - panel1->Width * 3 + 1, fondoMenuY, panel1->Width * 3, panel1->Height);
		//Render
		buffer->Render(g);
		fondoMenuX++;

	}
	Void btnPlay_Click(Object^ sender, EventArgs^ e) {
		
	}
};
}
