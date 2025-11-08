#include <iostream>

int* resize(const int* a, size_t k, size_t d, int filler);
int * add_row(const int* a, size_t n, size_t m, int filler);
int * add_col(const int* a, size_t n, size_t m, int filler);

int main()
{
  size_t rows = 2 , cols = 3;
  int* a = new int[rows * cols]{1,2,3,4,5,6};
  int k = 10;
  int* b = add_col(a, rows, cols, 0);
  ++cols;
  int* c = add_row(b,rows, cols, 1);
  ++rows;
  for (size_t i = 0; i < rows; ++i) {
  for (size_t j = 0; j < cols; ++j) {
    std::cout << c[i*cols + j] <<'\t';
  }
  std::cout << '\n';
}
  delete[] a;
  delete[] b;
  delete[] c;
}

int* resize(const int* a, size_t k, size_t d, int filler)
{
  int* newArr = new int[d];
  if (d > k) {
    size_t i = 0;
    for (; i < k; i++) {
      newArr[i] = a[i];
    }
    for (; i < d; i++) {
      newArr[i] = filler;
    }
  } else {
    size_t i = 0;
    for (; i < d; i++) {
      newArr[i] = a[i];
    }
  }
  return newArr;
}

int * add_row(const int* a, size_t n, size_t m, int filler)
{
  return resize(a, n*m, (n+1)*m, filler);
}

int * add_col(const int* a, size_t n, size_t m, int filler)
{
  int * new_arr = new int[n * (m+1)];
  for (size_t i = 0; i < n; ++i){
    for (size_t j = 0; j < m; ++j){
      new_arr[i * (m + 1) + j] = a[i * m + j]; 
    }
    new_arr[i * (m + 1) + m] = filler;
  }
  return new_arr;
}
