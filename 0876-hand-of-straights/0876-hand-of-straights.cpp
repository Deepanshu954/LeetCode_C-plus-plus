class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        
        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        
        for (auto& [card, freq] : count) {
            while (freq > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (count[card + i] == 0) return false;
                    count[card + i]--;
                }
                freq = count[card];
            }
        }
        
        return true;
    }
};