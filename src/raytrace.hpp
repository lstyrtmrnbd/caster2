#include <algorithm>
//#include <future>
#include <optional>
//#include <thread>
#include "structures.hpp"

using std::optional, std::nullopt;

optional<Intersection> intersect(const Sphere&, const Ray&, Material*);
optional<Intersection> intersect(const Triangle&, const Ray&, Material*);
optional<Intersection> intersect(const Plane&, const Ray&, Material*);

using std::transform, std::remove_if, std::back_inserter;

vector<Intersection> intersect(const Scene& scene, const Ray& ray);

void addTriangle(Scene& scene, vec3 p1, vec3 p2, vec3 p3, Material* material);
void addSphere(Scene& scene, vec3 position, double radius, Material* material);
void addPlane(Scene& scene, vec3 position, vec3 normal, Material* material);

// 2d Ray structure, 1 per pixel traditionally
// but casting at a higher res and reducing achieves anti-aliasing
using ray_grid = vector<vector<Ray>>;

// 3d Intersection structure, 1 list of intersections into a scene per ray
using intersectiong_rid = vector<vector<vector<Intersection>>>;

// (r,g,b) of unsigned int, feed to output
using color = glm::uvec3;

ray_grid cast(int height, int width);

intersection_grid intersect(Scene& scene, raygrid& rays);

vector<vector<color>> shade(intersectiongrid& intersections);
