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
			srand(time(NULL));
			//Tamaño del forms
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

			//Nivel 1
			bmpFondoNivel1 = gcnew Bitmap("archivos/Nivel1/Nivel1.png");
			bmpCazador = gcnew Bitmap("archivos/personajes/personajeblancoYrojo.png");

			//Controller
			juego = new Controller(bmpPersonajePrincipal, bmpPersonajeAncianoMINI, bmpCazador);
			teclaA = teclaD = teclaW = teclaS = false;
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

		//Nivel 1
		Bitmap^ bmpFondoNivel1;
		Bitmap^ bmpCazador;

		//Personaje
		Bitmap^ bmpPersonajePrincipal;

		//Controller
		Controller* juego;
		bool teclaA, teclaD, teclaW, teclaS;


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
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1184, 754);
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
			this->ClientSize = System::Drawing::Size(1181, 753);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"form1";
			this->Load += gcnew System::EventHandler(this, &form1::form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &form1::form1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &form1::form1_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: Void form1_Load(Object^ sender, EventArgs^ e) {
		//this->Width = 800;									   //
		//this->Height = 800;									   //
		//panel1->Width = 790;								   //
		//panel1->Height = 760;								   // Aqui se modifica
		//buffer = space->Allocate(g, panel1->ClientRectangle);  // para empezar en
		//CenterToScreen();									   // el inicio o en el
		//juego->getMainCharacter()->setNivel1();				   // nivel 1
		//tmrInicio->Enabled = false;							   //
		//tmrMenu->Enabled = false;							   //
		//tmrNivel1->Enabled = true;							   //
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
			teclaA = false;
			teclaD = false;
			teclaW = false;
			teclaS = false;
			formInstrucciones->Show();
		}
		else if (juego->colisionMenu() == 2) {
			this->Width = 800;
			this->Height = 800;
			panel1->Width = 790;
			panel1->Height = 760;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			CenterToScreen();
			juego->getMainCharacter()->setNivel1();
			juego->changetoNivel1();
			tmrInicio->Enabled = false;
			tmrNivel1->Enabled = true;
		}
		buffer->Graphics->DrawImage(bmpFondoInicio, 0, 0, panel1->Width, panel1->Height);
		juego->drawEverythingMenu(buffer->Graphics, bmpPersonajePrincipal, bmpPersonajeAncianoMINI);
		//Render
		buffer->Render(g);
		mover();
	}
	Void tmrNivel1_Tick(Object^ sender, EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);
		//Move & Draw
		buffer->Graphics->DrawImage(bmpFondoNivel1, 0, 0, panel1->Width, panel1->Height);
		juego->drawEverythingNivle1(buffer->Graphics, bmpPersonajePrincipal, bmpCazador);
		//Render
		buffer->Render(g);
		mover();
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
		
		if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left) {
			teclaA = true;
		}
		if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right) {
			teclaD = true;
		}
		if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up) {
			teclaW = true;
		}
		if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down) {
			teclaS = true;
		}
		
		
	}
	Void form1_KeyUp(Object^ sender, KeyEventArgs^ e) {
		if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left) {
			teclaA = false;
		}
		if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right) {
			teclaD = false;
		}
		if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up) {
			teclaW = false;
		}
		if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down) {
			teclaS = false;
		}
	}
	void mover() {
		if (tmrInicio->Enabled) {
			if (teclaA) {
				juego->getMainCharacter()->moveLeft(buffer->Graphics, juego->getObstaculosCasa());
			}
			if (teclaD) {
				juego->getMainCharacter()->moveRight(buffer->Graphics, juego->getObstaculosCasa());
			}
			if (teclaW) {
				juego->getMainCharacter()->moveUp(buffer->Graphics, juego->getObstaculosCasa());
			}
			if (teclaS) {
				juego->getMainCharacter()->moveDown(buffer->Graphics, juego->getObstaculosCasa());
			}
		}
		if (tmrNivel1->Enabled) {
			if (teclaA) {
				juego->getMainCharacter()->moveLeft(buffer->Graphics, juego->getObstaculosNivel1());
			}
			if (teclaD) {
				juego->getMainCharacter()->moveRight(buffer->Graphics, juego->getObstaculosNivel1());
			}
			if (teclaW) {
				juego->getMainCharacter()->moveUp(buffer->Graphics, juego->getObstaculosNivel1());
			}
			if (teclaS) {
				juego->getMainCharacter()->moveDown(buffer->Graphics, juego->getObstaculosNivel1());
			}
		}
	}
};
}
