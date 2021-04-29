//
// Created by kongshui on 4/26/21.
//


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <map>

/*
假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
 每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组people 所表示的队列。返回的队列应该格式化为数组 queue ，
 其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
解释：
编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。

输入：people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
输出：[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]

 1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
题目数据确保队列可以被重建

 */

class Solution
{
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people)
    {
        std::sort(people.begin(), people.end(),
                  [](std::vector<int> &left, std::vector<int> &rigth)
                  { return (left[0] < rigth[0]) || (left[0] == rigth[0] && left[1] > rigth[1]); });

        std::vector<int>                vec_index;
        std::vector<std::vector<int>>   vec_result;

        for (int index = 0; index < people.size(); ++index)
            vec_index.emplace_back(index);

        for (int index = people.size()  - 1; index >= 0; --index)
        {
            int num = people[index][1];
            if (num && ((num + index) < people.size()))
            {
                int old                 = vec_index[index + num];
                vec_index[index + num]  = vec_index[index];

                for (int tmp = 0; tmp < num; ++tmp)
                {
                    if (tmp == (num - 1))
                        vec_index[index + tmp] = old;
                    else
                        vec_index[index + tmp] = vec_index[index + tmp + 1];
                }
            }
        }

        for (auto index:vec_index)
            vec_result.emplace_back(people[index]);

        return vec_result;
    }
};

int main()
{
    Solution tmp;

    // [[3,0],[6,0],[7,0],[5,2],[3,4],[5,3],[6,2],[2,7],[9,0],[1,9]]
    std::vector<std::vector<int>> people{{9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}};

    tmp.reconstructQueue(people);

    return 0;
}


