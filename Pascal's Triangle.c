

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    int **arr = (int**)malloc(numRows*sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows*sizeof(int));
    
    for (int i=0; i<numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        arr[i] = (int*)malloc((i+1)*sizeof(int));
    }
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<=i; j++) {
            if(i==j || j==0){
                arr[i][j] = 1;
            } else {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }
    return arr;
}