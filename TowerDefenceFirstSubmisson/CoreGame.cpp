/* ‘CoreGame.cpp’ */

/* CoreGame complement header file */
#include "CoreGame.h"
#include  <vector>
CPlayer m_Player;


/* Init members to initial status */
CoreGame::CoreGame()
{
	//m_GameStatus = GameSplashScreen;
	m_GameStatus = 7;
	m_MenuOption = 0;
	m_LastAction = 0;
	playerCoins = 0;
	//m_Critters = NULL;

	//New Variables
	m_DisplaySplash = true;
	m_DisplayMenu = true;

	waveActive = false;

}

//Destructor
CoreGame::~CoreGame()
{

	delete &gameTowers;

}




/* Sets the game status */
void CoreGame::setStatus(int status)
{

	m_GameStatus = status;

}

/* Returns the game status */
int CoreGame::getStatus()
{

	return m_GameStatus;

}

/* Get player action */
int CoreGame::getAction()
{

	/* Get input from user */
	//m_LastAction = rlutil::getkey();			//Blocking

	/* Get input from user */
	char temp = rlutil::nb_getch();

	if ( temp != 0 )
	{
		m_LastAction = temp;		//Non Blocking
	}

	return m_LastAction;

}


void CoreGame::displayMenu()
{
	updateMenu();
	drawMenu();
}


void CoreGame::displaySplash()
{
	updateSplash();
	drawSplash();
}


/* Shows the splash screen */
void CoreGame::drawSplash()
{

	if (m_DisplaySplash)
	{
		//Clear screen
		rlutil::cls();

		gotoxy(1,3);

		rlutil::setColor(10);
		std::cout << "    Welcome to Tower Defense v1.0\n";





		rlutil::setColor(15);

		m_DisplaySplash = false;
	}

}

/* Shows the main menu */
void CoreGame::drawMenu()
{

	if (m_DisplayMenu)
	{

		//Clear screen
		rlutil::cls();


		rlutil::setColor(11);

		std::cout << "\n\n" << std::endl;
		std::cout << "    TTTTT DDD      GGG    A   M   M EEEEE  \n";
		std::cout << "      T   D  D    G   G  A A  MM MM E      \n";
		std::cout << "      T   D   D   G     A   A M M M EEE    \n";
		std::cout << "      T   D   D   G  GG AAAAA M   M E      \n";
		std::cout << "      T   D  D    G   G A   A M   M E      \n";
		std::cout << "      T   DDD      GGG  A   A M   M EEEEE  \n";

		rlutil::setColor(15);

		std::cout << "\n\n\n    What difficulty would you like?\n\n";


		m_DisplayMenu = false;
	}


	gotoxy(1,15);

	switch (m_MenuOption)
	{

	case 0:
		rlutil::setColor(10);
		std::cout << "        Easy" << std::endl;
		rlutil::setColor(15);
		std::cout << "        Medium" << std::endl;
		std::cout << "        Hard" << std::endl;
		break;
	case 1:
		std::cout << "        Easy" << std::endl;
		rlutil::setColor(10);
		std::cout << "        Medium" << std::endl;
		rlutil::setColor(15);
		std::cout << "        Hard" << std::endl;
		break;
	case 2:
		std::cout << "        Easy" << std::endl;
		std::cout << "        Medium" << std::endl;
		rlutil::setColor(10);
		std::cout << "        Hard" << std::endl;
		rlutil::setColor(15);
		break;

	}

}

/* Main Draw Method */
void CoreGame::drawGame()
{

	if ( waveActive )
	{

		//Draw HUD
		drawHud();

		//Draw Map
		drawMap();

		//Draw Towers
		drawTowers();

		//Draw Critters
		drawCritters();

	}
	else
	{

		//Draw HUD
		drawHud();

		//Draw Map
		drawMap();

		//Draw Towers
		drawTowers();

	}


}



/* Starts a new game */
void CoreGame::startNewGame(int difficultySetting)
{

	//COORD Position;
	m_GameStatus = GAME_RUNNING;

	/* Set game difficulty */
	switch ( difficultySetting )
	{
	case GAME_EASY:										//GameEasy
		m_Player.SetWavesNumber(5);
		m_Player.SetCrittersNumber(10);
		m_Player.SetLives(10);
		m_Player.SetCoins(250);
		playerCoins = 600;	//HARDCODED!
		playerLives = 10;	//HARDCODED!
		m_Arena.X = 20;
		m_Arena.Y = 10;
		std::cout << "Easy Game Selected\n";
		break;
	case GAME_MEDIUM:									//GameMedium
		m_Player.SetWavesNumber(10);
		m_Player.SetCrittersNumber(25);
		m_Player.SetLives(5);
		m_Player.SetCoins(200);
		playerCoins = 350;	//HARDCODED!
		playerLives = 5;	//HARDCODED!
		m_Arena.X = 20;
		m_Arena.Y = 10;
		std::cout << "Medium Game Selected\n";
		break;
	case GAME_DIFFICULT:								//GameDifficult
		m_Player.SetWavesNumber(20);
		m_Player.SetCrittersNumber(40);
		m_Player.SetLives(5);
		m_Player.SetCoins(100);
		playerCoins = 190;	//HARDCODED!
		playerLives = 1;	//HARDCODED!
		m_Arena.X = 20;
		m_Arena.Y = 10;
		std::cout << "Hard Game Selected\n";
		break;
	}


	/* Create player */


	/* Create Critters */


	/* Create Towers */



}



/* Process splash screen */
void CoreGame::updateSplash()
{

	/* If user pressed key, just move to main menu */
	if ( rlutil::nb_getch() )
	{
		m_GameStatus = GAME_MAIN_MENU;
	}

}

/* Gets menu option and either quit or start new game */
void CoreGame::updateMenu()
{
	//switch (m_LastAction)
	switch ( rlutil::getkey() )
	{
		/* Quit game */
	case rlutil::KEY_ESCAPE:
	case (char)81:                  //Q
	case (char)113:                 //q
		m_GameStatus = GAME_EXIT;
		break;

		/* Start new game */
	case rlutil::KEY_ENTER:

		switch (m_MenuOption)
		{
		case 0:
			startNewGame(GAME_EASY);			//GameEasy
			m_GameStatus = GAME_RUNNING;		//GameRunning
			break;
		case 1:
			startNewGame(GAME_MEDIUM);			//GameMedium
			m_GameStatus = GAME_RUNNING;		//GameRunning
			break;
		case 2:
			startNewGame(GAME_DIFFICULT);		//GameDifficult
			m_GameStatus = GAME_RUNNING;		//GameRunning
			break;
		}

		break;

		/* Start new game */
	case rlutil::KEY_UP:

		if (m_MenuOption == 0)
			m_MenuOption = 2;
		else
			m_MenuOption--;

		break;

	case rlutil::KEY_DOWN:

		if (m_MenuOption == 2)
			m_MenuOption = 0;
		else
			m_MenuOption++;

		break;
	}
}


/* Main Update Method */
void CoreGame::updateGame()
{

	if (waveActive)
	{

		////////////////////////////////////
		//		Wave Currently Active	  //
		////////////////////////////////////


		//Move Critters
		crittersUpdate();

		//Fire Towers
		towersUpdate();

		//Player Update
		playerUpdate();

		//Draw HUD
		//drawHud();

		//Check Game Win / Loss Status
		checkGameStatus();

	}
	else		
	{

		////////////////////////////////////////
		//		Wave NOT Currently Active	  //
		////////////////////////////////////////


		//Player Update
		playerUpdate();

		//Draw HUD
		//drawHud();

	}

}

void CoreGame::checkGameStatus()
{


	if ( playerLives <= 0 )			//Player Lost!
	{

		waveActive = false;

		////////////////////////////////////////////////

		//Clear screen
		rlutil::cls();


		rlutil::setColor(10);

		gotoxy(10,4);  std::cout << "########################################" << std::endl;
		gotoxy(10,5);  std::cout << "#                                      #" << std::endl;
		gotoxy(10,6);  std::cout << "#              YOU LOST!               #" << std::endl;
		gotoxy(10,7);  std::cout << "#         I hope you feel bad!         #" << std::endl;
		gotoxy(10,8);  std::cout << "#                                      #" << std::endl;
		gotoxy(10,9);  std::cout << "########################################" << std::endl;

		rlutil::setColor(15);


		rlutil::msleep(3000);
		rlutil::cls();

		////////////////////////////////////////////////

		initialiseGame();

	}
	else if ( crittersDefeated() )
	{

		waveActive = false;

		//Next Wave
		//Factory Call

		gameCritters.resize(0);
		gameCritters.resize(10);

	}



	//TODO: Display a Success Message for Wave Completed

	//Clear screen
	//rlutil::cls();


	//rlutil::setColor(10);

	//gotoxy(10,4);  std::cout << "########################################" << std::endl;
	//gotoxy(10,5);  std::cout << "#                                      #" << std::endl;
	//gotoxy(10,6);  std::cout << "#           Congratulations!           #" << std::endl;
	//gotoxy(10,7);  std::cout << "#     You completed all the waves!     #" << std::endl;
	//gotoxy(10,8);  std::cout << "#                                      #" << std::endl;
	//gotoxy(10,9);  std::cout << "########################################" << std::endl;

	//rlutil::setColor(15);

	//char val;
	//std::cin >> val;



	//TODO: CHECK FOR ALL CRITTERS ESCAPING!
	//gotoxy(1,20); std::cout << "The critter escaped!\n";



}

bool CoreGame::crittersDefeated()
{

	//Returns true if all the Critters have been defeated, otherwise false
	for(int critterNum = 0; critterNum < gameCritters.size(); critterNum++)
	{

		if ( gameCritters[critterNum].isAlive() )
		{
			return false;
		}

	}

	return true;

}

/*void CoreGame::setVars()
{
numTowers = 0;
gameTowers.resize(200); //TODO: variables for width*height of the map
gameCritters.resize(10);
}*/

void CoreGame::initialiseGame()
{


	switch (m_MenuOption)
	{
	case 0:
		startNewGame(GAME_EASY);			//GameEasy
		break;
	case 1:
		startNewGame(GAME_MEDIUM);			//GameMedium
		break;
	case 2:
		startNewGame(GAME_DIFFICULT);		//GameDifficult
		break;
	}

	numTowers = 0;





	gameTowers.resize(0);
	gameCritters.resize(0);

	gameTowers.resize(200); //TODO: variables for width*height of the map
	gameCritters.resize(10);

	//createMap();
	makeMap();

	//Init HUD
	initHud();

	//Tower* gameTowers = new Tower[15]; //Array to store the towers in play. %
	std::vector<Tower> gameTowers;


}


void CoreGame::playerUpdate()
{

	std::string mapData[20][10] = {
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" ","S"," "," ","P","P","P","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P","P","P","P"," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "}, 
		{" "," ","P","P","P","P","P","P"," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P","P","P"," "," "," "," "," "},
		{" "," "," "," ","P"," "," "," "," "," "},
		{" "," "," "," ","E"," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
	};

	if (kbhit())
	{

		int k = rlutil::getkey(); // Get character
		gotoxy(playerX,playerY); std::cout << " "; // Erase player

		//DEBUG - Character Code
		//gotoxy(30,1); std::cout << k;


		if ((k == rlutil::KEY_LEFT) && (playerX-1 != 1))
		{
			--playerX;
		}
		else if ((k == rlutil::KEY_RIGHT) && (playerX+1 != (m_Arena.X)+2))
		{
			++playerX;
		}
		else if ((k == rlutil::KEY_UP) && (playerY-1 != 1))
		{
			--playerY;
		}
		else if ((k == rlutil::KEY_DOWN) && (playerY+1 != (m_Arena.Y)+2))
		{
			++playerY;
		}
		else if (k == rlutil::KEY_SPACE)
		{

			if (towerSelected == 1)
			{
				printTowerMenuOption2(m_Arena.X);
				towerSelected = 2;
			}
			else if (towerSelected == 2)
			{
				printTowerMenuOption3(m_Arena.X);
				towerSelected = 3;
			}
			else if (towerSelected == 3)
			{
				printTowerMenuOption4(m_Arena.X);
				towerSelected = 4;
			}
			else if (towerSelected == 4)
			{
				printTowerMenuOption1(m_Arena.X);
				towerSelected = 1;
			}

		}
		else if (k == (char)115)      //S
		{

			if ((mapData[playerX-2][playerY-2] == "P") || (mapData[playerX-2][playerY-2] == "S") || (mapData[playerX-2][playerY-2] == "E"))
			{
				//Can not place something over path tiles

			}
			else if (mapData[playerX-2][playerY-2] == " ")
			{


				//Get the Value of the Selected Tower
				int currentTowerCost = Tower::getTowerCost(towerSelected);

				//Compare Players Coins with the Tower Cost
				if ( playerCoins >= currentTowerCost )
				{

					bool isTileAvialable = true;


					for (int towerNum = 0; towerNum < gameTowers.size(); towerNum++) 
					{

						if ( (gameTowers[towerNum].getX() == playerX-2) && (gameTowers[towerNum].getY() == playerY-2) )
						{

							//There is already a Tower here!!
							isTileAvialable = false;

							//Display Warning Message


							break;
						}

					}


					if ( isTileAvialable )
					{

						//Deduct Coins
						playerCoins -= currentTowerCost;

						gameTowers[numTowers] = Tower(towerSelected);
						gameTowers[numTowers].setX(playerX-2);
						gameTowers[numTowers].setY(playerY-2);

						numTowers++;
					}

				}
				else
				{

					//Not Enough Coins!


				}


				//stringstream convert;//int to String									
				//convert << numTowers;
				//parse = convert.str(); //passing value or pointer?
				//dummyTower = Tower(towerSelected);

				//if ( playerCoins >= dummyTower.getValue() )
				//{
				//	mapData[playerX-2][playerY-2] = parse; //^Placing Towers
				//	//gotoxy(x,y); std::cout << parse; //PLACES NUMBERS ON-SCREEN

				//	gameTowers[numTowers] = Tower(towerSelected);
				//	gameTowers[numTowers].setX(playerX-2);
				//	gameTowers[numTowers].setY(playerY-2);

				//	//Deduct Coins
				//	playerCoins -= gameTowers[numTowers].getValue();

				//	//gotoxy(1,17); std::cout << "Coins:    \n";
				//	//gotoxy(1,17); std::cout << "Coins: " << playerCoins <<"\n";

				//	numTowers++;
				//}
				//else
				//{
				//	//gotoxy(1,17); std::cout << "Coins:    \n";
				//	//gotoxy(1,17); std::cout << "Coins: " << playerCoins <<"\nNOT ENOUGH COINS!";

				//	//Display a Warning to the Player that he does not have enough Coins


				//}
			}

		}
		else if(k == (char)97) //A  +MATT FIXED - added tower upgrade method
		{


			if ((mapData[playerX-2][playerY-2] == "P") || (mapData[playerX-2][playerY-2] == "S") || (mapData[playerX-2][playerY-2] == "E"))
			{
				//Can not "upgrade" path tiles...

			}
			else
			{
				for (int towerNum = 0; towerNum < gameTowers.size(); towerNum++) 
				{

					if ( (gameTowers[towerNum].getX() == playerX-2) && (gameTowers[towerNum].getY() == playerY-2) ) //if tower is selected
					{

						if ( gameTowers[towerNum].isTowerUpgradable() ) //if tower isn't upgraded already
						{
							int currentUpgradeCost = ((gameTowers[towerNum].getValue())*0.60); //Get the Upgrade Value of the Selected Tower
							if ( playerCoins >= currentUpgradeCost ) //Compare Players Coins with the Upgrade Cost
							{
								gameTowers[towerNum].upgradeTower();
								playerCoins -= currentUpgradeCost;
							}
							else
							{
								//Tower already upgraded

							}

							break;
						}

					}
				}
			}
		}
		else if(k == (char)100) //D  +MATT FIXED - added tower delete method
		{


			if ((mapData[playerX-2][playerY-2] == "P") || (mapData[playerX-2][playerY-2] == "S") || (mapData[playerX-2][playerY-2] == "E"))
			{
				//Can not delete path tiles...

			}
			else
			{
				for (int towerNum = 0; towerNum < gameTowers.size(); towerNum++) 
				{
					if ( (gameTowers[towerNum].getX() == playerX-2) && (gameTowers[towerNum].getY() == playerY-2) ) //if tower is selected
					{
						playerCoins+=gameTowers[towerNum].getValue()*0.5;
						gameTowers[towerNum]=NULL;
					}
				}
			}
		}
		else if (k == rlutil::KEY_ENTER)
		{

			//If no Wave is Currently Active, Start one!
			if ( waveActive == false )
			{
				startWave();
			}

		}
		else if (k == rlutil::KEY_ESCAPE)
		{
			m_GameStatus = GAME_EXIT;
		}


		// Output player
		gotoxy(playerX,playerY); std::cout << (char)176; 


		fflush(stdout);

	}



	int lineNumber2 = 14; //+MATT FIXED - draw selected tower information 
	int offSet2 = 29;
	bool selected = false;

	for (int towerNum = 0; towerNum < gameTowers.size(); towerNum++) 
	{

		if ( (gameTowers[towerNum].getX() == playerX-2) && (gameTowers[towerNum].getY() == playerY-2) ) //if tower is selected
		{
			rlutil::setColor(10);
			gotoxy(offSet2,lineNumber2);  std::cout << "      " << gameTowers[towerNum].getName()<<"   "; lineNumber2++; 
			rlutil::setColor(12);
			gotoxy(offSet2,lineNumber2);  std::cout << "    " << "  Damage: "<< gameTowers[towerNum].getDamage() << "     \n"; lineNumber2++;
			rlutil::setColor(13);
			gotoxy(offSet2,lineNumber2);  std::cout << "    " << "  Range: "<< gameTowers[towerNum].getMaxRange() << "     \n"; lineNumber2++;
			gotoxy(offSet2,lineNumber2);  std::cout << "    " << "  Value: "<< gameTowers[towerNum].getValue() <<"      \n"; lineNumber2++;
			rlutil::setColor(14);
			selected = true;
			break;
		}
	}
	if(!selected)
	{
		gotoxy(offSet2,lineNumber2);  std::cout << "                    \n"; lineNumber2++; 
		gotoxy(offSet2,lineNumber2);  std::cout << "                    \n"; lineNumber2++;
		gotoxy(offSet2,lineNumber2);  std::cout << "                    \n"; lineNumber2++;
		gotoxy(offSet2,lineNumber2);  std::cout << "                    \n"; lineNumber2++;

		rlutil::setColor(14);
	}

}

void CoreGame::crittersUpdate()
{

	///////////////////////////////////////////////////////////////////////////

	//TODO: TEMP MAP DATA

	std::string mapData[20][10] = {
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" ","S"," "," ","P","P","P","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P","P","P","P"," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "}, 
		{" "," ","P","P","P","P","P","P"," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P","P","P"," "," "," "," "," "},
		{" "," "," "," ","P"," "," "," "," "," "},
		{" "," "," "," ","E"," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
	};



	///////////////////////////////////////////////////////////////////////////


	int xPos = 0;
	int yPos = 0;
	int lastX = 0;
	int lastY = 0;

	for(int critterNum = 0; critterNum < gameCritters.size(); critterNum++)
	{

		if ( gameCritters[critterNum].isAlive() && gameCritters[critterNum].getHP() > 0 )
		{

			int timeTillNextMove = gameCritters[critterNum].getTimeTillMove();


			if (timeTillNextMove <= 0)
			{

				xPos = gameCritters[critterNum].getX();
				yPos = gameCritters[critterNum].getY();
				lastX = gameCritters[critterNum].getLastX();
				lastY = gameCritters[critterNum].getLastY();



				////////////////////////////////


				int tempX;
				int tempY;

				//int critterHealth = 100;		//TODO: Get that Critters Health here!
				int critterHealth = gameCritters[critterNum].getHP();


				//Check Path Left
				if ((xPos-1 >= 0) && (mapData[xPos-1][yPos] == "P"))
				{
					if (lastX != xPos-1)
					{
						tempX = xPos-1;
						tempY = yPos;
					}
				}

				//Check Path Right
				if ((xPos+1 < m_Arena.X) && (mapData[xPos+1][yPos] == "P"))
				{
					if (lastX != xPos+1)
					{
						tempX = xPos+1;
						tempY = yPos;
					}
				}

				//Check Path Top
				if ((yPos-1 >= 0) && (mapData[xPos][yPos-1] == "P"))
				{
					if (lastY != yPos-1)
					{
						tempX = xPos;
						tempY = yPos-1;
					}
				}

				//Check Path Bottom
				if ((yPos+1 < m_Arena.Y) && (mapData[xPos][yPos+1] == "P"))
				{
					if (lastY != yPos+1)
					{
						tempX = xPos;
						tempY = yPos+1;
					}
				}



				//Check for End of Path
				if ((mapData[xPos-1][yPos] == "E") || (mapData[xPos+1][yPos] == "E") || (mapData[xPos][yPos-1] == "E") || (mapData[xPos][yPos+1] == "E"))
				{

					//TODO: This means the Critter Escaped! We must remove a life from the player, and make sure the critter gets destoryed!
					gameCritters[critterNum].setAlive(false);

					//Deduct the Score
					playerLives--;

				}
				else
				{
					//So far so good!
					gameCritters[critterNum].setLastX(xPos);
					gameCritters[critterNum].setLastY(yPos);

					gameCritters[critterNum].setX(tempX);
					gameCritters[critterNum].setY(tempY);

					//Set time for Critters Next Move
					gameCritters[critterNum].setTimeTillMove(20);			//Values to be changed for balancing later
					gameCritters[critterNum].incrementProgress();

				}

			}
			else
			{

				//Not time to for Critter to Move!
				int nextMove = timeTillNextMove - gameCritters[critterNum].getSpeed();
				gameCritters[critterNum].setTimeTillMove(nextMove);

			}

		}
	}


}


void CoreGame::drawMap()
{

	///////////////////////////////////////////////////////////////////////////

	//TODO: TEMP MAP DATA. We need to fetch the map and not have it hardcoded

	std::string mapData[20][10] = {
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" ","S"," "," ","P","P","P","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P","P","P","P"," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "}, 
		{" "," ","P","P","P","P","P","P"," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P","P","P"," "," "," "," "," "},
		{" "," "," "," ","P"," "," "," "," "," "},
		{" "," "," "," ","E"," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
	};

	std::string mapCurrentlyDrawn[20][10];		//TODO: This needs to be created outside the method, but it's causing errors.
	// Can someone please fix this?

	///////////////////////////////////////////////////////////////////////////


	for (int i = 0; i < m_Arena.X; i++)
	{
		for (int j = 0; j < m_Arena.Y; j++)
		{

			if ((mapData[i][j] == "P") && (mapData[i][j] != mapCurrentlyDrawn[i][j]))
			{
				rlutil::setColor(11);
				gotoxy(i+2,j+2); std::cout << (char)176;
				//gotoxy(i+2,j+2); std::cout << " ";
				rlutil::setColor(14);

				mapCurrentlyDrawn[i][j] = "P";
			}
			else if ((mapData[i][j] == "S") && (mapData[i][j] != mapCurrentlyDrawn[i][j]))
			{
				rlutil::setColor(10);
				gotoxy(i+2,j+2); std::cout << "S";
				rlutil::setColor(14);

				mapCurrentlyDrawn[i][j] = "S";
			}
			else if ((mapData[i][j] == "E") && (mapData[i][j] != mapCurrentlyDrawn[i][j]))
			{
				rlutil::setColor(12);
				gotoxy(i+2,j+2); std::cout << "E";
				rlutil::setColor(14);

				mapCurrentlyDrawn[i][j] = "E";
			}
			//else if ((mapData[i][j] == " ") && (mapData[i][j] != mapCurrentlyDrawn[i][j]))
			//{
			//	rlutil::setColor(10);
			//	gotoxy(i+2,j+2); std::cout << (char)176;
			//	rlutil::setColor(14);

			//	mapCurrentlyDrawn[i][j] = " ";
			//}

		}
	}


}

void CoreGame::towersUpdate()
{

	//+MATT FIXED - fixed strategy pattern


	for (int towerNum = 0; towerNum < gameTowers.size(); towerNum++) 
	{
		gameTowers[towerNum].fire(gameCritters, gameCritters.size());
	}
	for (int critterNum = 0; critterNum < gameCritters.size(); critterNum++)
	{
		if ( gameCritters[critterNum].getHP() <= 0 && gameCritters[critterNum].isAlive() )
		{
			gameCritters[critterNum].setAlive(false);
			playerCoins += (gameCritters[critterNum].getLevel() * 30 );		//TODO: Find Value for Reward

		}
		
	}

	//{
	//
	//	//MATT HAS TO PUT HIS TOWER CODE HERE!!
	//
	//
	//	for (int towerNum = 0; towerNum < gameTowers.size(); towerNum++) 
	//	{
	//
	//
	//		if ( gameTowers[towerNum].getReloadTick() >= gameTowers[towerNum].getReloadSpeed() )
	//		{
	//
	//			for (int critterNum = 0; critterNum < gameCritters.size(); critterNum++)
	//			{
	//
	//				if ( gameCritters[critterNum].isAlive() && gameCritters[critterNum].getHP() > 0 )
	//				{
	//
	//					int towerX = gameTowers[towerNum].getX();
	//					int towerY = gameTowers[towerNum].getY();
	//					int critterX = gameCritters[critterNum].getX();
	//					int critterY = gameCritters[critterNum].getY();
	//
	//
	//					if ( gameTowers[towerNum].isInRange(towerX, towerY, critterX, critterY) )
	//					{
	//
	//						gameCritters[critterNum].inflictDamage( gameTowers[towerNum].getDamage() );
	//						gameTowers[towerNum].setReloadTick(0);
	//						gameTowers[towerNum].setCurrentlyFiring(true);
	//
	//						if ( gameCritters[critterNum].getHP() <= 0 && gameCritters[critterNum].isAlive() )
	//						{
	//
	//							gameCritters[critterNum].setAlive(false);
	//							playerCoins += (gameCritters[critterNum].getLevel() * 50 );		//TODO: Find Value for Reward
	//
	//						}
	//
	//						break;
	//
	//					}
	//
	//
	//				}
	//
	//			}
	//
	//		}
	//
	//		gameTowers[towerNum].reload();
	//
	//	}


	//if (!gameTowers[tower].fire(gameCritters, gameCritters.size()))		//MAIN FIRE CODE
	//{ 


	//	//if ( gameTowers[tower].getTowerclass() == BASIC_TOWER )
	//	//{
	//	//	rlutil::setColor(9);	//Firing Ending, Restore Blue Tower Colour
	//	//	gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)5; 
	//	//	rlutil::setColor(14);
	//	//}
	//	//else if ( gameTowers[tower].getTowerclass() == ARROW_TOWER )
	//	//{
	//	//	rlutil::setColor(9);	//Firing Ending, Restore Blue Tower Colour
	//	//	gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)20;
	//	//	rlutil::setColor(14);
	//	//}
	//	//else if ( gameTowers[tower].getTowerclass() == NINJA_TOWER )
	//	//{
	//	//	rlutil::setColor(9);	//Firing Ending, Restore Blue Tower Colour
	//	//	gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)21;
	//	//	rlutil::setColor(14);
	//	//}
	//	//else if ( gameTowers[tower].getTowerclass() == ENERGY_TOWER )
	//	//{
	//	//	rlutil::setColor(9);	//Firing Ending, Restore Blue Tower Colour
	//	//	gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)399;
	//	//	rlutil::setColor(14);
	//	//}

	//}
	//else 
	//{
	//	if(gameTowers[tower].getTowerclass() == 1)
	//	{
	//		rlutil::setColor(12);	//Turns Tower Red to Indicate Firing
	//		gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)5;
	//		rlutil::setColor(14);
	//	}
	//	else if(gameTowers[tower].getTowerclass() == 2)
	//	{
	//		rlutil::setColor(12);	//Turns Tower Red to Indicate Firing
	//		gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)20;
	//		rlutil::setColor(14);
	//	}
	//	else if(gameTowers[tower].getTowerclass() == 3)
	//	{
	//		rlutil::setColor(12);	//Turns Tower Red to Indicate Firing
	//		gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)21;
	//		rlutil::setColor(14);
	//	}
	//	else if(gameTowers[tower].getTowerclass() == 4)
	//	{
	//		rlutil::setColor(12);	//Turns Tower Red to Indicate Firing
	//		gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)399;
	//		rlutil::setColor(14);;
	//	}

	//}

}


void CoreGame::initHud()
{


	//Display Lives
	gotoxy(2,17); std::cout << "Lives: " << playerLives << "\n";

	//Display Coins
	gotoxy(2,18); std::cout << "Coins: " << playerCoins << "\n";

}

void CoreGame::drawHud()
{


	//Show Critter Health
	{
		//TODO: THIS HAS TO BE CHANGED!
		// We need to find a way to display the Health of Multiple critters at once!
		// Currently the player has no way of knowing which critter has how much health.

		//rlutil::setColor(10);

		//gotoxy(1,15); 


		//for (int h = 0; h < 100/4; h++)
		//{
		//	std::cout << " ";
		//}

		//gotoxy(1,15); 
		//for (int h = 0; h < critterHealth/4; h++)
		//{
		//	std::cout << (char)219;
		//}

		//gotoxy(1,15); cout<<"HP: ";
		//for (int h = 0; h < gameCritters.size(); h++)
		//{
		//	cout << gameCritters[h].getHP() << " ";
		//}


		//gotoxy(1,16); cout<<"PR: ";
		//for (int h = 0; h < gameCritters.size(); h++)
		//{
		//	cout << gameCritters[h].getProgress() << " ";
		//}

		rlutil::setColor(14);
	}


	//Redraw Current Player Lives if Needed
	if ( playerLives != displayedLives )
	{

		gotoxy(9,17); std::cout << "      ";		//Erase current value first, in case the value is longer than the new value to be written
		gotoxy(9,17); std::cout << playerLives;

		displayedLives = playerLives;

	}


	//Redraw Current Coins if Needed
	if ( playerCoins != displayedCoins )
	{

		gotoxy(9,18); std::cout << "      ";		//Erase current value first, in case the value is longer than the new value to be written
		gotoxy(9,18); std::cout << playerCoins;

		displayedCoins = playerCoins;

	}

}


void CoreGame::drawCritters()
{

	int xPos = 0;
	int yPos = 0;
	int cLevel = 0;
	int cColour = 0;

	for(int critterNum = (gameCritters.size() -1); critterNum >= 0; critterNum--)
	{

		if ( gameCritters[critterNum].isAlive()  && gameCritters[critterNum].getHP() > 0 )
		{

			xPos = gameCritters[critterNum].getX();
			yPos = gameCritters[critterNum].getY();

			//Only draw critters who are past the Starting Point!
			if (gameCritters[critterNum].getProgress() > 0)
			{

				//Find out what Type of Critter this is!
				cLevel = gameCritters[critterNum].getLevel();
				cColour = gameCritters[critterNum].getColour();

				//Critter Apperence!
				switch ( cLevel )
				{
				case 1:
					cLevel = 1;		//Smiley Face #1
					break;
				case 2:
					cLevel = 2;		//Smiley Face #2
					break;
				case 3:
					cLevel = 190;	//Scorpian
					break;
				case 4:
					cLevel = 15;	//Spider
					break;
				case 5:
					cLevel = 12;	//Stickman
					break;
				}

				//Critter Colour!
				switch ( cColour )
				{
				case 1:
					rlutil::setColor(1);
					break;
				case 2:
					rlutil::setColor(2);
					break;
				case 3:
					rlutil::setColor(3);
					break;
				case 4:
					rlutil::setColor(5);
					break;
				case 5:
					rlutil::setColor(6);
					break;
				case 6:
					rlutil::setColor(7);
					break;
				case 7:
					rlutil::setColor(10);
					break;
				case 8:
					rlutil::setColor(13);
					break;	

					//TODO: CHANGE THE POSSIBLE COLOURS AND REMOVE THE ONES THAT ARE TOO DARK!!
					//Here is the list of Possible colours! Try them out!

					//0 Black
					//1 Blue (ANSI red)
					//2 Green
					//3 Cyan (ANSI brown)
					//4 Red (ANSI blue)
					//5 Magenta
					//6 Brown (dark yellow)
					//7 Light Grey (white)
					//8 Grey (dark grey or light black)
					//9 Light blue (ANSI light red)
					//10 Light green
					//11 Light cyan (ANSI yellow)
					//12 Light red (ANSI light magenta)
					//13 Light magenta
					//14 Yellow (ANSI light cyan)
					//15 White (bright)
				}

				gotoxy(xPos+2,yPos+2); std::cout << (char)cLevel;    // Output critter
				rlutil::setColor(14); //Set Colour back to Default

			}

		}
	}

}

void CoreGame::drawTowers()
{

	for (int tower = 0; tower < gameTowers.size(); tower++) 
	{


		if ( gameTowers[tower].getTowerclass() == BASIC_TOWER )
		{

			rlutil::setColor(9);		//Blue Tower = Level 0

			if ( gameTowers[tower].isCurrentlyFiring() )
			{
				rlutil::setColor(12);	//Red Tower = Firing
				gameTowers[tower].setCurrentlyFiring(false);
			}

			gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)5; 
			rlutil::setColor(14);

		}
		else if ( gameTowers[tower].getTowerclass() == ARROW_TOWER )
		{

			rlutil::setColor(9);	//Blue Tower = Level 0

			if ( gameTowers[tower].isCurrentlyFiring() )
			{
				rlutil::setColor(12);	//Red Tower = Firing
				gameTowers[tower].setCurrentlyFiring(false);
			}

			gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)20;
			rlutil::setColor(14);

		}
		else if ( gameTowers[tower].getTowerclass() == NINJA_TOWER )
		{

			rlutil::setColor(9);	//Blue Tower = Level 0

			if ( gameTowers[tower].isCurrentlyFiring() )
			{
				rlutil::setColor(12);	//Red Tower = Firing
				gameTowers[tower].setCurrentlyFiring(false);
			}

			gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)21;
			rlutil::setColor(14);

		}
		else if ( gameTowers[tower].getTowerclass() == ENERGY_TOWER )
		{

			rlutil::setColor(9);	//Blue Tower = Level 0

			if ( gameTowers[tower].isCurrentlyFiring() )
			{
				rlutil::setColor(12);	//Red Tower = Firing
				gameTowers[tower].setCurrentlyFiring(false);
			}

			gotoxy(gameTowers[tower].getX()+2,gameTowers[tower].getY()+2); std::cout << (char)399;
			rlutil::setColor(14);
		}


	}

}

void CoreGame::startWave()
{


	std::string mapData[20][10] = {
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" ","S"," "," ","P","P","P","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P","P","P","P"," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "}, 
		{" "," ","P","P","P","P","P","P"," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P","P","P"," "," "," "," "," "},
		{" "," "," "," ","P"," "," "," "," "," "},
		{" "," "," "," ","E"," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
	};

	displayWaveMessage(m_Arena.X, 20, " -Wave starting!"); //+MATT FIXED - moved this out of the way of the second box
	rlutil::msleep(500);
	displayWaveMessage(m_Arena.X, 20, " ");


	waveActive = true;


	int xPos = 0;
	int yPos = 0;

	for (int i = 0; i < m_Arena.X; i++)
	{
		for (int j = 0; j < m_Arena.Y; j++)
		{

			if (mapData[i][j] == "S")
			{
				xPos = i;
				yPos = j;

				for(int critterNum = 0; critterNum < gameCritters.size(); critterNum++)
				{

					gameCritters[critterNum].setX(xPos);
					gameCritters[critterNum].setY(yPos);

				}

			}
		}
	}

	//Init Critters so they aren't all overlapping each other all the time!
	for(int critterNum = 0; critterNum < gameCritters.size(); critterNum++)
	{

		int nextMove = (critterNum * 10);						//Gives each critter an initial delay
		gameCritters[critterNum].setTimeTillMove(nextMove);

	}


}

void CoreGame::createMap()
{

	rlutil::cls();
	rlutil::setColor(15);


	//std::string mapData[m_Arena.X][m_Arena.Y];

	std::string mapData[20][10] = {
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" ","S"," "," ","P","P","P","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P","P","P","P"," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "}, 
		{" "," ","P","P","P","P","P","P"," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P","P","P"," "," "," "," "," "},
		{" "," "," "," ","P"," "," "," "," "," "},
		{" "," "," "," ","E"," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
	};



	// Makes border
	for (int x = 0; x <= (m_Arena.X)+1; x++)
	{
		if ((x == 0) || (x == (m_Arena.X)+1))
		{
			for (int y = 0; y <= (m_Arena.Y)+1; y++)
			{
				rlutil::locate(x+1,y+1); std::cout << (char)219;
			}
		}
		else
		{
			rlutil::locate(x+1,1); std::cout << (char)219;
			rlutil::locate(x+1,(m_Arena.Y)+2); std::cout << (char)219;
		}

	}

	// Draws Tiles Inside Border
	for (int i = 0; i < (m_Arena.X); i++)
	{
		for (int j = 0; j < (m_Arena.Y); j++)
		{

			if ((mapData[i][j] == "P"))
			{
				rlutil::setColor(11);
				gotoxy(i+2,j+2); std::cout << (char)176;
				rlutil::setColor(14);
			}
			else if ((mapData[i][j] == "S"))
			{
				rlutil::setColor(10);
				gotoxy(i+2,j+2); std::cout << "S";
				rlutil::setColor(14);
			}
			else if ((mapData[i][j] == "E"))
			{
				rlutil::setColor(12);
				gotoxy(i+2,j+2); std::cout << "E";
				rlutil::setColor(14);
			}

		}

	}


	rlutil::setColor(14);


	int x = 3; int y = 3;	// Player Starting Location
	gotoxy(x,y); std::cout << (char)176 << std::endl; // Output player


	printTowerMenu(m_Arena.X);
	printTowerMenuOption1(m_Arena.X);
	printTowerHelpMenu(m_Arena.X);


	towerSelected = 1;			//Current Tower Highlighted On Menu


	//while (true)
	//{

	//	if (kbhit())
	//	{
	//		int k = rlutil::getkey(); // Get character
	//		gotoxy(x,y); std::cout << " "; // Erase player

	//		//DEBUG - Character Code
	//		//gotoxy(30,1); std::cout << k;

	//		if ((k == rlutil::KEY_LEFT) && (x-1 != 1))
	//		{
	//			--x;
	//		}
	//		else if ((k == rlutil::KEY_RIGHT) && (x+1 != (m_Arena.X)+2))
	//		{
	//			++x;
	//		}
	//		else if ((k == rlutil::KEY_UP) && (y-1 != 1))
	//		{
	//			--y;
	//		}
	//		else if ((k == rlutil::KEY_DOWN) && (y+1 != (m_Arena.Y)+2))
	//		{
	//			++y;
	//		}
	//		else if (k == rlutil::KEY_SPACE)
	//		{

	//			if (towerSelected == 1)
	//			{
	//				printTowerMenuOption2(m_Arena.X);
	//				towerSelected = 2;
	//			}
	//			else if (towerSelected == 2)
	//			{
	//				printTowerMenuOption3(m_Arena.X);
	//				towerSelected = 3;
	//			}
	//			else if (towerSelected == 3)
	//			{
	//				printTowerMenuOption4(m_Arena.X);
	//				towerSelected = 4;
	//			}
	//			else if (towerSelected == 4)
	//			{
	//				printTowerMenuOption1(m_Arena.X);
	//				towerSelected = 1;
	//			}

	//		}
	//		else if (k == (char)100)        //D
	//		{

	//			if ((mapData[x-2][y-2] == "P") || (mapData[x-2][y-2] == "S") || (mapData[x-2][y-2] == "E"))
	//			{
	//				//Can not remove path tiles

	//			}
	//			else
	//			{
	//				mapData[x-2][y-2] = " ";
	//				gotoxy(x,y); std::cout << " ";
	//			}

	//		}
	//		else if (k == (char)115)      //S
	//		{

	//			if ((mapData[x-2][y-2] == "P") || (mapData[x-2][y-2] == "S") || (mapData[x-2][y-2] == "E"))
	//			{
	//				//Can not place something over path tiles

	//			}
	//			else
	//			{

	//				switch ( towerSelected )
	//				{

	//					case 1:
	//						mapData[x-2][y-2] = "1";
	//						gotoxy(x,y); std::cout << "1";
	//						break;

	//					case 2:
	//						mapData[x-2][y-2] = "2";
	//						gotoxy(x,y); std::cout << "2";
	//						break;

	//					case 3:
	//						mapData[x-2][y-2] = "3";
	//						gotoxy(x,y); std::cout << "3";
	//						break;

	//					case 4:
	//						mapData[x-2][y-2] = "4";
	//						gotoxy(x,y); std::cout << "4";
	//						break;

	//				}

	//			}

	//		}
	//		else if (k == rlutil::KEY_ENTER)
	//		{

	//			//Start Wave!
	//			//startWave();

	//		}
	//		else if (k == rlutil::KEY_ESCAPE)
	//		{

	//			m_GameStatus = GAME_EXIT;

	//		}


	//		gotoxy(x,y); std::cout << (char)176; // Output player

	//		fflush(stdout);

	//	}

	//}


	rlutil::setColor(15);


}



void CoreGame::printTowerMenu(int xPos)
{
	int lineNumber = 2;
	int offSet = 8;

	rlutil::setColor(13);
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "     Tower Details     " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)204 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)185 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber++;

	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber++;

	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)204 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)185 << std::endl; lineNumber++;//+MATT FIXED - changed box outline to fit second box
	rlutil::setColor(14);

}

void CoreGame::printTowerHelpMenu(int xPos)
{

	//int lineNumber = 14;
	int lineNumber = 2;
	int offSet = 35;

	rlutil::setColor(13);
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "     Tower Details     " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)204 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)185 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "  S Key - Place Tower  " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "  D Key - Delete Tower " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "  A Key - Upgrade      " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "  SPACE - Change Tower " << (char)186 << std::endl; lineNumber++;//+MATT FIXED - updated control display
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "  ENTER - Confirm      " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "  ESC   - Quit         " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188 << std::endl; lineNumber++;
	rlutil::setColor(14);

	int lineNumber2 = 12; //+MATT FIXED  - added second box
	int offSet2 = 28;

	rlutil::setColor(13);
	//gotoxy(offSet2,lineNumber2);  std::cout << (char)201 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)187 << std::endl; lineNumber2++;
	gotoxy(offSet2,lineNumber2);  std::cout << (char)186 << "    Selected Tower:    " << (char)186 << std::endl; lineNumber2++;
	gotoxy(offSet2,lineNumber2);  std::cout << (char)204 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)185 << std::endl; lineNumber2++;
	gotoxy(offSet2,lineNumber2);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber2++;

	gotoxy(offSet2,lineNumber2);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber2++;
	gotoxy(offSet2,lineNumber2);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber2++;

	gotoxy(offSet2,lineNumber2);  std::cout << (char)186 << "                       " << (char)186 << std::endl; lineNumber2++;
	gotoxy(offSet2,lineNumber2);  std::cout << (char)200 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)205 << (char)188 << std::endl; lineNumber2++;
	rlutil::setColor(14);


}





void CoreGame::printTowerMenuOption1(int xPos)
{

	int lineNumber = 6;
	int offSet = 9;

	rlutil::setColor(10);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "  " << (char)5   << " - Basic Tower      \n"; lineNumber++; //TODO: Change HUD to show stats (TRUST ME BRENDAN!)
	rlutil::setColor(12);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Damage: 2     \n"; lineNumber++;
	rlutil::setColor(13);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Range: 3      \n"; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Cost: 50      \n"; lineNumber++;

	rlutil::setColor(14);

}

void CoreGame::printTowerMenuOption2(int xPos)
{

	int lineNumber = 6;
	int offSet = 9;

	rlutil::setColor(10);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "  " << (char)20   << " - Arrow Tower      " << std::endl; lineNumber++;
	rlutil::setColor(12);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Damage: 4     " << std::endl; lineNumber++;
	rlutil::setColor(13);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Range: 2      " << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Cost: 75      " << std::endl; lineNumber++;
	rlutil::setColor(14);

}

void CoreGame::printTowerMenuOption3(int xPos)
{

	int lineNumber = 6;
	int offSet = 9;

	rlutil::setColor(10);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "  " << (char)21   << " - Ninja Tower      " << std::endl; lineNumber++;
	rlutil::setColor(12);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Damage: 4      " << std::endl; lineNumber++;
	rlutil::setColor(13);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Range: 6       " << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Cost: 100       " << std::endl; lineNumber++;
	rlutil::setColor(14);


}

void CoreGame::printTowerMenuOption4(int xPos)
{

	int lineNumber = 6;
	int offSet = 9;

	rlutil::setColor(10);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "  " << (char)399   << " - Energy Tower " << std::endl; lineNumber++;
	rlutil::setColor(12);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Damage: 5     " << std::endl; lineNumber++;
	rlutil::setColor(13);
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Range: 8      " << std::endl; lineNumber++;
	gotoxy(xPos+offSet,lineNumber);  std::cout << "    " << "  Cost: 120      " << std::endl; lineNumber++;
	rlutil::setColor(14);


}

void CoreGame::displayWaveMessage(int xPos, int height, std::string msg)
{

	rlutil::setColor(10);
	gotoxy(xPos+10,height);  std::cout << "                                             " << std::endl;
	gotoxy(xPos+10,height);  std::cout << msg << std::endl;
	rlutil::setColor(14);

}



void CoreGame::makeMap()
{

	rlutil::cls();
	rlutil::setColor(15);


	//std::string mapData[m_Arena.X][m_Arena.Y];

	std::string mapData[20][10] = {
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" ","S"," "," ","P","P","P","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P"," "," ","P"," "," ","P"," "," "},
		{" ","P","P","P","P"," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "},
		{" "," "," "," "," "," "," ","P"," "," "}, 
		{" "," ","P","P","P","P","P","P"," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P"," "," "," "," "," "," "," "},
		{" "," ","P","P","P"," "," "," "," "," "},
		{" "," "," "," ","P"," "," "," "," "," "},
		{" "," "," "," ","E"," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
		{" "," "," "," "," "," "," "," "," "," "},
	};



	// Makes border
	for (int x = 0; x <= (m_Arena.X)+1; x++)
	{
		if ((x == 0) || (x == (m_Arena.X)+1))
		{
			for (int y = 0; y <= (m_Arena.Y)+1; y++)
			{
				rlutil::locate(x+1,y+1); std::cout << (char)219;
			}
		}
		else
		{
			rlutil::locate(x+1,1); std::cout << (char)219;
			rlutil::locate(x+1,(m_Arena.Y)+2); std::cout << (char)219;
		}

	}

	// Draws Tiles Inside Border
	for (int i = 0; i < (m_Arena.X); i++)
	{
		for (int j = 0; j < (m_Arena.Y); j++)
		{

			if ((mapData[i][j] == "P"))
			{
				rlutil::setColor(11);
				gotoxy(i+2,j+2); std::cout << (char)176;
				rlutil::setColor(14);
			}
			else if ((mapData[i][j] == "S"))
			{
				rlutil::setColor(10);
				gotoxy(i+2,j+2); std::cout << "S";
				rlutil::setColor(14);
			}
			else if ((mapData[i][j] == "E"))
			{
				rlutil::setColor(12);
				gotoxy(i+2,j+2); std::cout << "E";
				rlutil::setColor(14);
			}

		}

	}




	rlutil::setColor(14);

	playerX = 3;	// Player Starting Location
	playerY = 3;	// Player Starting Location
	//gotoxy(x,y); std::cout << (char)176 << std::endl; // Output player


	//TODO: Move inside initHud()
	printTowerMenu(m_Arena.X);
	printTowerMenuOption1(m_Arena.X);
	printTowerHelpMenu(m_Arena.X);


	towerSelected = 1;
	//bool updateNeeded = false;


	//int playerCoins = 750;
	//Show Current Coins
	//gotoxy(1,17); std::cout << "Coins:    \n";
	//gotoxy(1,17); std::cout << "Coins: " << playerCoins << "\n";




	rlutil::setColor(15);
	std::cout << "\n";

}
