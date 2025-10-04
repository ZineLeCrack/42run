#version 330 core
layout(location = 0) in vec3 aPos;

uniform mat4 MVP;

out vec3 FragPos;

void main()
{
    gl_Position = MVP * vec4(aPos, 1.0);
    FragPos = aPos; // On passe la position telle quelle
}
