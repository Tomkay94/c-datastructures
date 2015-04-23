struct Dynamic_Array {
	int resize_factor;
	int capacity;
	int size;
	int *dynamic_array;
};

struct Dynamic_Array *
dynamic_array_create(int capacity, int resize_factor);

void
append_item(struct Dynamic_Array *da, int item);

void
show(struct Dynamic_Array *da);

void
remove_item(struct Dynamic_Array *da, int index);
