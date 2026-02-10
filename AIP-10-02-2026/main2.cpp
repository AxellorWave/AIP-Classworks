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

int * partition(int * a, size_t s, bool(*cond)(int))
{
  size_t ind = 0;
  for (size_t i = 0; i < s; ++i) {
    if (cond(a[i])) {
      int e = a[i];
      for (size_t j = i; j > ind; --j) {
        a[j] = a[j - 1];
      }
      a[ind] = e;
      ++ind;
    }
  }
  return a + ind;
}

void quad_partition(int * a, size_t s, bool(*c1)(int), bool(*c2)(int), int ** pts)
{
  int * res1 = partition(a, s, c1);
  int * res2 = partition(a, res1 - a, c2);
  int * res3 = partition(res1, s - (res1 - a), c2);
  pts[0] = res1;
  pts[1] = res2;
  pts[2] = res3;

}

int main()
{
  const int arr[7] = {1, 2, 3, 4, 5, 6, 7};
  int * res = reverse(arr, 7);
  for (size_t i = 0; i < 7; ++i) {
    std::cout << res[i] << "\n";
  }
}