#include<stdio.h>
#include<stdlib.h>

int D[20], l, u, n;

void cscan();
void sort();
int indexof(int);
int main()
{
    int i,j,k;
    printf("\nEnter the lower and upper limit of disk : ");
    scanf("%d%d",&l,&u);
    printf("\nEnter the size of disk queue : ");
    scanf("%d",&n);
    printf("\nEnter the disk queue : ");
    for(i=1;i<=n;i++) {
        scanf("%d",&D[i]);
    }
    cscan();
}
void cscan()
{
    int i,j,k=0,head,h,hm=0,temp[20];

    printf("\nEnter the head pointer : ");
    scanf("%d",&head);
    D[0]=head;
    n=n+1;

    sort();

    h=indexof(head);

    for(i=h;i<n;i++,k++) {
        temp[k]=D[i];
    }
    temp[k]=u;
    k++;
    temp[k]=l;
    k++;

    for(i=0;i<h;i++,k++){
        temp[k]=D[i];
    }
    printf("\nSeek sequence in C-SCAN : ");
    for(i=0;i<k;i++)
    {
        printf("%d  ",temp[i]);
        if(i<k-1){
            hm=hm+abs(temp[i]-temp[i+1]);
        }
    }

    printf("\n\nTotal head movements : %d\n",hm);
}

void sort()
{
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(D[j+1]<D[j])
            {
                int temp=D[j];
                D[j]=D[j+1];
                D[j+1]=temp;
            }
        }
    }
}

int indexof(int head)
{
    for(int i=0;i<n;i++)
    {
        if(D[i]==head){
            return i;
        }
    }
}