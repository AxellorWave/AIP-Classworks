#include <iostream>

template< class T >
struct List {
  T val;
  List< T > * next;
};

template< class T >
struct Vec {
  T * data;
  size_t s, cap;
};

template< class T >
size_t size(Vec< List< T > * > v)
{
  size_t res = 0;
  for (size_t i = 0; i < v.s; ++i) {
    while (v.data[i]) {
      ++res;
      v.data[i] = v.data[i]->next;
    }
  }
  return res;
}

template< class T >
struct VecListIt {
  Vec< List< T > * > v;
  size_t i;
  List< T > * cur;
};

template< class T >
bool hasNext(VecListIt< T >  it)
{
  return it.i != it.v.s - 1;
}

template< class T >
VecListIt< T > next(VecListIt< T > it)
{
  if (it.cur->next) {
    return {v, it.i, cur->next};
  }
  return {v, it.i + 1, it.v.data[it.i + 1]};
}

template< class T >
T value(VecListIt< T > it)
{
  return it.cur->val;
}

template< class T >
VecListIt< T > begin(Vec< List< T > * > v)
{
  return {v, 0, v.data[0]};
}

template< class T >
Vec< List< T > * > balanced_copy(Vec< List< T > * > v, size_t k)
{
  size_t s = size(v) / k;
  if (s * k != size(v)) {
    ++s;
  }
  Vec< List< T > * > res = new Vec< List< T > * >
}