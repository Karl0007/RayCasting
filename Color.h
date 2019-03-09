#pragma once
namespace My {
	class Color
	{
	private:
		typedef unsigned char uch;

	public:
		Color(uch R=0, uch G=0, uch B=0, uch A=0) : R(R), G(G), B(B), A(A) {};
		uch R, G, B, A;
	};

}