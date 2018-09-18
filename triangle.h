//triangle.h

#ifndef triangle_h
#define triangle_h

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <vector>
using namespace std;

const int w = 26;

class Triangle
{
private:
  float area;
  float perimeter;
public:
  string name;
  string units;
  float x_max;
  float x_min;
  float y_max;
  float y_min;
  int n;
  char back;
  char line;
  char shape_inside;
  char canvas[w][w];
  string previous_time;
  float x1;
  float x2;
  float x3;
  float y1;
  float y2;
  float y3;
  float a;
  float b;
  float c;
  Triangle();
  void print_info();
  void print_menu();
  void calc_area();
  void calc_a();
  void calc_b();
  void calc_c();
  void calc_perm();
  void case2();
  string get_units();
  void get_Date();
  void print_Date();
  void max_x();
  void min_x();
  void max_y();
  void min_y();
  void paint_background();
  void setn();
  void draw_line(float x1, float y1, float x2, float y2);
  void set_back(char back1);
  void set_line(char line1);
  void print_tri();
  void set_can(char canvas1[w][w]);
  void fill_in_shape(int x, int y);
  void set_shape_inside(char tri_inside1);
  float get_perimeter();
  float get_area();



};

#endif
