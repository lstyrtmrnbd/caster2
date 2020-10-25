#include <algorithm>
//#include <future>
#include <optional>
//#include <thread>
#include "structures.hpp"

using std::optional, std::nullopt;
using std::transform, std::remove_if, std::back_inserter;

optional<Intersection> intersect(const Sphere&, const Ray&, Material*);
optional<Intersection> intersect(const Triangle&, const Ray&, Material*);
optional<Intersection> intersect(const Plane&, const Ray&, Material*);

vector<Intersection> intersect(const Scene& scene, const Ray& ray);

void addTriangle(Scene& scene, vec3 p1, vec3 p2, vec3 p3, Material* material);
void addSphere(Scene& scene, vec3 position, double radius, Material* material);
void addPlane(Scene& scene, vec3 position, vec3 normal, Material* material);
