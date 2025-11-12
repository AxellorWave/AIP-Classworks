#include <iostream>

// int * transpose(const int * a, size_t n, size_t m)
// {
//   int * new_a = new int[n*m];
//   for (size_t i = 0; i < n; ++i) {
//     for (size_t j = 0; j < m; ++j) {
//       new_a[j*n+i] = a[i*m+j];
//     }
//   }
//   return new_a;
// }

void transpose(int * a, size_t n, size_t m)
{
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i + 1; j < m; ++j) {
      int temp = a[i*m + j];
      a[i*m + j] = a[j*n + i];
      a[j*n + i] = temp;

    }
  }
}
size_t mem_for_transpose(size_t n, size_t m)
{}

int main()
{
  int * mtx = new int[8] {1, 2, 3, 4, 5, 6, 7, 8};
  transpose(mtx, 2, 4);
  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 0; j < 2; ++j) {
      std::cout << mtx[i*2 + j] << " ";
    }
    std::cout << "\n";
  }
}