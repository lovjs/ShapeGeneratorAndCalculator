// main1.cpp
// Date: Thursday October 5th, 2017
// Description: This program is a simple calculator and grapher that intake points and gives you area, perimeter,
//and then draws a picture of the shape.

#include "triangle.h"
#include "rectangle.h"
#include "shape.h"

int main(){
  int choice;
  Triangle tri;
  Rectangle rec;
  Shape s;
  char back1;
  char line1;
  char tri_inside1;
  char rec_inside1;

  do {
  tri.print_menu();
  cin >> choice;
  switch (choice) {

    case 1:
      rec.case1();
      rec.get_Date();
      break;
    case 2:
      tri.case2();
      tri.get_Date();
      break;
    case 3:
      cout << endl << endl << "The perimeter is: " << rec.get_perm() << rec.get_units() << endl;
      break;
    case 4:
      cout << endl << endl << "The perimeter is: " << tri.get_perimeter() << tri.get_units() << endl;
      break;
    case 5:
      cout << endl << endl << "The area is: " << rec.get_area_rec() << rec.get_units() << endl;
      break;
    case 6:
      cout << endl << endl << "The area is: " << tri.get_area() << tri.get_units() << endl;
      break;
    case 7:
      rec.print_Date();
      break;
    case 8:
      tri.print_Date();
      break;
    case 9:
      cout << endl << endl;
      rec.print_info();
      break;
    case 10:
      cout << endl << endl;
      tri.print_info();
      break;
    case 11:
      cout << "What symbol would you like the grid to be made of?\n ";
      cin >> back1;
      rec.set_back(back1);
      cout << "What do you want the boarder of the quadrilateral to be made of?\n";
      cin >> line1;
      rec.set_line(line1);
      cout << "What symbol would you like the inside of your quadrilateral to be made of?\n";
      cin >> rec_inside1;
      rec.set_shape_inside(rec_inside1);
      rec.print_rec();
      break;
    case 12:
      cout << "What symbol would you like the grid to be made of?\n ";
      cin >> back1;
      tri.set_back(back1);
      cout << "What do you want the boarder of the triangle to be made of?\n";
      cin >> line1;
      tri.set_line(line1);
      cout << "What symbol would you like the inside of your triangle to be made of?\n";
      cin >> tri_inside1;
      tri.set_shape_inside(tri_inside1);
      tri.print_tri();
        break;
    case 13:
      s.do_everything();
    case 14:
      break;
  }}while(choice != 14);
  return 0;
}
