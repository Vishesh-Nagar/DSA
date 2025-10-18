class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int a = nums[i];
            int b = target - a;
            if (mp.containsKey(b)) {
                ans[0] = i;
                ans[1] = mp.get(b);
                return ans;
            }
            mp.put(a, i);
        }
        return new int[] {};
    }
}