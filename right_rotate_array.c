#include <stdio.h>
int main(){
    int n ,  k ,i ,j ,temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter number of positions to rotate: ");
    scanf("%d", &k);
    int arr[n];
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    k = k % n;
    for(i=0;i<k;i++){
        temp = arr[n-1];
        for(j=n-1;j>0;j--){
            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }
    printf("Array after right rotation: ");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}