#include <stdlib.h>

typedef struct {
    union {
        int low;
        int mid;
        int high;
        int max_left;
        int max_right;
        int left_low;
        int left_high;
        int left_sum;
        int right_low;
        int right_high;
        int right_sum;
        int cross_low;
        int cross_high;
        int cross_sum;
        int sum;
        int temp;
    } * val;
} Triple;

struct *
find_max_crossing_subarray(int * A, const int low, const int mid, const int high)
{
    Triple * ret = malloc(sizeof(Triple));
    ret->val = malloc(5 * sizeof(int));
    
    int i;
    
    ret->val[0].left_sum = INT_MIN;
    ret->val[1].right_sum = INT_MIN;

    ret->val[2].sum = 0;

    for (i = mid; i > low; --i)
    {
        ret->val[2].sum = ret->val[2].sum + *(A + i);
        if (ret->val[2].sum > ret->val[0].left_sum)
        {
            ret->val[0].left_sum = ret->val[2].sum;
            ret->val[3].max_left = i;
        }
    }

    ret->val[2].sum = 0;
    for (i = mid + 1; i < high; ++i)
    {
        ret->val[2].sum = ret->val[2].sum + *(A + i);
        if (ret->val[2].sum > ret->val[1].right_sum)
        {
            ret->val[1].right_sum = ret->val[2].sum;
            ret->val[4].max_right = i;
        }
    }

    ret->val[2].sum = ret->val[0].left_sum + ret->val[1].right_sum;

    return ret;
}

struct *
find_maximum_array(int * A, const int low, const int high)
{
    Triple * ret = malloc(sizeof(Triple));
    ret->val = malloc();

    if (high == low)
    {
        ret->val[].low = low;
        ret->val[].high = high;
        ret->val[].temp = *(A + low);
        return ret;
    } else {
        //TODO

    }
        
}