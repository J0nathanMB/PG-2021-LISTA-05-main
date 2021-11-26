#version 450 core
in vec4 ourColor;
in vec2 TexCoord;

out vec4 color;

// pixels da textura
uniform sampler2D tex1, tex2;

uniform int idCanal;

void main()
{
    color = texture(tex1, TexCoord) * texture(tex2, TexCoord);

    float media = color.r * 0.2125 + color.g * 0.7154 + color.b * 0.0721;

    color = vec4(media, media, media, color.a);}
