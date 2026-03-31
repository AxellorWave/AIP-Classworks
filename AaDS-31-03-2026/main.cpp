#include <iostream>

template< class Key, class T, class Hash, class Equal >
struct HashTable {
  using Value = std::pair< Key, T >;

  size_t size;
  size_t capacity;
  Value ** slots;
};

template< class Key, class T, class Hash, class Equal >
size_t psl(const HashTable< Key, T, Hash, Equal > & table, typename HashTable< Key, T, Hash, Equal >::Value** value)
{
  Hash hasher;
  size_t home = hasher(*value->first) % table.capacity;
  size_t ind = value - table.slots;
  if (ind > home) {
    return ind - home;
  }
  return table.capacity-(home-ind);
}

template< class Key, class T, class Hash, class Equal >
typename HashTable< Key, T, Hash, Equal >::Value** find(
  const HashTable< Key, T, Hash, Equal > & table, const Key & key)
{

}

int main()
{}