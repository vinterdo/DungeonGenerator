
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
      
      char GetCell(int x, int y)
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
};
