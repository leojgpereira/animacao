#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

out vec3 ourColor;

uniform mat4 model; // Matriz de modelo para a rotação
uniform mat4 projection; // Matriz de modelo para a projeção
uniform mat4 view;

void main() {
    gl_Position = projection * view * model * vec4(aPos, 1.0); // Aplica a matriz de modelo à posição
    // gl_Position = vec4(posicao.x, posicao.y, posicao.z, posicao.w);
    ourColor = aColor;
}
