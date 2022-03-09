#pragma once
#include "Vec2.h"
#include <vector>

class Node
{
public:
	int rows = 0;
	int cols = 0;
	int maxX = 0;
	int maxY = 0;

	static const Vec2 offsets[8];
	Vec2 Pos;
	bool state = false; //False - dead True - Alive
	int AliveNei = 0;
	Node(){}
	Node(int x, int y, int rows, int cols, int maxX, int maxY)
	{
		this->Pos.x = x;
		this->Pos.y = y;
		this->rows = rows;
		this->cols = cols;
		this->maxX = maxX;
		this->maxY = maxY;
	}

	//Array of nieghbours
	//Node* neighbours[8]{nullptr};
	std::vector<Node*> neighbours;
	
	
	void InvertState();
	void GetNeighbourStats();
	void FindNeighbours(Node node_arr[]);
	void DecideIfDeadOccur();
	Node* FindSpecifiedNeighbours_PTR(Node node_arr[], int x, int y, int sizeOfArray);
};

