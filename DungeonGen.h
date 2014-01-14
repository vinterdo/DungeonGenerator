
class DungeonGen
{
      
      public:
      int CellsNum;
      WorldMap* Map;
      
      DungeonGen(int _CellsNum)
      {
          CellsNum = _CellsNum;
          Map = new WorldMap(60, 20);
      }
      
      void Initalize()
      {
      }
      
      void Update()
      {
      }
      
      void Draw()
      {
           Map->Draw();
      }
      
      void PollInput()
      {
      }
      
      
};
