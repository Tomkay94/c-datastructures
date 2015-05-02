/*
 * Hash map data type.
 */
struct HashMap {
	int *map_array;
	int capacity;
	int size;
}

/*
 * Hash map functions.
 */
struct HashMap *hash_map_create(int capacity);
