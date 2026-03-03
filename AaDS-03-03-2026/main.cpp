#include <iostream>

template< class T >
struct List {
  T val;
  List< T > * next;
};

template< class T >
struct Vec {
  T * data;
  size_t s;
};

template< class T >
List< Vec< T > > * copy(List< Vec< T > > * h)
{}

int main()
{}