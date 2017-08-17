#include <Rendering/Color.h>
#include "Math/Math.h"

Color Color::Normilized() const
{
	return Color(Math::NormalizeValue(R, 255.0f), Math::NormalizeValue(G, 255.0f), Math::NormalizeValue(B, 255.0f), Math::NormalizeValue(A, 255.0f));
}
