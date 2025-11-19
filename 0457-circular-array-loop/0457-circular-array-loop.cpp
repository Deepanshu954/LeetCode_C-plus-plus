class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            int slow = i, fast = i;
            bool isForward = nums[i] > 0;
            while (true) {
                slow = getNext(nums, slow, isForward);
                if (slow == -1) break;
                fast = getNext(nums, fast, isForward);
                if (fast == -1) break;
                fast = getNext(nums, fast, isForward);
                if (fast == -1) break;
                if (slow == fast) {
                    if (slow == getNext(nums, slow, isForward)) break;
                    return true;
                }
            }
            int j = i;
            int val = nums[j];
            while (val != 0 && (val > 0) == isForward) {
                int next = (j + val % n + n) % n;
                nums[j] = 0;
                j = next;
                val = nums[j];
            }
        }
        return false;
    }
    
    int getNext(vector<int>& nums, int i, bool isForward) {
        int n = nums.size();
        bool currDirection = nums[i] > 0;
        if (currDirection != isForward) return -1;
        int next = ((i + nums[i]) % n + n) % n;
        if (next == i) return -1;
        return next;
    }
};