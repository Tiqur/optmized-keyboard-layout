#include <stdio.h>
#include "./hashmap.h"

int main(void)
{
  // Since ASCII is 8 bit, initialize hashmap size to 257
  // Optimal size that eliminates the need for implenting resizing
  HashMap hm = CreateNewHashMap(257);

  for (int i = 0; i < 128; i++)
    HashMapSet(&hm, i, i);

  for (int i = 0; i < 128; i++) {
    KeyValue pair = HashMapGet(&hm, i);
    printf("%c %d\n", pair.key, pair.value);
  }

  //HashMapSet(&hm, 126, 99);
  //printf("%d %d\n", HashMapGet(&hm, 'a').key, HashMapGet(&hm, 'a').value);
  //printf("%d %d\n", HashMapGet(&hm, 126).key, HashMapGet(&hm, 126).value);

  HashMapFree(&hm);
  return 0;
}
