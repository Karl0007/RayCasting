#pragma once
#include"Mesh.h"
#include<vector>
#include"svpng.h"

namespace My {

	class Camera
	{
	public:
		Camera(vector3f const& pos, vector3f const& forward, vector3f const &hor,float horsize,float versize,int hres,int vres ,float dis) : m_poistion(pos),m_forward(forward),m_hor_res(hres),m_ver_res(vres),m_max_dis(dis)
		{
			m_horizontal = (hor-(forward.Normal()*hor)*forward.Normal()).Normal() * horsize;
			m_vertical = (m_forward % m_horizontal).Normal() * versize;
			//std::cout << m_forward << m_horizontal << m_vertical;
		}
		Camera(vector3f const& pos, vector3f const& lookat, float len, vector3f const &hor, float horsize, float versize, int hres, int vres,float dis) : Camera(pos, pos.LookAt(lookat).Normal()*len, hor, horsize, versize, hres, vres,dis) {};
		~Camera();

		void TakePhoto(std::vector<Mesh> const& all_mesh) {

			FILE *fp=fopen(R"(E:\test.png)","wb");
			unsigned char *rgb = new unsigned char[m_hor_res * m_ver_res * 4];
			auto *p = rgb;

			for (int i=0-m_hor_res/2;i< m_hor_res-m_hor_res/2; i++) {
				system("cls");
				cout << (i + m_hor_res / 2)*100.0f / m_hor_res << "%..." << endl;
				for (int j=0-m_ver_res/2 ; j < m_ver_res -m_ver_res/2; j++) {
					Ray ray{ m_poistion,(m_poistion + m_forward + m_horizontal * (i*2.0f / m_hor_res) + m_vertical * (j*2.0f / m_ver_res)) };
					
					Mesh const*NearMesh = nullptr;
					float dis = m_max_dis;
					for (auto &x : all_mesh) {
						auto tmp = x.RayCasting(ray);

						if (tmp>0 && tmp < dis) {
							//cout << tmp << " " << int (x.m_color.R) << " ";
							//std::cout << "¡ð";
							dis = tmp;
							NearMesh = &x;
						}
					}
					if (!NearMesh) {
						*p++ = 200;
						*p++ = 200;
						*p++ = 200;
						*p++ = 255;
					}
					else {
						//cout << int( NearMesh->m_color.R )<< endl;
						*p++ = NearMesh->m_color.R;
						*p++ = NearMesh->m_color.G;
						*p++ = NearMesh->m_color.B;
						*p++ = NearMesh->m_color.A;
					}

					//if (!flag) std::cout << "  ";


				}
				//std::cout << std::endl;
			}
			svpng(fp,m_hor_res,m_ver_res,rgb,1);
			delete[] rgb;
			fclose(fp);
		}

	private:
		vector3f m_poistion;
		vector3f m_forward;
		vector3f m_horizontal;
		vector3f m_vertical;
		float m_max_dis;
		int m_hor_res;
		int m_ver_res;
	};


	Camera::~Camera()
	{
	}

}