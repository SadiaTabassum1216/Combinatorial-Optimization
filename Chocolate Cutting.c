#include<stdio.h>
#include<math.h>

int Chocolate(int m, int n, int p[][100]);

int r[100][100];
int max(int a,int b)
{
    return (a>b)?a:b;
}

int main()
{
    FILE *fp;
    int n,m,i,j,ans;

//**********This part will be used to read from file********************

/*if((fp=freopen("ChocolateInput.txt","r",stdin))==NULL){
    printf("cannot open file.\n");
    exit(1);
}*/

   // printf("Enter number of row: ");
    scanf("%d",&m);
// printf("Enter number of column: ");
    scanf("%d",&n);
    int price[100][100];

   // printf("Enter the price:");
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&price[i][j]);
        }
    }

//fclose(fp);       //********use this too to read input from file********

   /* for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            printf("%d ",price[i][j]);
        }
        printf("\n");
    }*/
    ans=Chocolate(m,n,price);

   // ans=Chocolate(price,n,r,s);

    printf("Max profit: %d\n",ans);
}

int Chocolate(int m, int n, int p[][100])
{
    int i,j,k,l,x=-1,y=-1;

    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++)
            r[i][j]=0;
    }


    for(l=1;l<=m;l++){
        for(k=1;k<=n;k++){
            x=0,y=0;
            for(i=1;i<=k;i++){
            x=max(x,p[l][i]+r[l][k-i]);
            }
            for(j=1;j<=l;j++){
            y=max(y,p[j][k]+r[l-j][k]);
            }
            //printf("%d %d\n",x,y);
            r[l][k]=max(x,y);

        }
    }
    printf("\n\n");

    for(int a=1;a<=m;a++){
                 for(int b=1;b<=n;b++)
                    printf("%d ",r[a][b]);
                 printf("\n");
             }
    return r[m][n];
}
