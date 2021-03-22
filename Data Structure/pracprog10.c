#include <stdio.h>
#include <stdlib.h>

void heapify(int a[10], int n){
    int i, k, j, v, flag;
    for(i=n/2; i>=1; i--){
        k = i;
        v = a[k];
        flag = 0;
        while(!flag && 2*k <= n){
            j=2*k;
            if(j < n){
                if(a[j]<a[j+1]){
                    j = j + 1;
                }
            }
            if(v >= a[j]){
                flag = 1;
            }
            else{
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
    }
}

int main(){
    int i, j, choice, a[10], n;

    while (1)
    {
        printf("\n1. Create Heap\n2. Delete\n3. Exit\n\nSelect you choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                    printf("\nEnter the number of elements: ");
                    scanf("%d", &n);
                    for(i=1; i<=n; i++){
                        scanf("%d", &a[i]);
                    }
                    heapify(a, n);
                    printf("\nElements after heapify\n");
                    for(i=1; i<=n; i++){
                        printf("%d\t", a[i]);
                    }
                    printf("\n");
                    break;
            case 2:
                    if(n >= 1){
                        printf("Element deleted: %d", a[1]);
                        a[1] = a[n];
                        n = n - 1;
                        heapify(a, n);
                        printf("\nElements after heapify\n");
                        for(i=1; i<=n; i++){
                            printf("%d\t", a[i]);
                        }
                        printf("\n");
                        break;
                    }
                    else{
                        printf("Not enough elements to delete");
                        break;
                    }
            default:
                    exit(0);

        }
    }
    

}