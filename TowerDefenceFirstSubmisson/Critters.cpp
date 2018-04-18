// Critters.cpp : Defines the entry point for the console application.
//


#include "Critters.h"
#include <iostream>

using namespace std;
//Constructors
//Critters::Critters(int HP, int reward, int strength, int speed, int level)
//:HP(HP), reward(reward), strength(strength), speed(speed), level(level){progress=0; strength=HP;};

Critters::Critters() {

	critterAttributes();

};

//destructor
Critters::~Critters(){}


//defining the accessors
int Critters::getHP(){ return HP; };
int Critters::getLevel(){ return level; };
int Critters::getReward(){ return reward; };
int Critters::getSpeed(){ return speed; };
int Critters::getStrength(){ return strength; };
int Critters::getX(){ return x; };
int Critters::getY(){ return y; };
int Critters::getLastX(){ return lastX; };
int Critters::getLastY(){ return lastY; };
int Critters::getTimeTillMove(){ return moveTime; };
int Critters::getColour(){ return colour; };
std::string Critters::getName(){ return name; };
int Critters::getProgress() { return progress; };
bool Critters::isAlive() { return critterAlive; };

//defining mutators
void Critters::setHP(int HP) { this->HP = HP; };
void Critters::setLevel(int level) { this->level = level; };
void Critters::setReward(int reward) { this->reward = reward; };
void Critters::setSpeed(int speed) { this->speed = speed; };
void Critters::setStrenght(int strength) { this->strength = strength; };
void Critters::setName(std::string name) { this->name = name; };
void Critters::setX(int x) { this->x = x; };
void Critters::setY(int y) { this->y = y; };
void Critters::setLastX(int x) {lastX = x; };
void Critters::setLastY(int y) {lastY = y; };
void Critters::setTimeTillMove(int t) {moveTime = t; };
void Critters::setColour(int c) {colour = c; };
void Critters::setAlive(bool a) {critterAlive = a; };


//prints critter info
void Critters::printInfo(){

	cout << getName() << endl;
	cout << "   Level = " << getLevel() << endl;
	cout << "   HP = " << getHP() << endl;
	cout << "   Speed = " << getSpeed() << "\n" << endl;

}

void Critters::inflictDamage(int amount)
{

		HP -= amount; 

		//if (HP <= 0) 
		//{
		//	critterAlive=false;
		//}

} 
void Critters::incrementProgress(){progress+=1;}


//if the critter is dead
bool Critters::isDead(){

	if (getHP() <= 0)
		return true;

	return false;
}

//kill critter
void Critters::deleteCrit(){
	
	setLevel(NULL);
	setHP(NULL);
	setSpeed(NULL);
	setReward(NULL);
	setX(NULL);
	setY(NULL);
}


//Setting the attributes of the critters
void Critters::critterAttributes(){
	int choose = rand() % 5 + 1;

	switch (choose)
	{
		case 1:
			setLevel(1);
			setHP(10);
			setStrenght(10);
			setSpeed(2);
			setReward(10);
			break;
		case 2:
			setLevel(2);
			setHP(15);
			setStrenght(15);
			setSpeed(2);
			setReward(20);
			break;
		case 3:
			setLevel(3);
			setHP(20);
			setStrenght(20);
			setSpeed(3);
			setReward(25);
			break;
		case 4:
			setLevel(4);
			setHP(25);
			setStrenght(25);
			setSpeed(3);
			setReward(25);
			break;
		case 5:
			setLevel(5);
			setHP(30);
			setStrenght(30);
			setSpeed(5);
			setReward(40);
			break;

	}

	int randomColour = rand() % 8 + 1;
	setColour(randomColour);
	progress = 0;

	setX(0);
	setY(0);
	setLastX(-1);
	setLastY(-1);

	setAlive(true);

}
