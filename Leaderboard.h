#pragma once
#include "File.h"

namespace TFExtinctHero {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Leaderboard
	/// </summary>
	public ref class Leaderboard : public System::Windows::Forms::Form
	{
	public:
		Leaderboard(String^ uname, int t, int p, bool v)
		{
			InitializeComponent();
			label1->Visible = false;
			label2->Visible = false;
			label3->Visible = false;
			label4->Visible = false;
			//Buffer
			g = panel1->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, panel1->ClientRectangle);

			username = uname;
			usertime = t;
			pokemonrescued = p;
			victory = v;

		}
	private: System::Windows::Forms::Timer^ tmrVictory;
	public:
	private: System::Windows::Forms::Timer^ tmrDefeat;

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//User
		String^ username;
		int usertime;
		int pokemonrescued;
		bool victory;

		

		//Leaderboard
		String^ lbn1; int lbt1; int lbp1;
		String^ lbn2; int lbt2; int lbp2;
		String^ lbn3; int lbt3; int lbp3;
		String^ lbn4; int lbt4; int lbp4;
		String^ lbn5; int lbt5; int lbp5;
		String^ lbn6; int lbt6; int lbp6;
		String^ lbn7; int lbt7; int lbp7;
		String^ lbn8; int lbt8; int lbp8;
		String^ lbn9; int lbt9; int lbp9;
		String^ lbn10; int lbt10; int lbp10;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ tmrScreen;
	private: System::Windows::Forms::Timer^ timer;
		   int userPokemon;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Leaderboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::ComponentModel::IContainer^ components;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tmrVictory = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrDefeat = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tmrScreen = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(242, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(275, 60);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Leaderboard";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(54, 140);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(353, 140);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Time";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(567, 140);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(129, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Pokemon Captured";
			// 
			// tmrVictory
			// 
			this->tmrVictory->Interval = 10000;
			this->tmrVictory->Tick += gcnew System::EventHandler(this, &Leaderboard::tmrVictory_Tick);
			// 
			// tmrDefeat
			// 
			this->tmrDefeat->Interval = 6000;
			this->tmrDefeat->Tick += gcnew System::EventHandler(this, &Leaderboard::tmrDefeat_Tick);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(-2, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(824, 579);
			this->panel1->TabIndex = 4;
			// 
			// tmrScreen
			// 
			this->tmrScreen->Enabled = true;
			this->tmrScreen->Tick += gcnew System::EventHandler(this, &Leaderboard::tmrScreen_Tick);
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &Leaderboard::timer_Tick);
			// 
			// Leaderboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(816, 577);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"Leaderboard";
			this->Text = L"Leaderboard";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	Void tmrVictory_Tick(System::Object^ sender, System::EventArgs^ e) {
		tmrVictory->Enabled = false;
		tmrScreen->Enabled = false;
		timer->Enabled = true;
		label1->Visible = true;
		label2->Visible = true;
		label3->Visible = true;
		label4->Visible = true;
	}

	Void tmrDefeat_Tick(System::Object^ sender, System::EventArgs^ e) {
		tmrDefeat->Enabled = false;
		label1->Visible = true;
		label2->Visible = true;
		label3->Visible = true;
		label4->Visible = true;
		buffer->Graphics->Clear(Color::WhiteSmoke);
		buffer->Render();
	}

	private: System::Void tmrScreen_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (!tmrVictory->Enabled) {
			tmrVictory->Enabled = true;
		}
		if (victory) {
			buffer->Graphics->Clear(Color::ForestGreen);
			buffer->Graphics->DrawString("Congrats " + username + ",\nyou won the game in a total\ntime of " 
				+ usertime + " seconds!",
				gcnew Drawing::Font("MV Boli", 25, FontStyle::Bold),
				Brushes::DarkGreen, 60, 150);
		}
		else {
			buffer->Graphics->Clear(Color::Red);
			buffer->Graphics->DrawString("Too bad " + username + ",\nyou lost the game with a total\nof "
				+ pokemonrescued + " pokemon rescued\nBetter luck next time :v",
				gcnew Drawing::Font("MV Boli", 25, FontStyle::Bold),
				Brushes::DarkRed, 40, 120);
		}
		
		buffer->Render();
	}

	public: 
		void setLeaderBoardNames(vector<Player*>leaderboard) {

			lbn1 = gcnew String(leaderboard.at(0)->getName().c_str());
			lbt1 = leaderboard.at(0)->getTime();
			lbp1 = leaderboard.at(0)->getPokemonRescued();
			if (leaderboard.size() >= 2) {
				lbn2 = gcnew String(leaderboard.at(1)->getName().c_str());
				lbt2 = leaderboard.at(1)->getTime();
				lbp2 = leaderboard.at(1)->getPokemonRescued();
			}
			else {
				lbn2 = gcnew String("-");
				lbt2 = 0;
				lbp2 = 0;
			}
			if (leaderboard.size() >= 3) {
				lbn3 = gcnew String(leaderboard.at(2)->getName().c_str());
				lbt3 = leaderboard.at(2)->getTime();
				lbp3 = leaderboard.at(2)->getPokemonRescued();
			}
			else {
				lbn3 = gcnew String("-");
				lbt3 = 0;
				lbp3 = 0;
			}
			if (leaderboard.size() >= 4) {
				lbn4 = gcnew String(leaderboard.at(3)->getName().c_str());
				lbt4 = leaderboard.at(3)->getTime();
				lbp4 = leaderboard.at(3)->getPokemonRescued();
			}
			else {
				lbn4 = gcnew String("-");
				lbt4 = 0;
				lbp4 = 0;
			}
			if (leaderboard.size() >= 5) {
				lbn5 = gcnew String(leaderboard.at(4)->getName().c_str());
				lbt5 = leaderboard.at(4)->getTime();
				lbp5 = leaderboard.at(4)->getPokemonRescued();
			}
			else {
				lbn5 = gcnew String("-");
				lbt5 = 0;
				lbp5 = 0;
			}
			if (leaderboard.size() >= 6) {
				lbn6 = gcnew String(leaderboard.at(5)->getName().c_str());
				lbt6 = leaderboard.at(5)->getTime();
				lbp6 = leaderboard.at(5)->getPokemonRescued();
			}
			else {
				lbn6 = gcnew String("-");
				lbt6 = 0;
				lbp6 = 0;
			}
			if (leaderboard.size() >= 7) {
				lbn7 = gcnew String(leaderboard.at(6)->getName().c_str());
				lbt7 = leaderboard.at(6)->getTime();
				lbp7 = leaderboard.at(6)->getPokemonRescued();
			}
			else {
				lbn7 = gcnew String("-");
				lbt7 = 0;
				lbp7 = 0;
			}
			if (leaderboard.size() >= 8) {
				lbn8 = gcnew String(leaderboard.at(7)->getName().c_str());
				lbt8 = leaderboard.at(7)->getTime();
				lbp8 = leaderboard.at(7)->getPokemonRescued();
			}
			else {
				lbn8 = gcnew String("-");
				lbt8 = 0;
				lbp8 = 0;
			}
			if (leaderboard.size() >= 9) {
				lbn9 = gcnew String(leaderboard.at(8)->getName().c_str());
				lbt9 = leaderboard.at(8)->getTime();
				lbp9 = leaderboard.at(8)->getPokemonRescued();
			}
			else {
				lbn9 = gcnew String("-");
				lbt9 = 0;
				lbp9 = 0;
			}
			if (leaderboard.size() >= 10) {
				lbn10 = gcnew String(leaderboard.at(9)->getName().c_str());
				lbt10 = leaderboard.at(9)->getTime();
				lbp10 = leaderboard.at(9)->getPokemonRescued();
			}
			else {
				lbn10 = gcnew String("-");
				lbt10 = 0;
				lbp10 = 0;
			}
		}
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		buffer->Graphics->Clear(this->label1->BackColor);
		
		buffer->Graphics->DrawString(
			lbn1 + "\n\n" +
			lbn2 + "\n\n" +
			lbn3 + "\n\n" +
			lbn4 + "\n\n" +
			lbn5 + "\n\n" +
			lbn6 + "\n\n" +
			lbn7 + "\n\n" +
			lbn8 + "\n\n" +
			lbn9 + "\n\n" +
			lbn10,
			gcnew Drawing::Font("Microsoft Sans Serif", 10, FontStyle::Regular),
			Brushes::Black, 30, 140);

		buffer->Graphics->DrawString(
			lbt1 + "\n\n" +
			lbt2 + "\n\n" +
			lbt3 + "\n\n" +
			lbt4 + "\n\n" +
			lbt5 + "\n\n" +
			lbt6 + "\n\n" +
			lbt7 + "\n\n" +
			lbt8 + "\n\n" +
			lbt9 + "\n\n" +
			lbt10,
			gcnew Drawing::Font("Microsoft Sans Serif", 10, FontStyle::Regular),
			Brushes::Black, 270, 140);

		buffer->Graphics->DrawString(
			lbp1 + "\n\n" +
			lbp2 + "\n\n" +
			lbp3 + "\n\n" +
			lbp4 + "\n\n" +
			lbp5 + "\n\n" +
			lbp6 + "\n\n" +
			lbp7 + "\n\n" +
			lbp8 + "\n\n" +
			lbp9 + "\n\n" +
			lbp10,
			gcnew Drawing::Font("Microsoft Sans Serif", 10, FontStyle::Regular),
			Brushes::Black, 470, 140);

		buffer->Render();
	}
	};
}
