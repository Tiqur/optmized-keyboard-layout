#include <stdio.h>
#include <stdlib.h>
#include "./hashmap.h"

int main(void)
{
  // Can potentially use 2d array instead of hash map
  HashMap bigram_hash_table = CreateNewHashMap(0);
  unsigned int bigram_count[128][128] = {0};

  // Since ASCII is already indexed for us, we don't need a hashmap, just a normal array
  unsigned int char_count[128] = {0};

  unsigned long total_char_count = 0;

  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("test_data/1M_wikipedia_sentences.txt", "r");
  if (fp == NULL)
      exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, fp)) != -1) {
    for (int i = 0; i < read; i++)
    {
      char c = line[i];
      if (0 <= c <= 128)
        char_count[c]++;
    }
  }

  fclose(fp);
  if (line)
      free(line);

  for (int i = 0; i < 128; i++) {
    printf("%d: %d\n", i, char_count[i]);
  }

  HashMapFree(&bigram_hash_table);
  return 0;
}
