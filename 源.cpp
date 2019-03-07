#include<iostream>
using namespace std;
#include"Vector3.h"
using My::vector3f;

int main() {
	vector3f x(3,4,5),y(4,5,6);
	cout << x << y  << endl;
	cout << x*y<<endl ;
	cout << x.Normal()*y.Normal() << endl;
	x += y;
	cout << x << endl;
	system("pause");
	return 0;
}