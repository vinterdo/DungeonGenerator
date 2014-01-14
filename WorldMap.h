
class WorldMap
{
      public:
      Point* Size;
      char* Map;
      
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
};
