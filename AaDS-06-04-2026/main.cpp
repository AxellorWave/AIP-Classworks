#include <iostream>

template< class T >
struct BiTree {
  T val;
  BiTree< T > * lt, * rt;
};

template< class T, class Cmp >
const BiTree< T > * find(const T & d, const BiTree< T > * root, Cmp cmp)
{
  while (root) {
    if(cmp(d, root->val)) {
      root = root->lt;
    } else if (cmp(root->val, d)) {
      root = root->rt;
    } else {
      return root;
    }
  }
  return root;
}

template< class T >
struct TriTree {
  T val1, val2;
  TriTree< T > *lt, * rt, * mid;
};

template< class T, class Cmp >
std::pair<const TriTree< T > *, size_t> find(const T & d, const TriTree< T > * root, Cmp cmp)
{
  while (root) {
    if(cmp(d, root->val1)) {
      root = root -> lt;
    } else if (!cmp(root->val1, d)) {
      return {root, 0};
    } else if (cmp(b, root->val2)) {
      root = root->mid;
    } else if (!cmp(root->val2, d)) {
      return {root, 1};
    } else {
      root = root->rt;
    }
  }
  return {0, 0};
}

template< class T, class Cmp >
void clear(BiTree< T > * root)
{
  if (!root) return;
  clear(root->lt);
  clear(root->rt);
  delete root;
}



int main()
{}
