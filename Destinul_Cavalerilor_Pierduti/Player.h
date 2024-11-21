#pragma once
class Player
{
public:
	Player();
	void loseHp(int dmg);
	void setHp(int hp);
	void addGold(int gold);
	int getHp() { return this->hp; }
	int getDmg() { return this->damage; }
private:
	int hp;
	int gold;
	int damage;
};

