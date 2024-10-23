#include <iostream>
#include "caracter.h"

caracter::caracter()
{
	life = 100;
	gold = 0;
	damage = 10;
}

void caracter::loseLife(int dmg)
{
	life -= dmg;
}