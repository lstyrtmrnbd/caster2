#include <iostream>
#include <png.h>
#include "raytrace.hpp"

using std::ostream, std::cout;

ostream& operator<< (ostream &out, const vec3 &vec) {
  out << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
  return out;
}

ostream& operator<< (ostream &out, const Sphere &sphere) {
  out << "Sphere("
      << "pos:" << sphere.position
      << ", rad:" << sphere.radius << ")";
  return out;
}

ostream& operator<< (ostream &out, const Triangle &triangle) {
  out << "Triangle("
      << "p1:" << triangle.p1 << ", "
      << "p2:" << triangle.p2 << ", "
      << "p3:" << triangle.p3 << ", "
      << "normal:" << triangle.normal << ")";
  return out;
}

int main() {

  Material* g = new Material(vec3(0.0,1.0,0.0));
  Sphere* s = new Sphere(vec3(0.1,0.2,0.3), 0.5, g);
  Triangle* t = new Triangle(vec3(1.0,0.0,0.0),
                             vec3(0.0,1.0,0.0),
                             vec3(0.0,0.0,1.0), g);
  cout << *s << "\n";
  cout << *t << "\n";
  return 0;
}
