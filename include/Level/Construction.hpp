#ifndef _Construction_hpp_
#define _Construction_hpp_

#include <Level\PhysicalInstance.hpp>

class SolarSystem;

using namespace std;

class Construction
{
private:
	SolarSystem* parent;
	string* ID;
	PhysicalInstance* phInstance;

public:
	Construction();
	~Construction();
};

#endif // !_Construction_hpp_