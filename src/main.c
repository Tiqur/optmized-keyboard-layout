#include <stdio.h>
#include "./hashmap.h"

int main(void)
{
  HashMap bigram_hash_table = CreateNewHashMap(0);

  // Since ASCII is already indexed for us, we don't need a hashmap, just a normal array
  unsigned int char_count[128] = {0};

  for (int i = 0; i < 128; i++) {
    printf("%d: %d\n", i, char_count[i]);
  }

  HashMapFree(&bigram_hash_table);
  return 0;
}
