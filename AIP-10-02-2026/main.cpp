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

int main()
{
  const int * a = new const int[5] {0, 1, 2, 3, 4};
  int * res = nullptr;
  try {
    res = erase(a, 5, 2);
  } catch (const std::exception & e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  for (size_t i = 0; i < 4; i++) {
    std::cout << res[i] << " ";
  }
  std::cout << "\n";
  delete[] a;
  delete[] res;
}
