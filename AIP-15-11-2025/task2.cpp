#include <iostream>

void mul(int * c, const int * a, size_t n1, size_t m1, const int b, size_t m2)
{
  for (size_t i = 0; i < n1; ++i) {
    for (size_t j = 0; j < m2; ++j) {
      int res = 0;
      const int * row_a = a + i * m1;
      const int * row_b = a + j;
      for (size_t l = 0; l < m1; ++l) {
        int row_a_l = row_a[l];
        int row_b_l = row_b[l * m2];
        res += row_a_l * row_b_l;
      }
      c[i * m2 + j] = res;
    }
  }
}
int main()
{}