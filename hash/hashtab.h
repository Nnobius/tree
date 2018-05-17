#ifndef HASH_C
#define HASH_C

#define SIZE 10000
#define HASH_MUL 31

struct listnode {
	char *key;
	int value;

	struct listnode *next;
};

struct listnode *hashtab[HASHTAB_SIZE];

unsigned int hashtab_hash(char *key);

void hashtab_init(struct listnode **hashtab);

void hashtab_add(struct listnode **hashtab, char *key, int value);

struct listnode *hashtab_lookup(struct listnode **hashtab, 
char *key);

void hashtab_delete(struct listnode **hashtab, char *key);

#endif
