#include"Polygon.h"

void Polygon::AddCoord(const coord &coord)
{
   coords.push_back(coord);
}
void Polygon::SetCenter(const coord &coord)
{
    center=coord;
}
const std::vector<coord> & Polygon::GetCoords() const
{
    return coords;
}

const coord& Polygon::GetCenter() const
{
    return center;
}
