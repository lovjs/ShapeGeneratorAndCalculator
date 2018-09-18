// rectangle.h

#ifndef rectangle_h
#define rectangle_h

#include "triangle.h"

class Rectangle : public Triangle
{
private:
	float x4;
  float y4;
  float area;
  float perimeter;
	float d;

public:
	Rectangle();
  void calc_area();
  void calc_perm();
	float get_area_rec();
	float get_perm();
	void calc_a();
  void calc_b();
  void calc_c();
  void calc_d();
	void case1();
	void print_rec();
};

#endif
