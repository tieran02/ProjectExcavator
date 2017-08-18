#include <Rendering/Color.h>
#include "Math/Math.h"

Color Color::Normilized() const
{
	return Color(Math::Normalize(R, 255.0f), Math::Normalize(G, 255.0f), Math::Normalize(B, 255.0f), Math::Normalize(A, 255.0f));
}
