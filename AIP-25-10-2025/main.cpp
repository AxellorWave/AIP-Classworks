#include <iostream>
#include <limits>

bool isPyth(unsigned a, unsigned b, unsigned c);
bool isOverSum(unsigned a, unsigned b);
bool isOverMultiply(unsigned a, unsigned b);
unsigned max(unsigned a, unsigned b);
unsigned min(unsigned a, unsigned b);

int main()
{
  using u_t = unsigned;
  u_t a = 0, b, c;
  size_t count = 0;
  std::cin >> b >> c;
  while (std::cin >> a) {
    try {
      count+=isPyth(a,b,c);
    } catch (const std::overflow_error& e) {
        std::cerr <<  e.what() << "\n";
        return 2;
    }
    c = b;
    b = a;
  }

  if (std::cin.eof()) {
    std::cout << count << "\n";
  } else if (std::cin.fail()) {
    std::cerr << "Brooo, it is FAIL!!!\n";
    return 1;
  }
}

bool isPyth(unsigned a, unsigned b, unsigned c)
{
  unsigned biggest = max(a, max(b, c));
  unsigned smallest = min(a, min(b, c));
  unsigned medium = a + b + c - biggest - smallest;
  if (isOverMultiply(biggest,biggest) || isOverSum(smallest*smallest, medium*medium)) {
    throw std::overflow_error("Can't mulply or sum");
  }
  return biggest*biggest == (medium*medium + smallest*smallest);
}

bool isOverSum(unsigned a, unsigned b)
{
  unsigned max = std::numeric_limits<unsigned>::max();
  return (max - a < b);
}


bool isOverMultiply(unsigned a, unsigned b)
{
  unsigned max = std::numeric_limits<unsigned>::max();
  return (max / a < b);
}

unsigned max(unsigned a, unsigned b)
{
  return (a > b) ? a : b;
}

unsigned min(unsigned a, unsigned b)
{
  return (a < b) ? a : b;
}

