    /* ‘main.cpp’ */

    /* Windows standard header file */
    #include <windows.h>
    /* Standard input/output header file */
    #include <stdio.h>
    /* rlutil header file */
    #include "rlutil.h"
    /* CoreGame header file */
    #include "CoreGame.h"



    /* Start */
    int main()
    {

        CoreGame mGame;

        /* Set window title */
        SetConsoleTitle("TD Game");
		//mGame.setVars();
		/* Remove User Cursor */
		rlutil::CursorHider curs;


		const int FRAMES_PER_SECOND = 15;
		const int SKIP_TICKS = 1000 / FRAMES_PER_SECOND;

		/* GetTickCount() returns the current number of milliseconds 
		   that have elapsed since the system was started */
		DWORD nextGameTick = GetTickCount();
		
		int sleepTime = 0;
		bool gameRunning = true;
		const int GAME_EXIT = 0;
		const int GAME_RUNNING = 2;
		const int GAME_SPLASH_SCREEN = 7;


		while ( true )
		{

			mGame.displaySplash();
			mGame.displayMenu();


			if ( mGame.getStatus() == GAME_RUNNING )
			{


				mGame.initialiseGame();


				// Main Game Running Loop
				while ( mGame.getStatus() != GAME_EXIT )
				{

					//std::cout << "Entering Game Loop\n";


					mGame.updateGame();
					mGame.drawGame();


					nextGameTick += SKIP_TICKS;
					sleepTime = nextGameTick - GetTickCount();

					if( sleepTime >= 0 ) 
					{
						rlutil::msleep(sleepTime);
					}
					else 
					{
						// Can't keep up with requested Frames per Second!
						//std::cout << "\n\nCan't keep up with requested FPS!\n";
					}

				}

				//Clear screen
				rlutil::cls();
				mGame.setStatus(GAME_SPLASH_SCREEN);

			}


		}


		std::cout << "End of Game. Press any key to Continue\n";
		rlutil::anykey();

        return 0;

    }

