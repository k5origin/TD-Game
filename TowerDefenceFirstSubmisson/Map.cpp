	#include "Map.h"
	#include <sstream>
	#include <fstream>
	#include <iostream>


	Map::Map()
	{

		//Initializes the Private Variables
		mapName = "Unnamed";
		mapLength = 0;
		mapWidth = 0;
		entryCoords[0] = 0;
		entryCoords[1] = 0;
		exitCoords[0] = 0;
		exitCoords[1] = 0;

	} //End of default Constructor

	//Destructor
	Map::~Map()
	{

	}


	void Map::createNewMap(std::string mName, int mLength, int mWidth, int mEntryPos1, int mEntryPos2,  int mExitPos1, int mExitPos2)
	{

		mapName = mName;
		mapLength = mLength;
		mapWidth = mWidth;
		entryCoords[0] = mEntryPos1;
		entryCoords[1] = mEntryPos1;
		exitCoords[0] = mExitPos1;
		exitCoords[1] = mEntryPos2;

	}

	//Map Name
	void Map::setMapName(std::string mName)
	{

		mapName = mName;

	}

	std::string Map::getMapName()
	{

		return mapName;

	}

	//Map Length
	void Map::setMapLength(int mLength)
	{

		mapLength = mLength;

	}

	int Map::getMapLength()
	{

		return mapLength;

	}

	//Map Width
	void Map::setMapWidth(int mWidth)
	{

		mapWidth = mWidth;

	}

	int Map::getMapWidth()
	{

		return mapWidth;

	}

	//Map Entry Point
	void Map::setMapEntry(int mEntryPos1, int mEntryPos2)
	{

		entryCoords[0] = mEntryPos1;
		entryCoords[1] = mEntryPos2;

	}

	std::string Map::getMapEntry()
	{

		return entryCoords[0] + "|" + entryCoords[1];

	}

	//Map Exit Point
	void Map::setMapExit(int mExitPos1, int mExitPos2)
	{

		exitCoords[0] = mExitPos1;
		exitCoords[1] = mExitPos2;

	}

	std::string Map::getMapExit()
	{

		return exitCoords[0] + "|" + exitCoords[1];

	}


	//Map Tile
	void Map::setMapTile(int x, int y, int tile)
	{

		

	}

	void Map::setMap()
	{

		//char mapData[20][10];		
		int row = 0;
		std::ifstream fstrm("map.txt");

		while(fstrm.getline(mapData[row], 10)) 
		{
			++row;
		}
		

	}

	
