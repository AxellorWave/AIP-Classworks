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

int * erase(const int * a, size_t s, size_t i)
{
  int * res = new int[s - 1];
  for (size_t j = 0; j < i; ++j) {
    res[j] = a[j];
  }
  for (size_t j = i + 1; j < s + 1; ++j) {
    res[j - 1] = a[j];
  }
  return res;
}

void erase(int ** a, size_t s, size_t i)
{
  int * res  = erase(*a, s, i);
  delete[] *a;
  *a = res;
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

int * remove(int * a, size_t s, int v)
{
  for (size_t i = 0; i < s; ++i) {
    if (a[i] == v) {
      remove(a, s--, i--);
    }
  }
  return a + s;
}

int * cut(const int * a, size_t s)
{
  int * t = new int[s];
  for (size_t i = 0; i < s; ++i) {
    t[i] = a[i];
  }
  return t;
}

size_t erase(int ** a, size_t s, int v)
{
  size_t upd = remove(*a, s, v) - *a;
  int * t = cut(*a, upd);
  delete[] (*a);
  (*a) = t;
  return upd;

}

int * stable_partition(int * a, size_t s, bool(*cond)(int))
{
  int * res = nullptr;
  for (size_t i = s; i != 0; --i) {
    if (!cond(a[i])) {
      res = remove(a, s, i);
      --s;
    }
  }
  return res;
}

bool mod2(int n) {
  return n % 2;
}

int main()
{
  size_t n = 9;
  int * a = new int[n] {1, 2, 3, 4, 5 , 6, 7, 8, 9};
  for (size_t i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << "\n";
  int * res2 = stable_partition(a, n, mod2);
  for (size_t i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << "\n";
  delete[] a;
}
