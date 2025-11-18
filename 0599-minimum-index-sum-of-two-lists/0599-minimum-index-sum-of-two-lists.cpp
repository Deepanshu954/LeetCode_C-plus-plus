class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map1;
        for (int i = 0; i < list1.size(); i++) {
            map1[list1[i]] = i;
        }
        
        vector<string> result;
        int minSum = INT_MAX;
        
        for (int j = 0; j < list2.size(); j++) {
            if (map1.find(list2[j]) != map1.end()) {
                int sum = map1[list2[j]] + j;
                if (sum < minSum) {
                    minSum = sum;
                    result = {list2[j]};
                } else if (sum == minSum) {
                    result.push_back(list2[j]);
                }
            }
        }
        
        return result;
    }
};