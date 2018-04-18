#ifndef TOWER_H
#define TOWER_H

#include "iostream"
#include <string>
#include <sstream>
#include "Critters.h"
#include  <vector>

/* rlutil header file */
#include "rlutil.h"

using namespace std;

class Strategy {
public:
	virtual int fire(std::vector<Critters>, int);
	virtual void confirm();
};


class Tower{
public: 
	//Tower();
	Tower(string name = "", int r=0, int d=0, double s=0, int v=0, int c=0); //Range, damage, reload speed, value(coins)
	Tower(int); //special tower auto-constructor
	void activate();
	void deactivate();
	string getStatus();
	string getName();
	bool isAlive();
	bool isTowerUpgradable();
	void upgradeTower();
	void setName(string s);
	int getUpgradeStat();
	int getmaxupgrade();
	int getTowerclass();
	void setTowerclass(int z);
	bool enablefireammo();//this one is a bool because it is unlocked later instead of being included with purchase
	void enableiceammo();//Special ammo types unique to certain towers
	void enableSonic();
	void setMaxupgrade(int z);
	int getValue();
	int getMaxRange();
	int getDamage();
	double getReloadSpeed();
	bool hasFireAmmo();
	bool hasIceAmmo();
	bool isSonic(); 
	int getX();
	int getY();
	void setX(int);
	void setY(int);
	void reload();
	void setStrategy(Strategy*);
	bool fire(std::vector<Critters>&, int);

	int getDistanceToCritter(int tx, int ty, int cx, int cy);
	bool isInRange(int tx, int ty, int cx, int cy);

	void setReloadTick(int tick);
	int getReloadTick();
	void setCurrentlyFiring(bool val);
	bool isCurrentlyFiring();
	static int getTowerCost(int tower);

private:
	string name;
	bool alive;
	int upgradeLevel;
	int maxupgrade;
	int maxRange;
	int damage;
	double reloadspeed;
	int towerclass;
	bool fireammo;
	bool iceammo;
	int value;
	bool sonic;
	int xpos;
	int ypos;
	int reloadTick;
	Strategy* strategy; 

	bool currentlyFiring;

	static const int MAX_TOWER_LEVEL = 2;
};

class Vulcan : public Strategy {
public: 
	int fire(std::vector<Critters>, int);
	void confirm();
};

class Cannon : public Strategy {
public: 
	int fire(std::vector<Critters>, int);
	void confirm();
};

class Sniper : public Strategy {
public:
	int fire(std::vector<Critters>, int);
	void confirm();
};

class Sonic : public Strategy {
public:
	int fire(std::vector<Critters>, int);
	void confirm();
};




#endif