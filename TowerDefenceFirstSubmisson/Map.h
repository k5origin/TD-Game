	#ifndef MAP_H_
	#define MAP_H_

	#include <iostream>

	class Map 
	{

		public:

			//Default Constructor
			Map();

			//Destructor
			virtual ~Map();

			void createNewMap(std::string mapName, int mapLength, int mapWidth, int mapEntryPos1, int mapEntryPos2,  int mapExitPos1, int mapExitPos2);

			// Load Current Map
			void loadMap(std::string mapName);

			/////////////////////////


			void setMap();
			char** getMap(char[][10]);

			/////////////////////////

			// Set/Get Map Name
			void setMapName(std::string name);
			std::string getMapName();

			// Set/Get Map Length
			void setMapLength(int length);
			int getMapLength();

			// Set/Get Map Width
			void setMapWidth(int width);
			int getMapWidth();

			// Set/Get Map Entry Position
			void setMapEntry(int xPos, int yPos);
			std::string getMapEntry();

			// Set/Get Map Exit Position
			void setMapExit(int xPos, int yPos);
			std::string getMapExit();

			// Set/Get Map Tile
			void setMapTile(int xPos, int yPos, int selectedTile);
			std::string getMapTile();



		private:

			std::string mapName;
			int mapLength;
			int mapWidth;
			int entryCoords[2];
			int exitCoords[2];

			char mapData[20][10];
			//std::string** mapData;	


	};


	#endif
