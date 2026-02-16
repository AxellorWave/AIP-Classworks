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