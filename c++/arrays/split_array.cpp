class Solution {
public:
    // Logic
    //      dp  0  1  2  3  4  5  6  7  8  9  10  11
    // nums    "T" F  F  F  F  F  F  F  F  F  F   F
    //  1         "T"
    //  5                     "T""T"
    //  11                                       "T"
    //  5                                    "T"
    //  
    //  Effect of adding each number in terms of ability to
    //  build the "target" value.
    bool canPartition(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2) return false;
        target /= 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num: nums) {
            for (int i = target; i >= num; i--) {
                // It's only feasible for "i" greater than num
                dp[i] = dp[i] | dp[i - num];
                if (i == target && dp[i] == true) return true;
            }
        }
        return false;
    }

    // Recursive solution with memoization
    bool partitionMemoized(vector<int> &nums, int index, int runningSum, int target,
                          unordered_map<long long int, bool> &memoize) {
        long long int memKey = (((long long int) index) << 32) + (long long int) runningSum;
        auto it = memoize.find (memKey);
        if (it != memoize.end()) {
            return it->second;
        }
        if (runningSum == target) {
            memoize[memKey] = true;
            return true;
        }
        if (index == nums.size()) {
            memoize[memKey] = false;
            return false;
        }
        return partitionMemoized(nums, index + 1, runningSum, target, memoize) || 
            partitionMemoized(nums, index + 1, runningSum + nums[index], target, memoize);
    }
    
    bool canPartitionMemoized(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2) return false;
        target /= 2;
        // key = index << 32 + runningSum
        // value = bool
        unordered_map<long long int, bool> memoize;
        return partitionMemoized(nums, 0 /* index */, 0 /* sum */, target, memoize);
    }
    
    // Recursive solution based on power sets
    // Complexity: Time = O(n * (2 ^ n)), Space = O(n * (2 ^ n))
    bool canPartitionPowerSet(vector<int>& nums) {
       int size = (int) nums.size();
        if (size < 2) return false;
        
        // Step 1: Time = O(n), Space = O(1)
        // The sum must be even
        int sumTotal = accumulate(nums.begin(), nums.end(), 0);
        if (sumTotal % 2) return false;

        // Must find a list of numbers whose sum is sumTotal/2.
        vector<list<int>> powerSet;
        list<int> runningList;
        
        // Step 2: Time = O(n * (2 ^ n)), Space = O(n * (2 ^ n))
        getPowerSet(nums, 0 /* index */, runningList, powerSet, sumTotal/2);
        
        return (int) powerSet.size() > 0 ? true : false;
    }
    
    // Complexity: Time = , Space =
    void getPowerSet(vector<int> &nums, int runningIndex, 
                     list<int> runningList,
                     vector<list<int>> &powerSet, int targetSum) {
        if (runningIndex == nums.size()) {
            int sumList = accumulate(runningList.begin(), runningList.end(), 0);
            if (sumList == targetSum) {
                powerSet.push_back(runningList);
            }
            return;
        }
        // Recursive call without adding current number
        getPowerSet(nums, runningIndex + 1, runningList, powerSet, targetSum);
        
        // Recursive call adding current number
        runningList.push_back(nums[runningIndex]);
        getPowerSet(nums, runningIndex + 1, runningList, powerSet, targetSum);        
    }
    
    void printPowerList(list<int> &numList) {
        for (int num : numList) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    bool canPartitionNonReorder(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2) return false;
        target /= 2;

        int left = 0;
        int right = (int) nums.size() - 1;
        int sumLeft = 0, sumRight = 0;
        
        while (left < right) {
            sumLeft += nums[left];
            sumRight += nums[right];
            if (sumLeft < sumRight) {
                left++;
                // Avoid duplicate add in the next loop
                sumRight -= nums[right];
            } else if (sumLeft > sumRight) {
                right--;
                sumLeft -= nums[left];
            } else {
                if (right == left + 1) {
                    return true;
                } else {
                    left++;
                    right--;
                }
            }
        }
    
        return false;
    }
};
