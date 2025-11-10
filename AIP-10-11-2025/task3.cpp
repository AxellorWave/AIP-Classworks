#include <iostream>

int * copy(const int * v, size_t k, int * w)
{
  for (size_t i = 0; i < k; ++i) {
    w[i] = v[i];
  }
  return w + k;
}

int det(int * b, const int * lhs, size_t n)
{
  if (!n) {
    return 0;
  } else if (n == 1) {
    return lhs[0];
  } else if (n == 2) {
    return lhs[0] * lhs[3] - lhs[1] * lhs[2];
  }
  int d = 0;
  for (size_t l = 0; l < n; ++l) {
    int * minor = b;
    for (size_t i = 1; i < n; ++i) {
      const int * lhs_row = lhs + i * n;
      int * minor_row = minor + (i - 1) * (n - 1);
      minor_row = copy(lhs_row, l, minor_row);
      lhs_row += l + 1;
      copy(lhs_row, n - (l + 1), minor_row);
    }
    int * next = b + (n - 1) * (n - 1);
    d += lhs[l] * det(next, minor, n - 1) * ((l % 2) ? -1 : 1);
  }
  return d;
}

int main() 
{

}