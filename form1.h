#pragma once
#include "Controller.h"
#include "FormInstrucciones.h"

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
			//Tama�o del forms
			this->Width = 900;
			this->Height = 600;
			panel1->Width = 900;
			panel1->Height = 600;

			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			//Fondo Menu
			bmpFondoMenu = gcnew Bitmap("archivos/menu/fondoMenu.png");
			bmpTituloMenu = gcnew Bitmap("archivos/menu/titulojuego.png");
			bmpPLAYMenu = gcnew Bitmap("archivos/menu/btnPLAY.png");
			bmpENTERMenu = gcnew Bitmap("archivos/menu/ENTER.png");
			fondoMenuX = fondoMenuY = 0;

			//Inicio del juego
			bmpFondoInicio = gcnew Bitmap("archivos/fondoInicio.png");
			bmpPersonajeAncianoMINI = gcnew Bitmap("archivos/personajes/ancianoMINI.png");
			bmpPersonajeAncianoFULL = gcnew Bitmap("archivos/personajes/ancianoFULL.png");
			formInstrucciones = gcnew FormInstrucciones();

			//Menu del juego
			bmpPersonajePrincipal = gcnew Bitmap("archivos/personajes/rescatista.png");

			//Controller
			juego = new Controller(bmpPersonajePrincipal, bmpPersonajeAncianoMINI);
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
		FormInstrucciones^ formInstrucciones;

		//Personaje
		Bitmap^ bmpPersonajePrincipal;

		//Controller
		Controller* juego;


	private: System::Windows::Forms::Timer^ tmrInicio;
	private: System::Windows::Forms::Timer^ tmrNivel1;

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
			this->tmrNivel1 = (gcnew System::Windows::Forms::Timer(this->components));
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
			// tmrNivel1
			// 
			this->tmrNivel1->Tick += gcnew System::EventHandler(this, &form1::tmrNivel1_Tick);
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
		buffer->Graphics->DrawImage(bmpTituloMenu, 213, 100, 473, 89);
		buffer->Graphics->DrawImage(bmpPLAYMenu, 335, 250, 230, 83);
		buffer->Graphics->DrawImage(bmpENTERMenu, 324, 360, 252, 25);
		/*MessageBox::Show(panel1->Width);*/
		//Render
		buffer->Render(g);
		fondoMenuX += 5;
		if (fondoMenuX > panel1->Width * 3)fondoMenuX = 0;
	}
	Void tmrInicio_Tick(Object^ sender, EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);
		//Move & Draw
		if (juego->colisionMenu() == 1) {
			formInstrucciones->Show();
		}
		else if (juego->colisionMenu() == 2) {
			tmrInicio->Enabled = false;
			tmrNivel1->Enabled = true;
		}
		buffer->Graphics->DrawImage(bmpFondoInicio, 0, 0, panel1->Width, panel1->Height);
		juego->drawEverythingMenu(buffer->Graphics, bmpPersonajePrincipal, bmpPersonajeAncianoMINI);
		//Render
		buffer->Render(g);
	}
	Void tmrNivel1_Tick(Object^ sender, EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);
		//Move & Draw


		//Render
		buffer->Render(g);
	}
	Void form1_KeyDown(Object^ sender, KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter && tmrMenu->Enabled == true) {
			tmrMenu->Enabled = false;
			tmrInicio->Enabled = true;
			
			this->Width = 500;
			this->Height = 500;
			panel1->Width = 490;
			panel1->Height = 470;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			CenterToScreen();
			
		}
		if (tmrInicio) { 
			switch (e->KeyCode)
			{
			case Keys::A:case Keys::Left:
				juego->getMainCharacter()->move(buffer->Graphics, 'A', juego->getObstaculosCasa());
				break;
			case Keys::D:case Keys::Right:
				juego->getMainCharacter()->move(buffer->Graphics, 'D', juego->getObstaculosCasa());
				break;
			case Keys::W:case Keys::Up:
				juego->getMainCharacter()->move(buffer->Graphics, 'W', juego->getObstaculosCasa());
				break;
			case Keys::S:case Keys::Down:
				juego->getMainCharacter()->move(buffer->Graphics, 'S', juego->getObstaculosCasa());
				break;
			}
		}
	}
};
}
