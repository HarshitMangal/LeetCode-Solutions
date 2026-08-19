import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] s) {

        int n = s.length;

        List<List<String>> ans = new ArrayList<>();

        HashMap<String, List<String>> mp = new HashMap<>();

        for (String it : s) {

            String temp = it;

            char[] arr = temp.toCharArray();

            Arrays.sort(arr);

            temp = new String(arr);

            if (!mp.containsKey(temp)) {
                mp.put(temp, new ArrayList<>());
            }

            mp.get(temp).add(it);
        }

        for (List<String> it : mp.values()) {
            ans.add(it);
        }

        return ans;
    }
}