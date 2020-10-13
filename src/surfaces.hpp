#include <iostream>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

using vec3 = glm::dvec3;

using glm::cross, glm::normalize;

//// Surface Structures

struct Sphere {
  vec3 position;
  double radius;

  Sphere(vec3 pos, double rad)
    : position(pos), radius(rad) {}
};

struct Triangle {
  vec3 p1, p2, p3, normal;

  Triangle(vec3 p1, vec3 p2, vec3 p3)
    : p1(p1), p2(p2), p3(p3),
      normal(normalize(cross(p2 - p1, p3 - p1))) {}
};

struct Plane {
  vec3 position, normal;

  Plane(vec3 pos, vec3 norm)
    : position(pos), normal(norm) {}
};
