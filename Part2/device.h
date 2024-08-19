#include <vector>
#include "shape.h"


class Device

{
public:
	Device();

public:
	void AddShape(const Shape& object);
	void AddDevice(const Device& object);
	unsigned int size();
	
public:
	double surface();
	double volume();
	double mass();
	
public:
	void extract(std::vector<Shape>* vec);
	
public:
	std::vector<Shape> owned;
	
private:
	std::vector<Shape> _shapes;
	std::vector<Device> _devices;
};


Device::Device(){}

void Device::AddShape(const Shape& object)
{
	_shapes.push_back(object);
}

void Device::AddDevice(const Device& object)
{
	_devices.push_back(object);
}

unsigned int Device::size()
{
	owned.clear();
	extract(&owned);
	
	return owned.size();
}

double Device::surface()
{
	double total = 0;
	
	owned.clear();
	extract(&owned);
	
	for (int i = 0; i < owned.size(); i++)
		total += owned[i].surface();
	
	return total;
}

double Device::volume()
{
	double total = 0;
	
	owned.clear();
	extract(&owned);
	
	for (int i = 0; i < owned.size(); i++)
		total += owned[i].volume();
	
	return total;
}

double Device::mass()
{
	double total = 0;
	
	owned.clear();
	extract(&owned);
	
	for (int i = 0; i < owned.size(); i++)
		total += owned[i].mass();
	
	return total;
}

void Device::extract(std::vector<Shape>* vec)
{
	for (int i = 0; i < _shapes.size(); i++)
		vec -> push_back(_shapes[i]);
		
	for (int i = 0; i < _devices.size(); i++)
		_devices[i].extract(vec); 
}

