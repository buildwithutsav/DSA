#include <stdio.h>
#include <stdlib.h>

int main(){
    int i , n , target;
    int foundindex = -1;
    

    printf("Enter the size of an array: ");
    scanf("%d",&n);

    if(n<=0){
        printf("INVALID SIZE");
        return 1;
    }
int*arr = (int*)malloc(n * sizeof(int));

if(arr == NULL){
    printf("Memory allocation failed:\n");
    return 1 ;

}

printf("Enter %d integer:\n",n);
for(int i=0 ; i<n ; i++){
    scanf("%d",&arr[i]);
}

printf("Enter the number you want to search for: ");
scanf("%d",&target);

for(i = 0 ; i<n ; i++){
    if(arr[i] == target){
        foundindex = i;
        break;
    }
}


if(foundindex != -1){
    printf("Number %d found at index: %d (Position: %d)\n",target, foundindex, foundindex+1);

}else{
    printf("Number %d was not found in the array.\n",target);

}

free(arr);

return 0;
}