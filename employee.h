#ifndef employee_h
#define employee_h
#include<stdio.h>
#include<stdlib.h>

struct employee{
	int eid;
	char name[200];
	int age;
	int experience;
};
typedef struct employee eletype;

struct node{
	eletype data;
	struct node *rchild;
	struct node *lchild;	
};
typedef struct node* tree;

tree create(eletype key);
int insert(tree r, eletype key);
tree delete_tree(tree r,eletype key);
int isleaf(tree r);
tree findmin(tree r);
tree findmax(tree r);
int experinece_search(tree r,int exp);
eletype scan();
int print(eletype r);

#endif
