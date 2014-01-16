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
#include "Player.h"
#include "WorldMap.h"  
#include "DungeonGen.h"  

using namespace std; 

class Engine
{
      public:
             
      SDL_Surface *screen;
      DungeonGen* Generator;
      
      Engine()
      {
              cmain();
      } 
      
      void cmain()
      {
           LoadContent();
           
           const float StepTime = 0.03f;
           Generator = new DungeonGen(150);
           Generator->Initalize();
    
    
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

           screen = SDL_SetVideoMode (1024, 768, 16, SDL_SWSURFACE | SDL_DOUBLEBUF);
           if (screen == NULL)
           {
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
                   Generator->PollInput(&event);
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
               SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
               Draw();
               SDL_Flip( screen );
               //SDL_Delay(10);
           }
      }
      
      void LoadContent()
      {
           TextureManager::GetInstance().LoadTex("Content/Textures/BlockWall.bmp");
           TextureManager::GetInstance().LoadTex("Content/Textures/StoneWall.bmp");
           TextureManager::GetInstance().LoadTex("Content/Textures/StoneFloor.bmp");
           TextureManager::GetInstance().LoadTex("Content/Textures/Door.bmp");
           TextureManager::GetInstance().LoadTex("Content/Textures/StairsDown.bmp");
           TextureManager::GetInstance().LoadTex("Content/Textures/StairsUp.bmp");
      }
      
      void Draw()
      {
           Generator->Draw(screen);
      }
};
