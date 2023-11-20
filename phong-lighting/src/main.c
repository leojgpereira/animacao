#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "world/window.h"
#include "world/shader.h"
#include "cglm/cglm.h"
#include "cglm/call.h"

int main()
{
    createWindow();
    struct Shader shaderCubo = createShader("res/shaders/main.vs", "res/shaders/main.fs");
    struct Shader shaderPiramide = createShader("res/shaders/main.vs", "res/shaders/main.fs");
    struct Shader shaderPrisma = createShader("res/shaders/main.vs", "res/shaders/main.fs");

    float verticesCubo[] = {
        // Posições                 // Cores            // Normais

        // CUBO
        // FRONTAL
        0.3, -0.8, -0.3, 0.01961f, 0.23529f, 0.36863f, 0.0f, 0.0f, 1.0f,  // Vértice 0 (cor 5)
        0.8, -0.8, -0.3, 0.01961f, 0.23529f, 0.36863f, 0.0f, 0.0f, 1.0f,  // Vértice 1 (cor 6)
        0.8, -0.35, -0.3, 0.01961f, 0.23529f, 0.36863f, 0.0f, 0.0f, 1.0f, // Vértice 2 (cor 7)
        0.3, -0.35, -0.3, 0.01961f, 0.23529f, 0.36863f, 0.0f, 0.0f, 1.0f, // Vértice 3 (cor 8)

        // DIREITA
        0.8, -0.8, -0.3, 0.98039f, 0.65098f, 1.00000f, 1.0f, 0.0f, 0.0f,  // Vértice 4 (cor 5)
        0.8, -0.8, -0.8, 0.98039f, 0.65098f, 1.00000f, 1.0f, 0.0f, 0.0f,  // Vértice 5 (cor 6)
        0.8, -0.35, -0.3, 0.98039f, 0.65098f, 1.00000f, 1.0f, 0.0f, 0.0f, // Vértice 6 (cor 7)
        0.8, -0.35, -0.8, 0.98039f, 0.65098f, 1.00000f, 1.0f, 0.0f, 0.0f, // Vértice 7 (cor 8)

        // TRASEIRA
        0.3, -0.8, -0.8, 0.63922f, 0.08627f, 0.12941f, 0.0f, 0.0f, -1.0f,  // Vértice 8 (cor 1)
        0.8, -0.8, -0.8, 0.63922f, 0.08627f, 0.12941f, 0.0f, 0.0f, -1.0f,  // Vértice 9 (cor 2)
        0.8, -0.35, -0.8, 0.63922f, 0.08627f, 0.12941f, 0.0f, 0.0f, -1.0f, // Vértice 10 (cor 3)
        0.3, -0.35, -0.8, 0.63922f, 0.08627f, 0.12941f, 0.0f, 0.0f, -1.0f, // Vértice 11 (cor 4)

        // ESQUERDA
        0.3, -0.8, -0.3, 0.43529f, 0.45098f, 0.18431f, -1.0f, 0.0f, 0.0f,  // Vértice 12 (cor 5)
        0.3, -0.8, -0.8, 0.43529f, 0.45098f, 0.18431f, -1.0f, 0.0f, 0.0f,  // Vértice 13 (cor 6)
        0.3, -0.35, -0.3, 0.43529f, 0.45098f, 0.18431f, -1.0f, 0.0f, 0.0f, // Vértice 14 (cor 7)
        0.3, -0.35, -0.8, 0.43529f, 0.45098f, 0.18431f, -1.0f, 0.0f, 0.0f, // Vértice 15 (cor 8)

        // TOPO
        0.8, -0.35, -0.3, 0.94510f, 0.82745f, 0.00784f, 0.0f, 1.0f, 0.0f, // Vértice 16 (cor 7)
        0.8, -0.35, -0.8, 0.94510f, 0.82745f, 0.00784f, 0.0f, 1.0f, 0.0f, // Vértice 17 (cor 8)
        0.3, -0.35, -0.3, 0.94510f, 0.82745f, 0.00784f, 0.0f, 1.0f, 0.0f, // Vértice 18 (cor 7)
        0.3, -0.35, -0.8, 0.94510f, 0.82745f, 0.00784f, 0.0f, 1.0f, 0.0f, // Vértice 19 (cor 8)

        // BASE
        0.8, -0.8, -0.3, 0.63529f, 0.98039f, 0.63922f, 0.0f, -1.0f, 0.0f, // Vértice 20 (cor 7)
        0.8, -0.8, -0.8, 0.63529f, 0.98039f, 0.63922f, 0.0f, -1.0f, 0.0f, // Vértice 21 (cor 8)
        0.3, -0.8, -0.3, 0.63529f, 0.98039f, 0.63922f, 0.0f, -1.0f, 0.0f, // Vértice 22 (cor 7)
        0.3, -0.8, -0.8, 0.63529f, 0.98039f, 0.63922f, 0.0f, -1.0f, 0.0f, // Vértice 23 (cor 8)
    };

    float verticesPiramide[] = {
        // PIRAMIDE
        // BASE
        -0.8, -0.25, 0.0, 0.59608f, 0.14902f, 0.28627f, 0.0f, -1.0f, 0.0f,  // Vértice 24 (cor 9)
        -0.3, -0.25, 0.0, 0.59608f, 0.14902f, 0.28627f, 0.0f, -1.0f, 0.0f,  // Vértice 25 (cor 10)
        -0.3, -0.25, -0.5, 0.59608f, 0.14902f, 0.28627f, 0.0f, -1.0f, 0.0f, // Vértice 26 (cor 11)
        -0.8, -0.25, -0.5, 0.59608f, 0.14902f, 0.28627f, 0.0f, -1.0f, 0.0f, // Vértice 27 (cor 12)

        // FRONTAL
        -0.8, -0.25, 0.0, 0.48627f, 0.51765f, 0.51373f, 0.0f, 0.0f, 1.0f,   // Vértice 28 (cor 9)
        -0.3, -0.25, 0.0, 0.48627f, 0.51765f, 0.51373f, 0.0f, 0.0f, 1.0f,   // Vértice 29 (cor 10)
        -0.55, 0.25, -0.25, 0.48627f, 0.51765f, 0.51373f, 0.0f, 0.0f, 1.0f, // Vértice 30 (cor 13)

        // DIREITA
        -0.3, -0.25, 0.0, 1.00000f, 0.64706f, 0.64706f, 1.0f, 0.0f, 0.0f,   // Vértice 31 (cor 10)
        -0.3, -0.25, -0.5, 1.00000f, 0.64706f, 0.64706f, 1.0f, 0.0f, 0.0f,  // Vértice 32 (cor 11)
        -0.55, 0.25, -0.25, 1.00000f, 0.64706f, 0.64706f, 1.0f, 0.0f, 0.0f, // Vértice 33 (cor 13)

        // TRASEIRA
        -0.8, -0.25, -0.5, 0.37647f, 0.69804f, 0.89804f, 0.0f, 0.0f, -1.0f,  // Vértice 34 (cor 9)
        -0.3, -0.25, -0.5, 0.37647f, 0.69804f, 0.89804f, 0.0f, 0.0f, -1.0f,  // Vértice 35 (cor 10)
        -0.55, 0.25, -0.25, 0.37647f, 0.69804f, 0.89804f, 0.0f, 0.0f, -1.0f, // Vértice 36 (cor 13)

        // ESQUERDA
        -0.8, -0.25, 0.0, 0.96863f, 0.92549f, 0.34902f, -1.0f, 0.0f, 0.0f,   // Vértice 37 (cor 9)
        -0.8, -0.25, -0.5, 0.96863f, 0.92549f, 0.34902f, -1.0f, 0.0f, 0.0f,  // Vértice 38 (cor 9)
        -0.55, 0.25, -0.25, 0.96863f, 0.92549f, 0.34902f, -1.0f, 0.0f, 0.0f, // Vértice 39 (cor 13)
    };

    float verticesPrisma[] = {
        // PRISMA HEXAGONAL
        // BASE
        -0.125, 0.35, -0.125, 1.00000f, 0.51373f, 0.43922f, 0.0f, -1.0f, 0.0f, // Vértice 40 (cor 14)
        0.125, 0.35, -0.125, 1.00000f, 0.51373f, 0.43922f, 0.0f, -1.0f, 0.0f,  // Vértice 41 (cor 15)
        0.25, 0.35, 0.0, 1.00000f, 0.51373f, 0.43922f, 0.0f, -1.0f, 0.0f,      // Vértice 42 (cor 16)
        0.125, 0.35, 0.125, 1.00000f, 0.51373f, 0.43922f, 0.0f, -1.0f, 0.0f,   // Vértice 43 (cor 17)
        -0.125, 0.35, 0.125, 1.00000f, 0.51373f, 0.43922f, 0.0f, -1.0f, 0.0f,  // Vértice 44 (cor 18)
        -0.25, 0.35, 0.0, 1.00000f, 0.51373f, 0.43922f, 0.0f, -1.0f, 0.0f,     // Vértice 45 (cor 19)

        // TOPO
        -0.125, 0.8, -0.125, 0.00000f, 0.69412f, 0.69020f, 0.0f, 1.0f, 0.0f, // Vértice 46 (cor 20)
        0.125, 0.8, -0.125, 0.00000f, 0.69412f, 0.69020f, 0.0f, 1.0f, 0.0f,  // Vértice 47 (cor 21)
        0.25, 0.8, 0.0, 0.00000f, 0.69412f, 0.69020f, 0.0f, 1.0f, 0.0f,      // Vértice 48 (cor 22)
        0.125, 0.8, 0.125, 0.00000f, 0.69412f, 0.69020f, 0.0f, 1.0f, 0.0f,   // Vértice 49 (cor 23)
        -0.125, 0.8, 0.125, 0.00000f, 0.69412f, 0.69020f, 0.0f, 1.0f, 0.0f,  // Vértice 50 (cor 24)
        -0.25, 0.8, 0.0, 0.00000f, 0.69412f, 0.69020f, 0.0f, 1.0f, 0.0f,     // Vértice 51 (cor 25)

        // FRONTAL
        -0.125, 0.35, -0.125, 0.30588f, 0.10196f, 0.23922f, 0.0f, 0.0f, -1.0f, // Vértice 52 (cor 14)
        0.125, 0.35, -0.125, 0.30588f, 0.10196f, 0.23922f, 0.0f, 0.0f, -1.0f,  // Vértice 53 (cor 15)
        -0.125, 0.8, -0.125, 0.30588f, 0.10196f, 0.23922f, 0.0f, 0.0f, -1.0f,  // Vértice 54 (cor 20)
        0.125, 0.8, -0.125, 0.30588f, 0.10196f, 0.23922f, 0.0f, 0.0f, -1.0f,   // Vértice 55 (cor 21)

        // DIREITA FRONTAL
        0.125, 0.35, -0.125, 0.81176f, 0.93333f, 0.81961f, 1.0f, 0.0f, -1.0f, // Vértice 56 (cor 15)
        0.25, 0.35, 0.0, 0.81176f, 0.93333f, 0.81961f, 1.0f, 0.0f, -1.0f,     // Vértice 57 (cor 16)
        0.125, 0.8, -0.125, 0.81176f, 0.93333f, 0.81961f, 1.0f, 0.0f, -1.0f,  // Vértice 58 (cor 21)
        0.25, 0.8, 0.0, 0.81176f, 0.93333f, 0.81961f, 1.0f, 0.0f, -1.0f,      // Vértice 59 (cor 22)

        // DIREITA TRASEIRA
        0.25, 0.35, 0.0, 1.00000f, 0.15294f, 0.40784f, 1.0f, 0.0f, 1.0f,    // Vértice 60 (cor 16)
        0.125, 0.35, 0.125, 1.00000f, 0.15294f, 0.40784f, 1.0f, 0.0f, 1.0f, // Vértice 61 (cor 17)
        0.25, 0.8, 0.0, 1.00000f, 0.15294f, 0.40784f, 1.0f, 0.0f, 1.0f,     // Vértice 62 (cor 22)
        0.125, 0.8, 0.125, 1.00000f, 0.15294f, 0.40784f, 1.0f, 0.0f, 1.0f,  // Vértice 63 (cor 23)

        // TRASEIRA
        0.125, 0.35, 0.125, 0.01961f, 0.87843f, 0.91373f, 0.0f, 0.0f, 1.0f,  // Vértice 64 (cor 17)
        -0.125, 0.35, 0.125, 0.01961f, 0.87843f, 0.91373f, 0.0f, 0.0f, 1.0f, // Vértice 65 (cor 18)
        0.125, 0.8, 0.125, 0.01961f, 0.87843f, 0.91373f, 0.0f, 0.0f, 1.0f,   // Vértice 66 (cor 23)
        -0.125, 0.8, 0.125, 0.01961f, 0.87843f, 0.91373f, 0.0f, 0.0f, 1.0f,  // Vértice 67 (cor 24)

        // ESQUERDA TRASEIRA
        -0.125, 0.35, 0.125, 0.11373f, 0.77647f, 0.56471f, -1.0f, 0.0f, 1.0f, // Vértice 68 (cor 18)
        -0.25, 0.35, 0.0, 0.11373f, 0.77647f, 0.56471f, -1.0f, 0.0f, 1.0f,    // Vértice 69 (cor 19)
        -0.125, 0.8, 0.125, 0.11373f, 0.77647f, 0.56471f, -1.0f, 0.0f, 1.0f,  // Vértice 70 (cor 24)
        -0.25, 0.8, 0.0, 0.11373f, 0.77647f, 0.56471f, -1.0f, 0.0f, 1.0f,     // Vértice 71 (cor 25)

        // ESQUERDA FRONTAL
        -0.25, 0.35, 0.0, 0.89020f, 0.25882f, 0.20392f, -1.0f, 0.0f, -1.0f,     // Vértice 72 (cor 19)
        -0.125, 0.35, -0.125, 0.89020f, 0.25882f, 0.20392f, -1.0f, 0.0f, -1.0f, // Vértice 73 (cor 14)
        -0.25, 0.8, 0.0, 0.89020f, 0.25882f, 0.20392f, -1.0f, 0.0f, -1.0f,      // Vértice 74 (cor 25)
        -0.125, 0.8, -0.125, 0.89020f, 0.25882f, 0.20392f, -1.0f, 0.0f, -1.0f,  // Vértice 75 (cor 20)
    };

    unsigned int indicesCubo[] = {
        // CUBO
        0, 1, 2, 2, 3, 0,       // Face frontal
        8, 9, 10, 8, 10, 11,    // Face traseira
        12, 13, 14, 13, 14, 15, // Lado esquerdo
        4, 5, 6, 5, 6, 7,       // Lado direito
        16, 17, 18, 17, 18, 19, // Topo
        20, 21, 22, 21, 22, 23, // Base
    };

    unsigned int indicesPiramide[] = {
        // PIRAMIDE
        (24 - 24), (25 - 24), (26 - 24), (26 - 24), (27 - 24), (24 - 24), // Base
        (28 - 24), (29 - 24), (30 - 24),                                  // Face frontal
        (31 - 24), (32 - 24), (33 - 24),                                  // Face lateral direita
        (34 - 24), (35 - 24), (36 - 24),                                  // Face traseira
        (37 - 24), (38 - 24), (39 - 24),                                  // Face lateral esquerda
    };

    unsigned int indicesPrisma[] = {
        // PRISMA HEXAGONAL
        (40 - 40), (41 - 40), (43 - 40), (40 - 40), (43 - 40), (44 - 40), (41 - 40), (42 - 40), (43 - 40), (40 - 40), (44 - 40), (45 - 40), // BASE
        (46 - 40), (47 - 40), (49 - 40), (46 - 40), (49 - 40), (50 - 40), (47 - 40), (48 - 40), (49 - 40), (46 - 40), (50 - 40), (51 - 40), // TOPO
        (52 - 40), (53 - 40), (55 - 40), (52 - 40), (55 - 40), (54 - 40),                                                                   // FACE FRONTAL
        (56 - 40), (57 - 40), (59 - 40), (56 - 40), (58 - 40), (59 - 40),                                                                   // FACE LATERAL DIREITA FRONTAL
        (60 - 40), (61 - 40), (63 - 40), (60 - 40), (62 - 40), (63 - 40),                                                                   // FACE LATERAL DIREITA TRASEIRA
        (64 - 40), (65 - 40), (67 - 40), (64 - 40), (66 - 40), (67 - 40),                                                                   // FACE TRASERIRA
        (68 - 40), (69 - 40), (71 - 40), (68 - 40), (70 - 40), (71 - 40),                                                                   // FACE LATERAL ESQUERDA TRASEIRA
        (72 - 40), (73 - 40), (75 - 40), (72 - 40), (74 - 40), (75 - 40),                                                                   // FACE LATERAL ESQUERDA FRONTAL
    };

    // Cubo
    unsigned int VBOCubo, VAOCubo, EBOCubo;
    glGenVertexArrays(1, &VAOCubo);
    glGenBuffers(1, &VBOCubo);
    glGenBuffers(1, &EBOCubo);

    glBindVertexArray(VAOCubo);

    glBindBuffer(GL_ARRAY_BUFFER, VBOCubo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesCubo), verticesCubo, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOCubo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesCubo), indicesCubo, GL_STATIC_DRAW);

    // Posição do atributo
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Atributo de cor
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Normal
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Piramide
    unsigned int VBOPiramide, VAOPiramide, EBOPiramide;
    glGenVertexArrays(1, &VAOPiramide);
    glGenBuffers(1, &VBOPiramide);
    glGenBuffers(1, &EBOPiramide);

    glBindVertexArray(VAOPiramide);

    glBindBuffer(GL_ARRAY_BUFFER, VBOPiramide);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPiramide), verticesPiramide, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOPiramide);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesPiramide), indicesPiramide, GL_STATIC_DRAW);

    // Posição do atributo
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Atributo de cor
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Normal
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Prisma
    unsigned int VBOPrisma, VAOPrisma, EBOPrisma;
    glGenVertexArrays(1, &VAOPrisma);
    glGenBuffers(1, &VBOPrisma);
    glGenBuffers(1, &EBOPrisma);

    glBindVertexArray(VAOPrisma);

    glBindBuffer(GL_ARRAY_BUFFER, VBOPrisma);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesPrisma), verticesPrisma, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOPrisma);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesPrisma), indicesPrisma, GL_STATIC_DRAW);

    // Posição do atributo
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Atributo de cor
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Normal
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    useShader(shaderCubo);
    useShader(shaderPiramide);
    useShader(shaderPrisma);

    while (!glfwWindowShouldClose(window.self))
    {
        updateWindow();

        mat4 viewCubo = GLM_MAT4_IDENTITY_INIT;
        glm_translate(viewCubo, (vec3){0.0f, -0.1f, -2.0f});

        mat4 projectionCubo = GLM_MAT4_IDENTITY_INIT;
        glm_perspective(glm_rad(45.0f), 800.0f / 800.0f, 0.1f, 10.0f, projectionCubo);

        // Cálculo da matriz de rotação em torno do eixo Y
        mat4 model = GLM_MAT4_IDENTITY_INIT;
        float angle = 0.25 * glfwGetTime();
        glm_translate(model, (vec3){0.55f, 0.0f, -0.55f});
        glm_rotate(model, angle, (vec3){0.0f, 1.0f, 0.0f});
        glm_translate(model, (vec3){-0.55f, 0.0f, 0.55f});

        // Passa a matriz de modelo para o shader
        setShaderMat4(shaderCubo, "model", model);
        setShaderMat4(shaderCubo, "view", viewCubo);
        setShaderMat4(shaderCubo, "projection", projectionCubo);
        setShaderVec3(shaderCubo, "lightPos", 0.55f, -0.575f, 0.0f);
        setShaderVec3(shaderCubo, "viewPos", 0.55f, -0.575f, 0.0f);

        glBindVertexArray(VAOCubo);
        glDrawElements(GL_TRIANGLES, (36 + 18), GL_UNSIGNED_INT, 0);

        mat4 viewPiramide = GLM_MAT4_IDENTITY_INIT;
        glm_translate(viewPiramide, (vec3){0.0f, 0.0f, -3.0f});

        mat4 projectionPiramide = GLM_MAT4_IDENTITY_INIT;
        glm_perspective(glm_rad(45.0f), 800.0f / 800.0f, 0.1f, 10.0f, projectionPiramide);

        mat4 model2 = GLM_MAT4_IDENTITY_INIT;
        float angle2 = 0.25 * glfwGetTime();
        glm_translate(model2, (vec3){-0.55f, 0.0f, -0.25f});
        glm_rotate(model2, angle2, (vec3){0.0f, 1.0f, 0.0f});
        glm_translate(model2, (vec3){0.55f, 0.0f, 0.25f});

        // Passa a matriz de modelo para o shader
        setShaderMat4(shaderPiramide, "model", model2);
        setShaderMat4(shaderPiramide, "view", viewPiramide);
        setShaderMat4(shaderPiramide, "projection", projectionPiramide);
        setShaderVec3(shaderPiramide, "lightPos", -0.55f, 0.0f, 0.25f);
        setShaderVec3(shaderPiramide, "viewPos", -0.55f, -0.1f, 0.25f);

        glBindVertexArray(VAOPiramide);
        glDrawElements(GL_TRIANGLES, (36 + 18), GL_UNSIGNED_INT, 0);

        mat4 viewPrisma = GLM_MAT4_IDENTITY_INIT;
        glm_translate(viewPrisma, (vec3){0.0f, 0.0f, -4.0f});

        mat4 projectionPrisma = GLM_MAT4_IDENTITY_INIT;
        glm_perspective(glm_rad(45.0f), 800.0f / 800.0f, 0.1f, 10.0f, projectionPrisma);

        mat4 model3 = GLM_MAT4_IDENTITY_INIT;
        float angle3 = 0.25 * glfwGetTime();
        glm_rotate(model3, angle3, (vec3){0.0f, 1.0f, 0.0f});

        // Passa a matriz de modelo para o shader
        setShaderMat4(shaderPrisma, "model", model3);
        setShaderMat4(shaderPrisma, "view", viewPrisma);
        setShaderMat4(shaderPrisma, "projection", projectionPrisma);
        setShaderVec3(shaderPrisma, "lightPos", 0.0f, 0.55f, 0.6f);
        setShaderVec3(shaderPrisma, "viewPos", 0.0f, 0.55f, 0.6f);

        glBindVertexArray(VAOPrisma);
        glDrawElements(GL_TRIANGLES, (60), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window.self);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAOCubo);
    glDeleteBuffers(1, &VBOCubo);
    glDeleteBuffers(1, &EBOCubo);

    glDeleteVertexArrays(1, &VAOPiramide);
    glDeleteBuffers(1, &VBOPiramide);
    glDeleteBuffers(1, &EBOPiramide);

    glDeleteVertexArrays(1, &VAOPrisma);
    glDeleteBuffers(1, &VBOPrisma);
    glDeleteBuffers(1, &EBOPrisma);

    terminateWindow();

    return 0;
}
