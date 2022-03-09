#pragma once
class Vec2
{
public:
	int x;
	int y;
	
	Vec2(){
		this->x = 0;
		this->y = 0;
	}
	
	Vec2(int x, int y){
		this->x = x;
		this->y = y;
	}

	Vec2 operator + (const Vec2& rhs)
	{
		return Vec2(x + rhs.x, y + rhs.y);
	}
};

