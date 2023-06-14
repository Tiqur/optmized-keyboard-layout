typedef struct KeyValue {
  char key;
  int value;
} KeyValue;

typedef struct HashMap {
  KeyValue* data;
  int size;
} HashMap;

// Doesn't need to be resizable in this case, so just make it static
// We also don't need deletes, so delete flags are unnecessary which makes this very simple 
HashMap CreateNewHashMap(int size);
void HashMapSet(HashMap* hm, char key, int value);
KeyValue HashMapGet(HashMap* hm, char key);
int HashMapHashChar(char key, int size);
void HashMapFree(HashMap* hm);

