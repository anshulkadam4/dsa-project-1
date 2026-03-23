#include "log_engine.h"
int LogEngine::countActiveAt(int timestamp){
            int left=0;
            int right=timestamps.size()-1;

            while(left<=right){
                int mid=left+(right-left)/2;
                if(timestamps[mid]<timestamp){
                    left=mid+1;
                }
                else if (timestamps[mid]>timestamp){   
                    right=mid-1;
                }
                else{
                    return active_prefix[mid];
                }
            }
            if(right<0){
                return 0;
            }
            return active_prefix[right];
        }
int LogEngine::userRangeQuery(int user_id, int L, int R){
            if(user_timestamps.find(user_id)!=user_timestamps.end()){
                const auto&times=user_timestamps[user_id];
                auto left = lower_bound(times.begin(),times.end(),L);
                auto right = upper_bound(times.begin(),times.end(),R);
                return right-left;
            }
            else{
                return 0;
            }
        }
int LogEngine::Sliding_Window(int k){
            int left = 0;
            int mx=0;
            for(int right=0;right<timestamps.size();right++){
                while(timestamps[right] - timestamps[left]>k){
                    left++;
                }
                if(active_prefix[right]>mx){
                    mx=active_prefix[right];
                }
            }
            return mx;
        }
void LogEngine::addEvent(int timestamp, int user_id, const std::string& action) {
            if(action=="login"){
                if(!is_active[user_id]){
                    is_active[user_id]=true;
                    current_active++;
                }
            }
            else if (action=="logout"){
                if(is_active[user_id]){
                    is_active[user_id]=false;
                    current_active--;
                }
            }
            timestamps.push_back(timestamp);
            active_prefix.push_back(current_active);
            user_timestamps[user_id].push_back(timestamp);     
        }