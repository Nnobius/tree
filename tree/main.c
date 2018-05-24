#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

int main()
{
	int count = 0;
	bstree * test;
	bstree * find;
	test = bstree_create("jackodf", 43);
	FILE *file;
	char word[50];
	file = fopen ("ddd1.txt","r");
	
	char c;
	int i = 100000;

	do {
		c = fscanf(file, "%s", word);
		if (c == EOF){
			break;
		}
		count++;
		int ln = strlen(word) - 1;
		if (word[ln] == '\n') {
			word[ln] = '\0';
		}
		bstree_add(test, word, 1);
	} while(count < i);

	fclose(file);
	bstree_add(test,"getrekt", 45);
	find = bstree_lookup(test, "устоять");
	printf("%s", find -> key);
	return 0;
}