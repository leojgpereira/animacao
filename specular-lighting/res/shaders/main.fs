#version 330 core

out vec4 FragColor;
in vec3 ourColor;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 viewPos;

void main() {
    vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
    float specularStrength = 1.0;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    FragColor = vec4(specular, 1.0);
}