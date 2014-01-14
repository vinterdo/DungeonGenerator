
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
        tileDirtWall,
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
          Map = new char[SizeX * SizeY];
          
          for(int y = 0; y < Size->Y; y++)
             {
                     for(int x = 0; x < Size->X; x++)
                     {
                             Map[(y * Size->X + x)] = 'X';
                     }
             }
      }
      
      void Draw()
      {
             for(int y = 0; y < Size->Y; y++)
             {
                     for(int x = 0; x < Size->X; x++)
                     {
                             printf("%c", Map[(y * Size->X + x)]);
                     }
             std::cout << std::endl;
             }
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
        time_t seed;
        seed = time(NULL) + OldSeed;
        OldSeed = seed;
 
        srand(seed);
 
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
      
};
