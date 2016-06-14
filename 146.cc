

// Time Limit Exceeded
class LRUCacheData {
  public:
    int key;
    int val;
    LRUCacheData* next;
    LRUCacheData(int k, int v) : key(k), val(v), next(NULL) {}
};
class LRUCache{
  private:
    int cap;
    int size;
    LRUCacheData* dummy;
  public:
    LRUCache(int capacity) {
      cap = capacity;
      size = 0;
      dummy = new LRUCacheData(-1, -1);
    }

    int get(int key) {
      LRUCacheData* ptr = dummy;
      LRUCacheData* cur = dummy->next;
      while (cur) {
        if (cur->key == key) {
          ptr->next = cur->next;
          cur->next = dummy->next;
          dummy->next = cur;
          return cur->val;
        } else {
          ptr = cur;
          cur = cur->next;
        }
      }
      return -1;
    }

    void set(int key, int value) {
      if (size == cap) {
        LRUCacheData* ptr = dummy;
        while (ptr->next && ptr->next->next)
          ptr = ptr->next;
        delete ptr->next;
        ptr->next = NULL;
        ptr = new LRUCacheData(key, value);
        ptr->next = dummy->next;
        dummy->next = ptr;
      } else {
        LRUCacheData* ptr = new LRUCacheData(key, value);
        ptr->next = dummy->next;
        dummy->next = ptr;
        size++;
      }
    }
};
