#include "Node.h"
#include <iostream>

const Vec2 Node::offsets[8] = {
	Vec2(0, 1),
	Vec2(0, -1),
	Vec2(1, 1),
	Vec2(1, 0),
	Vec2(1, -1),
	Vec2(-1, -1),
	Vec2(-1, 0),
	Vec2(-1, 1)
};

void Node::InvertState()
{
	this->state = !this->state;
}

void Node::GetNeighbourStats()
{
	int aliveNeighbours = 0;
	for (int i = 0; i < neighbours.size(); i++)
	{
		if (neighbours.at(i)->state == true)
		{
			aliveNeighbours++;
		}
	}
	
	this->AliveNei = aliveNeighbours;
}

void Node::DecideIfDeadOccur()
{
	if (this->state == true && (AliveNei < 2 || AliveNei > 3))
	{
		this->state = false;
	}

	if (this->state == false && AliveNei == 3)
	{
		this->state = true;
	}
}


void Node::FindNeighbours(Node node_arr[])
{
	for (int i = 0; i < 8; i++)
	{
		Node* tempNode = FindSpecifiedNeighbours_PTR(node_arr, this->Pos.x+offsets[i].x, this->Pos.y+offsets[i].y, this->rows*this->cols);
		if (tempNode != NULL)
		{
			this->neighbours.push_back(tempNode);
		}
	}
}

Node* Node::FindSpecifiedNeighbours_PTR(Node node_arr[], int x, int y, int sizeOfArray)
{
	if (x < 0) x = maxX;
	if (y < 0) y = maxY;
	if (x > maxX) x = 0;
	if (y > maxY) y = 0;

	for (int i = 0; i < sizeOfArray; i++)
	{
		Node* tempNode = &node_arr[i];
		if (tempNode->Pos.x == x && tempNode->Pos.y == y)
		{
			return tempNode;
		}
	}
}
