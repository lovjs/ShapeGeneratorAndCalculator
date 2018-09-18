//triangle.cpp

#include "triangle.h"

Triangle::Triangle(){
  a = 0.0;
  area = 0.0;
  perimeter = 0.0;
  x1 = 0.0;
  x2 = 0.0;
  x3 = 0.0;
  y1 = 0.0;
  y2 = 0.0;
  y3 = 0.0;
  b = 0.0;
  c = 0.0;
}

void Triangle::set_back(char back1){
  back = back1;
}

void Triangle::set_line(char line1){
  line = line1;
}

void Triangle::calc_area(){
  float s = perimeter / 2;
  area = (sqrt(s * ((s - a) * (s - b) * (s - c))));
}

void Triangle::calc_a(){
  a = (sqrt((pow(x2 - x1, 2)) + (pow(y2 - y1, 2))));
}

void Triangle::calc_b(){
  b = (sqrt((pow(x3 - x2, 2)) + (pow(y3 - y2, 2))));
}

void Triangle::calc_c(){
  c = (sqrt((pow(x3 - x1, 2)) + (pow(y3 - y1, 2))));
}

void Triangle::calc_perm(){
  perimeter = a + b + c;
}

void Triangle::print_menu(){
  cout << "\n\nWelcome to your basic Shape calculator!!!!!\n\n";
  cout << "Just type the number of option you would like to choose.\n";
  cout << "1. Create new quadrilateral.\n";
  cout << "2. Create new triangle.\n";
  cout << "3. Calculate quadrilateral perimeter.\n";
  cout << "4. Calculate triangle perimeter.\n";
  cout << "5. Calculate quadrilateral area.\n";
  cout << "6. Calculate triangle area.\n";
  cout << "7. Print when quadrilateral was created.\n";
  cout << "8. Print when triangle was created.\n";
  cout << "9. Print all information about quadrilateral.\n";
  cout << "10. Print all information about triangle.\n";
  cout << "11. Draw the quadrilateral.\n";
  cout << "12. Draw the triangle.\n";
  cout << "13. Performe Calculations for a parallelogram with more than 4 sides.\n";
  cout << "14. Exit the program.\n";
}

void Triangle::print_info(){
  cout << "The name of your triangle is " << name << endl << endl;
  cout << "The cordinates you chose were (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")" << ", "<< "(" << x3 << "," << y3 << ")\n\n";
  cout << "The area of your triangle is " << area << " " << units << endl << endl;
  cout << "The perimeter of your triangle is " << perimeter << " " << units << endl << endl;
  print_Date();
}
float Triangle::get_perimeter(){
  return perimeter;
}
float Triangle::get_area(){
  return area;
}

string Triangle::get_units(){
  return units;
}


void Triangle::case2(){
  cout << "What would you like to name your triangle?\n";
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
  cout << "What units would you like to use? ";
  cin >> units;
  cout << endl << endl << endl;
  calc_a();
  calc_b();
  calc_c();
  calc_perm();
  calc_area();
  max_x();
  min_x();
  max_y();
  min_y();
  setn();
}

void Triangle::get_Date(){
  time_t now = time(0);
  char* dt = ctime(&now);
  previous_time = dt;
  cout << "Shape created " << dt;

}

void Triangle::print_Date(){
  cout << "\n\nYour triangle was created " << previous_time;
}

void Triangle::max_x(){
  if(x1 > x2){
    if(x1 > x3) x_max = x1;
  }else if(x2 > x3) x_max = x2;
  else x_max = x3;
}
void Triangle::min_x(){
  if(x1 < x2){
    if(x1 < x3) x_min = x1;
  }else if(x2 < x3) x_min = x2;
  else x_min = x3;
}
void Triangle::max_y(){
  if(y1 > y2){
    if(y1 > y3) y_max = y1;
  }else if(y2 > y3) y_max = y2;
   else y_max = y3;
}
void Triangle::min_y(){
  if(y1 < y2){
    if(y1 < y3) y_min= y1;
  }else if(y2 < y3) y_min = y2;
   else y_min = y3;
}

void Triangle::set_can(char canvas1[w][w]){
  for (int i = 0; i < w; i++)
    for (int j = 0; j < w; j++)
        canvas[i][j] = canvas1[i][j];
}
void Triangle::setn(){
  int xlength = x_max - x_min;
  int ylength = y_max - y_min;
  int finaln = 0;
  if(xlength < ylength) finaln = ylength;
  else finaln = xlength;
  if(finaln > 25) n = finaln;
  else n = 25;
}

void Triangle::set_shape_inside(char shape_inside1){
  shape_inside = shape_inside1;
}

void Triangle::paint_background(){
  for(int i = 0; i < w; i ++){
    for(int j = 0; j < w; j++){
      canvas[i][j] = back;
    }
  }
  set_can(canvas);
}

void Triangle::print_tri() {
  paint_background();
  draw_line(x1, y1, x2, y2);
  draw_line(x2, y2, x3, y3);
  draw_line(x1, y1, x3, y3);
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

void Triangle::draw_line(float x1, float y1, float x2, float y2){
  float dx = (x2 - x1)/(w * 10);
  float dy = (y2 - y1)/(w * 10);
  for(int i = 0; i <= (w * 10); i++){
    float x = i * dx + x1;
    float y = i * dy + y1;
    canvas[int(y)][int(x)] = line;
  }
  canvas[int(y2)][int(x2)] = line;
  set_can(canvas);
}

void Triangle::fill_in_shape(int x,int y){
  if(x > w - 1 || x < 0)return;
  if(y > w - 1 || x < 0)return;
  canvas[y][x] = shape_inside;
  if(canvas[y + 1][x] == back) fill_in_shape(x, y + 1);
  if(canvas[y - 1][x] == back) fill_in_shape(x, y - 1);
  if(canvas[y][x + 1] == back) fill_in_shape(x + 1, y);
  if(canvas[y][x - 1] == back) fill_in_shape(x - 1, y);
  set_can(canvas);
}
