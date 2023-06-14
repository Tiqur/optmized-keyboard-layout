#include <stdio.h>
#include "./hashmap.h"

int main(void)
{
  HashMap hm = CreateNewHashMap(97);
  for (int i = 97; i < 123; i++)
    HashMapSet(&hm, i, i);

  for (int i = 97; i < 123; i++) {
    KeyValue pair = HashMapGet(&hm, i);
    printf("%c %d\n", pair.key, pair.value);
  }

  //HashMapSet(&hm, 126, 99);
  //printf("%d %d\n", HashMapGet(&hm, 'a').key, HashMapGet(&hm, 'a').value);
  //printf("%d %d\n", HashMapGet(&hm, 126).key, HashMapGet(&hm, 126).value);

  HashMapFree(&hm);
  return 0;
}
