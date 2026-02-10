#include <iostream>
#include <limits>

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

int * remove(int * a, size_t s, size_t i)
{
  int to_rm = std::move(a[i]);
  for (size_t j = i; j < s - 1; ++j) {
    a[j] = std::move(a[j + 1]);
  }
  a[s] = std::move(to_rm);
  return a + s - 1;
}

int * unique(int * a, size_t s)
{
  size_t j = 0;
  for (size_t i = 1; i < s; ++i) {
    if (a[j] == a[i]) {
      a[j] = a[++i];
    }
    ++j;
  }
  return a + j;
}

int * merge(const int * const * a, size_t sa, const size_t * sai, int * c)
{
  size_t max_s = 0;
  size_t sum = 0;
  for (size_t i = 0; i < sa; ++i) {
    max_s = std::max(max_s, sai[i]);
    sum+=sai[i];
  }
  std::cout << sum << "\n";
  size_t * ids = new size_t[sa];
  for (size_t i = 0; i < sa; ++i) {
    ids[i] = 0;
  }

  for (size_t i = 0; i < sum; ++i) {
    size_t min_el_id = 0;
    int min_el = std::numeric_limits< int >::max();
    for(size_t j = 0; j < sa; ++j) {
      if (ids[j] < sai[j] && min_el > a[j][ids[j]]) {
        min_el = a[j][ids[j]];
        min_el_id = j;
      }
    }
    c[i] = min_el;
    ++ids[min_el_id];
  }
  return c + sum;
}

int main()
{
  size_t sa = 3;
  size_t* sai = new size_t[sa]{3, 4, 5};
  int ** a = new int * [sa];
  a[0] = new int[3]{2, 6, 56};
  a[1] = new int[4]{23, 32, 45, 100};
  a[2] = new int[5]{12, 23, 34, 45, 56};
  try {
    int * c = new int[12];
    merge(a, sa, sai, c);
    for (size_t i = 0; i < 12; ++i) {
      std::cout << c[i] << " ";
    }
    std::cout << "\n";
    delete [] c;
  } catch (const std::exception & e) {
    std::cerr << e.what() << "\n";
  }
  delete [] a;
}
