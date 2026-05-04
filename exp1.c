
#include <stdio.h>

int main() {
    int n,i,j,ch,po,el,key;
    int temp,fo=0;
    
    printf("Enter number of elements :");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:\n");
    for (i=0;i<n;i=i+1){
        scanf("%d",&a[i]);
        
    }
    do {
        
    printf("\n1.insertion at desired location\n");
    printf("2.Deletion from desired location\n");
    printf("3.Search using linear search\n");
    printf("4.bubble sort\n");
    printf("5. Selection sort\n");
    printf("6. Exit\n");
    printf("Enter ur choice:\n");
    scanf("%d",&ch);
    switch (ch){
        case 1:
        printf("Enter the postion:");
        scanf("%d",&po);
        printf("Enter element:");
        scanf("%d",&el);
        for (i=n;i>=po;i=i-1){
            a[i]=a[i-1];
        }
            a[po-1]=el;
         n=n+1;
        
        
            printf("Array after insertion:\n");
            for (i=0;i<n;i=i+1){
                printf("%d ",a[i]);
            }
                break;
                case 2:
                printf("enter position to delete:");
                scanf("%d",&po);
                for (i=po-1;i<n-1;i=i+1){
                    a[i]=a[i+1];
                }
                    n=n-1;
                printf("Array after deletion:\n");
                for (i=0;i<n;i=i+1){
                    printf("%d ",a[i]);
                    
                    }
                    break;
                
        case 3:
        printf("Enetr element to search:");
        scanf("%d",&key);
        fo=0;
        for (i=0;i<n;i=i+1){
            if (a[i] == key){
                printf("Element found at position %d\n",i+1);
                fo=1;
                break;
            }
        }
            if (!fo){
                printf("Element not found:\n");
            }
                break;
            
            case 4:
            for (i=0;i<n-1;i=i+1){
                for (j=0;j<n-i-1;j=j+1){
                    if (a[j]>a[j+1]){
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
            }
            printf("Array after sorting:\n");
            for (i=0;i<n;i=i+1){
                printf("%d ",a[i]);
                
            }
        
        break;
        case 5:   
                for (i=0;i<n-1;i++){
                    int min = i;
                    for (j=i+1;j<n;j++){
                        if (a[j] < a[min]){
                            min = j;
                        }
                    }
                    if (min != i){
                        temp = a[i];
                        a[i] = a[min];
                        a[min] = temp;
                    }
                }

                printf("Array after selection sort:\n");
                for (i=0;i<n;i++){
                    printf("%d ",a[i]);
                }
                printf("\n");
                break;
                
            
                
                case 6:
                printf("Exiting program...\n");
                break;


        default:
        printf("Invalid choice:\n");
     }
    } while(ch !=6);
    return 0;
}
