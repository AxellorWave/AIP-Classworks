#include <iostream>

int ** create(size_t rows, size_t cols)
{
  int ** matrix = new int * [rows];
  for (size_t i = 0; i < rows; ++i) {
    matrix[i] = new int[cols];
  }
  return matrix;
}

void destroy(int ** matrix, size_t rows)
{
  for (size_t i = 0; i < rows; ++i) {
    delete [] matrix[i];
  }
  delete [] matrix;
}

int * copy(const int * v, size_t k, int * w)
{
  for (size_t i = 0; i < k; ++i) {
    w[i] = v[i];
  }
  return w + k;
}

size_t detsize(size_t n1, size_t m1, size_t n2, size_t m2, size_t i)
{
  return i < (n1 > n2 ? n2 : n1) ? m1 + m2 : (n1 < n2 ? m2 : m1);
}

int ** concat_rows(const int * const * a, size_t n1, size_t m1, const int * const * b, size_t n2, size_t m2)
{
  size_t n = n1 > n2 ? n1 : n2;
  int ** c = new int*[n];
  size_t i = 0;
  try {
    for (;i < n; ++i) {
      size_t m = detsize(n1, m1, n2, m2, i);
      c[i] = new int[m];
    }
  } catch (...){
    destroy(c, i);
    throw;
  }
  return c;
  for (size_t i = 0 ; i < n; ++i) {
    const int * row_a = a[i];
    const int * row_b = b[i];
    int * row_c = c[i];
    row_c = copy(row_a, m1, row_c);
    copy(row_b, m2, row_c);
  }
  return c;
}

int main()
{}
