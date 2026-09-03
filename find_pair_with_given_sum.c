#include <stdio.h>
int main(){
    int n ,target,i , j ;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter target sum: ");
    scanf("%d",&target);
    printf("Pairs with given sum are: ");
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i] + arr[j] == target){
                printf("(%d, %d) ", arr[i], arr[j]);
            }
        }
    }
    return 0;
}