#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#include "Point.h"
#include "WorldMap.h"
#include "DungeonGen.h"

using namespace std;

int main(int argc, char *argv[])
{
    DungeonGen* Generator = new DungeonGen(150);
    const float StepTime = 0.03f;
    
    Generator->Initalize();
    
    float dt = 0;
    float lastUpdate = time(NULL);
    float accumulator = 0;
    
    
    while(true)
    {
        dt = time(NULL) - lastUpdate;
        lastUpdate += dt;
        
        accumulator += dt;
        
        Generator->PollInput();
        while(accumulator > StepTime)
        {
            Generator->Update();
            
            accumulator -= StepTime;
        
        }
        Generator -> Draw();
    }
    
    system("PAUSE");
    return 0;
}
