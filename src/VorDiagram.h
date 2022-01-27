#include<string>
#include"jc_voronoi.h"
class VorDiagram{
    private:
    jcv_point **points;
    size_t numPoints;
    jcv_diagram diagram;
    public:
    void ReadCSV(const std::string &fileName);
    void Generate();
};
