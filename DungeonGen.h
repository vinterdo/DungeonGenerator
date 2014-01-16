
class DungeonGen
{
      
      public:
      int CellsNum;
      WorldMap* Map;
      
      Player* Player1;
      
      DungeonGen(int _CellsNum)
      {
          CellsNum = _CellsNum;
          Map = new WorldMap(60, 20);
          Player1 = new Player();
      }
      
      void Initalize()
      {
      }
      
      void Update()
      {
      }
      
      void Draw(SDL_Surface* screen)
      {
           for(int y=0; y < Map->Size->Y; y++)
           {
                   for(int x=0; x < Map->Size->X; x++)
                   {
                           SDL_Rect* offset = new SDL_Rect();
                           offset->x = x * 16;
                           offset->y = y * 16;
                           
                           switch(Map->GetPos(x,y))
                           {
                               case 0:
                                    break;
                               case WorldMap::tileDirtWall:
                                   SDL_BlitSurface( TextureManager::GetInstance().GetTex("Content/Textures/StoneWall.bmp"), NULL, screen, offset );
                                   break;
                               case WorldMap::tileDirtFloor:
                                   SDL_BlitSurface( TextureManager::GetInstance().GetTex("Content/Textures/StoneFloor.bmp"), NULL, screen, offset );
                                   break;
                               case WorldMap::tileStoneWall:
                                   SDL_BlitSurface( TextureManager::GetInstance().GetTex("Content/Textures/StoneWall.bmp"), NULL, screen, offset );
                                   break;
                               case WorldMap::tileDoor:
                                   SDL_BlitSurface( TextureManager::GetInstance().GetTex("Content/Textures/Door.bmp"), NULL, screen, offset );
                                   break;
                               case WorldMap::tileCorridor:
                                   SDL_BlitSurface( TextureManager::GetInstance().GetTex("Content/Textures/StoneFloor.bmp"), NULL, screen, offset );
                                   break;
                               case WorldMap::tileDownStairs:
                                   SDL_BlitSurface( TextureManager::GetInstance().GetTex("Content/Textures/StairsDown.bmp"), NULL, screen, offset );
                                   break;
                               case WorldMap::tileUpStairs:
                                   SDL_BlitSurface( TextureManager::GetInstance().GetTex("Content/Textures/StairsUp.bmp"), NULL, screen, offset );
                                   break;
                               default:
                                   SDL_BlitSurface( TextureManager::GetInstance().GetTex("Content/Textures/BlockWall.bmp"), NULL, screen, offset );
                                   break;
                           }
                   }
           }
           
           // Draw player
           
           SDL_Rect* offset = new SDL_Rect();
           offset->x = Player1->Position->X * 16;
           offset->y = Player1->Position->Y * 16;
           
           SDL_BlitSurface( TextureManager::GetInstance().GetTex("Content/Textures/BlockWall.bmp"), NULL, screen, offset );
                                   
      }
      
      void PollInput(SDL_Event* event)
      {
           Player1->PollInput(event);
      }
      
      
};
