#include "VorDiagram.h"
#include <array>
#define JC_VORONOI_IMPLEMENTATION
#include "Polygon.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include<vector>
#include"jc_voronoi.h"

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
VorDiagram::VorDiagram()
{

}
void VorDiagram::ReadCSV(const std::string &fileName)
{
    // const char* file=fileName.c_str();
    // uint32_t len=0;
    // int success=read_input(file,&points,(uint32_t*)&len,&rect);
    // numPoints=len;
}

//Currently can only ReadCSV or AddPoints
void VorDiagram::AddPoints(const std::vector<std::pair<double,double>> &_points)
{
    if(points==nullptr)
    {
        points=(jcv_point*)malloc(_points.size()*sizeof(jcv_point));
    }

    for(size_t i=0;i<_points.size();i++)
    {
       points[i].x =_points[i].first;
       points[i].y =_points[i].second;
    }
    numPoints+=_points.size();
}

void VorDiagram::Generate() {
    memset(&diagram, 0, sizeof(jcv_diagram));
    std::cout<<numPoints<<" Points\n";
    

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

VorDiagram::~VorDiagram()
{
    free(points);
}
