
#include<stdio.h>
#include<conio.h>

void activities(int s[], int f[], int n)

{

	int i, j;

	printf ("\n\nSelected Activities are:\n");

	i = 1;

	printf("A%d ", i);

	for (j = 1; j < n; j++)

	{
		if (s[j] >= f[i])

		{
			printf ("A%d ", j+1);
			i = j;
		}
	}
}

int main()
{
	int s[10000];
	int f[10000];
	int n;
	int i,key,j;

	printf("Enter number of activities:\n");
	scanf("%d",&n);
	printf("Enter elements for start time:\n");
	for(i=0;i<n;i++)
    {
        scanf("%d", &s[i]);
    }
    printf("Enter elements for finish time:\n");
	for(i=0;i<n;i++)
    {
        scanf("%d", &f[i]);
    }

        for (i = 1; i < n; i++)
   {
       key = f[i];
       j = i-1;

       while (j >= 0 && f[j] > key)
       {
           f[j+1] = f[j];
           j = j-1;
       }
       f[j+1] = key;
   }
   printf("\nStart times are : ");
   for(i=0;i<n;i++)
    {
        printf("%d\t",s[i]);
    }
    printf("\nFinish times are : ");
   for(i=0;i<n;i++)
    {
        printf("%d\t",f[i]);
    }
	activities(s, f, n);
	return 0;
}
