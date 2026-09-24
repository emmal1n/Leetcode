/*
 * @lc app=leetcode id=49 lang=c
 *
 * [49] Group Anagrams
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpChar(const void* a, const void* b){
    return *(char*)a - *(char*)b;
}
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char* keys[strsSize];
    for(int i = 0; i < strsSize; i++){
        char* cpy = strdup(strs[i]);
        qsort(cpy,strlen(strs[i]),sizeof(char),cmpChar);//内存泄漏检查这个，分清参数的意义，第三个参数传的是要对比的单位大小
        keys[i] = cpy;
    }

    char*** result = malloc(strsSize * sizeof(char**));
    int* groupCount = malloc(strsSize * sizeof(int));
    char** groupKeys = malloc(strsSize *sizeof(char*));
    int groupTotal = 0;

    int k ;
    int found;
    for(int j = 0; j < strsSize; j++){
        k = 0;
        found = -1;
        while (k < groupTotal){            
            if(strcmp(keys[j],groupKeys[k]) == 0){
                found = k;
                break;
            }
            k++;
        }
        if(found == -1){
            result[groupTotal] = malloc(strsSize * sizeof(char*));
            result[groupTotal][0] = strs[j];
            groupKeys[groupTotal] = keys[j];
            groupCount[groupTotal] = 1;
            groupTotal++;
        }else{
            result[found][groupCount[found]] = strs[j];
            groupCount[found]++;
        }
        
    }
    *returnSize = groupTotal;
    *returnColumnSizes = malloc(groupTotal * sizeof(int));
    for(int i = 0; i < groupTotal; i++){
        (*returnColumnSizes)[i] = groupCount[i];
    }
    return result;
}
// @lc code=end

