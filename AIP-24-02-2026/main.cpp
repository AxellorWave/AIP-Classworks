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
