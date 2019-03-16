#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h>
#define SIZE 100000
#define SIZE1 5

void quicksort(int a[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,first,j-1);
      quicksort(a,j+1,last);

   }
}


int main()
{
    struct timeval tv,tv1;
    struct timezone tz,tz1;
    struct tm *tm;
    clock_t start,end;
    int i,n,a1[SIZE1],total,count;
    long int a[SIZE];
    FILE *fptr;

    printf("Enter 5 numbers:\n");
    for (i=0;i<SIZE1;i++)
    {
        scanf("%d",&a1[i]);
    }
    gettimeofday(&tv, &tz);
    quicksort(a1,0,SIZE1);
    printf("The sorted numbers are :\n");
    for (i=0;i<SIZE1;i++)
    {
        printf("%d\n",a1[i]);
    }
    tm=localtime(&tv.tv_sec);
    printf("The time taken to sort 5 numbers by quick sort is %d milliseconds\n",tm->tm_sec);

    fptr = fopen("input.txt","w");
    for (i=0;i<n;i++)
    {
      fprintf(fptr,"%d\n",rand()%1000+1);
    }
    fflush(fptr);
    fclose(fptr);
    fptr = fopen("input.txt","r");
    start = clock();
    for(i=0;i<SIZE;i++)
    {
       fscanf(fptr,"%d",&a[i]);
    }
    fclose(fptr);
    quicksort(a,0,SIZE);
    end = clock();
    fptr=fopen("output.txt","w");
    for (i=0;i<SIZE;i++)
    {
        fprintf(fptr,"%d\n",a[i]);
    }

    fclose(fptr);
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("The time taken to sort a million randomized numbers using quick sort is %d milliseconds\n",total);
    printf("Time difference: %d milliseconds\n",total-tm->tm_sec);
    getch();
    return 0;
}
