

class TextureManager
{
      std::map<std::string, SDL_Surface*> Textures;
      
      public:
             
      void LoadTex(std::string Name)
      {
             Textures.insert(std::pair<std::string, SDL_Surface*>(Name, SDL_LoadBMP(Name.c_str())));
      }
      
      void FreeTex(std::string Name)
      {
             
      }
      
      SDL_Surface* GetTex(std::string Name)
      {
             return Textures[Name];
      }
};
