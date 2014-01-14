class Engine
{
      public:
      
      Engine()
      {
              cmain();
      }
      
      void cmain()
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
        
        
           Generator->Map->SetPos(2, 2, ' ');
        system("cls");
        Generator -> Draw();
    }
    
      }
};