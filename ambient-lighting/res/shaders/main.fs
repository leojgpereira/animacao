#version 330 core

out vec4 FragColor;
in vec3 ourColor;

void main() {
    float ambientStrength = 0.1;
    vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
    vec3 ambient = ambientStrength * lightColor;

    vec3 result = ambient * ourColor;
    FragColor = vec4(result, 1.0f);
}