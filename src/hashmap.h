typedef struct KeyValue {
  char key;
  int value;
} KeyValue;

typedef struct HashMap {
  KeyValue* data;
  int size;
} HashMap;

HashMap CreateNewHashMap(int size);
void HashMapSet(HashMap* hm, char key, int value);
KeyValue HashMapGet(HashMap* hm, char key);
int HashMapHashChar(char key, int size);
void HashMapFree(HashMap* hm);

