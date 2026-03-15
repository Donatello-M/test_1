#include <stdio.h>
int check(int arr[], int n){
    int i;
    int k = 0;
    for(i = 0; i < n-1; i++){
        if(arr[i] > arr[i + 1]){
            k++;
            
        }
    }
    if(arr[n - 1] > arr[0]){
        k++;
        
    }
    if (k == 1) {
        return 1;
    }
    return 0;
}
int main() {
    int i;
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    if(check(arr, n)) {
        printf("Да\n");
    } else{
        printf("Нет\n");
        
    }
    return 0;
        
        
        
        
        
        
}



