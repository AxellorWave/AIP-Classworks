#include <iostream>

int * insert(const int * a, size_t s, size_t i, int v)
{
  if (i < 0 || i > s) {
    throw std::out_of_range("ENTER NORMAL I, STUPID HUMAN");
  }
  int * res = new int[s + 1];
  for (size_t j = 0; j < i; ++j) {
    res[j] = a[j];
  }
  res[i] = v;
  for (size_t j = i + 1; j < s + 1; ++j) {
    res[j] = a[j - 1];
  }
  return res;
}

void insert(int ** a, size_t s, size_t i, int v)
{
  int * res  = insert(*a, s, i ,v);
  delete[] *a;
  *a = res;
}

int main()
{
  const int * a = new const int[5] {0, 1, 2, 3, 4};
  int * res = nullptr;
  try {
    res = insert(a, 5, 2, 67);
  } catch (const std::exception & e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  for (size_t i = 0; i < 6; i++) {
    std::cout << res[i] << " ";
  }
  std::cout << "\n";
  delete[] a;
  delete[] res;
}
