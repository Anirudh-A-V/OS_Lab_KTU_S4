
#include<stdio.h>
#include<stdlib.h>

struct frame
{
    int PN;
    int F;
    int T;
}F[25];

int f,p[25],A;

int isfound(int p,int count)
{
    int i;
    for(i=0;i<count;i++)
    {
        if(F[i].PN==p)
        {
            A=i;
            return 1;
        }
            
    }
    return 0;
}

void increment(int count)
{
    int i;
    for(i=0;i<count;i++)
    {
        F[i].T++;
    }
}

int oldest(int count)
{
    int old=0;
    for(int i=0;i<count;i++)
    {
        if(F[old].T<F[i].T)
        {
            old=i;
        }

    }
    return old;
}

int least(int count)
{
    int i,less=0,old;
    for(i=0;i<count;i++)
    {
        if(F[i].F<F[less].F)
        {
            less=i;
        }
    }
    old=less;

    for(i=0;i<count;i++)
    {
        if(F[i].F==F[less].F)
        {
            if(F[i].T>F[old].T)
            {
                old=i;
            }
        }
    }
    return old;

}

void fifo(int n)
{
    int pf=0,count=0,i,j,k=0;

    for(i=0;i<n;i++)
    {
        if(isfound(p[i],count))
        {

            F[A].F++;;
            increment(count);
            
            printf("\n%d -> ",p[i]);
            continue;
        }
        else
        {
            if(count<f)
            {
                F[k].PN=p[i];
                F[k].F++;
                k++;
                count++;
            }
            else
            {
                j=least(count);
                F[j].PN=p[i];
                F[j].T=0;
                F[j].F=1;
            }
            pf++;
            increment(count);
        }

        printf("\n%d-> ",p[i]);
        for(int x=0;x<count;x++)
        {
            printf("%d -> ",F[x].PN);
        }
    }

    printf("\npage fault : %d",pf);
}

void main()
{
    int n;
    printf("\nenter the numer of reference string :");
    scanf("%d",&n);
    printf("\nenter the number of framees :  ");
    scanf("%d",&f);

    printf("\neneter the reference string : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }

    fifo(n);
}