//shape.cpp

#include "shape.h"


Shape::Shape():Triangle(){
  int num_points = 0;
  vector<float> x_vars;
  vector<float> y_vars;
}

void Shape::do_everything(){
  float part1 = 0.0;
  float part2 = 0.0;
  float area = 0.0;
  float perm = 0.0;
  for(int i = 0; i < w; i++){
    for(int j = 0; j < w; j++){
        canvas[i][j] = back;
    }
  }
  cout << "How many points do you want?\n";
  cin >> num_points;
  for(int i = 1; i < num_points + 1; i++){
    float x = 0.0;
    float y = 0.0;
    cout << "What do you want your x" << i << " to be?\n" << "x" << i << ":";
    cin >> x;
    x_vars.push_back(x);
    cout << "What do you want your y" << i << " to be?\n" << "y" << i << ":";
    cin >> y;
    y_vars.push_back(y);
  }
for(int i = 0; i < num_points; i++){
  if(i == num_points - 1) part1 += (x_vars[i] * y_vars[0]);
  else part1 += (x_vars[i] * y_vars[i + 1]);
}
for(int i = 0; i < num_points; i++){
  if(i == num_points - 1) part2 -= (x_vars[0] * y_vars[i]);
  else part2 += (x_vars[i + 1] * y_vars[i]);
}
area = ((.5) * (fabsf((part1 - part2))));
cout << "The area is" << area << endl;

for(int i = 0; i < num_points; i ++){
  if(i == (num_points - 1)) perm += (sqrt((pow(x_vars[i] - x_vars[0], 2)) + (pow(y_vars[i] - y_vars[0], 2))));
  else perm += (sqrt((pow(x_vars[i + 1] - x_vars[i], 2)) + (pow(y_vars[i + 1] - y_vars[i], 2))));
}
cout << "The perimeter is " << perm << endl;

print_shape();


}

void Shape::print_shape() {
  float x_avg = 0.0;
  float y_avg = 0.0;
  cout << "What symbol would you like the grid to be made of?\n ";
  cin >> back;
  cout << "What do you want the boarder of the shape to be made of?\n";
  cin >> line;
  cout << "What symbol would you like the inside of your shape to be made of?\n";
  cin >> shape_inside;
  paint_background();
  for(int i = 0; i < num_points; i++){
    if(i == (num_points - 1)) draw_line(x_vars[0], y_vars[0], x_vars[i], y_vars[i]);
    else draw_line(x_vars[i], y_vars[i], x_vars[i + 1], y_vars[i + 1]);
  }
  for(int i = 0; i < num_points; i++){
    x_avg += x_vars[i];
    y_avg += y_vars[i];
  }
  x_avg = x_avg / float(num_points);
  y_avg = y_avg / float(num_points);
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
