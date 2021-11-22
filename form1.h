#pragma once
#include "Controller.h"
#include "FormInstrucciones.h"
#include "MensajeDelAdmin.h"
#include "Leaderboard.h"

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
			label1->Visible = false;

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
			tiempoNivel1 = 60;//////////////////////////////////////////////////////////////////
			mensajedelAdmin = gcnew MensajeDelAdmin();

			//Nivel 2
			bmpFondoNivel2 = gcnew Bitmap("archivos/Nivel2.png");
			bmpCriminal = gcnew Bitmap("archivos/personajes/SSJ.png");
			bmpPotenciador = gcnew Bitmap("archivos/coin.png");

			//Controller
			bmpMensaje = gcnew Bitmap("archivos/mensajePositivo.png");
			juego = new Controller(bmpPersonajePrincipal, bmpPersonajeAncianoMINI, bmpCazador, bmpCriminal, bmpPotenciador, bmpMensaje);
			teclaA = teclaD = teclaW = teclaS = false;

			//Pokemon
			bmpWartortleIcon = gcnew Bitmap("archivos/icons/wartortleIcon.png");
			bmpBulbasaurIcon = gcnew Bitmap("archivos/icons/bulbasaurIcon.png");
			bmpPikachuIcon = gcnew Bitmap("archivos/icons/pikachuIcon.png");
			bmpSnorlaxIcon = gcnew Bitmap("archivos/icons/snorlaxIcon.png");
			bmpPsyduckIcon = gcnew Bitmap("archivos/icons/psyduckIcon.png");

			bmpWartortle = gcnew Bitmap("archivos/pokemon/wartortle.png");
			bmpBulbasaur = gcnew Bitmap("archivos/pokemon/bulbasaur.png");
			bmpPikachu = gcnew Bitmap("archivos/pokemon/pikachu.png");
			bmpSnorlax = gcnew Bitmap("archivos/pokemon/snorlax.png");
			bmpPsyduck = gcnew Bitmap("archivos/pokemon/psyduck4.png");

			//Leaderboard
			file = new File();
			file->readData();
			usuario = new Player("Google", 0, 0);
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
		MensajeDelAdmin^ mensajedelAdmin;
		int tiempoNivel1;

		//Nivel 2
		Bitmap^ bmpFondoNivel2;
		Bitmap^ bmpCriminal;
		Bitmap^ bmpPotenciador;

		//Personaje
		Bitmap^ bmpPersonajePrincipal;

		//Controller
		Controller* juego;
		Bitmap^ bmpMensaje;
		bool teclaA, teclaD, teclaW, teclaS;

		//Pokemons
		Bitmap^ bmpWartortleIcon; 
		Bitmap^ bmpWartortle;
		Bitmap^ bmpBulbasaurIcon;
		Bitmap^ bmpBulbasaur;
		Bitmap^ bmpPikachuIcon;
		Bitmap^ bmpPikachu;
		Bitmap^ bmpSnorlaxIcon;
		Bitmap^ bmpSnorlax;
		Bitmap^ bmpPsyduckIcon;
		Bitmap^ bmpPsyduck;

		//Leaderboard
		Leaderboard^ frLeaderboard;
		File* file;
		Player* usuario;
		int pokemonRescuedUsuario;
		int timeUsuario;


	private: System::Windows::Forms::Timer^ tmrInicio;
	private: System::Windows::Forms::Timer^ tmrNivel1;
	private: System::Windows::Forms::Timer^ tmrMensaje;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ tmrSegundo;
	private: System::Windows::Forms::Timer^ tmrNivel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Timer^ tmrPowerup;



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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tmrInicio = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrNivel1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrMensaje = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrSegundo = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrNivel2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrPowerup = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
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
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1184, 754);
			this->panel1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(500, 501);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(193, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Ingrese su nombre (opcional)";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(488, 531);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(219, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &form1::textBox1_KeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Olive;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(164, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tiempo Restante: 60";
			// 
			// tmrInicio
			// 
			this->tmrInicio->Tick += gcnew System::EventHandler(this, &form1::tmrInicio_Tick);
			// 
			// tmrNivel1
			// 
			this->tmrNivel1->Tick += gcnew System::EventHandler(this, &form1::tmrNivel1_Tick);
			// 
			// tmrMensaje
			// 
			this->tmrMensaje->Interval = 3000;
			this->tmrMensaje->Tick += gcnew System::EventHandler(this, &form1::tmrMensaje_Tick);
			// 
			// tmrSegundo
			// 
			this->tmrSegundo->Interval = 1000;
			this->tmrSegundo->Tick += gcnew System::EventHandler(this, &form1::tmrSegundo_Tick);
			// 
			// tmrNivel2
			// 
			this->tmrNivel2->Tick += gcnew System::EventHandler(this, &form1::tmrNivel2_Tick);
			// 
			// tmrPowerup
			// 
			this->tmrPowerup->Interval = 5000;
			this->tmrPowerup->Tick += gcnew System::EventHandler(this, &form1::tmrPowerup_Tick);
			// 
			// form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1181, 750);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"form1";
			this->Load += gcnew System::EventHandler(this, &form1::form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &form1::form1_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &form1::form1_KeyUp);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
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
			tmrSegundo->Enabled = true;
			label1->Visible = true;
			if (juego->getSecondTime()) {
				juego->setLvl1Again(bmpCazador);
			}
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
		juego->drawEverythingNivle1(buffer->Graphics, bmpPersonajePrincipal, bmpCazador, bmpCriminal, bmpMensaje, tmrMensaje->Enabled);
		juego->drawPokemonIcon(buffer->Graphics, bmpWartortleIcon, bmpBulbasaurIcon, bmpPikachuIcon, bmpSnorlaxIcon, bmpPsyduckIcon);
		juego->drawPokemon(buffer->Graphics, bmpWartortle, bmpBulbasaur, bmpPikachu, bmpSnorlax, bmpPsyduck);
		label1->Text = " Tiempo Restante: " + tiempoNivel1 + "  ";
		//Render
		buffer->Render(g);
		mover();
		if (tiempoNivel1 < 1) {
			timeUsuario = 60 - tiempoNivel1;
			usuario->setPokemonRescued(juego->getPokemonSize());
			usuario->setTime(timeUsuario);
			file->agregarJugador(usuario);
			file->readData();
			file->orderPlayers();
			frLeaderboard = gcnew Leaderboard(gcnew String(usuario->getName().c_str()), timeUsuario, juego->getPokemonSize(), false);
			frLeaderboard->setLeaderBoardNames(file->getPlayers());
			frLeaderboard->Show();
			tmrNivel1->Enabled = false;

			this->Width = 900;
			this->Height = 600;
			panel1->Width = 900;
			panel1->Height = 600;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			CenterToScreen();
			textBox1->Enabled = true;
			textBox1->Visible = true;
			label2->Visible = true;
			label1->Visible = false;
			tmrMenu->Enabled = true;
			tiempoNivel1 = 60;
			tmrSegundo->Enabled = false;
			teclaA = teclaD = teclaS = teclaW = false;
			juego->getMainCharacter()->setMenu();
 			juego->setMenuAgain();
			juego->setSecondTime(true);
		}
		if (juego->getPokemonSize() == 4 && juego->colisionNivel1Terminado()) {
			tmrNivel1->Enabled = false;
			tmrNivel2->Enabled = true;
			this->Width = 900;
			this->Height = 800;
			panel1->Width = 885;
			panel1->Height = 760;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			CenterToScreen();
			juego->changetoNivel2(bmpCazador, bmpCriminal);
			timeUsuario = 60 - tiempoNivel1;
			tiempoNivel1 = 90;
			if (juego->getSecondTime()) {
				juego->setLvl2Again(bmpPotenciador);
			}
		}

	}
	Void tmrNivel2_Tick(Object^ sender, EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);
		//Move & Draw
		buffer->Graphics->DrawImage(bmpFondoNivel2, 0, 0, panel1->Width, panel1->Height);
		juego->drawEverythingNivle2(buffer->Graphics, bmpPersonajePrincipal, bmpCazador, bmpCriminal, bmpPotenciador, bmpMensaje, tmrMensaje->Enabled);
		juego->drawPokemonIcon(buffer->Graphics, bmpWartortleIcon, bmpBulbasaurIcon, bmpPikachuIcon, bmpSnorlaxIcon, bmpPsyduckIcon);
		juego->drawPokemon(buffer->Graphics, bmpWartortle, bmpBulbasaur, bmpPikachu, bmpSnorlax, bmpPsyduck);
		label1->Text = " Tiempo Restante: " + tiempoNivel1 + "  ";
		mover();
		//Colision
		switch (juego->colisionNivel2(buffer->Graphics, tmrPowerup->Enabled))
		{
		case 1:
			tmrPowerup->Enabled = true;
			break;
		case 2:
			tmrMensaje->Enabled = true;
			break;
		case 3:
			timeUsuario += 90 - tiempoNivel1;
			usuario->setPokemonRescued(juego->getPokemonSize());
			usuario->setTime(timeUsuario);
			file->agregarJugador(usuario);
			file->readData();
			file->orderPlayers();
			frLeaderboard = gcnew Leaderboard(gcnew String(usuario->getName().c_str()), timeUsuario, juego->getPokemonSize() + 4, false);
			frLeaderboard->setLeaderBoardNames(file->getPlayers());
			frLeaderboard->Show();
			tmrNivel2->Enabled = false;

			this->Width = 900;
			this->Height = 600;
			panel1->Width = 900;
			panel1->Height = 600;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			CenterToScreen();
			textBox1->Enabled = true;
			textBox1->Visible = true;
			label2->Visible = true;
			label1->Visible = false;
			tmrMenu->Enabled = true;
			tiempoNivel1 = 60;
			tmrSegundo->Enabled = false;
			teclaA = teclaD = teclaS = teclaW = false;
			juego->getMainCharacter()->setMenu();
			juego->setMenuAgain();
			break;
		}
		if (tiempoNivel1 < 1) {
			timeUsuario += 90 - tiempoNivel1;
			usuario->setPokemonRescued(juego->getPokemonSize());
			usuario->setTime(timeUsuario);
			file->agregarJugador(usuario);
			file->readData();
			file->orderPlayers();
			frLeaderboard = gcnew Leaderboard(gcnew String(usuario->getName().c_str()), timeUsuario, juego->getPokemonSize() + 4, false);
			frLeaderboard->setLeaderBoardNames(file->getPlayers());
			frLeaderboard->Show();
			tmrNivel2->Enabled = false;

			this->Width = 900;
			this->Height = 600;
			panel1->Width = 900;
			panel1->Height = 600;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			CenterToScreen();
			textBox1->Enabled = true;
			textBox1->Visible = true;
			label2->Visible = true;
			label1->Visible = false;
			tmrMenu->Enabled = true;
			tiempoNivel1 = 60;
			tmrSegundo->Enabled = false;
			teclaA = teclaD = teclaS = teclaW = false;
			juego->getMainCharacter()->setMenu();
			juego->setMenuAgain();
		}
		if (juego->getPokemonSize() == 5) {
			timeUsuario += 90 - tiempoNivel1;
			usuario->setPokemonRescued(9);
			usuario->setTime(timeUsuario);
			file->agregarJugador(usuario);
			file->readData();
 			file->orderPlayers();
			frLeaderboard = gcnew Leaderboard(gcnew String(usuario->getName().c_str()), timeUsuario, 9, true);
			frLeaderboard->setLeaderBoardNames(file->getPlayers());
			frLeaderboard->Show();
			tmrNivel2->Enabled = false;

			this->Width = 900;
			this->Height = 600;
			panel1->Width = 900;
			panel1->Height = 600;
			buffer = space->Allocate(g, panel1->ClientRectangle);
			CenterToScreen();
			textBox1->Enabled = true;
			textBox1->Visible = true;
			label2->Visible = true;
			label1->Visible = false;
			tmrMenu->Enabled = true;
			tiempoNivel1 = 60;
			tmrSegundo->Enabled = false;
			teclaA = teclaD = teclaS = teclaW = false;
			juego->getMainCharacter()->setMenu();
			juego->setMenuAgain();

		}
		
		//Render
		buffer->Render(g);
	}
	Void form1_KeyDown(Object^ sender, KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter && tmrMenu->Enabled == true) {
			tmrMenu->Enabled = false;
			tmrInicio->Enabled = true;
			string nombrePlayer;

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

		if (e->KeyCode == Keys::Space && tmrNivel1->Enabled) {
			if (juego->colisionNivel1(g, bmpMensaje)) {
				tmrMensaje->Enabled = true;
			}
		}
		if (e->KeyCode == Keys::Space && tmrNivel2->Enabled) {
			juego->setSpaceBar(true);
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
		if (e->KeyCode == Keys::Space && tmrNivel2->Enabled) {
			juego->setSpaceBar(false);
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
		if (tmrNivel2->Enabled) {
			if (teclaA) {
				juego->getMainCharacter()->moveLeft(buffer->Graphics, juego->getObstaculosNivel2());
			}
			if (teclaD) {
				juego->getMainCharacter()->moveRight(buffer->Graphics, juego->getObstaculosNivel2());
			}
			if (teclaW) {
				juego->getMainCharacter()->moveUp(buffer->Graphics, juego->getObstaculosNivel2());
			}
			if (teclaS) {
				juego->getMainCharacter()->moveDown(buffer->Graphics, juego->getObstaculosNivel2());
			}

		}
	}
	Void tmrMensaje_Tick(Object^ sender, EventArgs^ e) {
		tmrMensaje->Enabled = false;
	}
	Void tmrSegundo_Tick(Object^ sender, EventArgs^ e) {
		tiempoNivel1--;
	}
	
	private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter && tmrMenu->Enabled == true && usuario->getTime() != -1) {
		label2->Visible = false;
		
		tmrMenu->Enabled = false;
		tmrInicio->Enabled = true;
		String^ nombrePlayer;
		nombrePlayer = textBox1->Text;
		usuario->setTime(-1);
		if (nombrePlayer == "")
			usuario->setName("Anonimus");
		else usuario->setName(nombrePlayer);

		textBox1->Enabled = false;
		textBox1->Visible = false;

		Form^ fr = gcnew Form();
		fr->Show();
		fr->Close();

		this->Width = 500;
		this->Height = 500;
		panel1->Width = 490;
		panel1->Height = 470;
		buffer = space->Allocate(g, panel1->ClientRectangle);
		CenterToScreen();
		
	}

	
	}
	Void tmrPowerup_Tick(System::Object^ sender, System::EventArgs^ e) {
		tmrPowerup->Enabled = false;
	}
	};
}
