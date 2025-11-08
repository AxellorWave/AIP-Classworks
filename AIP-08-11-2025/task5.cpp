#include <iostream>

void extend(size_t ** a, size_t k, size_t d, size_t filler)
{
  size_t * newArr = new size_t[d];
  if (d > k) {
    size_t i = 0;
    for (; i < k; i++) {
      newArr[i] = (*a)[i];
    }
    for (; i < d; i++) {
      newArr[i] = filler;
    }
  } else {
    size_t i = 0;
    for (; i < d; i++) {
      newArr[i] = * a[i];
    }
  }
  delete[] *a;
  *a = newArr;
}

int main()
{
  size_t c = 0;
  size_t n = 0;
  size_t * arr = new size_t[1];
  while (std::cin >> n) {
    try {
      ++c;
      if (c == 1) {
        arr[0] = n;
      } else {
        extend(&arr, c - 1, c, n);          
      }
    } catch (const std::bad_alloc &e){
      std::cerr << e.what() << "\n";
      delete[] arr;
      return 1;

    }
  }

  if (std::cin.eof()) {
    if (c == 0) {
      std::cerr << "Entered 0 numbers\n";
      delete[] arr;
      return 1;
      
    }
    for (size_t i = 0; i < c; ++i) {
      if (arr[i] % arr[c-1] == 0) {
        std::cout << arr[i] << "\n"; 
      } 
    }
    delete[] arr;
  } else if (std::cin.fail()) {
    std::cerr << "Brooo, it is FAIL!!!\n";
    delete[] arr;
    return 1;
  }
}