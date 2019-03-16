#include <stdio.h>

int i[11], j[10];
void merge(int low, int mid, int high)
    {
        int a, b, p;

        for(a=low,b=mid+1,p=low; a<=mid && b<= high; p++)
        {
            if(i[a]<=i[b])
                j[p] = i[a++];
            else
                j[p] = i[b++];
        }

        while(a<=mid)
            j[p++] = i[a++];
        while (b<= high)
            j[p++] = i[b++];
        for (p=low; p<=high;p++){
            i[p]=j[p];}
    }

void sort (int low, int high){

    int mid;

    if(low<high){
        mid = (low+high)/2;
        sort(low,mid);
        sort(mid+1,high);
        merge(low,mid,high);}
    else
        return;
}



int main()
{
    int k;

    printf("Enter 10 elements: \n");
    for (k=0;k<11;k++)
    {
        scanf("%d", &i[k]);
    }
    printf("The entered numbers are : \n");
     for (k=0;k<11;k++)
    {
        printf("%d\n", i[k]);
    }
    sort(0,10);
    printf("The sorted numbers are : \n");
    for (k=0;k<11;k++)
    {
        printf("%d\n", i[k]);
    }
}
