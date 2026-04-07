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

template< class T >
struct MList {
  T val;
  MList<T> *next, *prev, *ref;
};

template< class T >
bool has_common(MList<T>* a,MList<T>* b )
{
  auto head = a;
  while (head->prev) {
    head = head.prev;
  }
  while (head) {
    if (head == b) {
      return true;
    }
  }
  return false;
}

template< class T >
bool self_refed(MList< T >* h)
{
  auto head = h;
  while (head) {
    if (!head->ref || !has_common(head, head->prev)) {
      return true;
    }
    head = head->next;
  }
  return false;
}

template< class T >
bool has_ref(MList< T > * list, MList< T > * node)
{
  while (list)
  {
    if (list->prev == node) {
      return true;
    }
    list = list->next;
  }
  return false;
}

template< class T >
List< const MList< T > * > * no_refs(const MList< T > * h)
{
  List< const MList< T > * > dummy_head {nullptr, nullptr, nullptr};
  List< const MList< T > * > * tail = & dummy_head;
  List< const MList< T > * >  * prev = nullptr;
  MList< T > * inner = h;
  while (inner)
  {
    if (!has_ref(h, inner)) {
      try {
        tail->next = new List< const MList< T > * > {inner, nullptr, prev};
        tail = tail->next;
        prev = tail;
      } catch (...) {
        while (tail)
        {
          auto temp = tail->prev;
          delete tail;
          tail = temp;
        }
        throw;
      }
    }
    inner = inner->next;
  }
  return dummy_head->next;
}

int main()
{
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
