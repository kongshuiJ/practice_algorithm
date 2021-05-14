//
// Created by kongshui on 5/14/21.
//

/*
 * 我们从数组中选择一个元素，我们把这个元素称之为中轴元素吧，然后把数组中所有小于中轴元素的元素放在其左边，
 * 所有大于或等于中轴元素的元素放在其右边，显然，此时中轴元素所处的位置的是有序的。也就是说，我们无需再移动中轴元素的位置。
 * 从中轴元素那里开始把大的数组切割成两个小的数组(两个数组都不包含中轴元素)，接着我们通过递归的方式，
 * 让中轴元素左边的数组和右边的数组也重复同样的操作，直到数组的大小为1，此时每个元素都处于有序的位置。
 */

#include <iostream>

void quick_sort(int *arr, int len)
{
    if ((arr == nullptr) || (len < 2))
        return;

    int start_index = 0;
    int tmp = 0;

    for (int index = start_index + 1; index < len; ++index)
    {
        if (arr[index] < arr[start_index])
        {
            tmp = arr[index];

            for (int idx = index; idx > start_index; --idx)
                arr[idx] = arr[idx - 1];

            arr[start_index] = tmp;
            start_index += (index - start_index - 1);
        }
    }

    quick_sort(arr, start_index);
    quick_sort(arr + start_index + 1, len - start_index - 1);
}

int main()
{
    int arr[9] = {6, 5, 4, 7, 3, 2, 22, 1, 9};
    quick_sort(arr, 9);

    printf("\nresult: ");
    for (auto tmp: arr)
        printf(" %d ", tmp);

    printf("\n");


    return 0;
}