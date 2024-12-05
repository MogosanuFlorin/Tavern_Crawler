#pragma once
class Player
{
public:
	Player();
	void loseHp(int dmg);
	void setHp(int hp);
	void setDmg(int dmg);
	void setGold(int gold);
	void addGold(int gold);
	int getHp() { return this->hp; }
	int getDmg() { return this->damage; }
	int getGold() { return this->gold; }
private:
	int hp;
	int gold;
	int damage;
};

