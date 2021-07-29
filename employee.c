#include"employee.h"

tree create(eletype key)
{
	tree p=(tree)malloc(sizeof(struct node));
	p->data=key;
	p->lchild=p->rchild=NULL;
	return p;
}
eletype scan()
{
	eletype t1;
	printf("\nENTER THE EMPLOYEE ID: ");
	scanf("%d",&t1.eid);
	printf("ENTER THE EMPLOYEE NAME: ");
	scanf("%s",&t1.name);
	printf("ENTER THE AGE: ");
	scanf("%d",&t1.age);
	printf("ENTER THE EMPLOYEE'S EXPERIENCE: ");
	scanf("%d",&t1.experience);
	return t1;
}
int print(eletype r)
{
	printf("\n\nEMPLOYEE ID: %d",r.eid);
	printf("\nENTER THE EMPLOYEE NAME: %s",r.name);
	printf("\nENTER THE AGE: %d",r.age);
	printf("\nENTER THE EMPLOYEE'S EXPERIENCE: %d",r.experience);
	return 1;
}
int insert(tree r, eletype key)
{
	if(r==NULL)
	{
		r=create(key);
		return;
	}
    if(key.experience<r->data.experience)
    {
        if(r->lchild==NULL)
            r->lchild=create(key);
        else 
			insert(r->lchild,key);
    }
    else if(key.experience>r->data.experience)
    {
        if(r->rchild==NULL)
            r->rchild = create(key);
        else 
			insert(r->rchild,key);
    }
    return 1;
}
int inorder(tree r)
{
	if(r)
	{
		inorder(r->lchild);
		print(r->data);
		inorder(r->rchild);
	}
	return 1;
}

int isleaf(tree r)
{
	if((r->rchild==NULL) && (r->lchild==NULL))
		return 1;
	else
		return 0;
}
tree findmin(tree r)
{
	if(r->lchild!=NULL)
		return(findmin(r->lchild));
	else
		return r;
}
tree findmax(tree r)
{
	if(r->rchild!=NULL)
		return(findmax(r->rchild));
	else
		return r;
}
tree delete_tree(tree r,eletype key)
{
	tree temp;
	if(r==NULL)
		return;
	if(key.experience>r->data.experience)
		r->rchild=delete_tree(r->rchild,key);
	else if(key.experience<r->data.experience)
		r->lchild=delete_tree(r->lchild,key);
	else if(key.eid==r->data.eid)
	{
		if(isleaf(r))
		{
			free(r);
			return NULL;
		}
		else if(r->rchild==NULL)
		{
			temp=r;
			r=r->lchild;
			free(temp);
			return r;	
		}
		else if(r->lchild==NULL)
		{
			temp=r;
			r=r->rchild;
			free(temp);
			return r;	
		}
		else
		{
			temp=findmin(r->rchild);
			r->data=temp->data;
			r->rchild=delete_tree(r->rchild,temp->data);	
		}		
	}
	return;
}
int experience_search(tree r,int exp)
{
	tree temp;
	temp=r;
	if(temp==NULL)
		return 0;
	if(temp->data.experience>exp)
	{
		print(r->data);
		experience_search(r->lchild,exp);
		experience_search(r->rchild,exp);
	}
	else if(temp->data.experience<exp)
	{
		experience_search(r->lchild,exp);
		experience_search(r->rchild,exp);
	}
	return 1;	
}


