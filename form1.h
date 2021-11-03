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
			bmpTituloMenu = gcnew Bitmap("archivos/titulojuego.png");
			bmpPLAYMenu = gcnew Bitmap("archivos/btnPLAY.png");
			bmpENTERMenu = gcnew Bitmap("archivos/ENTER.png");
			fondoMenuX = fondoMenuY = 0;

			//Inicio del juego
			bmpFondoInicio = gcnew Bitmap("archivos/fondoInicio.png");
			bmpPersonajeAncianoMINI = gcnew Bitmap("archivos/personajes/ancianoMINI.png");
			bmpPersonajeAncianoFULL = gcnew Bitmap("archivos/personajes/ancianoFULL.png");
		}

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		
		//Fondo Menu
		Bitmap^ bmpFondoMenu;
		Bitmap^ bmpTituloMenu;
		Bitmap^ bmpPLAYMenu;
		Bitmap^ bmpENTERMenu;
		int fondoMenuX, fondoMenuY;

		//Inicio del juego/lobby
		Bitmap^ bmpFondoInicio;
		Bitmap^ bmpPersonajeAncianoMINI;
		Bitmap^ bmpPersonajeAncianoFULL;

		//Personaje
		Bitmap^ bmpPersonajePrincipal;
	private: System::Windows::Forms::Timer^ tmrInicio;

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
			this->tmrMenu = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tmrInicio = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// tmrMenu
			// 
			this->tmrMenu->Enabled = true;
			this->tmrMenu->Interval = 50;
			this->tmrMenu->Tick += gcnew System::EventHandler(this, &form1::tmrMenu_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1184, 755);
			this->panel1->TabIndex = 0;
			// 
			// tmrInicio
			// 
			this->tmrInicio->Tick += gcnew System::EventHandler(this, &form1::tmrInicio_Tick);
			// 
			// form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1182, 753);
			this->Controls->Add(this->panel1);
			this->Name = L"form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"form1";
			this->Load += gcnew System::EventHandler(this, &form1::form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &form1::form1_KeyDown);
			this->ResumeLayout(false);

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
		buffer->Graphics->DrawImage(bmpTituloMenu, 216, 100, 473, 89);
		buffer->Graphics->DrawImage(bmpPLAYMenu, 338, 250, 230, 83);
		buffer->Graphics->DrawImage(bmpENTERMenu, 327, 360, 252, 25);
		/*MessageBox::Show(panel1->Width);*/
		//Render
		buffer->Render(g);
		fondoMenuX += 5;
		if (fondoMenuX > panel1->Width * 3)fondoMenuX = 0;
	}
	Void tmrInicio_Tick(Object^ sender, EventArgs^ e) {

	}
	Void form1_KeyDown(Object^ sender, KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter && tmrMenu->Enabled == true) {
			tmrMenu->Enabled = false;
			tmrInicio->Enabled = true;
			/*buffer->Graphics->Clear(Color::White);
			buffer->Render(g);*/
		}
	}
};
}
