#ifndef COREGAME_H_INCLUDED
#define COREGAME_H_INCLUDED

    /* ‘CoreGame.h’ */

    /* Windows standard header file */
    #include <windows.h>
    /* Standard input/output header file */
    #include <stdio.h>
	#include <vector>

    /* rlutil header file */
    #include "rlutil.h"
    /* Player header file */
    #include "Player.h"

    /* Tower header file */
    #include "Tower.h"

	/* Critter header file */
	#include "Critters.h"

	/* Map header file */
	#include "Map.h"


    /* Game base class */
    class CoreGame
    {

        public:

            /* Constructors */
            CoreGame();

			//Destructor
			~CoreGame();

			//void setVars();
			void initHud();
			void initialiseGame();
			void updateGame();
			void drawGame();

			void playerUpdate();		//This is where the Player's input is updated
			void crittersUpdate();		//This is where the Critters get Updated		(Movement)
			void towersUpdate();		//This is where the Towers get Updated			(Firing)
			void drawHud();				//This is where the HUD gets Drawn				(Heads Up Display)
			void checkGameStatus();		//This is where the Game checks if the Player has Won or Lost
			bool crittersDefeated();	//Returns true if all the Critters have been defeated, otherwise false

			void drawMap();				//Draws the Map Tiles
			void drawCritters();		//Draws the Critters
			void drawTowers();			//Draws the Towers


			void displaySplash();
			void displayMenu();


			/* Shows the relative information depending on game status */
			void drawSplash();
			void drawMenu();
            //void drawPlaying();
            //void drawWon();
			//void drawLostLife();
			//void drawLost();
            //void drawExit();


			/* Process the turn depending on game status */
			void updateSplash();
			void updateMenu();
			//void updatePlaying();
			//void updateWon();
			//void updateLostLife();
			//void updateLost();
			//void updateExit();


            /* Game methods */
			void startNewGame(int difficultySetting);
            int getAction();
            int getStatus();
			void setStatus(int);
            //void endGame();

            //void moveCritters();
            //void towerAttacks();


			//Map Methods
			void makeMap();		//Backup Method
			void createMap();
			void startWave();
			void printTowerHelpMenu(int);
			void printTowerMenu(int);
			void printTowerMenuOption1(int);
			void printTowerMenuOption2(int);
			void printTowerMenuOption3(int);
			void printTowerMenuOption4(int);
			void displayWaveMessage(int, int, std::string);


			static const int GAME_EXIT = 0;
            static const int GAME_MAIN_MENU = 1;
            static const int GAME_RUNNING = 2;
            static const int GAME_PAUSED = 3;
            static const int GAME_WON = 4;
            static const int GAME_LOST_LIFE = 5;
            static const int GAME_LOST = 6;
            static const int GAME_SPLASH_SCREEN = 7;

            static const int GAME_EASY = 1;
            static const int GAME_MEDIUM = 2;
            static const int GAME_DIFFICULT = 3; 

			

			//Tower Names
			static const int BASIC_TOWER = 1;
			static const int ARROW_TOWER = 2;
			static const int NINJA_TOWER = 3;
			static const int ENERGY_TOWER = 4;

			//Tower Appearance


			//static const int TOWER_APPEARANCE[BASIC_TOWER] = 5;
			//static const int TOWER_APPEARANCE[ARROW_TOWER] = 20;
			//static const int TOWER_APPEARANCE[NINJA_TOWER] = 21;
			//static const int TOWER_APPEARANCE[ENERGY_TOWER] = 399;


        private:

            /* Input/output information */
            int m_LastAction;

            /* Game information */
            int m_GameStatus;
            int m_MenuOption;
			bool m_DisplaySplash;
			bool m_DisplayMenu;

			COORD m_Arena;
			std::string** mapData;
			
			std::string** mapCurrentlyDrawn;

			int towerSelected;
			bool waveActive;

			int playerX;
			int playerY;


			int towerid;
			int towerid2;
			int towerid3;
			std::string parse;
			std::string parse2;
			std::string parse3;

			

			COORD playerMovement;
			Tower dummyTower;
			std::vector<Tower> gameTowers;		//Array to store the towers in play.
			std::vector<Critters> gameCritters; //Array to store the critters in play.
			int numTowers;
			int playerCoins;
			int playerLives;
			bool allclear;

			int displayedCoins;		//Value that's currently be Displayed
			int displayedLives;		//Value that's currently be Displayed

			//std::vector<Map> mapData;				//Array to store the Map.
			//std::vector<Map> mapCurrentlyDrawn;		//Array to store the Currently Drawn Map Tiles.
			

    };




#endif // COREGAME_H_INCLUDED
