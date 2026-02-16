#include <iostream>

template< class T >
T* insert(const T* a, size_t s, size_t o, T v) // конструктор копирования
{
  T* z = new T[s + 1]; // T собирается по умолчанию
  try {
    for (size_t k = 0; k < o; ++k ) {
      z[k] = a[k];
    }
    z[o] = v;
    for (size_t k = o + 1; k < s + 1; ++k ) {
      z[k] = a[k - 1]; // оператор присваивания
    }
  } catch(...) {
    delete[] z;
    throw;
  }
  return z;
}

template< class T >
T * reverse(const T * a, size_t s)
{
  T * r = new T[s]; //конструктор по умолчанию
  try {
    for (size_t i = 0; i < s; ++i) {
      r[i] = a[s - (i + 1)]; //копирующее присваивание
    }
  } catch (...) {
    delete[] r;
    throw;
  }
  return r;
}

template< class T >
void reverse(T * a, size_t s, size_t & z)
{
  z = 0;
  for (size_t i = 0; i < s / 2; ++i) {
    std::swap(a[i], a[s - (i+1)]);// huinia, tak ne delaem
    ++z;
  }
}

bool istoerase(size_t toerase, const size_t * eids, size_t id)
{
  for (size_t i = 0; i < toerase; ++i) {
    if (id == eids[i]) {
      return true;
    }
  }
  return false;
}

template< class T >
T * erase(size_t & valid, const T * a, size_t s, const size_t * eids, size_t toerase)
{
  valid = 0;
  T * res = nullptr;
  try {
    res = new T[s - toerase];
    size_t j = 0;
    for (size_t i = 0; i < s; ++i) {
      if (!istoerase(toerase, eids, i)) {
        res[j++] = a[i];
        ++valid;
      }
    }
  } catch (...) {}
  return res;
}