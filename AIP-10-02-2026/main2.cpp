#include <iostream>

void reverse(int * a, size_t s){
  for (size_t i = 0; i < s / 2; ++i) {
    std::swap(a[i], a[s - i - 1]);
  }
}

int * reverse(const int * a, size_t s){
  int * res = new int[s];
  for (size_t i = s; i > 0; --i){
    res[s - i] = a[i - 1];
  }
  return res;
}


int main()
{
  const int arr[7] = {1, 2, 3, 4, 5, 6, 7};
  int * res = reverse(arr, 7);
  for (size_t i = 0; i < 7; ++i) {
    std::cout << res[i] << "\n";
  }
}