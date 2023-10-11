//WAP to display the elements in the main diagonal, the diagonal above and below the main diagonal
//of a matrix.

#include<stdio.h>

int main() {
    int arr[100][100];
    int m,n,count=0;
    printf("Enter the the row and column of the matrix");
    scanf("%d %d", &m, &n);
    
    for (int i = 0;i < m;i++) {
        for(int j=0;j<n;j++){
            printf("Enter the %d %d element of the matrix ",i,j);
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0){
                count++;
            }
        }
    }
    
    for (int i = 0;i < m;i++) {
        for(int j=0;j<n;j++){
            if(i==j){
                printf("%d",arr[i][j]);
            }
            else{
                printf(" ");
            }
           
        }
        printf("\n");
    }

    printf("for the above and below of diagonal \n");

    printf("The upper is \n");
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if (j == i + 1 ) {
                printf("%d ", arr[i][j]);
            }
        }
       
    }

    printf("\nThe below is \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if (j == i - 1 ) {
                printf("%d ", arr[i][j]);
            }
        }
       
    }
    
}