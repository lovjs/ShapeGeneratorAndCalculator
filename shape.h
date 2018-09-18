// shape.h

#ifndef shape_h
#define shape_h

#include "triangle.h"

class Shape : public Triangle
{
private:
  int num_points;
  vector<float> x_vars;
  vector<float> y_vars;


public:
  Shape();
  void do_everything();
  void print_shape();
};
#endif
