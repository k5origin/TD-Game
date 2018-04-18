    /* ‘Player.cpp’ */

    /* Player header file */
    #include "Player.h"


    /* Constructor  */
    CPlayer::CPlayer()
    {
		m_Position.X = 3;
        m_Position.Y = 3;
    }


    /* Moves player */
    void CPlayer::Move(COORD Direction)
    {
        m_Position.X += Direction.X;
        m_Position.Y += Direction.Y;
    }

    /* Gets player position */
    //COORD CPlayer::GetPosition()
    //{
	//	return m_Position;
    //}

	/* Gets player position */
	void CPlayer::GetPosition(COORD * Position)
	{
		memcpy (Position, &m_Position, sizeof (COORD));
	}

    /* Sets player Waves Number */
    void CPlayer::SetWavesNumber(int WaveNumber)
    {
        m_WavesNumber = WaveNumber;
    }

    /* Gets player Waves Number */
    int CPlayer::GetWavesNumber()
    {
        return m_WavesNumber;
    }

    /* Sets player Critters Number */
    void CPlayer::SetCrittersNumber(int CritterNumber)
    {
        m_CrittersNumber = CritterNumber;
    }

    /* Gets player Critters Number */
    int CPlayer::GetCrittersNumber()
    {
        return m_CrittersNumber;
    }

    /* Sets player lives */
    void CPlayer::SetLives(short Lives)
    {
        m_Lives = Lives;
    }

    /* Gets player lives */
    short CPlayer::GetLives()
    {
        return m_Lives;
    }

    /* Sets player score */
    void CPlayer::SetScore(int Score)
    {
        m_Score = Score;
    }

    /* Gets player score */
    int CPlayer::GetScore()
    {
        return m_Score;
    }

    /* Sets player coins */
    void CPlayer::SetCoins(int Coins)
    {
        m_Coins = Coins;
    }

    /* Gets player coins */
    int CPlayer::GetCoins()
    {
        return m_Coins;
    }
