#include "Polygon.h"
#include "jc_voronoi.h"
#include <string>
class VorDiagram {
private:
  jcv_point *points = nullptr;
  jcv_rect *rect = nullptr;
  size_t numPoints=0;
  jcv_diagram diagram;
  std::vector<Polygon *> polygons;
  ~VorDiagram();

public:
  VorDiagram();
  void ReadCSV(const std::string &fileName);
  void AddPoints(const std::vector<std::pair<double, double>> &_points);
  void Generate();
  std::vector<Polygon *> GetPolygons();
};
