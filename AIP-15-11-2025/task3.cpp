#include <iostream>

void sum(size_t n, size_t m, int * c, const int * a, const int * b)
{
  for (size_t i = 0; i < n * m; ++i) {
    c[i] = a[i] + b[i];
  }
}

void add(size_t n, size_t m, int * a, const int * b)
{
  sum(n, m, a, a, b);
}
int * mul(const int * a, size_t n1, size_t m1, const int * b, size_t m2);

void mul(int * c, const int * a, size_t n1, size_t m1, const int * b, size_t m2)
{
  for (size_t i = 0; i < n1; ++i) {
    for (size_t j = 0; j < m2; ++j) {
      int res = 0;
      const int * row_a = a + i * m1;
      const int * col_b = b + j;
      for (size_t l = 0; l < m1; ++l) {
        int row_a_l = row_a[l];
        int row_b_l = col_b[l * m2];
        res += row_a_l * row_b_l;
      }
      c[i * m2 + j] = res;
    }
  }
}


void sum_of_mul(size_t n, int * c, const int * a, const int * const * b, size_t s)
{
  for (size_t i = 0; i < n*n; ++i) {
    c[i] = 0;
  }
  for (size_t i = 0; i < s; ++i) {
    add(n, n, c, b[i]);
  }
  mul(c, a, n, n, c, n);
}

int * sum_of_mul(size_t n, const int * a, const int * const * b, size_t s)
{
  int * c = new int[n*n];
  sum_of_mul(n, c, a, b, s);
  return c;
}

void mul_of_mul(size_t n, int * c, const int * a, const int * const * b, size_t s)
{
  for (size_t i = 0; i < n*n; ++i) {
    c[i] = 1;
  }
  int * temp = nullptr;
  for (size_t i = 0; i < s; ++i) {
    temp = mul(a, n, n, b[i], n);
    mul(c, c, n, n, temp, n);
    delete[] temp;
  }
}

int * mul_of_mul(size_t n, const int * a, const int * const * b, size_t s)
{
  int * c = new int[n*n];
  mul_of_mul(n, c, a, b, s);
  return c;
}

int main()
{}