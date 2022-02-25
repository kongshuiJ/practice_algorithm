#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

int length_of_LIS(const std::vector<int> &vec)
{
    std::vector<int> vec_nums(vec.size(), 1);
    std::cout << vec_nums.size() << std::endl;

    for (int idx = vec.size() - 1; idx >= 0; --idx)
    {
        for (int n = idx + 1; n < vec.size(); ++n)
        {
            if (vec[n] > vec[idx])
                vec_nums[idx] = std::max(vec_nums[idx], vec_nums[n] + 1);
        }
    }

    std::cout << "end" << std::endl;
    auto biggest = std::max_element(vec_nums.begin(), vec_nums.end());

    return *biggest;
}

int sub_list_maxsum(const std::vector<int> &vec)
{
    std::vector<int> vec_nums(vec);
    std::cout << vec_nums.size() << std::endl;

    for (int idx = vec.size() - 1; idx >= 0; --idx)
    {
        if (idx == vec.size() - 1)
            continue;

        vec_nums[idx] = std::max(vec_nums[idx], vec_nums[idx + 1] + vec[idx]);
    }

    std::cout << "end" << std::endl;
    auto biggest = std::max_element(vec_nums.begin(), vec_nums.end());

    return *biggest;
}

int main()
{
    const std::vector<int> vec = {1, 5, 2, 4, 3};
    std::cout << "max len: " << length_of_LIS(vec) << std::endl;

    const std::vector<int> vec1 = {3, -4, 2, -1, 2, 6, -5, 4};
    std::cout << "sub_list_maxsum: " << sub_list_maxsum(vec1) << std::endl;

}
