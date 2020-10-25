#include "raytrace.hpp"

// Sphere Intersection
// somewhat more optimized, less sqrt
// originally transcribed from Sherrod
optional<Intersection> intersect(const Sphere& sphere, const Ray& ray, Material* material) {

  const auto [position, radius]  = sphere;
  const auto [origin, direction] = ray;
  
  vec3 rsVec = position - origin;

  double radius2 = radius * radius;
  
  double intersectDistA = dot(rsVec, direction); // cosine angle

  if(intersectDistA < 0.0) return nullopt;  

  double rsLength = dot(rsVec, rsVec); // returns length^2

  double intersectDistB = radius2 - rsLength +
    (intersectDistA * intersectDistA);
  
  if(intersectDistB < 0.0 || intersectDistB > radius2)
    return nullopt;
  
  // distance to intersection
  double distance = intersectDistA - sqrt(intersectDistB);

  // intersection location and normal determination
  vec3 interPt = origin + distance * direction;
  vec3 normal = interPt - position;
  normalize(normal);
  
  return Intersection(distance, interPt, normal, direction, material);
}

// Triangle Intersection
// annotations match up to wikipedia "Möller-Trumbore intersection algorithm"
optional<Intersection> intersect(const Triangle& triangle, const Ray& ray, Material* material) {

  const auto [p1, p2, p3, normal] = triangle;
  const auto [origin, direction]  = ray;
  
  vec3 vecAB = p2 - p1;                           //edge1
  vec3 vecAC = p3 - p1;                           //edge2

  vec3 crossProduct = cross(direction, vecAC);    //h

  // get determinate
  double det = dot(vecAB, crossProduct);          //a
  double inverseDet = 1.0 / det;                  //f

  if(det < 1e-6) return nullopt;

  vec3 rayPointVec = origin - p1;                 //s

  double test1 = dot(rayPointVec, crossProduct);  //u

  // rather than multiplying u and v by inverse
  // determinate and testing against 1.0,
  // just test against determinate
  if(test1 < 0.0 || test1 > det) return nullopt;

  vec3 crossProduct2 = cross(rayPointVec, vecAB); //q

  double test2 = dot(direction, crossProduct2);   //v

  // same here
  if(test2 < 0.0 || test1 + test2 > det) return nullopt;

  double distance = dot(vecAC, crossProduct2);
  distance *= inverseDet;

  vec3 interPt = origin + distance * direction;
  
  return Intersection(distance, interPt, normal, direction, material);
}

// Plane Intersetion
optional<Intersection> intersect(const Plane& plane, const Ray& ray, Material* material) {

  const auto [origin, normal] = plane;
  const auto [position, direction]  = ray;
  
  double denom = dot(normal, direction);

  if(denom < 1e-6) return nullopt;

  //vector between ray origin and plane position
  vec3 L = position - origin;

  double distance = dot(L, normal) / denom;

  if(distance < 0.0) return nullopt;

  vec3 interPt = origin + distance * direction;

  return Intersection(distance, interPt, normal, direction, material);
}
