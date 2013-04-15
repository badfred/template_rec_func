#include <iostream>

// math. power function
template<unsigned b, unsigned e>
struct power {
  static const int value;
};

template<unsigned b, unsigned e>
const int power<b, e>::value = b * power<b, e - 1>::value;

template<unsigned b>
struct power<b, 0> {
  static const int value;
};

template<unsigned b>
const int power<b, 0>::value = 1;

// tests

template<unsigned i>
struct minus {
  static const unsigned value;
};

template<unsigned i>
const unsigned minus<i>::value = i - 1;

template<>
struct minus<0> {
  static const unsigned value;
};

const unsigned minus<0>::value = 0;


template<unsigned i>
struct plus {
  static const unsigned value;
};

template<unsigned i>
const unsigned plus<i>::value = i + 1;

class c {};

template<template<typename> class t>
struct loop {
  static const unsigned value;
};

template<template<typename> class t>
const unsigned loop<t>::value = t<t<int> >::value;

///////////////////////////////////
// recursive functions, n = 0..3 //
///////////////////////////////////

// sucessor

template <unsigned x>
struct S {
  static const unsigned value;
};

template <unsigned x>
const unsigned S<x>::value = x + 1;

// projections

template <unsigned x1>
struct U1_1 {
  static const unsigned value;
};

template <unsigned x1>
const unsigned U1_1<x1>::value = x1;


template <unsigned x1, unsigned x2>
struct U2_1 {
  static const unsigned value;
};

template <unsigned x1, unsigned x2>
const unsigned U2_1<x1, x2>::value = x1;


template <unsigned x1, unsigned x2>
struct U2_2 {
  static const unsigned value;
};

template <unsigned x1, unsigned x2>
const unsigned U2_2<x1, x2>::value = x2;

//

template <unsigned x1, unsigned x2, unsigned x3>
struct U3_1 {
  static const unsigned value;
};

template <unsigned x1, unsigned x2, unsigned x3>
const unsigned U3_1<x1, x2, x3>::value = x1;


template <unsigned x1, unsigned x2, unsigned x3>
struct U3_2 {
  static const unsigned value;
};

template <unsigned x1, unsigned x2, unsigned x3>
const unsigned U3_2<x1, x2, x3>::value = x2;


template <unsigned x1, unsigned x2, unsigned x3>
struct U3_3 {
  static const unsigned value;
};

template <unsigned x1, unsigned x2, unsigned x3>
const unsigned U3_3<x1, x2, x3>::value = x3;

// constants

template <unsigned c>
struct C0 {
  struct func {
    static const unsigned value;
  };
};

template <unsigned c>
const unsigned C0<c>::func::value = c;

//

template <unsigned c>
struct C1 {
  template <unsigned x1>
  struct func {
    static const unsigned value;
  };
};

template <unsigned c>
template <unsigned x1>
const unsigned C1<c>::func<x1>::value = c;

//

template <unsigned c>
struct C2 {
  template <unsigned x1, unsigned x2>
  struct func {
    static const unsigned value;
  };
};

template <unsigned c>
template <unsigned x1, unsigned x2>
const unsigned C2<c>::func<x1, x2>::value = c;

//

template <unsigned c>
struct C3 {
  template <unsigned x1, unsigned x2, unsigned x3>
  struct func {
    static const unsigned value;
  };
};

template <unsigned c>
template <unsigned x1, unsigned x2, unsigned x3>
const unsigned C3<c>::func<x1, x2, x3>::value = c;

// simultaneous substitution

template <template<unsigned> class g,
            template<unsigned> class h1>
struct subs1_1 {
  template<unsigned x1>
  struct func {
    static const unsigned value;
  };
};

template <template<unsigned> class g,
            template<unsigned> class h1>
template<unsigned x1>
const unsigned subs1_1<g, h1>::func<x1>::value = g<h1<x1>::value>::value;

//

template <template<unsigned, unsigned> class g,
            template<unsigned> class h1,
            template<unsigned> class h2>
struct subs1_2 {
  template<unsigned x1>
  struct func {
    static const unsigned value;
  };
};

template <template<unsigned, unsigned> class g,
            template<unsigned> class h1,
            template<unsigned> class h2>
template<unsigned x1>
const unsigned subs1_2<g, h1, h2>::func<x1>::value = g<h1<x1>::value, h2<x1>::value>::value;

//

template <template<unsigned> class g,
            template<unsigned, unsigned> class h1>
struct subs2_1 {
  template<unsigned x1, unsigned x2>
  struct func {
    static const unsigned value;
  };
};

template <template<unsigned> class g,
            template<unsigned, unsigned> class h1>
template<unsigned x1, unsigned x2>
const unsigned subs2_1<g, h1>::func<x1, x2>::value = g<h1<x1, x2>::value>::value;

//

template <template<unsigned, unsigned> class g,
            template<unsigned, unsigned> class h1,
            template<unsigned, unsigned> class h2>
struct subs2_2 {
  template<unsigned x1, unsigned x2>
  struct func {
    static const unsigned value;
  };
};

template <template<unsigned, unsigned> class g,
            template<unsigned, unsigned> class h1,
            template<unsigned, unsigned> class h2>
template<unsigned x1, unsigned x2>
const unsigned subs2_2<g, h1, h2>::func<x1, x2>::value = g<h1<x1, x2>::value, h2<x1, x2>::value>::value;

//

template <template<unsigned> class g,
            template<unsigned, unsigned, unsigned> class h1>
struct subs3_1 {
  template<unsigned x1, unsigned x2, unsigned x3>
  struct func {
    static const unsigned value;
  };
};

template <template<unsigned> class g,
            template<unsigned, unsigned, unsigned> class h1>
template<unsigned x1, unsigned x2, unsigned x3>
const unsigned subs3_1<g, h1>::func<x1, x2, x3>::value = g<h1<x1, x2, x3>::value>::value;

//

template <template<unsigned, unsigned> class g,
            template<unsigned, unsigned, unsigned> class h1,
            template<unsigned, unsigned, unsigned> class h2>
struct subs3_2 {
  template<unsigned x1, unsigned x2, unsigned x3>
  struct func {
    static const unsigned value;
  };
};

template <template<unsigned, unsigned> class g,
            template<unsigned, unsigned, unsigned> class h1,
            template<unsigned, unsigned, unsigned> class h2>
template<unsigned x1, unsigned x2, unsigned x3>
const unsigned subs3_2<g, h1, h2>::func<x1, x2, x3>::value
                      = g<h1<x1, x2, x3>::value, h2<x1, x2, x3>::value>::value;


// primitive recursion

template <template<unsigned, unsigned, unsigned> class g,
            template<unsigned, unsigned, unsigned, unsigned, unsigned> class h,
            unsigned x1, unsigned x2, unsigned x3, unsigned y>
struct pr3 {
  static const unsigned value;
};

template <template<unsigned, unsigned, unsigned> class g,
            template<unsigned, unsigned, unsigned, unsigned, unsigned> class h,
            unsigned x1, unsigned x2, unsigned x3, unsigned y>
const unsigned pr3<g, h, x1, x2, x3, y>::value
            = h<x1, x2, x3, y - 1, pr3<g, h, x1, x2, x3, y - 1>::value >::value;

template <template<unsigned, unsigned, unsigned> class g,
            template<unsigned, unsigned, unsigned, unsigned, unsigned> class h,
            unsigned x1, unsigned x2, unsigned x3>
struct pr3<g, h, x1, x2, x3, 0> {
  static const unsigned value;
};

template <template<unsigned, unsigned, unsigned> class g,
            template<unsigned, unsigned, unsigned, unsigned, unsigned> class h,
            unsigned x1, unsigned x2, unsigned x3>
const unsigned pr3<g, h, x1, x2, x3, 0>::value
            = g<x1, x2, x3>::value;

//

template <template<unsigned> class g,
            template<unsigned, unsigned, unsigned> class h,
            unsigned x1, unsigned y>
struct pr1_aux {
  static const unsigned value;
};

template <template<unsigned> class g,
            template<unsigned, unsigned, unsigned> class h,
            unsigned x1, unsigned y>
const unsigned pr1_aux<g, h, x1, y>::value
            = h<x1, y - 1, pr1_aux<g, h, x1, y - 1>::value>::value;

template <template<unsigned> class g,
            template<unsigned, unsigned, unsigned> class h,
            unsigned x1>
struct pr1_aux<g, h, x1, 0> {
  static const unsigned value;
};

template <template<unsigned> class g,
            template<unsigned, unsigned, unsigned> class h,
            unsigned x1>
const unsigned pr1_aux<g, h, x1, 0>::value
            = g<x1>::value;


template <class g,
            template<unsigned, unsigned> class h,
            unsigned y>
struct pr0_aux {
  static const unsigned value;
};

template <class g,
            template<unsigned, unsigned> class h,
            unsigned y> 
const unsigned pr0_aux<g, h, y>::value
            = h<y - 1, pr0_aux<g, h, y - 1>::value>::value;

template <class g,
            template<unsigned, unsigned> class h>
struct pr0_aux<g, h, 0> {
  static const unsigned value;
};

template <class g,
            template<unsigned, unsigned> class h>
const unsigned pr0_aux<g, h, 0>::value
            = g::value;

// without x1 and x2:

template <template<unsigned> class g,
            template<unsigned, unsigned, unsigned> class h>
struct pr1 {
  template <unsigned x1, unsigned x2>
  struct func {
    static const unsigned value;
  };
};

template <template<unsigned> class g,
            template<unsigned, unsigned, unsigned> class h>
template <unsigned x1, unsigned x2>
const unsigned pr1<g, h>::func<x1, x2>::value = pr1_aux<g, h, x1, x2>::value;


template <class g,
            template<unsigned, unsigned> class h> 
struct pr0 {
  template <unsigned x1>
  struct func {
    static const unsigned value;
  };
};

template <class g,
            template<unsigned, unsigned> class h>
template <unsigned x1>
const unsigned pr0<g, h>::func<x1>::value = pr0_aux<g, h, x1>::value;


// mu operator

template <template<unsigned> class g,
            unsigned y, unsigned g_value>
struct mu0_aux {
  static const unsigned value;
};

template <template<unsigned> class g,
            unsigned y, unsigned g_value>
const unsigned mu0_aux<g, y, g_value>::value = mu0_aux<g, y + 1, g<y + 1>::value>::value;


template <template<unsigned> class g,
            unsigned y>
struct mu0_aux<g, y, 0> {
  static const unsigned value;
};

template <template<unsigned> class g,
            unsigned y>
const unsigned mu0_aux<g, y, 0>::value = y;


template <template<unsigned> class g>
struct mu0 {
  struct func {
    static const unsigned value;
  };
};

template <template<unsigned> class g>
const unsigned mu0<g>::func::value = mu0_aux<g, 0, g<0>::value>::value;

//

template <template<unsigned, unsigned> class g,
            unsigned x1, unsigned y, unsigned g_value>
struct mu1_aux {
  static const unsigned value;
};

template <template<unsigned, unsigned> class g,
            unsigned x1, unsigned y, unsigned g_value>
const unsigned mu1_aux<g, x1, y, g_value>::value = mu1_aux<g, x1, y + 1, g<x1, y + 1>::value>::value;


template <template<unsigned, unsigned> class g,
            unsigned x1, unsigned y>
struct mu1_aux<g, x1, y, 0> {
  static const unsigned value;
};

template <template<unsigned, unsigned> class g,
            unsigned x1, unsigned y>
const unsigned mu1_aux<g, x1, y, 0>::value = y;


template <template<unsigned, unsigned> class g>
struct mu1 {
  template <unsigned x1>
  struct func {
    static const unsigned value;
  };
};

template <template<unsigned, unsigned> class g>
template <unsigned x1>
const unsigned mu1<g>::func<x1>::value = mu1_aux<g, x1, 0, g<x1, 0>::value>::value;

// complex functions

template <unsigned x1, unsigned x2>
struct add {
  static const unsigned value;
};

template <unsigned x1, unsigned x2>
const unsigned add<x1, x2>::value = pr1<U1_1, subs3_1<S, U3_3>::func>::func<x1, x2>::value;

//

template <unsigned x1, unsigned x2>
struct mult {
  static const unsigned value;
};

template <unsigned x1, unsigned x2>
const unsigned mult<x1, x2>::value = pr1<C1<0>::func, subs3_2<add, U3_3, U3_1>::func>::func<x1, x2>::value;

//

template <unsigned x1>
struct P {
  static const unsigned value;
};

template <unsigned x1>
const unsigned P<x1>::value = pr0<C0<0>::func, U2_1>::func<x1>::value;

//

template <unsigned x1, unsigned x2>
struct sub {
  static const unsigned value;
};

template <unsigned x1, unsigned x2>
const unsigned sub<x1, x2>::value = pr1<U1_1, subs3_1<P, U3_3>::func>::func<x1, x2>::value;

//

template <unsigned x1>
struct f1 {
  static const unsigned value;
};

template <unsigned x1>
const unsigned f1<x1>::value = subs1_2<sub, C1<9>::func, subs1_2<mult, U1_1, U1_1>::func>::func<x1>::value;

//

template <unsigned x1, unsigned x2>
struct f2 {
  static const unsigned value;
};

template <unsigned x1, unsigned x2>
const unsigned f2<x1, x2>::value = subs2_2<sub, U2_1, subs2_2<mult, U2_2, U2_2>::func>::func<x1, x2>::value;

//

template <unsigned x1>
struct sqrt {
  static const unsigned value;
};

template <unsigned x1>
const unsigned sqrt<x1>::value = mu1<f2>::func<x1>::value;


int main() {
  std::cout << "2^20    = " << power<2, 20>::value << std::endl;

  std::cout << "22 + 11 = " << pr1<U1_1, subs3_1<S, U3_3>::func>::func<22, 11>::value << std::endl;

  std::cout << "12 *  7 = " << pr1<C1<0>::func, subs3_2<add, U3_3, U3_1>::func>::func<12, 6>::value << std::endl;

  std::cout << "3!      = " << pr0<C0<1>::func, subs2_2<mult, subs2_1<S, U2_1>::func, U2_2>::func>::func<3>::value << std::endl;

  std::cout << "3  -  1 = " << pr0<C0<0>::func, U2_1>::func<3>::value << std::endl;
  
  std::cout << "3  -  2 = " << pr1<U1_1, subs3_1<P, U3_3>::func>::func<3, 2>::value << std::endl;
  
  std::cout << "12 -  7 = " << subs3_2<sub, C3<12>::func, C3<7>::func>::func<3, 4, 5>::value << std::endl;


  std::cout << "3 * 4 - 7 = " << subs3_2<sub, subs3_2<mult, U3_1, U3_2>::func, U3_3 >::func<3, 4, 7>::value << std::endl;

  std::cout << "f1(2)   = " << f1<2>::value << std::endl;

  std::cout << "f2(2, 3)= " << f2<2, 3>::value << std::endl;

  std::cout << "µ[f1]   = " << mu0<f1>::func::value << std::endl;

  std::cout << "µ[f2](16)= " << mu1<f2>::func<16>::value << std::endl; //sqrt

  std::cout << "sqrt(25)= " << sqrt<25>::value << std::endl;

  return 0;
}
