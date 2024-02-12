#pragma once

namespace Engine
{
	class vec2
	{
	public:
		float a = 0;
		float b = 0;
		vec2(float a, float b)
		{
			this->a = a;
			this->b = b;
		};

		vec2 operator+(vec2 const& obj)
		{
			vec2 p(0,0);
			p.a = a + obj.a;
			p.b = b + obj.b;
			return p;
		}
		vec2 operator*(vec2 const& obj)
		{
			vec2 p(0, 0);
			p.a = a * obj.a;
			p.b = b * obj.b;
			return p;
		}
		vec2 operator/(vec2 const& obj)
		{
			vec2 p(0, 0);
			p.a = a / obj.a;
			p.b = b / obj.b;
			return p;
		}
		vec2 operator-(vec2 const& obj)
		{
			vec2 p(0, 0);
			p.a = a - obj.a;
			p.b = b - obj.b;
			return p;
		}
	}; 
};