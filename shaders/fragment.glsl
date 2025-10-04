#version 330 core

in vec3 FragPos;   // Position du pixel dans l’espace (envoyée depuis le vertex shader)
out vec4 FragColor;

void main()
{
    // Couleur de base du couloir
    vec3 baseColor = vec3(0.7, 0.7, 0.8);

    // Distance depuis la caméra (ici on suppose que z augmente vers l'avant)
    float dist = FragPos.z;

    // Calcul d'une intensité de lumière qui décroît avec la distance
    float brightness = 1.0 - clamp(dist / 30.0, 0.0, 1.0); 
    // -> z=0 → 1.0 (éclairé)
    // -> z=30 → 0.0 (sombre)

    // Appliquer l’éclairage
    vec3 color = baseColor * (0.2 + brightness * 0.8); 
    // (0.2) = luminosité minimale, pour pas que tout soit noir

    FragColor = vec4(color, 1.0);
}
