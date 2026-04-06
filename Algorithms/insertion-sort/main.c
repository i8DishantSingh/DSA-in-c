#include<stdio.h>


void insertionSort(int arr[], int n);
void printArray(int arr[], int n);
int main();

int main(){

    int i, n, arr[110];

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    printf("Enter Array: \n");
    for(i=0; i<n; i++){

        printf("Arr[%d] = ", i);
        scanf("%d", &arr[i]);

    }

    insertionSort(arr, n);
    printArray(arr, n);

}

void insertionSort(int arr[], int n){

    int i, j;
    printf("Starting insertion Sort... \n");
    printf("Waiting...\n");

    for(j = 1; j < n; j++){
        int key = arr[j];
        i = j - 1;
        while( i >= 0 && arr[i]>key){
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key;
    }

    printf("Sorting completed... \n");
}

void printArray(int arr[], int n){

    printf("Array: \n");
    for(int i = 0; i<n; i++){
        printf("Arr[%d] = %d\n", i, arr[i]);
    }
}