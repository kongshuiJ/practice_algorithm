// Least Frequently Used
// TODO optimization

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <list>

template<typename key_t, typename value_t>
class Node
{
public:
    key_t   key;
    value_t value;
    int     fre;

    Node(key_t _key, value_t _val, int _fre) : key(_key), value(_val), fre(_fre) {}
};

template<typename key_t, typename value_t>
class LFUCache
{
private:
    typedef class    Node<key_t, value_t>                        node_t;
    typedef typename std::list<node_t>::iterator                 node_list_iter_t;
    typedef typename std::unordered_map<key_t, node_list_iter_t> key_node_map_t;
    typedef typename std::unordered_map<int, std::list<node_t>>  fre_list_map_t;

    int min_fre_     = {0};
    size_t max_size_ = {0};

    key_node_map_t key_map_;
    fre_list_map_t fre_map_;

public:
    LFUCache() = delete;

    explicit LFUCache(size_t max_size) : max_size_(max_size)
    {
        key_map_.clear();
        fre_map_.clear();
    }

    bool exist(const key_t &key)
    {
        return key_map_.count(key) > 0;
    }

    int moveNode(key_t &key, value_t &value, int fre)
    {
        auto node = key_map_[key];
        fre_map_[fre].erase(node);

        if (fre_map_[fre].size() == 0)
        {
            fre_map_.erase(fre);
            if (min_fre_ == fre) ++min_fre_;
        }

        int cur_fre   = fre + 1;
        fre_map_[cur_fre].push_front(node_t(key, value, cur_fre));
        key_map_[key] = fre_map_[cur_fre].begin();
    }

    key_t get(key_t key)
    {
        if (!max_size_ || !key_map_.count(key))
            throw std::range_error("There is no such key in cache");

        int fre       = key_map_[key]->fre;
        value_t value = key_map_[key]->value;
        moveNode(key, value, fre);

        return value;
    }

    void put(key_t key, value_t value)
    {
        if (!max_size_) return;

        if (key_map_.count(key) == 0)
        {
            if (key_map_.size() == max_size_)
            {
                key_map_.erase(fre_map_[min_fre_].back().key);
                fre_map_[min_fre_].pop_back();
                if (fre_map_[min_fre_].size() == 0)
                    fre_map_.erase(min_fre_);
            }

            min_fre_      = 1;
            fre_map_[min_fre_].push_front(node_t(key, value, 1));
            key_map_[key] = fre_map_[min_fre_].begin();

        } else
            moveNode(key, value, key_map_[key]->fre);
    }

    void traversePrint()
    {
        for (auto iter = key_map_.begin(); iter != key_map_.end(); iter++)
        {
            std::cout << "key: "     << iter->second->key
                      << ", value: " << iter->second->value
                      << ", fre: "   << iter->second->fre << std::endl;
        }
    }
};

int main()
{
    auto cache = new LFUCache<int, int>(2);
    cache->put(1, 10);
    cache->put(2, 11);
    cache->traversePrint();
    std::cout << cache->get(1) << std::endl;
    std::cout << cache->get(1) << std::endl;
    cache->get(2);
    cache->get(1);
    cache->get(2);

    cache->traversePrint();
    cache->put(3, 12);

    if (cache->exist(1)) std::cout << "1: " << cache->get(1) << std::endl;
    if (cache->exist(2)) std::cout << "2: " << cache->get(2) << std::endl;

    return 0;
}