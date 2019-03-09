#include<iostream>
#include<vector>
using namespace std;
#include"Mesh.h"
#include"Camera.h"
using My::vector3f;
using My::Mesh;
using My::Ray;
using My::Camera;

typedef vector3f Point;

int main() { 
	Camera camera{ vector3f{-10,0,-10},vector3f{0,0,0},1,vector3f{0,1,0},2,2,255,255 };
	Mesh mesh{ vector3f{0,0,-10},vector3f{0,-10,10},vector3f{0,10,10} };
	vector<Mesh> amesh;
	amesh.push_back(mesh);
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
	//system("pause");
	return 0;
}