#include<stdio.h>
int main()
{
    int sales[4][3];
    int totalsale=0;
    int prodtotal[3]={0};
    int depttotal[4]={0};
    int i,j;
    printf("\n enter the sales figures for 4 departments and 3 products :");
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\n sales for department %d ,product %d :",i+1,j+1);
            scanf("%d",&sales[i][j]);
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            totalsale+=sales[i][j];
            depttotal[i]+=sales[i][j];
            prodtotal[j]+=sales[i][j];
        }
    }
    printf("\n total sale of the company %d \n",totalsale);
    printf("\n department wise total sales : \n");
    for(i=0;i<4;i++)
    {
        printf("\n deprtment %d : %d \n",i+1,depttotal[i]);
    }
    printf("\n product wise total sales : \n");
    for(j=0;j<3;j++)
    {
        printf("\n product %d : %d \n",j+1,prodtotal[j]);
    }
    return 0;
}
