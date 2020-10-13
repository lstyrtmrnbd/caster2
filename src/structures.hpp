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

//// Tracing Structures

struct Ray {
  vec3 origin, direction;
  
  Ray(vec3 origin, vec3 direction)
    : origin(origin), direction(direction) {}
};

struct Material {
  vec3 color, ambk, diffk, speck;
  double shineA;

  Material(vec3 color, vec3 ambk, vec3 diffk, vec3 speck)
    : color(color), ambk(ambk), diffk(difk), speck(speck),
      shineA(shineA) {}
};

struct IntersectionRecord {
  vec3 point, normal, direction; // ray.direction
  double distance;
  Material* material;

  IntersectionRecord(double distance, vec3 point, vec3 normal, vec3 direction)
    : distance(distance), point(point), normal(normal), direction(direction);
};


