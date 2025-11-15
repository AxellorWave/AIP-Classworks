#include <iostream>

void sum(size_t n, size_t m, int * c, const int * a, const int *b)
{
  for (size_t i = 0; i < n * m; ++i) {
    c[i] = a[i] + b[i];
  }
}

int * sum(size_t n, size_t m, const int * a, const int *b)
{
  int * c = new int[n*m];
  sum(n, m, c, a, b);
  return c;
}

void add(size_t n, size_t m, int * a, const int * b)
{
  sum(n, m, a, a, b);
}


int main()
{
  int * a = new int[4] {1, 2, 3, 4};
  int * b = new int[4] {4, 3, 2, 1};
  add(2,2, a, b);
  for (size_t i = 0; i < 4; ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << "\n";
  delete [] a;
  delete [] b;
}