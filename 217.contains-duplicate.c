/*
 * @lc app=leetcode id=217 lang=c
 *
 * [217] Contains Duplicate
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// @lc code=start
bool containsDuplicate(int* nums, int numsSize) {
    //思路：先排序再对比
    //cmp():作为函数指针，帮助判断大小
    int cmp(const void* num1, const void* num2){//const:符合qsort类型限制
        return *((int*)num1)-*((int*)num2);//int*强转，*获取值
    }
    //qsort排序
    qsort(nums,numsSize,sizeof(int),cmp);
    //与下一个数字做对比，如果相同直接return true
    for(int i = 0; i < numsSize-1; i++){
        if(nums[i]==nums[i+1]) return true;
    }
    return false;
}
// @lc code=end

int main() {
    int nums[] = {1, 2, 3, 1};
    int numsSize = 4;
    bool result = containsDuplicate(nums, numsSize);
    printf("%d\n", result);  // 1表示true，0表示false
    return 0;
}