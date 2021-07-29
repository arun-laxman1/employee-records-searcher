#include"employee.h"

int main()
{
	int i,n;
	tree t,max,min;
	eletype t1;
	printf("ENTER THE NUMBER OF EMPLOYEES YOU WISH TO INSERT: ");
	scanf("%d",&n);
	t1=scan();
	t=create(t1);
	for(i=0;i<n-1;i++)
	{
		t1=scan();
		insert(t,t1);
	}
	max=findmax(t);
	printf("\nTHE SENIOR MOST EMPLOYEE IS %s",max->data.name);
	min=findmin(t);
	printf("\nTHE JUNIOR MOST EMPLOYEE IS %s",min->data.name);
	printf("\n\nENTER THE NO. OF YEARS OF EXPERIENCE: ");
	scanf("%d",&n);
	printf("\nEMPLOYEES WITH EXPERIENCE GREATER THAN %d YRS:\n",n);
	return 1;
}
