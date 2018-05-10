#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"


bstree *bstree_create(char *key,int value)
{
    bstree *node;

    node = malloc( sizeof (*node) );
    if (node != NULL) {
	node -> key = strdup(key);
	node -> value = value;
	node -> left = NULL;
	node -> right = NULL;
    }
    return node;
}

bstree_add(bstree *tree, char *key, int value)
{
    bstree *parent;
    bstree *node;

    if(tree == NULL) {
	return;
    }

    while (tree != NULL) {
	parent = tree;
	if (key < tree -> key) {
	    tree = tree -> left;
	} else if (key > tree -> key) {
	    tree = tree -> right;
	} else {
	    return;
	}
    }

    node = bstree_create(key, value);

    if (key < parent -> key) {
	parent -> left = node;
    } else {
	parent -> right = node;
    }
}

bstree *bstree_lookup(bstree *tree, char *key)
{
    while (tree != NULL) {
	if (key == tree -> key) {
	    return tree;
	} else if (key < tree -> key) {
	    tree = tree -> left;
	} else {
	    tree = tree -> right;
	}
    }
    return tree;
}

bstree *bstree_min (bstree *tree) 
{
    if (tree == NULL) {
	return NULL;
    }

    while (tree -> left != NULL) {
	tree = tree -> left;
    }
    return tree;
}

bstree *bstree_max (bstree *tree) 
{
    if(tree == NULL) {
	return NULL;
    }

    while (tree -> right != NULL) {
	tree = tree -> right;
    }
    return tree;
}

void treeprint(bstree *tree)
{
    if (tree!=NULL) {

        treeprint (tree->left);
        treeprint (tree->right);
        printf("%s\n", tree -> key);

  }
}