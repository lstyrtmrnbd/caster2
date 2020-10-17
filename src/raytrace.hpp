#include <optional>
#include "structures.hpp"

using std::optional, std::nullopt;

optional<Intersection> intersect(const Sphere&, const Ray&);
optional<Intersection> intersect(const Triangle&, const Ray&);
optional<Intersection> intersect(const Plane&, const Ray&);

// IntersectionRecord* castRay(const Ray &ray, vector<Object*> &objectList);
// // for single surface?
// IntersectionRecord* castRay(const Ray &ray, const Surface &surface);
// vector<IntersectionRecord*>* castRays(vector<Object*> &objectList);
// vector<vec3>* shade(vector<Light*> &lightList);
