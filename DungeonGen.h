
class DungeonGen
{
      
      public:
      int CellsNum;
      WorldMap* Map;
      
      DungeonGen(int _CellsNum)
      {
          CellsNum = _CellsNum;
          Map = new WorldMap(10, 10);
      }
      
      void Initalize()
      {
           Map->SetPos(2, 2, ' ');
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
