class Solution {
    public int maxDifference(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        for (char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        int odd = 0, even = Integer.MAX_VALUE;
        for (char it : mp.keySet()) {
            int freq = mp.get(it);
            if (freq % 2 != 0)
                odd = Math.max(odd, freq);
            else
                even = Math.min(even, freq);
        }
        return odd - even;
    }
}