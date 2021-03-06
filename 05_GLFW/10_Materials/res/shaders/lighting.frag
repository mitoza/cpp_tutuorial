#version 330 core
struct Material {
  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
  float shininess;
};

struct Light {
  vec3 position;

  vec3 ambient;
  vec3 diffuse;
  vec3 specular;
};

out vec4 color;

in vec3 FragPos;
in vec3 Normal;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main() {
  // ambient lighting / general lighting // Окружающий свет
  vec3 ambient = light.ambient * material.ambient;

  // diffuse lighting / direct light // Рассеивание
  vec3 norm = normalize(Normal);
  vec3 lightDir = normalize(light.position - FragPos);
  float diff = max(dot(norm, lightDir), 0.0f); // dot() - dot product
  vec3 diffuse = light.diffuse * (diff * material.diffuse);

  // specular lighting / little shiny light // Зеркальный свет
  vec3 viewDir = normalize(viewPos - FragPos);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
  vec3 specular = light.specular * (spec * material.specular);

  // Combined (Phong)
  vec3 result = ambient + diffuse + specular;
  color = vec4(result, 1.0f);
}
