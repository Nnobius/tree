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
	} else {
		printf("Error bstree_create");
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
		if (strcmp(key,tree-> key) < 0) {
			tree = tree -> left;
		} else if(strcmp(key, tree -> key) > 0) {
			tree = tree -> right;
		} else {
			return;
		}
	}

	node = bstree_create(key, value);
	
	if (strcmp(key, parent-> key) < 0) {
		parent -> left = node;
	} else {
		parent -> right = node;
	}	
	
}

bstree *bstree_lookup(bstree *tree, char *key) {

	bstree *detector;
	detector = tree;

	while (detector != NULL) {
		if (strcmp(key, detector-> key) == 0 ) {
			return detector;
		} else if (strcmp(key, detector-> key) < 0) {
			detector = detector -> left;
		} else {
			detector = detector -> right;
		}
	}
	return detector;
}

bstree *bstree_min (bstree *tree) {
	
	if(tree== NULL) {
		return NULL;
	}
	
	while (tree -> left != NULL) {
		tree = tree -> left;
	}
	return tree;
}

bstree *bstree_max (bstree *tree) {
	
	if(tree == NULL) {
		return NULL;
	}
	
	while (tree -> right != NULL) {
		tree = tree -> right;
	}
	return tree;
}
		
void treeprint(bstree *tree) {
	

	if (tree!=NULL) {
		treeprint(tree->left);
		treeprint(tree->right); 
		printf("%s\n", tree -> key); 
	}
}
