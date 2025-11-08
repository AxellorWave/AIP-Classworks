#include <iostream>

int det(const int * a, size_t n)
{
  if (!n) {
    return 0;
  }
  if (n == 1) {
    return a[0];
  }
  if (n == 2) {
    return a[0] * a[3] - a[1] * a[2];
  }
  return 1; 
}

int main()
{}