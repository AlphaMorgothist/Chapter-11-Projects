#include "stdafx.h"
#include "Header.h"


Enemy::Enemy(string &name, int dam):
	m_EneType(name), m_Damage(dam)
{
	cout << "\nA new enemy, " << m_EneType << " has arrvied" << endl;
}

void Enemy::Attack()
{
	cout << "The enemy " << this->m_EneType << " inflicts " << this->m_Damage << " damage!" << endl;
}

void Enemy::Attack(int att) {
	cout << "The enemy " << this->m_EneType << " inflicts " << att << " damage!" << endl;
}

void Enemy::MegaAttack()
{
}

void Enemy::Taunt()
{
	cout << "\n" << m_EneType << " says: I will defeat you ";
}

Boss::Boss(string &name, int dam):
	Enemy(name, dam)
{

	cout << "A boss has arrived! " << m_EneType << " is preparing for battle" << endl;
}

void Boss::MegaAttack()
{
	cout << "Mega attack!\n";
	int temp = this->m_Damage * 3;
	Attack(temp);
}

void Boss::Taunt()
{
	Enemy::Taunt();
	cout << "and laugh heartily!!" << endl;
}

void Boss::SetAge()
{
	cout << "\nPlease enter a number: ";
	int temp;
	cin >> temp;
	m_Age = temp;
}

void Boss::TellAge()
{
	cout << "Boss Age: " << m_Age << endl;
}

void Boss::IterAge()
{
	m_Age += 1;
}

