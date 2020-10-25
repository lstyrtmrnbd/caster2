#include <vector>
#include <utility>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

using std::vector, std::pair;
using vec3 = glm::dvec3;
using glm::cross, glm::normalize, glm::dot;

//// Surface Structures

struct Material {
  vec3 color = vec3(0.0, 0.0, 0.0);
  vec3 ambk  = vec3(1.0,1.0,1.0);
  vec3 diffk = vec3(1.0,1.0,1.0);
  vec3 speck = vec3(1.0,1.0,1.0);
  double shineA;

  // plain colored material
  Material(vec3 color) : color(color) {}
  
  Material(vec3 color, vec3 ambk, vec3 diffk, vec3 speck, double shineA)
    : color(color), ambk(ambk), diffk(diffk),
      speck(speck), shineA(shineA) {}
};

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

//// Light Structures

struct AmbientLight {
  vec3 intensity;

  AmbientLight(vec3 intensity)
    : intensity(intensity) {}
};

struct DistantLight {
  vec3 direction, intensity;
  
  DistantLight(vec3 direction, vec3 intensity)
    : direction(direction), intensity(intensity) {}
};

struct PointLight {
  vec3 position, intensity;
  const double epsilon = .75; // used to decrease distance attenuation

  PointLight(vec3 position, vec3 intensity)
    : position(position), intensity(intensity) {}
};

//// Tracing Structures

struct Ray {
  vec3 origin, direction;
  
  Ray(vec3 origin, vec3 direction)
    : origin(origin), direction(direction) {}
};

struct Intersection {
  double distance;
  vec3 point, normal, direction; // ray.direction
  Material* material;

  Intersection(double distance, vec3 point, vec3 normal, vec3 direction, Material* material)
    : distance(distance), point(point), normal(normal),
      direction(direction), material(material) {}
};

struct Scene {
  vector<pair<Plane, Material*>> planes;
  vector<pair<Sphere, Material*>> spheres;
  vector<pair<Triangle, Material*>> triangles;

  
};
