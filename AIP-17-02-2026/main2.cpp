#include <iostream>

template< class T >
struct List {
  T val;
  const T * next;
};

template< class T >
List< T > * clear(List< T > * start, List< T > * end)
{
  while (start != end) {
    List< T > * temp = start->next;
    delete start;
    start = temp;
  }
  return end;
}

template< class T >
List< T > * convert(const T * data, size_t s)
{
  List< T > * h = new List< T >{data[0], nullptr};
  List< T > * tail = h;
  try {
    for (size_t i = 1; i < s; ++i) {
      List< T > * node = new List< T >{data[i], nullptr};
      tail->next = node;
      tail = node;
    }
  } catch (...) {
    clear(h, nullptr);
    throw;
  }
  return h;
}

template< class T >
List< T > * convert(const T * data, size_t s, List< T > ** tail)
{
  List< T > * h = new List< T >{data[0], nullptr};
  List< T > * t = h;
  try {
    for (size_t i = 1; i < s; ++i) {
      List< T > * node = new List< T >{data[i], nullptr};
      t->next = node;
      t = node;
    }
  } catch (...) {
    clear(h, nullptr);
    throw;
  }
  *tail = t;
  return h;
}

// template < class T, class C >
// List< T > * remove_if(List< T > ** head, C cond)
// {
//   List< T > * r = nullptr, * t = *head;
//   if (cond(t->val)) {
//     r = t;
//     *head = r->next;
//     r->next = nullptr;
//   } else {
//     while (t->next && !cond(t->next->val)) {
//       t = t->next;
//     }
//     if (!t->next) {
//       return nullptr;
//     }
//     r = t->next;
//     t->next = r->next;
//   }
//   return res;
// }

template< class T >
List< const List< T > * > * clear(List< const List< T > * > * start, List< const List< T > * > * end)
{
  while (start != end) {
    List< const List< T > * > * temp = start->next;
    delete start;
    start = temp;
  }
  return end;
}

template< class T, class C >
size_t count(const List< T > * h, C c,
  List< const List< T > * > ** chead,
  List< const List< T > * > ** ctail)
{
  List< const List< T > * > * head = new List< const List< T > * >;
  List< const List< T > * > * tail = head;
  size_t res = 0;
  const List< T > * t = h;
  try {
    while (t != nullptr) {
      if (c(t)) {
        head->val = t;
        head->next = nullptr;
        ++res;
        break;
      }
      t = t->next;
    }

    t = t->next;
    while (t != nullptr) {
      if (c(t)) {
        List< const List< T > * > * n = new List< const List< T > * >{t, nullptr};
        tail->next = n;
        tail = n;
        ++res;
      }
      t = t->next;
    }
  } catch (...) {
    clear(head, nullptr);
    throw;
  }

  *chead = head;
  *ctail = tail;
  return res;
}

int main()
{
  List<int>* oak = new List<int>{1, nullptr};
  oak->next = new List<int>{2, nullptr};
  oak->next->next = new List<int>{3, nullptr};
  oak->next->next->next = new List<int>{4, nullptr};
  oak->next->next->next->next = new List<int>{5, nullptr};
  oak->next->next->next->next->next = new List<int>{6, nullptr};

  List< const List< int >* >* chead;
  List< const List< int >* >* ctail;

  size_t co = count(oak, [](int a) {return a%2==0;}, &chead, &ctail);

  delete oak;
}