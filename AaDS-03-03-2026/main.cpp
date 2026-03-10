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
void clear(List< Vec< T > > * h)
{
  while (h) {
    List< Vec< T > > * next = h->next;
    delete[] h->val.data;
    delete[] h;
    h = next;
  }

}

template< class T >
Vec< T > copy(const Vec< T > & v)
{
  Vec< T > res;
  res.s = v.s;
  try {
    res.data = new T[v.s];
    for (size_t i = 0; i < v.s; ++i) {
      res.data[i] = v.data[i];
    }
  } catch (...) {
    delete[] res.data;
  }
  return res;
}


template< class T >
List< Vec< T > > * copy(List< Vec< T > > * h)
{
  List< Vec< T > > * res = nullptr;
  try {
    res = new List< Vec< T > >{copy(h->val), nullptr};
    List< Vec< T > > * c = res;
    while (h->next) {
      h = h->next;
      c->next = new List< Vec< T > >{copy(h->val), nullptr};
      c = c->next;
    }
  } catch (...) {
    clear(res);
    throw;
  }
  return res;
}

template< class T >
List< T > * next(List< T > * node)
{
  return node->next;
}

template< class T >
bool hasNext(List< T > * node)
{
  return node->next != 0;
}

int main()
{
  List< Vec< int > >* h = new List<Vec<int>>;
  h->val = Vec<int>{new int[3], 3};
  for (size_t i = 0; i < 3; ++i) {
    h->val.data[i] = (int) i;
  }
  h->next = new List<Vec<int>>;
  h->next->val = Vec<int>{new int[3], 3};
  for (size_t i = 3; i < 6; ++i) {
    h->next->val.data[i-3] = (int) i;
  }
  List< Vec< int > >* r = copy(h);
  clear(h);
  clear(r);

}
