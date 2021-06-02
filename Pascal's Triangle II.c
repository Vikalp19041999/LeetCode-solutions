

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int *ans = calloc(rowIndex + 1, sizeof(int));
    ans[0] = 1;
    for(int i=0; i<rowIndex; i++) {
        long val = ans[i];
        val = val * (rowIndex - i);
        ans[i+1] = val/(i+1);
    }
    *returnSize = rowIndex + 1;
    return ans;
}