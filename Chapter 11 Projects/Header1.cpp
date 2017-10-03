#include "stdafx.h"
#include "Header1.h"

EnemyBeta::EnemyBeta(string &name):
	m_Name(name)
{
	m_pDamage = new int(10);
}

EnemyBeta::EnemyBeta(EnemyBeta* clone):
	m_pDamage(clone->m_pDamage), m_Name(clone->m_Name + " clone")
{
	cout << "An enemy has been cloned: " << m_Name << endl;
	*m_pDamage += 10;
	
}

EnemyBeta::~EnemyBeta()
{
	/*delete m_pDamage;
	m_pDamage = NULL;*/
}

void EnemyBeta::Attack()
{
	cout << "\n" << m_Name << " attacks and does " << *m_pDamage << " damage!" << endl;
}

EnemyOmega::EnemyOmega(string &name):
	EnemyBeta(name)
{
	m_pDamage = new int(25);
	m_pDamMult = new int(1);
}

EnemyOmega::EnemyOmega(EnemyOmega* cloner):
	EnemyBeta(cloner)
{
	m_pDamMult = cloner->m_pDamMult;
}

EnemyOmega::~EnemyOmega()
{

	/*delete m_pDamMult;
	m_pDamMult = NULL;*/
}

void EnemyOmega::Attack()
{
	*m_pDamMult = rand() % 4 + 2;
	int temp = *m_pDamage * *m_pDamMult;
	cout << "\n" << m_Name << " attacks and does " << *m_pDamage << " damage!" << endl;
	cout << "But it's not over! He winds up for a MEGA ATTACK that does " << temp << " damage!!" << endl;

}
