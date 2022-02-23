// Least Recently Used

#include <iostream>
#include <unordered_map>
#include <list>
#include <cstddef>
#include <stdexcept>

template<typename key_t, typename value_t>
class LRUCache
{
public:
    typedef typename std::pair<key_t, value_t>           key_value_pair;
    typedef typename std::list<key_value_pair>::iterator list_iter;

private:
    size_t                               max_size_;
    std::list<key_value_pair>            items_list_;
    std::unordered_map<key_t, list_iter> items_map_;

public:
    LRUCache() = delete;
    LRUCache(size_t max_size) : max_size_(max_size) {}

    void put(const key_t &key, const value_t & value)
    {
        // 1. Insert key to head
        items_list_.push_front(key_value_pair(key, value));

        // 2. Delete key if key exist
        auto iter = items_map_.find(key);
        if(iter != items_map_.end())
        {
            items_list_.erase(iter->second);
            items_map_.erase(iter);
        }

        // 3. Link list and map
        items_map_[key] = items_list_.begin();

        // 4. Pop back if current size > size threshold
        if(items_map_.size() > max_size_)
        {
            auto last = --items_list_.end();
            if(last != items_list_.end())
            {
                items_map_.erase(last->first);
                items_list_.pop_back();
            }
        }
    }

    // exists() before get()
    const value_t &get(const key_t &key)
    {
        auto iter = items_map_.find(key);
        if (iter == items_map_.end())
            throw std::range_error("There is no such key in cache");
        else
        {
            items_list_.splice(items_list_.begin(), items_list_, iter->second);
            return iter->second->second;
        }
    }

    bool exist(const key_t &key) const { return items_map_.find(key) != items_map_.end(); }

    size_t size() const { return items_map_.size(); }

    void traversePrint()
    {
        std::cout << "cache size: " << size() << std::endl;

        for (auto iter = items_list_.begin(); iter != items_list_.end(); ++iter)
            std::cout << iter->first << ", " << iter->second << std::endl;
    }

};

int main()
{
    constexpr int max_size = 5;

    LRUCache<std::string, int> cache(max_size);

    for(int idx = 0; idx < max_size;++idx)
        cache.put("key_" + std::to_string(idx), idx);

    std::cout << "1 Print:" << std::endl;
    cache.traversePrint();

    cache.put("put_key", 1);
    std::cout << "2 Print:" << std::endl;
    cache.traversePrint();

    cache.put("key_2", 1);
    std::cout << "3 Print:" << std::endl;
    cache.traversePrint();

    if (cache.exist("key_3"))
        cache.get("key_3");
    std::cout << "4 Print:" << std::endl;
    cache.traversePrint();

    return 0;
}