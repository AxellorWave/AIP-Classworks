#include <iostream>

template <size_t N>
struct Fibonachi {
  enum {
    value = Fibonachi< N-1>::value + Fibonachi<N-2>::value
  };
};

template< >
struct Fibonachi< 0 > {
  enum {
    value = 0
  };
};

template< >
struct Fibonachi< 1 > {
  enum {
    value = 1
  };
};

int main()
{
  std::cout << Fibonachi< 10 >::value << "\n";
}