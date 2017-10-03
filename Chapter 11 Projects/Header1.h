#pragma once
#include "Header.h"

class EnemyBeta {
public:
	EnemyBeta(string &name);
	EnemyBeta(EnemyBeta* clone);
	~EnemyBeta();
	virtual void Attack();
protected:
	string m_Name;
	int* m_pDamage;
};

class EnemyOmega : public EnemyBeta {
public:
	EnemyOmega(string &name);
	EnemyOmega(EnemyOmega* cloner);
	~EnemyOmega();
	void Attack();
private:
	int* m_pDamMult;
};