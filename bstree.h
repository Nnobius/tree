#ifndef BSTREE_C
#define BSTREE_C

typedef struct
{
    char *value;
    int key;
    struct bstree *left;
    struct bstree *right;

} bstree;

typedef struct
{
  char *field; 
  struct list *ptr; 

} list;

void treeprint(bstree *tree);
bstree *bstree_create(char *value,int key);
void bstree_add(bstree *map, char *value, int key);
bstree *bstree_lookup(bstree *map, char key);
bstree *bstree_min (bstree *map);
bstree *bstree_max(bstree *map);

#endif