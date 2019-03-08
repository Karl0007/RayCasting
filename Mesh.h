#pragma once
#include"Vector3.h"
#include"Ray.h"
namespace My {
	class Mesh
	{
	public:
		Mesh(vector3f const &a, vector3f const&b, vector3f const&c) { m_point[0] = a, m_point[1] = b, m_point[2] = c; m_normal = (b - a).Cross(c - a); m_normal.Normalize(); }
		~Mesh();
		vector3f Normal() { return m_normal; };
		bool RayCasting(Ray const&);
	private:
		vector3f m_point[3];
		vector3f m_normal;
	};



	Mesh::~Mesh()
	{
	}

	bool Mesh::RayCasting(Ray const & _ray)
	{
		vector3f TestRay[3];
		vector3f TestNor[3];
		for (int i = 0; i < 3; i++) {
			TestRay[i] = m_point[i] - _ray.StPoint();
		}
		if (TestRay[0] * _ray.ToVec() < 0 && TestRay[1] * _ray.ToVec() < 0 && TestRay[2] * _ray.ToVec() < 0) return false;
		TestNor[0] = TestRay[0] % TestRay[1];
		TestNor[1] = TestRay[1] % TestRay[2];
		TestNor[2] = TestRay[2] % TestRay[0];
		std::cout << TestNor[0] * _ray.ToVec() <<" "<< TestNor[1] * _ray.ToVec() << " "<< TestNor[2] * _ray.ToVec() << std::endl;
		if (TestNor[0] * _ray.ToVec() <= 0 && TestNor[1] * _ray.ToVec() <= 0 && TestNor[2] * _ray.ToVec() <= 0
			|| TestNor[0] * _ray.ToVec() > 0 && TestNor[1] * _ray.ToVec() > 0 && TestNor[2] * _ray.ToVec() > 0) {
			return true;
		}
		return false;
	}

}