#pragma once

#include<vector>
#include<functional>
#include <string>

#include"logic/Item.h"

class Hero {
public:
	Hero() = default;
	~Hero() = default;

public:
	std::string name;
	unsigned int HP, HP_Limit; //Ѫ
	unsigned int MP, MP_Limit; //��
	unsigned int AD, /* ������ */
		AP,/* ����ǿ�� */
		AC,/* ���� */
		PC,/* ħ�� */
		Le,/*�ȼ�*/
		Exp,/*��ǰ����*/
		Gold
		;
	Item Bag[6] {};//װ����

	std::vector<Item> Items;//����
	bool AI = false;

public:
	int GetAD();
	int GetAP();
	int GetAC();
	int GetPC();

public:
	virtual void Action() = 0;
};

class AI: public Hero {
public:
	AI() {
		Hero::AI = true;
	}
public:
	void Action() override;
};

class Player: public Hero {
public:
	Player() {
		Hero::AI = false;
	}
public:
	void Action() override;

public:
	std::function<void()> ShowTable;
};