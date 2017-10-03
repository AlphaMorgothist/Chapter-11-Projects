#pragma once
#include "Header1.h"

class Weapon {
public: 
	Weapon(const string &name, int dam);
	virtual void Attack();
	virtual void Reload();
protected:
	string m_WepName;
	int m_Damage;
};

class Sword : public Weapon {
public:
	Sword(const string &name, int dam);
	void Attack();
};

class Crossbow : public Weapon {
public:
	Crossbow(const string&name, int dam, int ammo = 0);
	void Attack();
	void Reload();
private:
	int m_Ammo;
};