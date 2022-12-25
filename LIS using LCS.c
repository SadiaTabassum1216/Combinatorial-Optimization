#include<stdio.h>

void LCSLength(int x[],int y[],int n, int c[n+1][n+1]);
void print(char b[100][100],int x[],int i, int j);
char b[100][100];
int main()
{
    int n,i,j,temp;
   // printf("Enter the size: ");
    scanf("%d",&n);
    int x[n],y[n];

  //  printf("Enter the values: ");
    for(i=0;i<n;i++){
        scanf("%d",&x[i]);
        y[i]=x[i];
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(y[j]<y[i]){
               temp=y[i];
               y[i]=y[j];
               y[j]=temp;
            }
        }
    }

    int c[n+1][n+1];

    LCSLength(x,y,n,c);
    printf("\nThe maximum length of the common subsequence is: %d",c[n][n]);
    printf("\nThe subsequence is: ");

    print(b,x,n,n);
}


void LCSLength(int x[],int y[],int n,int c[n+1][n+1])
{
    int i,j;

   for(i=0;i<=n;i++){
        c[i][0]=0;
        c[0][i]=0;}


    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='C';
            }
            else if(c[i-1][j]>c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='U';
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]='L';
                }

        }
    }
}

void print(char b[100][100],int x[],int i, int j)
{

    if(i==0 || j==0)
        return;

    if(b[i][j]=='C'){
        print(b,x,i-1,j-1);
        printf("%d ",x[i-1]);
    }

    else if(b[i][j]=='U')
        print(b,x,i-1,j);

    else
        print(b,x,i,j-1);
}
