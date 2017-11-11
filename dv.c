#include<stdio.h>
int main()
{
int i,m,j,k,x,y,min,n,a[10][10],h[10][10];
system("clear");
printf("enter the number of nodes\n");
scanf("%d",&n);
printf("enter the distance matrix\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
h[i][j]=0;
}
}
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
if(a[i][j]!=0&&a[i][j]!=999)
h[i][j]=1;
}
}
for(i=1;i<=n;i++)
{
printf("\n the routing table for %d node is",i);
printf("\n NODE\tDISTANCE\tHOPS");
for(j=1;j<=n;j++)
{
printf("\n...................\n");
printf("\n %d\t%d\t%d",j,a[i][j],h[i][j]);
}
}
printf("\nafter calculation of path\n");
for(m=1;m<=n;m++)
{
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
min=a[i][j];
for(k=1;k<=n;k++)
if(min>a[i][k]+a[k][j])
{
a[i][j]=a[i][k]+a[k][j];
h[i][j]=h[i][k]+h[k][j];
}
}
}
}
for(i=1;i<=n;i++)
{
printf("\nrouting table for %d node is",i);
printf("\n NODE\tDISTANCE\tHOPS");
for(j=1;j<=n;j++)
{
printf("\n......................\n");
printf("\n %d\t%d\t%d",j,a[i][j],h[i][j]);
}
}
printf("\nenter the node whose shortest path is to be found\n");
scanf("%d%d",&x,&y);
printf("\nshortest path is %d with %d hops\n",a[x][y],h[x][y]);
}

