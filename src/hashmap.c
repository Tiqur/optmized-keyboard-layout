#include "./hashmap.h"
#include <stdlib.h>
#include <stdio.h>

HashMap CreateNewHashMap(int size)
{
  HashMap hm;
  hm.size = size;
  hm.data = malloc(sizeof(KeyValue) * size);

  if (hm.data == NULL)
  {
    printf("Memory allocation failed.\n");
    exit(-1);
  }

  // Explicitly set values
  for (int i = 0; i < size; i++)
    hm.data[i] = (struct KeyValue){0, 0};

  return hm;
}

int HashMapHashChar(char key, int size)
{
  return key % size;
}

KeyValue HashMapGet(HashMap* hm, char key)
{
  int hash_index = HashMapHashChar(key, hm->size);
  int counter = 0;
  while (hm->data[hash_index].key != 0)
  {
    if (counter > hm->size)
    {
      printf("Counter exceeded maximum capacity, exiting to avoid infinite loop.");
      exit(-1);
    }

    if (hm->data[hash_index].key == key)
      return hm->data[hash_index];

    hash_index++;
    hash_index %= hm->size;
    counter++;
  }

  return hm->data[hash_index];
}

void HashMapSet(HashMap* hm, char key, int value)
{
  int hash_index = HashMapHashChar(key, hm->size);
  int counter = 0;
  while (hm->data[hash_index].key != 0)
  {
    if (counter > hm->size)
    {
      printf("Counter exceeded maximum capacity, exiting to avoid infinite loop.");
      exit(-1);
    }

    if (hm->data[hash_index].key == key)
      break;

    hash_index++;
    hash_index %= hm->size;
    counter++;
  }
  hm->data[hash_index] = (struct KeyValue){key, value};
}

void HashMapFree(HashMap* hm)
{
  free(hm->data);
  hm->size = -1;
}
