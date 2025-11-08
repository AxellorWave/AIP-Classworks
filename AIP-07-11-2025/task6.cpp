#include <iostream>

int ** concat_rows(
  const int * const * lhs, size_t m1,
  const int * const * rhs, size_t m2
);


int main()
{
  
}


int ** concat_rows(
  const int * const * lhs, size_t n1, size_t m1,
  const int * const * rhs, size_t n2, size_t m2
)
{
  size_t maxRows = std::max(n1, n2);
  int ** table = new int * [maxRows];
  for (size_t i = 0; i < maxRows; ++i) {
    table[i] = new int[m1 + m2];
  }
  for (size_t i = 0; i < n1; ++i) {
    for (size_t j = 0; j < m1; ++j) {
      table[i][j] = lhs[i][j];
    }
  }
  for (size_t i = 0; i < n2; ++i) {
    for (size_t j = 0; j < m2; ++j) {
      table[i][j+m1] = rhs[i][j];
    }
  }
  return table;
}