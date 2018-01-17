class LRUCache {
    typedef list<pair<int,int>> List;
    int capacity;
    list<pair<int,int>> cachedata;
    unordered_map<int,List::iterator> cache;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.count(key)==0)return -1; //not in cache
        
        auto point = cache[key];//get pointer to cache data
        int val = point->second;//save value
        cachedata.erase(point);//del element
        cachedata.emplace_front(key,val);  //insert element in front
        cache.at(key) = cachedata.begin();//change pointer in cache
        return val;
    }
    
    void put(int key, int value) {
        if(cache.count(key)!=0)//key already present in cache
        {
            auto point = cache[key];//get pointer to cache data
            cachedata.erase(point);//del element
            cachedata.emplace_front(key,value);  //insert element in front
            cache.at(key)=cachedata.begin();//change pointer in cache
            return;
        }
        //key not in cache
        //check if exceeding cache capacity
        if(cachedata.size()==capacity){
            auto point = cachedata.back();//remove least recently used
            int keyd = point.first;
            cache.erase(keyd);
            cachedata.pop_back();
        }
        //add new data to cache and place it in front of list
        cachedata.emplace_front(key,value);
        cache.emplace(key,cachedata.begin());
    }
};

/**
 * LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
