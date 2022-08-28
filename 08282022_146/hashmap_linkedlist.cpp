class LRUCache {
private:
    int m_capacity;
    unordered_map<int, list<pair<int, int>>::iterator> m_map;
    list<pair<int,int>> m_list;
    
public:
    LRUCache(int capacity): m_capacity(capacity) {}
    
    int get(int key) 
    {
        if (m_map.find(key) == m_map.end()) return -1;
        // If key is in the map, then need to move the node to the very beginning
        // 2nd usage of m_slice from Cpp reference: void splice( const_iterator pos, list& other, const_iterator it ); Transfers the element pointed to by it from other into *this. The element is inserted before the element pointed to by pos.
        m_list.splice(m_list.begin(), m_list, m_map[key]);
        return m_map[key]->second;
    }

    void put(int key, int value) 
    {
        // If key already exists, calling get function will automatically put the refered node in the beginning, then we only need to update its value
        if (get(key) != -1) 
        {
            m_map[key]->second = value;
            return;
        }
        
        // If reach capacity, then delete last used element using pop_back. Also remove it from the unordered map
        if(m_map.size() == m_capacity) 
        {
            int key2Del = m_list.back().first;
            m_list.pop_back();
            m_map.erase(key2Del);
        }
        
        // Insert new key value pair
        m_list.emplace_front(key, value);
        m_map[key] = m_list.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
