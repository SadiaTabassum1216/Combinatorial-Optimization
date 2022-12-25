#include<stdio.h>
#include<stdlib.h>

struct item{
int weight;
int benefit;
float value;
};

int main()
{
    FILE *fp;
    int n,totalWeight,i,flag;
    float profit=0,w=0,max;


//**********This part will be used to read from file********************
/*if((fp=freopen("knapsackInput.txt","r",stdin))==NULL){
    printf("cannot open file.\n");
    exit(1);
}*/

    scanf ("%d %d", &n,&totalWeight);  //number of items and total weight

struct item items[n];

//read weight and benefit of each item from file

  for(i=0;i<n;i++)
    {
      scanf ("%d", &items[i].weight);
      scanf ("%d", &items[i].benefit);
      items[i].value=(float)items[i].benefit/(float)items[i].weight;
    }

        printf("Item no\tWeight\tBenefit\tValue\n");
  for(i=0;i<n;i++)
      printf("%d\t%d\t%d$\t%.2f$\n",i+1,items[i].weight,items[i].benefit,items[i].value);

//fclose(fp);       //********use this too to read input from file********

printf("\nItems to be selected\n");

while(w<totalWeight){
    flag=0, max=0;
    for(i=0;i<n;i++)
    {
        if(items[i].value>max){
            max=items[i].value;
            flag=i; //max value item
        }
    }
    if((totalWeight-w)>=items[flag].weight){
        profit=profit+items[flag].benefit;
        w=w+items[flag].weight;
        printf("%d no item of %d unit: %.2f$\n",flag+1,items[flag].weight,(float)items[flag].benefit);
        items[flag].weight=0;
        items[flag].value=0;
    }
    else{
        profit=profit+(totalWeight-w)*items[flag].value;
        printf("%d no item of %.0f unit: %.2f$\n",flag+1,(totalWeight-w),(totalWeight-w)*items[flag].value);
        w=totalWeight;
        items[flag].weight=0;
        items[flag].value=0;
    }

}

printf("\nTotal profit is: %.2f$\n",profit);

return 0;
}
