#include <iostream>

template< class T >
struct Vec {
  T* data;
  size_t size;
};

template< class T >
struct List {
  T val;
  List< T > * next;
};


template < class T >
size_t size(const List< Vec< T > * > * h)
{
  size_t res = 0;
  while (h) {
    res += h->val ? h->val->s : 0;
    h = h->next;
  }
  return res;
}

template < class T >
void clear(List< Vec< T > * > * h)
{
  while (h) {
    List< Vec< T > * > * n = h->next;
    delete[] h->val->data;
    delete h->val;
    delete h;
    h = n;
  }
}