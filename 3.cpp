#include<iostream>
#include<iomanip>
#include<cmath>

const long double pi = 3.14159265359;

int main(){
	long double grid_size, R, steps; 
	std::cout << "Enter the Radius of the Hemisphere: " << std::endl; std::cin >> R;
	std::cout << "Enter the No. of Samples in Radial Direction: " << std::endl; std::cin >> steps;
	std::cout << "Enter the Grid Cell Size: " << std::endl; std::cin >> grid_size;
	long double mr = R / steps, Total_points = 0, sum = 0, l = 0;
	long double r = mr;
	for(int i = 1; i <= steps - 1; i++){
		long double pts = (2 * pi * r * R / sqrt(R * R - r * r) * mr) / grid_size;
		Total_points += pts;
		sum += pts * (R * R - r * r);
		l += mr, r += mr;
	}
	std::cout << std::fixed << std::setprecision(6) << R * sqrt((long double) 1 / 3) << std::endl;
	std::cout << std::fixed << std::setprecision(6) << sqrt(sum / Total_points) << std::endl;
}