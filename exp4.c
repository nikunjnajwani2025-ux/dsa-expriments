// Online C compiler to run C program online
#include <stdio.h>

int main() {
   int r,c,i,j;
   int rs,cs,ts=0;
   printf("Enter number of rows:");
   scanf("%d",&r);
   printf("Enter number of columns:");
   scanf("%d",&c);
   int arr[r][c];
   printf("Enter elements of matrix:\n");
   for (i=0;i<r;i=i+1){
       for (j=0;j<c;j=j+1){
           scanf("%d",&arr[i][j]);
       }
   }
   for (i=0;i<r;i=i+1){
       rs=0;
       for (j=0;j<c;j=j+1){
           rs=rs+arr[i][j];
       }
       printf("Sum of rows %d = %d\n",i+1,rs);
       ts=ts+rs;
   }
   for (j=0;j<c;j=j+1){
       cs=0;
       for (i=0;i<r;i=i+1){
           cs=cs+arr[i][j];
       }
       printf("Sum of columc %d = %d\n",j+1,cs);
   }
   printf("Total sum of all elements= %d\n",ts);
   return 0;
}
