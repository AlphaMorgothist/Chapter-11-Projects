#pragma once
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Enemy {
public:
	Enemy(string &name, int dam = 10);
	void Attack();
	void Attack(int att);
	virtual void MegaAttack();
	virtual void Taunt();
	void DeBuff() { 
		cout << "Debuffing " << m_EneType << endl;
		m_Damage = 20; };
	void Buff() {
		srand(time(NULL));
		int temp = rand() % 30 + 1;
		m_Damage += temp;
	}
protected:
	int m_Damage = 10;
	string m_EneType;
};

class Boss: public Enemy {
public: 
	Boss(string &name, int dam = 15);
	int GetDam() { return m_Damage; }
	string GetName() { return m_EneType; }
	void MegaAttack();
	void Taunt();
	void SetAge();
	void TellAge();
	void IterAge();
private:
	int m_Age;
};