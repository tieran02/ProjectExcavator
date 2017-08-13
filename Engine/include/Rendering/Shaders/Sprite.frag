R"(
#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform vec3 color = vec3(1,1,1);
uniform sampler2D texture1;

void main()
{
    FragColor = texture(texture1, TexCoord) * vec4(color, 1.0);
}
)"