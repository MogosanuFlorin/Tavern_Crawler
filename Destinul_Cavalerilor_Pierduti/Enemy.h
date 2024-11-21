#pragma once
class Enemy
{
public:
	Enemy();
	Enemy(int hp, int dmg, int gold);
	int getHp() const;
	int getDmg() const;
	int getGoldDrop() const;
	void setHp(int hp);
	void setDmg(int dmg);
	void setGoldDrop(int goldDrop);
private:
	int hp;
	int dmg;
	int goldDrop;
};

