#include <iostream>

struct Ints {
  Ints(); // Конструктор по умолчанию
  Ints(size_t k, int i);
  ~Ints(); // Деструктор
  Ints(const Ints & w); // Конструктор копирования
  Ints & operator=(const Ints & w); // Оператор присваивания
  Ints (Ints && w); // Конструктор перемещения
  Ints & operator=(Ints && w); // Оператор перемещения
  Ints append(int i) const;
  Ints append(const Ints & w) const;
  size_t size() const;
  int get(size_t id) const;
  void set(size_t id, int i);
private:
  size_t k;
  int * d;
};

struct p_t {
  int x, y;
};

struct Points {
  Points() = default;
  Points(size_t k, p_t a);
  void set(size_t id, p_t a);
  p_t get(size_t id) const;
  size_t size() const;
  Points append(p_t s) const;
  Points append(const Points & w) const;
private:
  Points(Ints && d);
  Ints data;
};

Ints in() {
  Ints r;
  int v = 0;
  while (std::cin >> v) {
    r.append(v);
  }
  return r;
}

Ints::~Ints()
{
  delete [] d;
}

Ints::Ints():
  k(0), d(nullptr)
{}

Ints::Ints(size_t k, int i):
  k(k), d(k ? new int[k] : nullptr)
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
  int * r = nullptr;
  if (w.k) {
    r = new int[w.k];
    for (size_t i = 0; i < w.k; ++i) {
      r[i] = w.d[i];
    }
  }
  delete [] d;
  d = r;
  k = w.k;
  return *this;
}

Ints::Ints(Ints && w):
  k(w.k),
  d(w.d)
{
  w.d = nullptr;
}

Ints & Ints::operator=(Ints && w)
{
  if (this == &w) {
    return *this;
  }
  delete [] d;
  d = w.d;
  k = w.k;
  w.d = nullptr;
  return *this;
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
  for (size_t i = 0; i < k; ++i) {
    r.d[i] = d[i];
  }
  for (size_t i = 0; i < w.k; ++i) {
    r.d[k + i] = w.d[i];
  }
  return r;
}

Points::Points(size_t k, p_t a):
  data(k * 2, a.x)
{
  for (size_t i = 0; i < k; ++i) {
    data.set(i * 2 + 1, a.y);
  }
}

size_t Points::size() const
{
  return data.size() / 2;
}

void Points::set(size_t id, p_t a) 
{
  data.set(id * 2, a.x);
  data.set(id * 2 + 1, a.y);
} 

p_t Points::get(size_t id) const
{
  p_t r{data.get(id * 2), data.get(id * 2 + 1)};
  return r;
}

Points::Points(Ints && d) : data(std::move(d))
{}

Points Points::append(p_t a) const
{
  Ints delta(2, a.x);
  delta.set(1, a.y);
  delta=data.append(delta);
  return Points(std::move(delta));
}

int main()
{
  Ints data = in();
  for (size_t i = 0; i < data.size(); ++i) {
    std::cout << data.get(i) << "\n";
  }
}