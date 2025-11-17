#include <iostream>

struct Ints
{
  Ints();
  ~Ints();
  size_t size() const;
  int get(size_t i) const;
  void set(size_t id, int i); 
  Ints append(int i) const;
  Ints append(const Ints & w) const;
  Ints (const Ints & w);
  Ints (Ints && w);
  Ints & operator=(const Ints & w);
  Ints & operator=(Ints && w);
private:
  size_t k;
  int * d;
};

Ints::~Ints()
{
  delete[] d;
}

Ints::Ints():
  k(0), d(nullptr)
{}

Ints::Ints(const Ints & w):
  k(w.k), d(k ? new int[k] : nullptr)
{
  for (size_t i = 0; i < k; ++i) {
    d[i] = w.d[i];
  }
}

Ints & Ints::operator=(const Ints & w)
{
  if (w.k) {
    delete[] d;
    d = nullptr;
    k = 0;
  } else {
    int * t = new int[w.k];
    for (size_t i = 0; i < w.size(); ++i) {
      t[i] = w.d[i];
    }
    delete[] d;
    d = t;
    k = w.k;
  }
  return * this;
}

Ints::Ints(Ints && w):
  k(w.k), d(w.d)
{
  w.d = nullptr;
}

Ints & Ints::operator=(Ints && w)
{
  delete[] d;
  d = w.d;
  k = w.k;
  w.d = nullptr;
  return * this; 
}

size_t Ints::size() const
{
  return k;
}

int Ints::get(size_t id) const
{
  return d[id];
}

void Ints::set(size_t id, int i)
{
  d[id] = i;
}

Ints Ints::append(int i) const
{
  Ints r;
  r.d = new int[k + 1];
  for (size_t j = 0; j < k; ++j) {
    r.d[j] = d[j];
  }
  r.d[k] = i;
  r.k = k + 1;
  return r;
}

Ints Ints::append(const Ints & w) const
{
  Ints r;
  r.d = new int[k + w.k];
  for (size_t i =0; i < k; ++i) {
    r.d[i] = d[i];
  }
  for (size_t j = 0; j < w.k; ++j) {
    r.d[k+j] = w.d[j];
  }
  return r;
}

Ints in() 
{
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
