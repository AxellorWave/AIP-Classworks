#include <iostream>

int* resize(const int* a, size_t k, size_t d, int filler);

int main()
{
  int a[] = {1,2,3,4,5};
  int k = 10;
  int* narr(resize(a, 5, k, 11));

  for (size_t i = 0; i < k; ++i ) {
    std::cout << narr[i] << '\n';
  }
  delete[] narr;
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