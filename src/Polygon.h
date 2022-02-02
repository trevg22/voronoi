#pragma once
#include <vector>
struct coord {
  double x;
  double y;
};

class Polygon {
private:
  std::vector<coord> coords;
  coord center;

public:
  void AddCoord(const coord &coord);
  void SetCenter(const coord &coord);

  // Change to stream or other approach
  const std::vector<coord> &GetCoords() const;
  const coord &GetCenter() const;
};
