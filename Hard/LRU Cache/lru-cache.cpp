//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
    list<pair<int, int>> cache; //you can use Deque 
    unordered_map<int, list<pair<int, int>>::iterator> mymap;

    void updateRecent(int key, int value)
    {
        cache.erase(mymap[key]);
        cache.push_front(make_pair(key, value));
        mymap[key] = cache.begin();
    }

    int capacity;

public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->capacity = cap;
    }

    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if (mymap.find(key) != mymap.end())
        {
            updateRecent(key, (*mymap[key]).second);
            return (*mymap[key]).second; 
        }
        return -1;
    }

    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if (mymap.find(key) != mymap.end())
        {
            updateRecent(key, value);
        }
        else
        {
            if (mymap.size() >= capacity)
            {
                mymap.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            mymap[key] = cache.begin();
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends