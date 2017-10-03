#include "stdafx.h"
#include "Nim.h"

NimPlayer::NimPlayer(string & name):
	m_Name(name)
{
}

string NimPlayer::GetName()
{
	return m_Name;
}

int NimPlayer::StickPrompt()
{
	return 0;
}

Human::Human(string &name):
	NimPlayer(name)
{
}

int Human::StickPrompt()
{
	int temp;
	while (true) {
		cout << "Player: " << m_Name << endl;
		cout << "\nPick a number of sticks to remove from the pile (1-4)" << endl;
		cout << "Choice: ";
		cin >> temp;
		if (temp > 4 || temp < 0) {
			cout << "Invalid choice" << endl;
		}
		else {
			return temp;
		}
	}
	return 0;
}

int Pile::GetSticks()
{
	return m_Sticks;
}

void Pile::SetSticks()
{
	srand(time(NULL));
	cout << "\nNumber of sticks to play with: ";
	int temp;
	cin >> temp;
	if (temp > 4) {
		m_Sticks = temp * (rand() % 2 + 1);
	}
	else {
		m_Sticks = rand() % 50 + 13;
	}
}

void Pile::RemSticks(NimPlayer *player, int rem)
{
	cout << "Player " << player->GetName() << " removes " << rem << " sticks from the pile" << endl;
	m_Sticks -= rem;
}

Computer::Computer(string & name):
	NimPlayer(name)
{
}

int Computer::StickPrompt(Pile *pile)
{
	int calc = pile->GetSticks();
	if (calc <= 4) {
		return 4;
	}
	else if (calc % 4 == 1) {
		return 1;
	}
	else if (calc % 4 == 2) {
		return 1;
	}
	else if (calc % 4 == 3) {
		return 2;
	}
	else if (calc % 4 == 0) {
		return 3;
	}
}
