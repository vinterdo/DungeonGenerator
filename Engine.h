#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <conio.h> 
#include <time.h>  
#include <time.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <windows.h>
#include <map>
   
#include "Point.h"  
#include "TextureManager.h"
#include "WorldMap.h"  
#include "DungeonGen.h"  

using namespace std; 

class Engine
{
      SDL_Surface *screen;
      TextureManager* TexManager;
      public:
      
      Engine()
      {
              TexManager = new TextureManager();
              cmain();
      } 
      
      private:
      
      void cmain()
      {
           LoadContent();
           
           DungeonGen* Generator = new DungeonGen(150);
           const float StepTime = 0.03f;
    
           Generator->Initalize();
    
           float dt = 0;
           float lastUpdate = time(NULL);
           float accumulator = 0;
    
           // SDL STUFF
    
           char *msg;
           int done;

           if (SDL_Init (SDL_INIT_VIDEO) < 0)
           {
               sprintf (msg, "Couldn't initialize SDL: %s\n", SDL_GetError ());
               MessageBox (0, msg, "Error", MB_ICONHAND); 
               free (msg);
               exit (1);
           }
           atexit (SDL_Quit);

           screen = SDL_SetVideoMode (640, 480, 16, SDL_SWSURFACE | SDL_DOUBLEBUF);
           if (screen == NULL)
           {
               sprintf (msg, "Couldn't set 640x480x16 video mode: %s\n",
               SDL_GetError ());
               MessageBox (0, msg, "Error", MB_ICONHAND); 
               free (msg);
               exit (2);
           }
           SDL_WM_SetCaption ("SDL MultiMedia Application", NULL);

           done = 0;
           while (!done)
           {
               SDL_Event event;

               while (SDL_PollEvent (&event))
               {
                   switch (event.type)
                   {
                       case SDL_KEYDOWN:
                            break;
                       case SDL_QUIT:
                            done = 1;
                            break;
                       default:
                            break;
                   }
               }
               Draw();
               SDL_Flip( screen );
           }
      }
      
      void LoadContent()
      {
           TexManager->LoadTex("Content/Textures/BlockWall.bmp");
      }
      
      void Draw()
      {
           SDL_BlitSurface( TexManager->GetTex("Content/Textures/BlockWall.bmp"), NULL, screen, NULL );
      }
};
