
// Towers.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include "Tower.h"

//#include "crittersX.h"
using namespace std;

Tower::Tower(string name, int r, int d, double s, int v, int t):name(name),maxRange(r),damage(d),reloadspeed(s),value(v),towerclass(t){
	alive=false;
	maxupgrade=3;
	reloadTick=0;
	currentlyFiring = false;
}

Tower::Tower(int type){ //special tower autoconstructor
	towerclass = type;
	switch (type){
	case 1:{
		name = "Basic Tower";
		maxRange = 3;
		damage = 2;
		value = 50;
		reloadspeed = 2.0;
		setStrategy(new Vulcan());
		break;
		   }
	case 2:{
		name = "Arrow Tower";
		maxRange = 2;
		damage = 4;
		value = 75;
		reloadspeed = 3.0;
		setStrategy(new Cannon());
		break;
		   }
	case 3:{
		name = "Ninja Tower";
		maxRange = 6;
		damage = 4;
		value = 100;
		reloadspeed = 3.0;
		setStrategy(new Cannon());
		break;
		   }
	case 4:{
		name = "Energy Tower";
		maxRange = 8;
		damage = 5;
		value = 120;
		reloadspeed = 10.0;
		setStrategy(new Sniper());
		break;
		   }
	default: {
		name = "Plastic Tower - DEFAULT TOWER NAME (report this as a bug)";
		maxRange = 1;
		damage = 1;
		value = 0;
		break;
			 }	
	}
	reloadTick = reloadspeed;
	upgradeLevel = 0;
}

string Tower::getStatus(){if(alive)return name; else return "disabled";}
string Tower::getName(){return name;}
void Tower::activate(){alive=true;cout<<name<<"> ONLINE\n";}
void Tower::deactivate(){alive=false;}
bool Tower::isAlive(){return alive;}
int Tower::getValue(){return value;}
int Tower::getDamage(){return damage;}
int Tower::getMaxRange(){return maxRange;}
int Tower::getX(){return xpos;}
int Tower::getY(){return ypos;}
void Tower::setX(int x){xpos=x;}
void Tower::setY(int y){ypos=y;}
int Tower::getTowerclass(){return towerclass;}
double Tower::getReloadSpeed(){return reloadspeed;}
int Tower::getUpgradeStat(){return upgradeLevel;}

void Tower::setReloadTick(int tick) {reloadTick = tick; }
int  Tower::getReloadTick() {return reloadTick; }
void Tower::setCurrentlyFiring(bool val) {currentlyFiring = val; }
bool Tower::isCurrentlyFiring(){return currentlyFiring;}

//////////////////////////////////////////////////////////////////////New code for demo
//void Tower::reload(){if(reloadTick<reloadspeed)reloadTick+=1;}//If reload is necessary, reload
void Tower::reload(){reloadTick+=1;}//reload

//void Tower::fire(Critters target, int nbcritters){
//	reload();
//	double distancefromtower=0;
//	for (int i=0; i<nbcritters; i++){ //acquiring targets
//		distancefromtower = sqrt(pow((xpos-target[i].getX()),2)+(pow((ypos-target[i].getY()),2))); //distance formula
//		if(distancefromtower>getMaxRange()){}//cout<<"Target "<<i+1<<" is out of range\n";
//		else 
//		{
//			if (reloadtick>=reloadspeed)
//				target[i].gotshot(damage);
//			break;
//		}
//
//	}
//}


//bool Tower::fire(int cx, int cy){
//	double distancefromtower=0;
//	distancefromtower = sqrt(pow((xpos-(cx)),2)+(pow((ypos-(cy)),2)));
//	if (distancefromtower <maxrange) 
//		return true;
//	else
//		return false;
//}

bool Tower::fire(std::vector<Critters> &targets, int size)
{ 

	reload();

	if (reloadTick >= reloadspeed)
	{

		std::vector<Critters> targetsInRange; //Critters in range of the tower
		targetsInRange.resize(size);
		double distanceFromTower = 0;
		int bestTarget = 0; //the strategy determines the best target
		bool anyInRange=false;

		for (int t=0; t<size; t++)
		{

			distanceFromTower = sqrt(pow((xpos-(targets[t].getX())),2)+(pow((ypos-(targets[t].getY())),2))); //distance formula

			if (distanceFromTower < maxRange)
			{
				if (targets[t].isAlive())
				{
					if (targets[t].getProgress() > 0)
					{
						targetsInRange[t] = targets[t];
						anyInRange = true;
					}
				}
			}
		}

		if (anyInRange == false)
		{
			return false;
		}
		else 
		{
			bestTarget = this->strategy->fire(targetsInRange, size); //stratagy determines the best target
			targets[bestTarget].inflictDamage(damage); 
			currentlyFiring = true;
			reloadTick = 0;
			return true; 
		}
	}
	else 
	{
		currentlyFiring = false;
		return false;
	}
}
/*
void Tower::fire(int nbcritters)
{

reload();

double distancefromtower=0;
CrittersX target;

//acquiring targets
for (int i=0; i<nbcritters; i++)
{	

//distancefromtower = sqrt(pow((xpos-target[i].getX()),2)+(pow((ypos-target[i].getY()),2))); //distance formula
distancefromtower = sqrt(pow((xpos-target.getX()),2)+(pow((ypos-target.getY()),2))); //distance formula

//if(distancefromtower>getMaxRange())
if(distancefromtower > maxrange)
{
//cout <<"Target " << i+1 << " is out of range\n";
gotoxy(1,15); std::cout << "Target " << i+1 << " is out of range\n";
}
else 
{

if (reloadtick>=reloadspeed)
{
//target[i].gotshot(damage);
target.gotshot(damage);
}

break;
}

}
}
*/

/*BasicTower::BasicTower(string name, int r, int d, double s, int v, int t):name(name),maxrange(r),damage(d),reloadspeed(s),value(v),towerclass(t){
alive=false;
maxupgrade=3;
reloadtick=0;
}
*/
void Tower::setStrategy(Strategy *newStrategy){
	this->strategy = newStrategy;
}

int Vulcan::fire(std::vector<Critters> test, int size)
{
	//cout << "This strategy fires on the critter with the lowest amount of health\n";
	int weakest = 0;
	int weakesthealth = 99999;
	int testhealth = 0;
	for (int t=0; t<size; t++){
		testhealth = test[t].getHP();
		if(testhealth<weakesthealth){
			weakest = t;
			weakesthealth = testhealth;
		}
	}
	return weakest;
}
void Vulcan::confirm()
{
	cout << "Adopting Vulcan strategy\n";
}

int Cannon::fire(std::vector<Critters> test, int size)
{
	//cout << "This strategy fires on the strongest critter regardless of health\n";
	int strongest = 0;
	int strongeststrength = 0;
	int teststrength = 0;
	for (int t=0; t<size; t++){
		teststrength = test[t].getStrength();
		if(teststrength>strongeststrength){
			strongest = t;
			strongeststrength = teststrength;
		}
	}
	return strongest;return 0;
}
void Cannon::confirm()
{
	cout << "Adopting Cannon strategy\n";
}


int Sniper::fire(std::vector<Critters> test, int size)
{
	//cout << "This strategy fires on the critter closest to the goal\n";
	int farthest = 0;
	int farthestprogress = 0;
	int testprogress = 0;
	for (int t=0; t<size; t++){
		testprogress = test[t].getProgress();
		if(testprogress>farthestprogress){
			farthest = t;
			farthestprogress = testprogress;
		}
	}
	return farthest;return 0;
}
void Sniper::confirm()
{
	cout << "Adopting Sniper strategy\n";
}

int Sonic::fire(std::vector<Critters> test, int size)
{
	cout << "This tower deals damage to all surrounding targets\n";
	return 0;
}
void Sonic::confirm()
{
	cout << "Equipped with Sonic weapon\n";
}


int Strategy::fire(std::vector<Critters> test, int size)
{
	cout << "Default strategy, fires at the nearest critter\n";
	return 0;
}
void Strategy::confirm()
{
	cout << "Adopting no strategy\n";

}


int Tower::getDistanceToCritter(int towerX, int towerY, int critterX, int critterY)
{

	//Distance Formula
	int distanceToCritter = sqrt( pow(towerX - critterX, 2) + pow(towerY - critterY, 2) ); 

	return distanceToCritter;

}

bool Tower::isInRange(int towerX, int towerY, int critterX, int critterY)
{

	int distanceToCritter = getDistanceToCritter(towerX, towerY, critterX, critterY);

	if (distanceToCritter < maxRange)
	{	
		return true;
	}

	return false;
}

bool Tower::isTowerUpgradable()
{

	if ( upgradeLevel >= MAX_TOWER_LEVEL )
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Tower::upgradeTower()
{
	name+="+";
	upgradeLevel++;
	maxRange++;
	damage += 1;
	value *= 1.5;

}

int Tower::getTowerCost(int tower)
{

	int towerCost;

	switch (tower)
	{
	case 1:
		{
			towerCost = 50;		//TODO: Change to Variable
			break;
		}
	case 2:
		{
			towerCost = 75;		//TODO: Change to Variable
			break;
		}
	case 3:
		{
			towerCost = 100;	//TODO: Change to Variable
			break;
		}
	case 4:
		{
			towerCost = 120;	//TODO: Change to Variable
			break;
		}
	}


	return towerCost;
}
