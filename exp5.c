#include <stdio.h>

int main() {
  int r1,r2,c1,c2,i,j,k;
  printf("Enter number  of rows of 1 matrix:");
  scanf("%d",&r1);
  printf("Enter number of column of 1 matrix:");
  scanf("%d",&c1);
  printf("Enter number of rows of 2 matrix:");
  scanf("%d",&r2);
  printf("Enter number of column of 2 matrix:");
  scanf("%d",&c2);
  int arr[r1][c1];
  int brr[r2][c2];
  int re[r1][c2];
  if (c1 != r2){
      printf("Matrix multiplication not posssible:");
      return 0;
  }
  printf("Enter elements  of first  matrix:\n");
   for (i=0;i<r1;i=i+1){
       for (j=0;j<c1;j=j+1){
           scanf("%d",&arr[i][j]);
       }
   }
   printf("Enter elements of  second matrix:\n");
   for (i=0;i<r2;i=i+1){
       for (j=0;j<c2;j=j+1){
           scanf("%d",&brr[i][j]);
       }
   }
   for (i=0;i<r1;i=i+1){
       for (j=0;j<c2;j=j+1){
           re[i][j]=0;
           for (k=0;k<c1;k=k+1){
               re[i][j]=re[i][j]+(arr[i][k]*brr[k][j]);
           }
       }
   }
printf("Matrix multiplication:\n");
   for (i=0;i<r1;i=i+1){
       for (j=0;j<c2;j=j+1){
           printf("%d ",re[i][j]);
       }
       printf("\n");
   }
    return 0;
}
