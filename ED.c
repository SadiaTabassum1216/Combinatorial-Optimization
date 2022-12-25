#include<stdio.h>
#include<string.h>

int ED(char x[],char y[],int m, int n);
void print(char b[100][100],char x[],char y[],int i, int j);
char b[100][100];

int main()
{
    char x[100],y[100];
     FILE *fp;

//**********This part will be used to read from file********************

/*if((fp=freopen("EDinput.txt","r",stdin))==NULL){
    printf("cannot open file.\n");
    exit(1);
}*/
   // printf("Enter two strings: ");
    scanf("%s %s",&x,&y);

//fclose(fp);       //********use this too to read input from file********

    int m,n,i,j,ans;
    m=strlen(x);
    n=strlen(y);

    int c[m+1][n+1];

    ans=ED(x,y,m,n);
    printf("\nThe minimum number of edit: %d",ans);
    printf("\nSequence of edit operations needed to convert \"%s\" to \"%s\": " ,x,y);

    print(b,x,y,m,n);
}


int ED(char x[],char y[],int m, int n)
{
    int i,j;
    int c[m+1][n+1];

    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(j==0){
                c[i][j]=i;
                b[i][j]='D';
                }
            else if(i==0){
                c[i][j]=j;
                b[i][j]='I';
            }

            else if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1];
                b[i][j]='N';
            }
            else if(c[i-1][j-1]<=c[i-1][j] && c[i-1][j-1]<=c[i][j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='S';
            }

            else if(c[i-1][j]<=c[i-1][j-1] && c[i-1][j]<=c[i][j-1]){
                c[i][j]=c[i-1][j]+1;
                b[i][j]='D';
            }
            else{
                c[i][j]=c[i][j-1]+1;
                b[i][j]='I';
                }

        }
    }
  /*  for(i=0;i<=m;i++){
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
return c[m][n];
}

void print(char b[100][100],char x[],char y[],int i, int j)
{

    if(i==0 && j==0)
        return;

    if(b[i][j]=='S'){
        print(b,x,y,i-1,j-1);
        printf("\nSubstitute %c by %c",x[i-1],y[j-1]);
    }

    else if(b[i][j]=='N'){
        print(b,x,y,i-1,j-1);
       // printf("Substitute %c",x[i-1]);
    }

    else if(b[i][j]=='D'){
        print(b,x,y,i-1,j);
        printf("\nDelete %c",x[i-1]);
    }

    else{
        print(b,x,y,i,j-1);
        printf("\nInsert %c",y[j-1]);
    }

}
