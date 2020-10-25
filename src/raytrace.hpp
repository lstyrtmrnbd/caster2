#include <future>
#include <optional>
#include <thread>
#include "structures.hpp"

using std::optional, std::nullopt;

optional<Intersection> intersect(const Sphere&, const Ray&, Material*);
optional<Intersection> intersect(const Triangle&, const Ray&, Material*);
optional<Intersection> intersect(const Plane&, const Ray&, Material*);

//vector<Intersection> raytrace(const vector<Shape>&, const vector<Ray>&);

// // for single surface?
// IntersectionRecord* castRay(const Ray &ray, const Surface &surface);
// IntersectionRecord* castRay(const Ray &ray, vector<Object*> &objectList);
// vector<IntersectionRecord*>* castRays(vector<Object*> &objectList);
// vector<vec3>* shade(vector<Light*> &lightList);
