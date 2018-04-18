#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

    /* ‘Player.h’ */


    /* Time header file */
    #include <time.h>
    /* Windows standard header file */
    #include <windows.h>

	#include "CoreGame.h"

    /* Player class */
    class CPlayer
    {

        public:

            /* Constructor / destructor */
            CPlayer();

            /* Move player */
            void Move(COORD Direction);

            /* Maintenance methods */
            //COORD GetPosition();
			void GetPosition(COORD * Position);

            void SetWavesNumber(int WaveNumber);
            int GetWavesNumber();

            void SetCrittersNumber(int CritterNumber);
            int GetCrittersNumber();

            void SetLives(short Lives);
            short GetLives();

            void SetScore(int Score);
            int GetScore();

            void SetCoins(int Coins);
            int GetCoins();


        private:

            /* Player attributes */
            COORD m_Position;
            //COORD * m_Critters;		//TODO: Move to Critter Class

            short m_Lives;
            int m_WavesNumber;
            int m_CrittersNumber;
            int m_Score;
            int m_Coins;



    };



#endif // PLAYER_H_INCLUDED
