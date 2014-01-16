class Tile
{
      std::string Texture;
      int id;
      
      void Draw(int Posx, int Posy, SDL_Surface* screen)
      {
           SDL_Rect* offset = new SDL_Rect();
           offset->x = Posx * 16;
           offset->y = Posy * 16;
           SDL_BlitSurface( TextureManager::GetInstance().GetTex(Texture), NULL, screen, offset );               
      }
};
