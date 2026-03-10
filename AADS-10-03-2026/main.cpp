#include <iostream>

template< class T >
struct List {
  T val;
  List< T >* next;
  List< T >* prev;
};

template< class T >
bool has_common(const List< T >* h1, const List< T >* h2)
{
  const List<T>* h = h1;
  while (h->prev != nullptr) {
    h = h->prev;
  }
  while (h) {
    if (h == h2) {
      return true;
    }
    h = h->next;
  }
  return false;
}

template< class T >
bool no_common(const List< const List<T>* >* h)
{
  const List< const List<T>* >* head = h;
  const List< const List<T>* >* curr = nullptr;
  while (h) {
    curr = head->next;
    while (curr) {
      if (has_common(head->val, curr->val)) {
        return false;
      }
      curr = curr->next;
    }
    head = head->next;
  }
  return true;
}

int main()
{
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
