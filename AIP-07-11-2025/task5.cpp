#include <iostream>

int* resize(const int* a, size_t k, size_t d, int filler);
void resize2(int** a, size_t d, size_t k, int filler);
int * add_row(const int* a, size_t n, size_t m, int filler);
void * add_col(int** a, size_t n, size_t m, int filler);

int main()
{
  size_t rows = 2 , cols = 3;
  int* a = new int[rows * cols]{1,2,3,4,5,6};
  int k = 10;
  //add_col(a, rows, cols, 0);
  //++cols;
  int* c = add_row(a,rows, cols, 1);
  ++rows;
  for (size_t i = 0; i < rows; ++i) {
  for (size_t j = 0; j < cols; ++j) {
    std::cout << c[i*cols + j] <<'\t';
  }
  std::cout << '\n';
}
  delete[] a;
  //delete[] b;
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

void add_col(const int** a, size_t n, size_t m, int filler)
{
  for (size_t i = 0; i < n; ++i) {
    int *new_str = resize(a[i], m, m + 1, filler) ;
    delete[] a[i];
    a[i] = new_str;
  }
  // for (size_t i = 0; i < n; ++i) {
  //   resize(a[i], m, m+1, filler);
  // }
}

void resize2(int** a, size_t d, size_t k, int filler)
{
  int* narr = resize(*a, d, k, filler);
  delete[] *a;
  *a = narr;
}
