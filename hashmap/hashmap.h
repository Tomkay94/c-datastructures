/*
 * Hash map data type.
 */
struct HashMap {
	struct HashNode *map;
	unsigned int capacity;
	unsigned int size;
};

struct HashNode {
	void *data;
	long key;
	int flags;
};

 /*
  * Hash map functions.
  */
struct HashMap *
hash_map_create(int capacity);

struct HashMap *
hash_insert(struct HashMap *hm, void *data);
