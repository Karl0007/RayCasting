#include<iostream>
using namespace std;
#include"Mesh.h"
using My::vector3f;
using My::Mesh;
using My::Ray;

typedef vector3f Point;

int main() {
	Point camera{ -10,0,0 };

	Mesh mesh{ {0.5,0,-1},{.5,1,1},{.5,-1,1} };
	Ray ray{ {0,0,0},{-1,0,0} };

	cout << mesh.RayCasting(ray);
	vector3f x(3,4,5),y(4,5,6);
	cout << x << y  << endl;
	cout << x*y<<endl ;
	cout << x.Normal()*y.Normal() << endl;
	x += y;
	cout << x << endl;
	system("pause");
	return 0;
}