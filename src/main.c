#include <stdio.h>
#include <stdlib.h>
#include "./hashmap.h"

typedef struct CC {
  char c;
  unsigned int count;
} CC;

int compare_by_cc(const void *a, const void *b)
{
  const CC *x = (const CC*)a;
  const CC *y = (const CC*)b;

  return (y->count - x->count);
}

int main(void)
{
  // Can potentially use 2d array instead of hash map
  HashMap bigram_hash_table = CreateNewHashMap(0);
  unsigned int bigram_count[128][128] = {0};

  // Since ASCII is already indexed for us, we don't need a hashmap, just a normal array
  CC char_count[128];

  // Init chars
  for (int i = 0; i < 128; i++)
    char_count[i] = (struct CC){i, 0};


  unsigned long total_char_count = 0;

  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("test_data/1M_wikipedia_sentences.txt", "r");
  if (fp == NULL)
      exit(EXIT_FAILURE);

  // For each line
  while ((read = getline(&line, &len, fp)) != -1) {
    // For each char in line
    for (int i = 0; i < read; i++)
    {
      char c = line[i];
      if (0 <= c <= 128)
        char_count[c].count++;
    }
  }

  fclose(fp);
  if (line)
      free(line);



  qsort(char_count, 128, sizeof(CC), compare_by_cc);





  for (int i = 0; i < 128; i++) {
    printf("%d: %d\n", char_count[i].c, char_count[i].count);
  }

  HashMapFree(&bigram_hash_table);
  return 0;
}
