#ifndef CRITTERS_H_
#define CRITTERS_H_


#include <string>

class Critters {

public:
	//default constructor
	Critters();

	//Constructor to create a Critter
	Critters(int level, int hitpoints, int strenght, int speed, int reward);

	//Destructor
	virtual ~Critters();

	//Accessors
	int getLevel();
	int getHP();
	int getStrength();
	int getSpeed();
	int getReward();
	int getX();
	int getY();
	int getLastX();
	int getLastY();
	int getTimeTillMove();
	int getColour();
	bool isAlive();
	std::string getName();
	int getProgress();

	//Mutators
	void setLevel(int set);
	void setHP(int set);
	void setStrenght(int set);
	void setSpeed(int set);
	void setReward(int set);
	void setName(std::string set);
	void setX(int x);
	void setY(int y);
	void setLastX(int x);
	void setLastY(int y);
	void setTimeTillMove(int t);
	void setColour(int c);
	void setAlive(bool a);
	void incrementProgress();

	//chooses the level
	void critterAttributes();
	
	//critter get's shot(the paramater is for the different type of tower)
	void gotShot(Critters* crit);
	
	//if the critter is dead
	bool isDead();

	//kills critter
	void deleteCrit();

	//prints critter info
	void printInfo();

	//damages a critter by removing HP
	void inflictDamage(int);


protected:

	int HP;
	int reward;
	int strength;	
	int speed; 
	int level;
	int x;
	int y;
	int lastX;
	int lastY;
	int moveTime;
	int colour;
	int progress;
	bool critterAlive;
	std::string name;

};


#endif


