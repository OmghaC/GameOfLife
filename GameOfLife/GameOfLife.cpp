#include <iostream>
#include "Vec2.h"
#include "Node.h"

const int rows = 9;
const int cols = 7;
const int max_X = rows-1;
const int max_Y = cols-1;
Node node_arr[rows * cols];

void PrintArray()
{
	for (int i = 0; i < rows * cols; i++)
	{
		if (i % rows == 0 && i !=0)
		{
			std::cout << std::endl;
		}

		bool tempState = node_arr[i].state;
		if (tempState == true)
		{
			std::cout << "*";
		}
		else
		{
			std::cout << ".";
		}
	}
}

void InitData()
{
	int index = 0;
	for (int y = 0; y < cols; y++)
	{
		for (int x = 0; x < rows; x++)
		{
			Node tempNode = Node(x, y, rows, cols, max_X, max_Y);
			if ((x == 3 && y == 2) || (x == 3 && y == 3) || (x == 4 && y == 2) || (x == 4 && y == 3) || (x == 5 && y == 2) || (x == 5 && y == 3) || (x == 8 && y == 2) || (x == 8 && y == 3) || (x == 8 && y == 4))
			{
				tempNode.state = true;
				node_arr[index] = tempNode;
				index++;
			}
			else
			{
				node_arr[index] = tempNode;
				index++;
			}
		}
	}
}

int main()
{
	//Gen 0 Init
	int gen = 0;
	InitData();
	//Gen 0 end
	PrintArray();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	//Gen 1 init
	for (int i = 0; i < rows * cols; i++)
	{
		node_arr[i].FindNeighbours(node_arr);
	}

	for (int i = 0; i < rows * cols; i++)
	{
		node_arr[i].GetNeighbourStats();
	}
	for (int i = 0; i < rows * cols; i++)
	{
		node_arr[i].DecideIfDeadOccur();
	}
	PrintArray();
	std::cin.get();
	//Gen 1 end
}
