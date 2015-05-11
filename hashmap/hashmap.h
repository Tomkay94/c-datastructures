/*
 * Hash map data type.
 */
struct HashMap {
	struct HashNode *map;
	unsigned int capacity;
	unsigned int size;
}

struct HashNode {
	char *data;
}

 /*
  * Hash map functions.
  */
struct HashMap *hash_map_create(int capacity);
struct HashMap *hash_insert(struct HashMap *hm, char *data);
