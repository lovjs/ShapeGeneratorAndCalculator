//rectangle.cpp

#include "rectangle.h"

Rectangle::Rectangle():Triangle(){
  x4 = 0.0;
  y4 = 0.0;
  area = 0.0;
  perimeter = 0.0;
}

void Rectangle::calc_area(){
  area = ((.5) * (fabsf((x1 * y2) + (x2 * y3) + (x3 * y4) + (x4 * y1) - (x2 * y1) - (x3 * y2) - (x4 * y3) - (x1 * y4))));
}



void Rectangle::calc_a(){
  a = (sqrt((pow(x2 - x1, 2)) + (pow(y2 - y1, 2))));
}

void Rectangle::calc_b(){
  b = (sqrt((pow(x3 - x2, 2)) + (pow(y3 - y2, 2))));
}

void Rectangle::calc_c(){
  c = (sqrt((pow(x4 - x3, 2)) + (pow(y4 - y3, 2))));
}

void Rectangle::calc_d(){
  d = (sqrt((pow(x4 - x1, 2)) + (pow(y4 - y1, 2))));
}

void Rectangle::calc_perm(){
  perimeter = a + b + c + d;
}

float Rectangle::get_area_rec(){
  cout << "it ran";
  return area;
}

float Rectangle::get_perm(){
  return perimeter;
}

void Rectangle::case1(){
  cout << "What would you like to name your quadrilateral?\n";
  cin >> name;
  cout << "What would you like your first x cordinate to be?\n x1: ";
  cin >> x1;
  cout << "What would you like your first y cordinate to be?\ny1: ";
  cin >> y1;
  cout << "What would you like your second x cordinate to be?\nx2: ";
  cin >> x2;
  cout << "What would you like your second y cordinate to be?\ny2: ";
  cin >> y2;
  cout << "What would you like your third x cordinate to be?\nx3: ";
  cin >> x3;
  cout << "What would you like your third y cordinate to be?\ny3: ";
  cin >> y3;
  cout << "What would you like your fourth x cordinate to be?\nx4: ";
  cin >> x4;
  cout << "What would you like your fourth y cordinate to be?\ny4: ";
  cin >> y4;
  cout << "What units would you like to use? ";
  cin >> units;
  cout << endl << endl << endl;
  calc_a();
  calc_b();
  calc_c();
  calc_d();
  calc_perm();
  calc_area();
  max_x();
  min_x();
  max_y();
  min_y();
  setn();
}

void Rectangle::print_rec() {
  paint_background();
  draw_line(x1, y1, x2, y2);
  draw_line(x2, y2, x3, y3);
  draw_line(x3, y3, x4, y4);
  draw_line(x1, y1, x4, y4);
  float x_avg = (x1 + x2 + x3) / 3.0;
  float y_avg = (y1 + y2 + y3) / 3.0;
  fill_in_shape(int(x_avg), int(y_avg));
	for (int i = (w - 1); i >= 0; i--) {
    if(i < 10) cout << i << " ";
    else cout << i;
		for (int j = 0; j < w; j++) {
			cout << " " << canvas[i][j] << " ";
		}
    cout << endl;
	}
  cout << endl << "   ";
  for (int i = 0; i < w; i++){
    if( i > 9) cout << i << " ";
    else cout << i << "  ";
  }
}
