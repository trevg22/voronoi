#include "VorDiagram.h"
#include <array>
#define JC_VORONOI_IMPLEMENTATION
#include "Polygon.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include"oldVor.c"

/*void VorDiagram::ReadCSV(const std::string &filename) {
  std::ifstream file(filename);
  std::string line, ele, substr;
  std::array<float, 2> coord;
  size_t count = 0;
  // print_state(file);
  points=(jcv_point**)malloc(sizeof(jcv_point*));
  jcv_point *pointsAddr = (jcv_point*)malloc(sizeof(jcv_point)*200);
  *points=pointsAddr;
  
  while (file.good()) {
    while (std::getline(file, line)) {
      std::stringstream stream(line);
      bool isSecond = false;
      while (getline(stream, substr, ',')) {
        coord[isSecond] = stof(substr);
        isSecond = true;
      }
      //std::cout<< coord[0]<<""<<coord[1]<<"\n";
      pointsAddr[count].x = coord[0];
      pointsAddr[count].y = coord[1];
      count++;
    }
  }
  numPoints = count;
}
*/
void VorDiagram::ReadCSV(const std::string &fileName)
{
    const char* file=fileName.c_str();
    uint32_t len=0;
    int success=read_input(file,&points,(uint32_t*)&len,&rect);
    numPoints=len;
}

void VorDiagram::Generate() {
    memset(&diagram, 0, sizeof(jcv_diagram));
    std::cout<<numPoints<<" Points\n";
    for(size_t i=0;i<numPoints;i++)
    {
        printf("%f, %f\n",(points)[i].x,(points)[i].y);
    }

  jcv_diagram_generate(numPoints, (const jcv_point *)points, rect, nullptr,
                       &diagram);

  size_t numSites = diagram.numsites;
  const jcv_site *sites = jcv_diagram_get_sites(&diagram);

  for (size_t i = 0; i < numSites; i++) {
    const jcv_site *site = &sites[i];
    Polygon *poly = new Polygon();
    const jcv_graphedge* e=site->edges;
    poly->SetCenter({site->p.x,site->p.y});
    while (e) {
      poly->AddCoord({e->pos[0].x,e->pos[0].y});
      e=e->next;
    }
    polygons.push_back(poly);
  }
}

std::vector<Polygon*> VorDiagram::GetPolygons()
{
    return polygons;
}
