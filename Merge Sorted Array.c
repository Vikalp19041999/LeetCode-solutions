

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i, j = 0, temp;
    for(i=m; i<m+n; i++) {
        nums1[i] = nums2[j];
        j++;
    }
    for(i=0; i<m+n-1; i++) {
        for(j=0; j<m+n-i-1; j++) {
            if(nums1[j] > nums1[j+1]) {
                temp = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = temp;
            }
        }
    }
}