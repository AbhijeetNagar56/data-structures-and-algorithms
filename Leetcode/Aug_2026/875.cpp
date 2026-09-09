class Solution {
private:
    bool isValid(const std::vector<int>& piles, int s, int h) {
        long long time = 0;
        for (int pile : piles) {
            time += (pile + s - 1) / s;
            if (time > h) {
                return false;
            }
        }
        return true;
    }
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int low = 1;
        int high = *std::max_element(piles.begin(), piles.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};