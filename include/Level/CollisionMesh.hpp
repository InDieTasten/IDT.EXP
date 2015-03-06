#ifndef _CollisionMesh_hpp_
#define _CollisionMesh_hpp_

#include <list>
#include <Level\Vector.hpp>
#include <Level\Line.hpp>
#include <Level\Poly.hpp>

using namespace std;

class CollisionMesh
{
private:
	list<Vector*>* dots;
	list<Line*>* edges;
	list<Poly*>* polys;

public:
	CollisionMesh();
	~CollisionMesh();
};

#endif // !_CollisionMesh_hpp_