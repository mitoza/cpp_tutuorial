#version 330 core
out vec4 color;

in vec3 FragPos;
in vec3 Normal;

uniform vec3 lightPos;
uniform vec3 viewPos;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main() {
  //color = vec4(lightColor * objectColor, 1.0f);

  // ambient lighting / general lighting
  float ambientStrength = 0.2f;
  vec3 ambient = ambientStrength * lightColor;

  // defuse lighting / direct light
  vec3 norm = normalize(Normal);
  vec3 lightDir = normalize(lightPos - FragPos);
  float diff = max(dot(norm, lightDir), 0.0f); // dot() - dot product
  vec3 diffuse = diff * lightColor;

  // specular lighting / little shiny light
  float specularStrength = 1.0f;
  vec3 viewDir = normalize(viewPos - FragPos);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
  vec3 specular = specularStrength * spec * lightColor;

  vec3 result = (ambient + diffuse + specular) * objectColor;
  color = vec4(result, 1.0f);
}
