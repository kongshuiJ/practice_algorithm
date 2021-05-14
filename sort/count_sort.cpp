//
// Created by kongshui on 5/14/21.
//

/*
 * 计数排序是一种适合于最大值和最小值的差值不是不是很大的排序。
 * 基本思想：就是把数组元素作为数组的下标，然后用一个临时数组统计该元素出现的次数，
 * 例如 temp[i] = m, 表示元素 i 一共出现了 m 次。最后再把临时数组统计的数据从小到大汇总起来，
 * 此时汇总起来是数据是有序的。
 */

#include <iostream>
#include <string.h>
#include <memory>
#include <typeinfo>

void count_sort(int *arr, int len)
{
    if (arr == nullptr || len < 2)
        return;

    int max = arr[0];
    for (int index = 0; index < len; ++index)
    {
        if (max < arr[index])
            max = arr[index];
    }

    int new_arr_size = max + 1;
    std::shared_ptr<int> tmp(new int[new_arr_size], std::default_delete<int[]>());

    for (int index = 0; index < len; ++index)
        tmp.get()[arr[index]] += 1;

    int arr_index = 0;
    for (int index = 0; index < new_arr_size; ++index)
    {
        for (int idx = 0; idx < tmp.get()[index]; ++idx)
            arr[arr_index++] = index;
    }
}

int main()
{
    int arr[6] = {4, 5, 2, 2, 10, 122};

    count_sort(arr, 6);

    for (auto tmp: arr)
        printf(" %d ", tmp);

    printf("\n");

    return 0;
}