#include <stdlib.h>

typedef struct {
    union {
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
    } * val;
} Triple;

struct *
find_max_crossing_subarray(int * A, const int low, const int mid, const int high)
{
    Triple * ret = malloc(sizeof(Triple));
    ret->val = malloc(sizeof(int) * 3);
    
    int i;
    ret->val[0].left_sum = INT_MIN;
    ret->val[1].right_sum = INT_MIN;

    ret->val[2].sum = 0;

    for (i = mid; i > low; --i)
    {
        ret->val[2].sum = ret->val[2].sum + *(A + i);
        if (ret->val[2].sum > left_sum)
        {
            left_sum = ret->val[2].sum;
            ret->max_left = i;
        }
    }

    ret->val[2].sum = 0;
    for (i = mid + 1; i < high; ++i)
    {
        ret->val[2].sum = ret->val[2].sum + *(A + i);
        if (ret->val[2].sum > right_sum)
        {
            right_sum = ret->val[2].sum;
            ret->max_right = i;
        }
    }

    ret->sum = left_sum + right_sum;

    return ret;
}

