#include "stdafx.h"
#include "Weapons.h"

Weapon::Weapon(const string & name, int dam):
	m_WepName(name), m_Damage(dam)
{
	cout << "A weapon has been spawned: " << m_WepName << endl;
}

void Weapon::Attack()
{
	cout << "This is def" << endl;
}

void Weapon::Reload()
{
}

Sword::Sword(const string &name, int dam):
	Weapon(name, dam)
{
}

void Sword::Attack()
{
	cout << "\nYou swing the " << m_WepName << " and it inflicts " << m_Damage << " damage!" << endl;
}

Crossbow::Crossbow(const string & name, int dam, int ammo):
	Weapon(name, dam), m_Ammo(ammo)
{
}

void Crossbow::Attack()
{
	if (m_Ammo == 1) {
		cout << "Your " << m_WepName << " fires and inflicts " << m_Damage << " damage!" << endl;
		m_Ammo = 0;
	}
	else {
		cout << "Your " << m_WepName << " is not loaded!" << endl;
	}
}

void Crossbow::Reload()
{
	if (m_Ammo <= 0) {
		cout << "\nYou reload your " << m_WepName << endl;
		m_Ammo = 1;
	}
	else {
		cout << "\nYour crossbow is already loaded!" << endl;
	}
}
