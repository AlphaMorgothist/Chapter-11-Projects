#pragma once
#include "Nim.h"
#include <Windows.h>

void initEn(bool on) {
	const int MAX_ENEMY = 2;
	string temp1 = "Droidikar";
	Enemy* en1 = new Enemy(temp1);
	string temp2 = "Droidiking";
	Boss* bs1 = new Boss(temp2);
	Enemy* en2 = bs1;
	Enemy* list[2] = { en1, en2 };
	list[0]->Taunt();
	cout << endl;
	list[1]->Taunt();
	cin.ignore();
	if (on == false) {
		delete en1;
		delete bs1;
		en2 = NULL;
		for (int i = 0; i < MAX_ENEMY; i++)
		{
			list[i] = NULL;
		}
	}
}

void wepInit() {
	string nameS = "Excalihoe";
	string nameC = "Crossd'Hoe";
	Sword* excal = new Sword(nameS, 10);
	Crossbow* hoe = new Crossbow(nameC, 15);
	Weapon* list[2] = { excal, hoe };
	bool quit = false;
	while (quit == false) {
		cout << endl;
		cout << "Please chose an option " << endl;
		cout << "\n1:Swing sword" << endl;
		cout << "2:Fire crossbow" << endl;
		cout << "3:Reload crossbow" << endl;
		cout << "0:Quit" << endl;
		int temp;
		cout << "\nChoice: ";
		cin >> temp;
		system("CLS");
		switch (temp) {
		default:break;
		case 1: {list[0]->Attack(); }break;
		case 2: {list[1]->Attack(); }break;
		case 3: {list[1]->Reload(); }break;
		case 0: { quit = true;
			break; }break;
		}
	}
}

void TwoPlayer() {
	cin.ignore();
	cout << "\nEnter two player names" << endl;
	cout << "\nPlayer One: ";
	string temp1;
	getline(cin, temp1);
	Human *h1 = new Human(temp1);
	//cin.ignore();
	cout << "\nPlayer Two: ";
	getline(cin, temp1);
	Human *h2 = new Human(temp1);
	//cin.ignore();
	Pile *stick = new Pile();
	stick->SetSticks();
	cin.ignore();
	while (true) {
		system("CLS");
		cout << "Sticks left: " << stick->GetSticks() << endl;
		stick->RemSticks(h1, h1->StickPrompt());
		if (stick->GetSticks() <= 0) {
			cout << h1->GetName() << " has won!!" << endl;
			system("pause");
			break;
		}
		system("CLS");
		cout << "Sticks left: " << stick->GetSticks() << endl;
		stick->RemSticks(h2, h2->StickPrompt());
		if (stick->GetSticks() <= 0) {
			cout << h2->GetName() << " has won!!" << endl;
			system("pause");
			break;
		}
	}
	delete stick;
	stick = NULL;
	delete h1;
	h1 = NULL;
	delete h2;
	h2 = NULL;
}

void VsAI() {
	cin.ignore();
	cout << "\nPlease enter your name: ";
	string temp;
	string comp = "Computer";
	getline(cin, temp);
	Human *H = new Human(temp);
	Computer *AI = new Computer(comp);
	Pile *stick = new Pile();
	stick->SetSticks();
	cin.ignore();
	while (true) {
		system("CLS");
		
		cout << "Sticks left: " << stick->GetSticks() << endl;
		stick->RemSticks(AI, AI->StickPrompt(stick));
		if (stick->GetSticks() <= 0) {
			cout << AI->GetName() << " has won!!" << endl;
			system("pause");
			break;
		}
		cout << endl;
		cout << "Sticks left: " << stick->GetSticks() << endl;
		stick->RemSticks(H, H->StickPrompt());
		if (stick->GetSticks() <= 0) {
			cout << H->GetName() << " has won!!" << endl;
			system("pause");
			break;
		}
		system("pause");
	}

}

void runProj1(){
	string nameE = "Battle Droid";
	Enemy* En1 = new Enemy(nameE, 15);
	string nameb = "Mega Bot";
	Boss* boss1 = new Boss(nameb, 30);
	boss1->SetAge();
	while (true) {

		cout << endl;
		En1->Attack();
		boss1->Attack();
		cout << endl;
		boss1->MegaAttack();
		cout << endl;
		boss1->Buff();
		int dam = boss1->GetDam();
		string name = boss1->GetName();
		cout << "Name: " << name << endl;
		boss1->TellAge();
		cout << "Damage: " << dam << endl;
		char resp;
		cout << "\nDo it again? (y/n):";
		cin >> resp;
		if (resp == 'n' || resp == 'N') {
			break;
		}
		else {
			//boss1->DeBuff();
			boss1->IterAge();
			system("CLS");
		}
	}
}

void runProj2() {
	initEn(false);
}

void runProj3() {
	string name = "Jim";
	string boss = "Yohimbu";
	EnemyBeta* en1 = new EnemyBeta(name);
	EnemyOmega* en2 = new EnemyOmega(boss);
	EnemyBeta* list[2] = { en1, en2 };
	list[0]->Attack();
	list[1]->Attack();
	cout << endl;
	EnemyBeta* en3 = new EnemyBeta(en1);
	cout << endl;
	EnemyOmega* en4 = new EnemyOmega(en2);
	en3->Attack();
	en4->Attack();
	cin.ignore();
	delete en1;
	delete en2;
	en1 = NULL;
	en2 = NULL;
}

void runProj4() {
	wepInit();

}

void runProj5() {
	cout << "\nPlease choose a game mode" << endl;
	cout << "1:Two players" << endl;
	cout << "2:Vs AI" << endl;
	cout << "\nChoice: ";
	int pick;
	cin >> pick;
	switch (pick) {
	case 1: {TwoPlayer(); }break;
	case 2: {VsAI(); }break;
	}
	}

void chapOptions() {
	cout << "\n\tChapter 11 Projects" << endl;
	cout << "\n0: Quit" << endl;
	cout << "1: [Project 11.1] Enemy/Boss Inheritence" << endl;
	cout << "2: [Project 11.2] ";
}

int getInput() {
	cout << "\nPlease make a choice" << endl;
	cout << "Choice: ";
	int choice;
	cin >> choice;
	system("CLS");
	return choice;
}

void runSwitch(int select) {
	switch (select)
	{
	default:
		break;
	case 1: {runProj1(); }break;
	case 2: {runProj2(); }break;
	case 3: {runProj3(); }break;
	case 4: {runProj4(); }break;
	case 5: {runProj5(); }break;
	}
}



