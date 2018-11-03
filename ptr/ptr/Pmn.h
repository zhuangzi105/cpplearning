#pragma once
template<unsigned N>
struct Factorial {
	enum { VALUE = N*Factorial<N - 1>::VALUE };

};
template<>
struct Factorial<1> {
	enum { VALUE = 1 };

};


template<unsigned H, unsigned N>
struct Permutation {
	enum {
		VALUE = Factorial<N>::VALUE / Factorial<H>::VALUE / Factorial<N-H>::VALUE
	};

};

//template<>
//struct Permutation<0,1> {
//	enum { VALUE =0 };
//
//};
//
//template<>
//struct Permutation<1, 1> {
//	enum { VALUE = 1 };
//
//};