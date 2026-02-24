#include <iostream>

template< class T >
struct Vec {
  T* data;
  size_t s;
};

template< class T >
struct VecIt {
  T* data;
  size_t s, i;
};

template< class T >
VecIt< T > begin(Vec< T > v)
{
  return {v.data, v.s, 0};
}

template< class T >
bool hasNext(VecIt< T > it)
{
  return it.s != it.i;
}

template< class T >
VecIt< T > next(VecIt< T > it)
{
  it.i++;
  return it;
}

template < class T >
T & value(VecIt< T > it)
{
  return it.data[it.i];
}

template< class T >
struct VecRIT {
  T * data;
  size_t s, i;
};

template< class T >
VecRIT< T > begin(Vec< T > v)
{
  return {v.data, v.s, v.s};
}

template< class T >
T & value(VecRIT< T > it)
{
  return it.data[it.i - 1];
}

template< class T >
bool hasNext(VecRIT< T > it)
{
  return it.i;
}

template< class T >
VecRIT< T > prev(VecRIT< T > it)
{
  it.i--;
  return it;
}

template< class T >
struct List {
  T val;
  List< T > * next;
};

template< class T >
struct ListOfVecIt {
  List< Vec< T > > * curr;
  size_t i;
};

template< class T >
ListOfVecIt< T > begin(List< Vec< T > > * h)
{
  return {h, 0};
}

template< class T >
ListOfVecIt< T > next(ListOfVecIt< T > it)
{
  if (it.i + 1 < it.curr->val.s) {
    return {it.curr, it.i + 1};
  } else {
    it.curr = it.curr->next;
    while (it.curr->val.data == nullptr) {
      it.curr = it.curr->next;
    }
    return {it.curr, 0};
  }
}




template< class T >
T & value(ListOfVecIt< T > it)
{
  return it.curr->val.data[it.i];
}

template< class T >
bool hasNext(ListOfVecIt< T > it)
{
  return it.curr != nullptr;
}

int main()
{
  List <Vec<int>>* h = new List<Vec<int>>;
  h->val = Vec<int>{new int[3], 3};
  for (size_t i = 0; i < 3; ++i) {
    h->val.data[i] = i;
  }

  List <Vec<int>>* m = new List<Vec<int>>;
  m->val = Vec<int>{nullptr, 0};
  h->next = m;

  List <Vec<int>>* t = new List<Vec<int>>;
  t->val = Vec<int>{new int[4], 4};
  for (size_t i = 0; i < 4; ++i) {
    t->val.data[i] = i;
  }
  m->next = t;
  ListOfVecIt<int> it = begin(h);
  for (; hasNext(it); it = next(it)) {
    std::cout << value(it) << '\n';
  }


  return 0;
}
