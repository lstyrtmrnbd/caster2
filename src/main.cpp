#include <iostream>
#include <memory>
#include <optional>
#include <png.h>
#include "raytrace.hpp"

using std::ostream, std::cout;
using std::make_unique;

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
  const auto [p1,p2,p3,normal] = triangle;
  out << "Triangle("
      << "p1:" << p1 << ", "
      << "p2:" << p2 << ", "
      << "p3:" << p3 << ", "
      << "normal:" << normal << ")";
  return out;
}

ostream& operator<< (ostream& out, const Intersection& intersection) {
  const auto [distance,point,normal,direction,material] = intersection;
  out << "Intersection("
      << distance << ", "
      << point << ", "
      << normal << ", "
      << direction << ", "
      << material << ")";
  return out;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    for (const auto& el : vec) {
      os << el << ' ';
    }
    return os;
}

int main() {

  auto g = make_unique<Material>(vec3(0.0,1.0,0.0));
  auto s = make_unique<Sphere>(vec3(0.1,0.2,0.3), 0.5);
  auto t = make_unique<Triangle>(vec3(1.0,0.0,0.0),
                                 vec3(0.0,1.0,0.0),
                                 vec3(0.0,0.0,1.0));
  auto r = make_unique<Ray>(vec3(0.0,0.0,0.0),
                            vec3(0.0,0.0,1.0));
  
  cout << "welcome to caster2" << "\n";
  cout << *s << "\n";
  cout << *t << "\n";

  //auto intersections = new vector<optional<Intersection>>{};
  //intersections->push_back(intersect(*s, *r, g.get()));

  //cout << intersections << "\n";
  
  auto scene = make_unique<Scene>();
  addTriangle(*scene,
              vec3(1.0,0.0,0.0),
              vec3(0.0,1.0,0.0),
              vec3(0.0,0.0,1.0),
              g.get());

  auto intersections = make_unique<vector<Intersection>>(intersect(*scene, *r));
  cout << *intersections << "\n";
  
  return 0;
}
