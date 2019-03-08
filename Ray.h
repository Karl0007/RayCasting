#pragma once
#include"Vector3.h"

namespace My {
	class Ray
	{
	public:
		Ray(vector3f const& _st, vector3f const& _ed) : m_st(_st), m_ed(_ed) { m_tovec = m_ed - m_st; };
		vector3f ToVec() const { return m_tovec; }
		vector3f StPoint() const { return m_st; }
		vector3f EdPoint() const { return m_ed; }
		~Ray();

	private:
		vector3f m_tovec;
		vector3f m_st, m_ed;
	};

	Ray::~Ray()
	{
	}

}