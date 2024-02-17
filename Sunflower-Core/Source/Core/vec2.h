#pragma once

namespace Sunflower
{
	class vec2
	{
	public:
		float x = 0;
		float y = 0;
		vec2(float a, float b)
		{
			this->x = a;
			this->y = b;
		};

		vec2()
		{
			this->x = 0;
			this->y = 0;
		};

		vec2 operator+(vec2 const& obj)
		{
			vec2 p(0,0);
			p.x = x + obj.x;
			p.y = y + obj.y;
			return p;
		}
		vec2 operator*(vec2 const& obj)
		{
			vec2 p(0, 0);
			p.x = x * obj.x;
			p.y = y * obj.y;
			return p;
		}
		vec2 operator/(vec2 const& obj)
		{
			vec2 p(0, 0);
			p.x = x / obj.x;
			p.y = y / obj.y;
			return p;
		}
		vec2 operator-(vec2 const& obj)
		{
			vec2 p(0, 0);
			p.x = x - obj.x;
			p.y = y - obj.y;
			return p;
		}
	}; 
};