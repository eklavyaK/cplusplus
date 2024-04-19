#include <iostream>
#include <cmath>
#include <iomanip>

const long double pi = 3.14159265359;

int main(){
	long double H, grid_size, steps, R;
	std::cout << "Enter Height of the Cone: " << std::endl; std::cin >> H;
	std::cout << "Enter Radius of the Cone: " << std::endl; std::cin >> R;
	std::cout << "Enter the No. of Samples in Radial Direction: " << std::endl; std::cin >> steps;
	std::cout << "Enter the Grid Cell Size: " << std::endl; std::cin >> grid_size;
	long double mh = H / steps, mr = H / steps, Total_points = 0, sum = 0, l = 0;
	long double h = H, r = mr;
	for(int i = 1; i <= steps; i++){
		int pts = (2 * pi * r * sqrt(R * R + H * H) / R) / grid_size;
		Total_points += pts;
		sum += pts * (h * h);
		h -= mh, l += mr, r += mr;
	}
	std::cout << std::fixed << std::setprecision(6) << H * sqrt((long double) 1 / 6) << std::endl;
	std::cout << std::fixed << std::setprecision(6) << sqrt(sum / Total_points) << std::endl;
}