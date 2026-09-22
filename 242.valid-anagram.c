/*
 * @lc app=leetcode id=242 lang=c
 *
 * [242] Valid Anagram
 */

// @lc code=start
int cmpStr(const void* a, const void* b){//c不能方法套方法
    return *((char*)a) - *((char*)b);
}
bool isAnagram(char* s, char* t) {
    //本质和217一样，先排序再逐字对比
    qsort(s, strlen(s), sizeof(char), cmpStr);
    qsort(t, strlen(t), sizeof(char), cmpStr);
    if(strcmp(s,t)==0){
        return true;
    }else{
        return false;
    }
}
// @lc code=end

