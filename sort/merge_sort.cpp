//
// Created by kongshui on 5/14/21.
//

#include <iostream>

/*
 * 将一个大的无序数组有序，我们可以把大的数组分成两个，然后对这两个数组分别进行排序，
 * 之后在把这两个数组合并成一个有序的数组。由于两个小的数组都是有序的，所以在合并的时候是很快的。
 * 通过递归的方式将大的数组一直分割，直到数组的大小为 1，此时只有一个元素，那么该数组就是有序的了，
 * 之后再把两个数组大小为1的合并成一个大小为2的，再把两个大小为2的合并成4的 ….. 直到全部小的数组合并起来。
 */

void merge_sort(int *arr, int *result, int left, int right)
{
    if (left == right)
    {
        result = arr;
    } else if (left < right)
    {
        int center = (left + right) / 2;

        merge_sort(arr, result, left, center);
        merge_sort(arr, result, center + 1, right);

        int left_index  = left;
        int right_index = center + 1;

        for (auto index = left; index <= right; ++index)
        {
            if ((left <= left_index) && (left_index <= center) && (right_index <= right) && (right_index > center))
            {
                if (arr[left_index] <= arr[right_index])
                    result[index] = arr[left_index++];
                else
                    result[index] = arr[right_index++];
            } else
            {
                if (left_index > right_index)
                    result[index] = arr[right_index++];
                else
                    result[index] = arr[left_index++];
            }
        }

        for (int index = left; index <= right; ++index)
            arr[index] = result[index];
    }
}

int main()
{
    int arr[5] = {4, 5, 3, 2, 1};
    int result[5] = {0};

    merge_sort(arr, result, 0, 4);

    for (auto tmp: result)
        printf(" %d ", tmp);

    printf("\n");

    return 0;
}