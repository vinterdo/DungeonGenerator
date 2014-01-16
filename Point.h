class Point
{
	public:
	
	int X;
	int Y;
	
	Point(int _X, int _Y)
	{
       X = _X;
       Y = _Y;
    }
    
    float SqaredLenghtFromStart()
    {
          return X * X + Y * Y;
    }
    
    float SqaredLenghtFromPoint(Point* P)
    {
          return (P->X - X) * (P->X - X) + (P->Y - Y) * (P->Y - Y);
    }
};
