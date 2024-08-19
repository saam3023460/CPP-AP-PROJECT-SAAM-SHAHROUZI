#include <iostream>
#include "device.h"

int main()
{
	Poly circle(1);   // base object with radius 1
	Shape cylinder(circle, 2, 3);   // shape object constructed with base, height and density
	
	Poly square(4, 1);   // base object with 4 sides and distance from center equal to 1
	Shape cube(square, 1, 1);
	
	Poly triangle(3, 2);
	Shape prism(triangle, 3, 1);
	
	Device d1;   // device object
	
	d1.AddShape(cylinder);   // adding a shape to device
	d1.AddShape(cube);
	
	Device d2;
	
	d2.AddShape(prism);
	
	Device d3;
	
	d3.AddDevice(d1);   // adding a sub-device to device
	d3.AddDevice(d2);
	d3.AddShape(prism);
	
	std::cout << "total surface of the main device d3: " << d3.surface() << std::endl;
	std::cout << "total volume of the main device d3: " << d3.volume() << std::endl;
	std::cout << "total mass of the main device d3: " << d3.mass() << std::endl;
	
	std::cin.get();
	
	return 0;
}
