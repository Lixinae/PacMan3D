#version 330 core

// Entrees du shader
in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec2 vTexCoords; // Coordonnées de texture du sommet

out vec3 vFragColor;

void main() {
  vFragColor = normalize(vNormal_vs);
}
