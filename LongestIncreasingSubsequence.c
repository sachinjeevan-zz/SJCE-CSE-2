#include<stdio.h>
int print(int max,int index,int lis[],int arr[]){
    if(max==0){
        return 0;
    }
    if(lis[index]==max){
        print(max-1,index-1,lis,arr);
        printf("%d ",arr[index]);
    }
    else{
        print(max,index-1,lis,arr);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int lis[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        lis[i]=1;
    }
    int max=1,index=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                if(lis[j]+1>lis[i]){
                    lis[i]=lis[j]+1;
                    if(lis[i]>max){
                        max=lis[i];
                        index=i;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",lis[i]);
    }
    printf("\n");
print(max,index,lis,arr);

    /*
    while(max>0){
        if(lis[index]==max){
            printf("%d ",arr[index]);
            index--;
            max--;
        }
        else{
            index--;
        }
    }
    */
}