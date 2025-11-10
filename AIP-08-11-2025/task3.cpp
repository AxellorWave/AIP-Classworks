#include <iostream>

int det(const int * a, size_t n)
{
  if (!n) {
    return 0;
  }
  if (n == 1) {
    return a[0];
  }
  if (n == 2) {
    return a[0] * a[3] - a[1] * a[2];
  }
  int res = 0;
  for (size_t i = 0; i < n; ++i) {
    int num = a[i];
    int * minor = new int[(n-1)*(n-1)];
    size_t count = 0;
    for (size_t j = 1; j < n; ++j) {
      for (size_t k = 0; k < n; ++k) {
        if (k != i) {
          minor[count] = (i + j) * n + k;
          ++count;
        }
      }
    }
    if (i % 2 == 0) {
      res += num * det(minor, n-1);
    } else {
      res -= num * det(minor, n-1);
    }
  }
  return res;
}

int main()
{
  int * matrix = new int[9];
  for (size_t i = 1; i < 10; ++i){
    matrix[i-1] = i;
  }
  std::cout << det(matrix, 3) << "\n"; 
}