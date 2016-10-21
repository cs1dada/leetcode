/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    
    int* ptr = (int*)malloc(sizeof(int)*2);
    
    for (int i=0; i<numsSize; i++) {  
        for (int j=i+1; j<numsSize; j++) {

            if (nums[j] == (target - nums[i])) {
                printf("i=%d, j=%d, nums[i]=%d, nums[j]=%d\n", i, j, nums[i], nums[j] );
                *ptr = i;
                *(ptr+1) = j;
                //printf("result[0]=%d, result[1]=%d, result[2]=%d\n", result[0], result[1], result[2]);
                return ptr;   
            }
            
        } //inner for    
    }//outer for
                 
    printf("final");                 
    return ptr;     
}

