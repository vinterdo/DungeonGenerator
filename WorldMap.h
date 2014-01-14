
class WorldMap
{
      public:
      Point* Size;
      Point* Max;
      char* Map;
      
      int Objects;
      int ChanceRoom;
      int ChanceCorridor;
      
      long OldSeed;
      
      enum
      {
        tileUnused = 0,
        tileDirtWall = 'X',
        tileDirtFloor,
        tileStoneWall,
        tileCorridor,
        tileDoor,
        tileUpStairs,
        tileDownStairs,
        tileChest
      };
      
      WorldMap(int SizeX, int SizeY)
      {
          Size = new Point(SizeX, SizeY);
          
          ChanceRoom = 75;
          ChanceCorridor = 25;
          //Map = new char[SizeX * SizeY];
          /*
          for(int y = 0; y < Size->Y; y++)
             {
                     for(int x = 0; x < Size->X; x++)
                     {
                             Map[(y * Size->X + x)] = 'X';
                     }
             }*/
          
          CreateDungeon(SizeX, SizeY, 100);
      }
      
      
      void SetPos(int x, int y, char value)
      {
           Map[(y * Size->X + x)] = value;
      }
      
      char GetPos(int x, int y)
      {
           return Map[(y * Size->X + x)];
      }
      
      int GetRand(int min, int max)
      {
        time_t Seed;
        Seed = time(NULL) + OldSeed;
        OldSeed = Seed;
 
        srand(Seed);
 
        int n = max - min + 1;
        int i = rand() % n;
 
        if(i < 0)
            i = -i;
 
        return min + i;
      }
      
      
       bool MakeCorridor(int x, int y, int lenght, int direction)
      {
        int Lenght = GetRand(2, lenght);
        char Floor = tileCorridor;
        int Dir = 0;
        if(direction > 0 && direction < 4) Dir = direction;
 
        int xtemp = 0;
        int ytemp = 0;
 
        switch(Dir)
        {
            case 0:
            {
                if(x < 0 || x > Size->X) return false;
                else xtemp = x;
 
                for(ytemp = y; ytemp > (y- Lenght); ytemp--)
                {
                    if(ytemp < 0 || ytemp > Size->Y) return false;
                    if(GetPos(xtemp, ytemp) != tileUnused) return false;
                }
 
                for(ytemp = y; ytemp > (y - Lenght); ytemp--)
                {
                    SetPos(xtemp, ytemp, Floor);
                }
                break;
 
            }
            case 1:
            {
                if(y < 0 || y > Size->Y) return false;
                else ytemp = y;
 
                for(xtemp = x; xtemp < (x + Lenght); xtemp++)
                {
                    if(xtemp < 0 || xtemp > Size->X) return false;
                    if(GetPos(xtemp, ytemp) != tileUnused) return false;
                }
 
                for(xtemp = x; xtemp < (x + Lenght); xtemp++)
                {
                    SetPos(xtemp, ytemp, Floor);
                }
                break;
            }
            case 2:
            {
                if(x < 0 || x > Size->X) return false;
                else xtemp = x;
 
                for(ytemp = y; ytemp < (y + Lenght); ytemp++)
                {
                    if(ytemp < 0 || ytemp > Size->Y) return false;
                    if(GetPos(xtemp, ytemp) != tileUnused) return false;
                }
                for (ytemp = y; ytemp < (y+Lenght); ytemp++){
                    SetPos(xtemp, ytemp, Floor);
                }
			break;
            }
            case 3:
            {
                if (ytemp < 0 || ytemp > Size->Y) return false;
                else ytemp = y;
 
                for (xtemp = x; xtemp > (x-Lenght); xtemp--){
                    if (xtemp < 0 || xtemp > Size->X) return false;
                    if (GetPos(xtemp, ytemp) != tileUnused) return false;
                }
 
                for (xtemp = x; xtemp > (x-Lenght); xtemp--){
                    SetPos(xtemp, ytemp, Floor);
                }
                break;
            }
		}
		return true;
	}
	
	bool MakeRoom(int x, int y, int xlength, int ylength, int direction)
    {
         //Set Room size (4 x 4 min)
		int xlen = GetRand(4, xlength);
		int ylen = GetRand(4, ylength);
		// Set floor and walls
		int floor = tileDirtFloor; 
		int wall = tileDirtWall; 
		// Direction
		int dir = 0;
		if (direction > 0 && direction < 4) dir = direction;
 
		switch(dir)
        {
		case 0:
		//north
			//Check if there's enough space left for it
			for (int ytemp = y; ytemp > (y-ylen); ytemp--)
            {
				if (ytemp < 0 || ytemp > Size->Y) return false;
				for (int xtemp = (x-xlen/2); xtemp < (x+(xlen+1)/2); xtemp++)
                {
					if (xtemp < 0 || xtemp > Size->X) return false;
					if (GetPos(xtemp, ytemp) != tileUnused) return false; //no space left...
				}
			}
 
			//we're still here, build
			for (int ytemp = y; ytemp > (y-ylen); ytemp--)
            {
				for (int xtemp = (x-xlen/2); xtemp < (x+(xlen+1)/2); xtemp++)
                {
					//start with the walls
					if (xtemp == (x-xlen/2)) SetPos(xtemp, ytemp, wall);
					else if (xtemp == (x+(xlen-1)/2)) SetPos(xtemp, ytemp, wall);
					else if (ytemp == y) SetPos(xtemp, ytemp, wall);
					else if (ytemp == (y-ylen+1)) SetPos(xtemp, ytemp, wall);
					//and then fill with the floor
					else SetPos(xtemp, ytemp, floor);
				}
			}
			break;
		case 1:
		//east
			for (int ytemp = (y-ylen/2); ytemp < (y+(ylen+1)/2); ytemp++)
            {
				if (ytemp < 0 || ytemp > Size->Y) return false;
				for (int xtemp = x; xtemp < (x+xlen); xtemp++)
                {
					if (xtemp < 0 || xtemp > Size->X) return false;
					if (GetPos(xtemp, ytemp) != tileUnused) return false;
				}
			}
 
			for (int ytemp = (y-ylen/2); ytemp < (y+(ylen+1)/2); ytemp++)
            {
				for (int xtemp = x; xtemp < (x+xlen); xtemp++)
                {
 
					if (xtemp == x) SetPos(xtemp, ytemp, wall);
					else if (xtemp == (x+xlen-1)) SetPos(xtemp, ytemp, wall);
					else if (ytemp == (y-ylen/2)) SetPos(xtemp, ytemp, wall);
					else if (ytemp == (y+(ylen-1)/2)) SetPos(xtemp, ytemp, wall);
 
					else SetPos(xtemp, ytemp, floor);
				}
			}
			break;
		case 2:
		//south
			for (int ytemp = y; ytemp < (y+ylen); ytemp++)
            {
				if (ytemp < 0 || ytemp > Size->Y) return false;
				for (int xtemp = (x-xlen/2); xtemp < (x+(xlen+1)/2); xtemp++)
                {
					if (xtemp < 0 || xtemp > Size->X) return false;
					if (GetPos(xtemp, ytemp) != tileUnused) return false;
				}
			}
 
			for (int ytemp = y; ytemp < (y+ylen); ytemp++)
            {
				for (int xtemp = (x-xlen/2); xtemp < (x+(xlen+1)/2); xtemp++)
                {
 
					if (xtemp == (x-xlen/2)) SetPos(xtemp, ytemp, wall);
					else if (xtemp == (x+(xlen-1)/2)) SetPos(xtemp, ytemp, wall);
					else if (ytemp == y) SetPos(xtemp, ytemp, wall);
					else if (ytemp == (y+ylen-1)) SetPos(xtemp, ytemp, wall);
 
					else SetPos(xtemp, ytemp, floor);
				}
			}
			break;
		case 3:
		//west
			for (int ytemp = (y-ylen/2); ytemp < (y+(ylen+1)/2); ytemp++)
            {
				if (ytemp < 0 || ytemp > Size->Y) return false;
				for (int xtemp = x; xtemp > (x-xlen); xtemp--)
                {
					if (xtemp < 0 || xtemp > Size->X) 
                       return false;
					if (GetPos(xtemp, ytemp) != tileUnused) 
                       return false;
				}
			}
 
			for (int ytemp = (y-ylen/2); ytemp < (y+(ylen+1)/2); ytemp++)
            {
				for (int xtemp = x; xtemp > (x-xlen); xtemp--)
                {
 
					if (xtemp == x) SetPos(xtemp, ytemp, wall);
					else if (xtemp == (x-xlen+1)) SetPos(xtemp, ytemp, wall);
					else if (ytemp == (y-ylen/2)) SetPos(xtemp, ytemp, wall);
					else if (ytemp == (y+(ylen-1)/2)) SetPos(xtemp, ytemp, wall);
 
					else SetPos(xtemp, ytemp, floor);
				}
			}
			break;
		}
 
		//yay, all done
		return true;
	}
	
	bool CreateDungeon(int inx, int iny, int inobj){
		if (inobj < 1) Objects = 10;
		else Objects = inobj;
 
		//map size magic
		if (inx < 3) Size->X = 3;
		else if (inx > Max->X) Size->X = Max->X;
		else Size->X = inx;
 
		if (iny < 3) Size->Y = 3;
		else if (iny > Max->Y) Size->Y = Max->Y;
		else Size->Y = iny;
 
		//redefine the map var, so it's adjusted to our new map size
		Map = new char[Size->X * Size->Y];
 
		//start with making the "standard stuff" on the map
		for (int y = 0; y < Size->Y; y++){
			for (int x = 0; x < Size->X; x++){
				//ie, making the borders of unwalkable walls
				if (y == 0) SetPos(x, y, tileStoneWall);
				else if (y == Size->Y-1) SetPos(x, y, tileStoneWall);
				else if (x == 0) SetPos(x, y, tileStoneWall);
				else if (x == Size->X-1) SetPos(x, y, tileStoneWall);
 
				//and fill the rest with dirt
				else SetPos(x, y, tileUnused);
			}
		}
 
		/*******************************************************************************
		And now the code of the random-map-generation-algorithm begins!
		*******************************************************************************/
 
		//start with making a room in the middle, which we can start building upon
		MakeRoom(Size->X/2, Size->Y/2, 8, 6, GetRand(0,3)); 
 
		//keep count of the number of "objects" we've made
		int currentFeatures = 1; //+1 for the first room we just made
 
		//then we sart the main loop
		for (int countingTries = 0; countingTries < 1000; countingTries++){
			//check if we've reached our quota
			if (currentFeatures == Objects){
				break;
			}
 
			//start with a random wall
			int newx = 0;
			int xmod = 0;
			int newy = 0;
			int ymod = 0;
			int validTile = -1;
			//1000 chances to find a suitable object (room or corridor)..
			//(yea, i know it's kinda ugly with a for-loop... -_-')
			for (int testing = 0; testing < 1000; testing++){
				newx = GetRand(1, Size->X-1);
				newy = GetRand(1, Size->Y-1);
				validTile = -1;
				//System.out.println("tempx: " + newx + "\ttempy: " + newy);
				if (GetPos(newx, newy) == tileDirtWall || GetPos(newx, newy) == tileCorridor){
					//check if we can reach the place
					if (GetPos(newx, newy+1) == tileDirtFloor || GetPos(newx, newy+1) == tileCorridor){
						validTile = 0; //
						xmod = 0;
						ymod = -1;
					}
					else if (GetPos(newx-1, newy) == tileDirtFloor || GetPos(newx-1, newy) == tileCorridor){
						validTile = 1; //
						xmod = +1;
						ymod = 0;
					}
					else if (GetPos(newx, newy-1) == tileDirtFloor || GetPos(newx, newy-1) == tileCorridor){
						validTile = 2; //
						xmod = 0;
						ymod = +1;
					}
					else if (GetPos(newx+1, newy) == tileDirtFloor || GetPos(newx+1, newy) == tileCorridor){
						validTile = 3; //
						xmod = -1;
						ymod = 0;
					}
 
					//check that we haven't got another door nearby, so we won't get alot of openings besides
					//each other
					if (validTile > -1){
						if (GetPos(newx, newy+1) == tileDoor) //north
							validTile = -1;
						else if (GetPos(newx-1, newy) == tileDoor)//east
							validTile = -1;
						else if (GetPos(newx, newy-1) == tileDoor)//south
							validTile = -1;
						else if (GetPos(newx+1, newy) == tileDoor)//west
							validTile = -1;
					}
 
					//if we can, jump out of the loop and continue with the rest
					if (validTile > -1) break;
				}
			}
			if (validTile > -1){
				//choose what to build now at our newly found place, and at what direction
				int feature = GetRand(0, 100);
				if (feature <= ChanceRoom){ //a new room
					if (MakeRoom((newx+xmod), (newy+ymod), 8, 6, validTile)){
						currentFeatures++; //add to our quota
 
						//then we mark the wall opening with a door
						SetPos(newx, newy, tileDoor);
 
						//clean up infront of the door so we can reach it
						SetPos((newx+xmod), (newy+ymod), tileDirtFloor);
					}
				}
				else if (feature >= ChanceRoom){ //new corridor
					if (MakeCorridor((newx+xmod), (newy+ymod), 6, validTile)){
						//same thing here, add to the quota and a door
						currentFeatures++;
 
						SetPos(newx, newy, tileDoor);
					}
				}
			}
		}
 
 
		/*******************************************************************************
		All done with the building, let's finish this one off
		*******************************************************************************/
 
		//sprinkle out the bonusstuff (stairs, chests etc.) over the map
		int newx = 0;
		int newy = 0;
		int ways = 0; //from how many directions we can reach the random spot from
		int state = 0; //the state the loop is in, start with the stairs
		while (state != 10){
			for (int testing = 0; testing < 1000; testing++){
				newx = GetRand(1, Size->X-1);
				newy = GetRand(1, Size->Y-2); //cheap bugfix, pulls down newy to 0<y<24, from 0<y<25
 
				//System.out.println("x: " + newx + "\ty: " + newy);
				ways = 4; //the lower the better
 
				//check if we can reach the spot
				if (GetPos(newx, newy+1) == tileDirtFloor || GetPos(newx, newy+1) == tileCorridor){
				//north
					if (GetPos(newx, newy+1) != tileDoor)
					ways--;
				}
				if (GetPos(newx-1, newy) == tileDirtFloor || GetPos(newx-1, newy) == tileCorridor){
				//east
					if (GetPos(newx-1, newy) != tileDoor)
					ways--;
				}
				if (GetPos(newx, newy-1) == tileDirtFloor || GetPos(newx, newy-1) == tileCorridor){
				//south
					if (GetPos(newx, newy-1) != tileDoor)
					ways--;
				}
				if (GetPos(newx+1, newy) == tileDirtFloor || GetPos(newx+1, newy) == tileCorridor){
				//west
					if (GetPos(newx+1, newy) != tileDoor)
					ways--;
				}
 
				if (state == 0){
					if (ways == 0){
					//we're in state 0, let's place a "upstairs" thing
						SetPos(newx, newy, tileUpStairs);
						state = 1;
						break;
					}
				}
				else if (state == 1){
					if (ways == 0){
					//state 1, place a "downstairs"
						SetPos(newx, newy, tileDownStairs);
						state = 10;
						break;
					}
				}
			}
		}
 
 
		//all done with the map generation, tell the user about it and finish
		//printf("%s %d\n",msgNumObjects.c_str(), currentFeatures);
 
		return true;
	}
      
};
