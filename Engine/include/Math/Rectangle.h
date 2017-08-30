#pragma once
#include <Math/Vector2.h>

namespace Math {
	struct Rectangle
	{
		float x, y, width, height;
		Rectangle(float _x, float _y, float _width, float _height) : x(_x), y(_y), width(_width), height(_height) {}
		Rectangle() : x(0), y(0), width(0), height(0) {}

		float Left() const { return x; }
		float Right() const { return x + width; }
		float Bottom() const { return y; }
		float Top() const { return y + height; }

		Vector2 BottomLeft() const { return Vector2(Left(), Bottom()); }
		Vector2 BottomRight() const { return Vector2(Right(), Bottom()); }
		Vector2 TopLeft() const { return Vector2(Left(), Top()); }
		Vector2 TopRight() const { return Vector2(Right(), Top()); }
		Vector2 Center() const { return Vector2(x + (width / 2), y + (height / 2)); }

		bool Overlap(Rectangle& R2) const
		{
			if (Left() <= R2.Right() && Right() >= R2.Left() && Top() >= R2.Bottom() && Bottom() <= R2.Top())
				return true;
			return false;
		}
	};
}

inline bool operator ==(Math::Rectangle R1, Math::Rectangle R2)
{
	return R1.x == R2.x && R1.y == R2.y && R1.width == R2.width && R1.height == R2.height;
}

