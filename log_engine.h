#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include <unordered_map>
using namespace std;
struct Event {
    int timestamp;
    int user_id;
    std::string action;
};

class LogEngine {
    private:
        std::vector<int> timestamps;
        std::vector<int> active_prefix;
        std::unordered_map<int,bool> is_active;
        std::unordered_map<int,std::vector<int>> user_timestamps;

        int current_active = 0;
    
    public:
        void addEvent(int timestamp, int user_id, const std::string& action);
        int countActiveAt(int timestamp);
        int userRangeQuery(int user_id, int L, int R);
        int Sliding_Window(int k);
};