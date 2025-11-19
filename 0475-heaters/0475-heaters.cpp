class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        
        for (int house : houses) {
            int pos = lower_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int minDist = INT_MAX;
            
            if (pos > 0) {
                minDist = min(minDist, house - heaters[pos - 1]);
            }
            if (pos < heaters.size()) {
                minDist = min(minDist, heaters[pos] - house);
            }
            radius = max(radius, minDist);
        }
        return radius;
    }
};