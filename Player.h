class Player
{
      public:
      Point* Position;
      
      Player()
      {
              Position = new Point(0,0);
      }
      
      void PollInput(SDL_Event* event)
      {
           switch (event->type)
                   {
                       case SDL_KEYDOWN:
                            switch( event->key.keysym.sym )
                            {
                                case SDLK_UP: Position->Y--; break;
                                case SDLK_DOWN: Position->Y++; break;
                                case SDLK_LEFT: Position->X--; break;
                                case SDLK_RIGHT: Position->X++; break;
                            }
                            break;
                   }
      }
};
