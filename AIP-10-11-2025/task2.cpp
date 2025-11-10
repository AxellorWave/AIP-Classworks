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
    int pivot = a[i];
    int * minor = nullptr;
    minor = new int[(n-1)*(n-1)];
    size_t count = 0;
    for (size_t j = 1; j < n; ++j) {
      for (size_t k = 0; k < n; ++k) {
        if (k != i) {
          minor[count] = a[j * n + k];
          ++count;
        }
      }
    }
    try {
      if (i % 2 == 0) {
        res += pivot * det(minor, n-1);
      } else {
        res -= pivot * det(minor, n-1);
      }
    } catch (const std::bad_alloc &) {
      delete[] minor;
      throw;
    }
    delete[] minor;
  }
  return res;
}

int main()
{
  int * matrix = nullptr;
  try {
    matrix = new int[9];
  } catch (const std::bad_alloc &) {
    return 1;
  }
  for (size_t i = 1; i < 10; ++i){
    matrix[i-1] = i;
  }
  try {
    std::cout << det(matrix, 3) << "\n"; 
  } catch (const std::bad_alloc &) {
    delete[] matrix;
    return 1;
  }
  delete[] matrix;
}