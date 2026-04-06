#include<stdio.h>

int linearSearch(int arr[], int n, int target);
void printArray(int arr[], int n);


int main(){
    
    int n, i, arr[100], target;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    printf("\nEnter the elements: \n");
    for (i=0;i<n;i++){
        printf("Arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the targeted value: ");
    scanf("%d", &target);

    int index = linearSearch(arr, n, target);
    printArray(arr, n);
}

int linearSearch(int arr[], int n, int target){

    int i, j, foundValue;
    printf("Starting linear Search...\n");
    printf("Waiting...\n");
    
    for(i=0; i<n; i++){
        if(arr[i] == target){
            printf("Value found at index: %d\n", i);
            foundValue = i;
        }
    }

    printf("Linear Search Completed...");
    return foundValue;

}

void printArray(int arr[], int n){

    printf("Array: \n");
    for(int i = 0; i<n; i++){
        printf("Arr[%d] = %d\n", i, arr[i]);
    }
}