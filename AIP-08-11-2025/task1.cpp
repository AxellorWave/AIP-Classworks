#include <iostream>

int ** concat_rows(
  const int * const * lhs, size_t n1, size_t m1,
  const int * const * rhs, size_t n2, size_t m2
);
void show_matrix(int** a, size_t n, size_t m);
void destroy(int ** mtx, size_t rows);

int main()
{
  int** a = new int*[2];
  int** b = new int*[3];


  a[0] = new int[3]{1,2,3};
  a[1] = new int[3]{6,7,8};

  b[0] = new int[3]{4,5,6};
  b[1] = new int[3]{9,10,11};
  b[2] = new int[3]{12,13,14};

  show_matrix(a, 2, 3);
  std::cout << "\n---------------------\n\n";
  show_matrix(b, 3, 3);

  int** n = concat_rows(a, 2, 3, b, 3, 3);
  std::cout << "\n---------------------\n\n";
  show_matrix(n, 2, 6);
  destroy(a, 2);
  destroy(b, 3);
  destroy(n, 2);
}

int ** concat_rows(
  const int * const * lhs, size_t n1, size_t m1,
  const int * const * rhs, size_t n2, size_t m2
)
{
  size_t maxRows = std::min(n1, n2);
  int ** table = new int * [maxRows];
  for (size_t i = 0; i < maxRows; ++i) {
    table[i] = new int[m1 + m2];
  }
  for (size_t i = 0; i < maxRows; ++i) {
    for (size_t j = 0; j < m1; ++j) {
      table[i][j] = lhs[i][j];
    }
  }
  for (size_t i = 0; i < maxRows; ++i) {
    for (size_t j = 0; j < m2; ++j) {
      table[i][j+m1] = rhs[i][j];
    }
  }
  return table;
}

void show_matrix(int** a, size_t n, size_t m)
{
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      std::cout << a[i][j] <<'\t';
    }
    std::cout << '\n';
  }
}

void destroy(int ** mtx, size_t rows)
{
  for (size_t i = 0; i < rows; ++i) {
    delete[] mtx[i];
  }
  delete[] mtx;
}
