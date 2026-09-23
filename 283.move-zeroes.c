/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 */

// @lc code=start
void moveZeroes(int* nums, int numsSize) {
    int last0 = -1;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0 && last0 == -1) last0 = i;
        if(last0 != -1 && nums[i] != 0){
            nums[last0] = nums[i];
            nums[i] = 0;
            last0 += 1;
        }
    }
}
// @lc code=end

