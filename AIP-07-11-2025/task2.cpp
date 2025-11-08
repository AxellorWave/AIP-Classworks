#include <iostream>

void resize2(int** a, size_t d, size_t k, int filler);

int main()
{
  int* a = new int[5]{1,2,3,4,5};
  int k = 10;
  resize2(&a, 5, k, 0);
  for (size_t i = 0; i < k; ++i ) {
    std::cout << a[i] << '\n';
  }
  delete[] a;
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

void resize2(int** a, size_t d, size_t k, int filler)
{
  int* narr = resize(*a, d, k, filler);
  delete[] *a;
  *a = narr;
}
