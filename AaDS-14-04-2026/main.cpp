#include <iostream>

template< class T >
struct BiTree {
  T val;
  BiTree< T > *lt, *rt, *parent;
};

template< class T >
struct BiTreeIt {
  BiTree< T > * curr;
};

template< class T >
T & value(BiTreeIt< T > it)
{
  return it.curr->val;
}

template< class T >
BiTreeIt< T > next(BiTreeIt< T > it)
{
  if (!it.curr) {
    return;
  }
  BiTree< T > * next = it.curr;
  if (next->rt) {
    next = next->rt;
    next = minimum(next);
  } else {
    BiTree< T > * parent = next->parent;
    while (parent && parent->lt != next) {
      next = parent;
      parent = next->parent;
    }
    next = parent;
  }
  return {next};
}

template< class T >
BiTreeIt< T > prev(BiTreeIt< T > it)
{
  if (!it.curr) {
    return;
  }
  BiTree< T > * next = it.curr;
  if (next->lt) {
    next = next->lt;
    next = maximum(next);
  } else {
    BiTree< T > * parent = next->parent;
    while (parent && parent->rt != next) {
      next = parent;
      parent = next->parent;
    }
    next = parent;
  }
  return {next};
}

template< class T >
BiTree< T > * minimum(BiTree< T > * root)
{
  if (!root) {
    return root;
  }
  while (root->lt) {
    root->lt;
  }
  return root;
}

template< class T >
BiTree< T > * maximum(BiTree< T > * root)
{
  if (!root) {
    return root;
  }
  while (root->rt) {
    root->rt;
  }
  return root;
}

template< class T, class F >
F traverse(BiTree< T > * root, F f)
{
  if (!root) {
    return f;
  }
  BiTree< T > * next = minimum(root);
  while (next) {
    f(next->val);
    if (next->rt) {
      next = next->rt;
      next = minimum(next);
    } else {
      BiTree< T > * parent = next->parent;
      while (parent && parent->lt != next) {
        next = parent;
        parent = next->parent;
      }
      next = parent;
    }
  }
  return f;
}

template< class T >
bool hasNext(BiTreeIt< T > it)
{
  return next(it).curr;
}

template< class T >
bool hasPrev(BiTreeIt< T > it)
{
  return prev(it).curr;
}

template< class T, class Cmp >
bool isEqual(BiTree< T > * lhs, BiTree< T > * rhs, Cmp cmp)
{
  if (!rhs && !lhs) return true;
  if (!rhs || !lhs) return false;
  assert(rhs && lhs);
  BiTree< T > * blhs = fallLeft(lhs);
  BiTree< T > * brhs = fallLeft(rhs);
  // while (hasNext(blhs) && hasNext(brhs)) {
  //   if (notEqual(cmp))
  // }
}

template< class T >
BiTree< T > * fallLeft(BiTree< T > * root)
{
  assert(root);
  while (roor->lt) {
    root = root->lt;
  }
  return root;
}

template< class T, class Cmp >
BiTree< T > * less(Cmp cmp, T lhs, T rhs)
{
  return cmp(lhs, rhs);
}

template< class T, class Cmp >
BiTree< T > * greater(Cmp cmp, T lhs, T rhs)
{
  return cmp(rhs, lhs);
}

template< class T, class Cmp >
BiTree< T > * notEqual(Cmp cmp, T lhs, T rhs)
{
  return less(cmp, lhs, rhs) || greater(cmp, lhs, rhs);
}

int main()
{}
