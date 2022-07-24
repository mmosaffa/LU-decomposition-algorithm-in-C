#include <stdio.h>
#include <stdlib.h>
void scanmatrisA(int i,int j,float matris[20][20])
{
    int k,t;
    printf("please insert elements of matrix A : \n");
    for(k=0;k<i;k++)
        for(t=0;t<j;t++)
        scanf("%f",&matris[k][t]);
    printf("done \n");
}
void printmatrisA(int i,int j,float matris[20][20])
{
    int k,t;
    for(k=0;k<i;k++)
     {
      for(t=0;t<j;t++)
        printf("%.1f   ",matris[k][t]);
     printf("\n");
     }
printf("done \n");
}
void matrisLinsert(int i,float matris[20][20])
{
    int k,t;
    for(k=0;k<i;k++)
        for(t=0;t<i;t++)
        matris[k][t]=0;
    for(k=0;k<i;k++)
        matris[k][k]=1;
}
void printmatrisL(int i,float matris[20][20])
{
    int k,t;
    for(k=0;k<i;k++)
    {
       for(t=0;t<i;t++)
        printf("%.1f   ",matris[k][t]);
        printf("\n");
    }
//printf("done \n");
}
void printmatrisU(int i,int j,float matris[20][20])
{
    int k,t;
    for(k=0;k<i;k++)
     {
      for(t=0;t<j;t++)
        printf("%.1f   ",matris[k][t]);
     printf("\n");
     }
//printf("done \n");
}
int main()
{
    float temp=0,matrisA[20][20],matrisU[20][20],matrisL[20][20];
    int i=0,j=0,t=0,k=0,s=0,w=0,p=0,count=0,row,column;
    printf("please insert rows' number : ");
    scanf("%d",&row);
    printf("please insert columns' number : ");
    scanf("%d",&column);
    scanmatrisA(row,column,matrisA);
    printf("this is original matrix A ! :\n\n");
    printmatrisA(row,column,matrisA);
    matrisLinsert(row,matrisL);
    //printmatrisL(row,matrisL);
    for(i=0;i<row;i++)
        for(j=0;j<column;j++)
        matrisU[i][j]=matrisA[i][j];
    //printf("This is matris A : \n\n");
    //printmatrisU(row,column,matrisU);
    j=0;
    for(i=0;i<row;i++)
    {
        w=i;
      //  printf("before \n");
      //  printmatrisA(row,column,matrisA);
      //  printmatrisU(row,column,matrisU);
      //  printmatrisL(row,matrisL);
        while((matrisU[i][w]==0)&&(matrisU[i+1][w]==0))
            w=w+1;
        if((i!=row-1)&&(matrisU[i][w]==0)&&(matrisU[i+1][w]!=0))
        {
            count=count+1;
            //printf("%d",x);
            for(p=0;p<column;p++)
            {
                temp=matrisA[i][p];
                matrisA[i][p]=matrisA[i+1][p];
                matrisA[i+1][p]=temp;
            }
            for(j=j+w;j<column;j++)
            {
                temp=matrisU[i][j];
                matrisU[i][j]=matrisU[i+1][j];
                matrisU[i+1][j]=temp;
            }
            j=0;
            for(k=0;k<i;k++)
            {
                temp=matrisL[i][k];
                matrisL[i][k]=matrisL[i+1][k];
                matrisL[i+1][k]=temp;
            }
        //    printf("after \n");
        //    printmatrisA(row,column,matrisA);
        //    printmatrisU(row,column,matrisU);
        //    printmatrisL(row,matrisL);
        }
        t=i+1;
        for(;t<row;t++)
        {
              //  printf("%d \n",w);
              //  printf("%d \n",t);
              //  printf("%d \n",i);
            matrisL[t][i]=(matrisU[t][w])/(matrisU[i][w]);
          //  printf("%f ",matrisL[t][w]);
            for(s=s+w;s<column;s++)
            {
                matrisU[t][s] = (matrisU[t][s]-((matrisU[i][s])*(matrisL[t][i])));
            }
            s=0;
        }
    }
    printf("\nThis is matrix A \n\n");
    printmatrisA(row,column,matrisA);
    printf("\nThis is matrix L \n\n");
    printmatrisL(row,matrisL);
    printf("\nThis is matrix U \n\n");
    printmatrisU(row,column,matrisU);
    return 0;
}
