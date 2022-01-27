#include<vector>
struct coord{
    double x;
    double y;
};

class Polygon{
    private:
    std::vector<coord> coords;
    public:
    void AddCoord(const coord & coord);
};
