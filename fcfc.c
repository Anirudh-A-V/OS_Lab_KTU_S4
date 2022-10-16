#include<stdio.h>
#include<string.h>

struct process
{
    char id[10];
    int AT,BT,WT,TAT;
}P[10];

struct done
{
    char id[10];
    int AT,CT;
}D[10];

void fcfs(int);

int main()
{
    int n,i=0;

    printf("\nEnter the number of process : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nPROCESS %d\n",i+1);
         
        printf("Enter the Process ID : ");
        scanf("%s",P[i].id);

        printf("Enter the Arrival Time : ");
        scanf("%d",&P[i].AT);

        printf("Enter the Burst Time : ");
        scanf("%d",&P[i].BT);
    }

    fcfs(n);
}

void fcfs(int n)
{
    int TT=0,count=0,i=0,k=0;
    float TAWT=0.0,TATAT=0.0;

    while(count<n)
    {
        if(TT < P[i].AT)
        {
            strcpy(D[k].id,"IDLE");
            D[k].AT=TT;
            D[k].CT=P[i].AT;
            TT=P[i].AT;
            k++;
        }

        else
        {
            strcpy(D[k].id,P[i].id);
            D[k].AT=TT;
            D[k].CT=TT+P[i].BT;
            TT=TT+P[i].BT;

            P[i].TAT=TT-P[i].AT;
            P[i].WT=P[i].TAT-P[i].BT;

            TAWT=TAWT+P[i].WT;
            TATAT=TATAT+P[i].TAT;
            i++;
            k++;
            count++;
        }
    }

    TAWT=TAWT/n;
    TATAT=TATAT/n;

    printf("\n\nGANTT CHART ");
    printf("\n\t--------------------------------------------------------------------\n\t");
    for(i=0;i<k;i++)
    {
        printf("|");
        printf("%s\t",D[i].id);
    }
    printf(" |");
    printf("\n\t--------------------------------------------------------------------\n\t");
    
    for(i=0;i<k;i++)
    {
        printf("%d\t",D[i].AT);
    }
    printf("%d\t\n",D[k-1].CT);

    printf("\nAVERAGE WAITING TIME : %f",TAWT);
    printf("\nAVERAGE TURNAROUND TIME : %f\n",TATAT);
}
