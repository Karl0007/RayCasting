#include<iostream>
#include<vector>
using namespace std;
#include"Mesh.h"
#include"Camera.h"
#include"Color.h"
using My::vector3f;
using My::Mesh;
using My::Ray;
using My::Camera;
using My::Color;

typedef vector3f Point;

int main() { 
	Camera camera{ vector3f{0,-10,10},vector3f{0,0,0},2,vector3f{0,-1,0},4,4,255,255,500};
	Mesh mesh{ vector3f{10,0,0},vector3f{-10,0,0},vector3f{0,17,0},Color(200,0,0,0) };
	Mesh mesh2{ vector3f{10,0,-5},vector3f{-10,0,-5},vector3f{0,5,5},Color(0,200,0,0) };
	cout << mesh2.RayCasting({ vector3f(0,9,10), vector3f(0,9,0) });
	vector<Mesh> amesh;
	amesh.push_back(mesh);
	amesh.push_back(mesh2);

	camera.TakePhoto(amesh);
	Ray ray{ vector3f{0,0,0},vector3f{-1,0,0} };

	//cout << mesh.RayCasting(ray);
	//vector3f x(3,4,5),y(4,5,6);
	//cout << x*2.f << 3.f*y  << endl;
	//cout << x*y<<endl ;
	//cout << x.Normal()*y.Normal() << endl;
	//x += y;
	//cout << x << endl;
	system(R"(E:\test.png)");
	system("pause");
	return 0;
}