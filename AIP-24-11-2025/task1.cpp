#include <iostream>

struct Stud {
  const char * fst;
  const char * snd;
  int year;
  int dep;
};

struct Subj {
  const char * name;
  size_t people, classes;
  const Stud * const * studs;
  const size_t * visited;
};

size_t countYear(const Stud * const * studs, size_t k, int y)
{
  size_t r = 0;
  for (size_t i = 0; i < k; ++i) {
    const Stud * stud_i = studs[i];
    int stud_y = stud_i->year;
    r += (stud_y == y);
  }
  return r;
}

const Stud ** studDep(const Stud * const * studs, size_t k, int dep, size_t & found)
{
  size_t dep_count = 0;
  for (size_t i = 0; i < k; ++i) {
    const Stud * stud_i = studs[i];
    dep_count += (stud_i->dep == dep);
  }
  const Stud ** r = new const Stud * [dep_count];
  found = dep_count;
  size_t j = 0;
  for (size_t i = 0; i < k; ++i) {
    const Stud * stud_i = studs[i];
    if (stud_i->dep == dep) {
      r[j++] = stud_i;
    }
  }
  return r;
}

const Stud *** studDeps(const Stud * const * studs, size_t k, int max_dep, size_t ** found) 
{}

size_t maxVisits(const Subj & sub, int y)
{
  size_t cy = countYear(sub.studs, sub.people, y);
  return cy * sub.classes;
}

size_t visits(const Subj & sub, int y)
{
  size_t r = 0;
  for (size_t i = 0; i < sub.people; ++i) {
    const Stud * stud_i = sub.studs[i];
    if (stud_i->year == y) {
      r += sub.visited[i];
    }
  }
  return r;
}

bool isBetter(const Subj & sub, int y1, int y2)
{
  size_t n_y1 = visits(sub, y1);
  size_t m_y1 = maxVisits(sub, y1);
  size_t n_y2 = visits(sub, y2);
  size_t m_y2 = maxVisits(sub, y2);
  return n_y1 * m_y2 > n_y2 * m_y1; 
}

int main()
{}