#include<stdio.h>
#include<string.h>

void LCSLength(char x[],char y[],int m, int n, int c[n+1][m+1]);
void print(char b[100][100],char x[],int i, int j);
char b[100][100];
int main()
{
    char x[100],y[100];
     FILE *fp;

//**********This part will be used to read from file********************

/*if((fp=freopen("LCSinput.txt","r",stdin))==NULL){
    printf("cannot open file.\n");
    exit(1);
}*/
    //printf("Enter two strings: ");
    scanf("%s %s",&x,&y);

//fclose(fp);       //********use this too to read input from file********

    int m,n,i,j;
    m=strlen(x);
    n=strlen(y);

    int c[m+1][n+1];

    LCSLength(x,y,m,n,c);
    printf("\nThe maximum length of the common subsequence is: %d",c[m][n]);
    printf("\nThe maximum length common subsequence is: ");

    print(b,x,m,n);
}


void LCSLength(char x[],char y[],int m, int n, int c[m+1][n+1])
{
    int i,j;

   for(i=0;i<=m;i++)
        c[i][0]=0;

    for(j=0;j<=n;j++)
        c[0][j]=0;


    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='C';
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='U';
            }
            else{
                c[i][j]=c[i][j-1];
                b[i][j]='L';
                }

        }
    }
   /* for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
        for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            printf("%c ",b[i][j]);
        }
        printf("\n");
    }*/

}

void print(char b[100][100],char x[],int i, int j)
{

    if(i==0 || j==0)
        return;

    if(b[i][j]=='C'){
        print(b,x,i-1,j-1);
        printf("%c",x[i-1]);
    }

    else if(b[i][j]=='U')
        print(b,x,i-1,j);

    else
        print(b,x,i,j-1);

}

