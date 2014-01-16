

class TextureManager
{
      private:
        TextureManager() {}
        TextureManager(const TextureManager &);
        TextureManager& operator=(const TextureManager&);
        ~TextureManager() {}
        
      std::map<std::string, SDL_Surface*> Textures;
        
        public:
        static TextureManager& GetInstance()
        {
          static TextureManager instance;
          return instance;
        }
        
      
             
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
