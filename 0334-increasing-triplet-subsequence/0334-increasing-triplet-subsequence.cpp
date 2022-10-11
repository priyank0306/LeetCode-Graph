class Solution
{
    public:
        bool increasingTriplet(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> right(n, INT_MIN);
            vector<int> left(n, INT_MAX);
            left[0] = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                left[i] = min(nums[i], left[i - 1]);
            }
            right[n - 1] = nums[n - 1];
            for (int i = nums.size() - 2; i >= 0; i--)
            {
                right[i] = max(nums[i], right[i + 1]);
            }
            for (int i = 0; i < nums.size(); i++)
            {

                if (nums[i] > left[i] && nums[i] < right[i]) return true;
            }
            return false;
        }
};