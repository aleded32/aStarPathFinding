#include <iostream>
#include <vector>



template<typename T>

class grid
{
public:

	int width, height, cellsize, originPoint;
    T* gridArray;

	grid(int width, int height, int cellsize, int originPoint, int value);
	~grid();

};