#include <iostream>

int ** concat_rows(const int * const * a, size_t n1, size_t m1, const int * const * b, size_t n2, size_t m2);

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

int ** concat_rows(const int * const * a, size_t n1, size_t m1, const int * const * b, size_t n2, size_t m2)
{
  size_t n = n1 > n2 ? n2 : n1;
  int ** c = create(n, m1 + m2);
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
