#include "Polygon.h"
#include "jc_voronoi.h"
#include <string>
class VorDiagram {
private:
  jcv_point *points = nullptr;
  jcv_rect *rect = nullptr;
  size_t numPoints;
  jcv_diagram diagram;
  std::vector<Polygon *> polygons;

public:
  void ReadCSV(const std::string &fileName);
  void Generate();
  std::vector<Polygon*> GetPolygons();
};
