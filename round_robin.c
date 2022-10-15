#include<stdio.h>

typedef struct{
    int pid;
    int btime;
    int atime;
} process;

process p[100];

void defineProcess(int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\nPlease enter the process P%d arrival time here - ", i+1);
        scanf("%d", &p[i].atime);

        printf("\nPlease enter the process P%d burst time here - ", i+1);
        scanf("%d", &p[i].btime);

        p[i].pid = i;

    }

    return;
}

int makeRQ(int n, int clk, int q[], int pclk)
{
    int move = q[0], i=0;

    while(q[i+1] != -1)
    {
        if(i != n -1)
            q[i] = q[i+1];
        else
        break;
        i++;
    }
    int len = i;
    q[i] = -1;

    for(int i=0; i<n; i++)
    {
        if(pclk < p[i].atime)
        {
            if(clk >= p[i].atime)
            {
                if(p[i].btime != 0)
                    q[len++] = i;
            }
        }
    }

    if(p[move].btime != 0)
    q[len] = move;

    if(q[0] == -1)
    return -1;
    else
    return 0;
}

void execute(int n, int tq)
{
    int clk = 0, pclk=0;

    // Initialize the ready queue
    int q[n];

    for(int i=0; i<n; i++)
    q[i] = -1;

    q[0] = 0;

    // Initial process and idle time
    if(p[0].atime != 0)
    {
        printf("\n0\tIdle\t%d", p[0].atime);
        clk = pclk = p[0].atime;
    }
    else
        printf("\n0\t");

    if(p[0].btime > tq)
    {
        p[0].btime-=tq;
        clk += tq;
    }
    else
    {
        p[0].btime = 0;
        clk += p[0].btime;
    } 

    printf("P%d\t%d\t", p[0].pid+1, clk);

    while(makeRQ(n, clk, q, pclk) != -1)
    {
        int pr = q[0];
        pclk = clk;
        if(clk < p[pr].atime)
        {
            printf("Idle\t%d\t", p[pr].atime);
            clk = p[pr].atime;
        }

        if(p[pr].btime > tq)
        {
            p[pr].btime -= tq;
            clk += tq;
        }
        else
        {
            clk += p[pr].btime;
            p[pr].btime = 0;
        }    
        printf("P%d\t%d\t", p[pr].pid+1, clk);
        // pclk = clk;
    }
    
}

void main()
{
    printf("\nPlease enter the number of processes - ");
    int n;
    scanf("%d", &n);

    printf("\nPlease enter the details of these processes below:\n");

    defineProcess(n);

    int tq;

    for(int i=0; i<n; i++)
    printf("%d\t", p[i].pid+1);
    printf("\n");

    printf("\nPlease enter the time quanta - ");
    scanf("%d", &tq);

    execute(n, tq);

    return;
}