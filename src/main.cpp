#include <iostream>
#include <png.h>
#include <glm/vec3.hpp>

using vec3 = glm::dvec3;

struct Sphere {
  vec3 position;
  double radius;

  Sphere(vec3 pos, double rad);
};

Sphere::Sphere(vec3 pos, double rad)
  : position(pos), radius(rad) {}

std::ostream& operator<< (std::ostream &out, const Sphere &sphere) {

  out << "Sphere("
      << sphere.position.x << ", "
      << sphere.position.y << ", "
      << sphere.position.z << ")";

  return out;
}

int main() {

  Sphere* s = new Sphere(vec3(0.1,0.2,0.3), 0.5);
  std::cout << *s << "\n";
  return 0;
}
