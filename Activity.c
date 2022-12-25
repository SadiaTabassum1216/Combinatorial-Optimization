#include<stdio.h>
#include<stdlib.h>

struct activity{
int no;
int start;
int finish;
int c;
};

int main()
{
    FILE *fp;
    int n,i;

//**********This part will be used to read from file********************


/*if((fp=freopen("activitySelection.txt","r",stdin))==NULL){
    printf("cannot open file.\n");
    exit(1);
}*/
    scanf ("%d", &n);  //number of activities
    struct activity activities[n],temp;

//read start and finish time from file
  for(i=0;i<n;i++)
    {
      activities[i].no=i+1;
      scanf ("%d", &activities[i].start);
      scanf ("%d", &activities[i].finish);
    }

//fclose(fp);       //********use this too to read input from file********

//sort the activities by ending time
int j;
for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(activities[i].finish>activities[j].finish){
            temp=activities[i];
            activities[i]=activities[j];
            activities[j]=temp;
        }
    }
}

    activities[0].c=0;
for(i=1;i<n;i++)
    activities[i].c=-1;
j=0;

        printf("---Sorted Activities according to finish time---\n");
        printf("\nActivity no\tStart Time\tFinish Time\n");
for(i=0;i<n;i++)
        printf("%d\t\t%d\t\t%d\n",activities[i].no,activities[i].start,activities[i].finish);

//removing conflicting activities
for(i=1;i<n;i++){
    if(activities[i].start>=activities[j].finish){
        activities[i].c=0;
        j=i;
    }
}

//Output
printf("\nAn optimal solution is: {%d",activities[0].no);
for(i=1;i<n;i++){
    if(activities[i].c==0)
        printf(", %d",activities[i].no);
}
printf("}\n\nActivity no\tStart Time\tFinish Time\n");
for(i=0;i<n;i++){
    if(activities[i].c==0)
        printf("%d\t\t%d\t\t%d\n",activities[i].no,activities[i].start,activities[i].finish);
}

return 0;
}
