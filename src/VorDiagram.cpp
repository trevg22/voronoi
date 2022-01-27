#include "VorDiagram.h"
#include <array>
#define JC_VORONOI_IMPLEMENTATION
#include "Polygon.h"
#include "jc_voronoi.h"
#include <fstream>
#include <iostream>
#include <sstream>

void VorDiagram::ReadCSV(const std::string &filename) {
  std::ifstream file(filename);
  std::string line, ele, substr;
  std::array<float, 2> coord;
  size_t count = 0;
  // print_state(file);
  jcv_point *pointsAddr = nullptr;
  *points = (jcv_point *)malloc(100 * sizeof(jcv_point));
  while (file.good()) {
    while (std::getline(file, line)) {
      std::stringstream stream(line);
      bool isSecond = false;
      pointsAddr =
          (jcv_point *)realloc(pointsAddr, (count + 1) * sizeof(jcv_point));
      while (getline(stream, substr, ',')) {
        coord[isSecond] = stof(substr);
        isSecond = true;
      }
      pointsAddr[count].x = coord[0];
      pointsAddr[count].y = coord[1];
      count++;
    }
  }
  *points = pointsAddr;
  numPoints = count;
}

void VorDiagram::Generate() {
  jcv_diagram_generate(numPoints, (const jcv_point *)points, nullptr, nullptr,
                       &diagram);

  size_t numSites = diagram.numsites;
  const jcv_site *sites = jcv_diagram_get_sites(&diagram);
  std::vector<Polygon *> polygons;

  for (size_t i = 0; i < numSites; i++) {
    const jcv_site *site = &sites[i];
    Polygon *poly=new Polygon();
    while (site->edges->next) {
        poly->add
    }
  }
}
