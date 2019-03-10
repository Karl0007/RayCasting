#pragma once
#include<vector>
#include<string>
#include<fstream>
#include"Mesh.h"
#include"Color.h"
using std::vector;
using std::string;

namespace My {
	class GetObjectFromOBJ;
	
	class Object
	{
	private:
		string m_name;
		vector<Mesh> m_mesh;
		Object(const string & name) : m_name(name) {}
	public:
		friend class GetObjectFromOBJ;



	};
	
	class GetObjectFromOBJ
	{
	public:

		static const vector<Object> & Objects() {
			return m_objects;
		}

		static void OpenFromFile(char const* _file);
		static vector<Mesh> m_f;
	private:
		GetObjectFromOBJ() = delete;

		static vector<Object> m_objects;
		static vector<vector3f> m_v, m_vn, m_vt;
		static void StrToInt(const string&, int &x, int &y, int &z);
		
	};

	vector<Object> GetObjectFromOBJ::m_objects;
	vector<vector3f>  GetObjectFromOBJ::m_v;
	vector<vector3f> GetObjectFromOBJ::m_vn;
	vector<vector3f> GetObjectFromOBJ::m_vt;
	vector<Mesh> GetObjectFromOBJ::m_f;
}


void My::GetObjectFromOBJ::StrToInt(const string &s, int & x, int & y, int & z)
{
	x = y = z = 0;
	int i = 0;
	while (i < s.size() && s[i] != '/') {
		x = x * 10 + s[i] - '0';
		i++;
	}
	i++;
	while (i < s.size() && s[i] != '/') {
		y = y * 10 + s[i] - '0';
		i++;
	}
	i++;
	while (i < s.size() && s[i] != '/') {
		z = z * 10 + s[i] - '0';
		i++;
	}
	x--, y--, z--;
}

void My::GetObjectFromOBJ::OpenFromFile(char const*_file) {
	std::ifstream is(_file);
	string tmp;
	float x, y, z;
	Color c = Color( rand() % 256,rand() % 256,rand() % 256 ,rand() % 256 );
	while (is >> tmp) {
		if (tmp == "g") {
			string name;
			is >> name;
			m_objects.push_back(Object(name));
			c = Color( rand() % 256,rand() % 256,rand() % 256 ,rand() % 256 );
		}
		if (tmp == "f") {
			c = Color(rand() % 256, rand() % 256, rand() % 256, 255);
			int vx, vy, vz, vnx, vny, vnz, vtx, vty, vtz;
			string s1, s2, s3;
			is >> s1 >> s2 >> s3;
			StrToInt(s1, vx, vtx, vnx);
			StrToInt(s2, vy, vty, vny);
			StrToInt(s3, vz, vtz, vnz);
			m_f.push_back(Mesh(m_v[vx], m_v[vy], m_v[vz],c));
			//m_objects.back().m_mesh.push_back(m_f.back());
		}
		if (tmp == "v") {
			is >> x >> y >> z;
			m_v.push_back(vector3f(x, y, z));
		}
		if (tmp == "vn") {
			is >> x >> y >> z;
			m_vn.push_back(vector3f(x, y, z));
		}
		if (tmp == "vt") {
			is >> x >> y >> z;
			m_vt.push_back(vector3f(x, y, z));
		}
	}
}