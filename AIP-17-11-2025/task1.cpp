#include <iostream>

struct Ints
{
  Ints();
  ~Ints();
  size_t size() const;
  int get(size_t i) const;
  void set(size_t id, int i) const; 
  void append(int v);
  Ints (const Ints & c);
  Ints (const Ints && c);
  Ints & operator=(const Ints & c);
};

Ints in() {
  Ints r;
  int v = 0;
  while (std::cin >> v) {
    r.append(v);
  }
  return r;
}

int main()
{
  Ints data = in();
  for (size_t i = 0; i < data.size(); ++i) {
    std::cout << data.get(i) << "\n";
  }
}