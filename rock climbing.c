#include<stdio.h>
#include<math.h>

int climb(int m,int n, int c[m][n]);
void PrintBest(int index,int m,int n,int a[m+1][n+2],int c[m][n]);

int min(int a,int b,int c){
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    else
        return c;
}

int main()
{
int i,j,m,n,ans;

//printf("Enter number of rows: ");
scanf("%d",&m);

//printf("Enter number of columns: ");
scanf("%d",&n);

int c[m][n];
//printf("Enter the values:\n");
for(i=0;i<m;i++){
    for(j=0;j<n;j++)
        scanf("%d",&c[i][j]);
    }

ans=climb(m,n,c);

printf("\nThe minimum danger is: %d",ans);

}

int climb(int m,int n, int c[m][n])
{
    int i,j,a[m+1][n+2];

    for(j=1;j<=n;j++){
        a[0][j]=0;
        a[1][j]=c[0][j-1];
    }

    for(i=0;i<=m;i++){
        a[i][0]=INFINITY;
        a[i][n+1]=INFINITY;
    }

    for(i=2;i<=m;i++){
        for(j=1;j<=n;j++){
            a[i][j]=min(a[i-1][j-1],a[i-1][j],a[i-1][j+1])+c[i-1][j-1];
        }
    }

    int min=a[m][1],index=1;
    for(i=1;i<=n;i++){
        if(a[m][i]<min){
            min=a[m][i];
            index=i;}
    }

    PrintBest(index,m,n,a,c);

return min;
}

void PrintBest(int index,int m,int n,int a[m+1][n+2],int c[m][n]) // Printing the best path ending at (i,j)
	{
    int i,j=index;
    printf("The path is:\n");
	for(i=m;i>0;i--){

        printf("(%d,%d) with danger %d\n",i,j,c[i-1][j-1]);

        if ((a[i-1][j-1]<=a[i-1][j]) && (a[i-1][j-1]<=a[i-1][j+1]))
            j=j-1;

        else if ((a[i-1][j]<=a[i-1][j-1]) && (a[i-1][j]<=a[i-1][j+1]))
            ;

        else if((a[i-1][j+1]<=a[i-1][j-1]) && (a[i-1][j+1]<=a[i-1][j]))
            j=j+1;
	}
  }

