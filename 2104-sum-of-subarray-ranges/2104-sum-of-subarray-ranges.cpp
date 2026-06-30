class Solution {
public:

    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nextGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] >= arr[st.top()]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> prevGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& arr) {

        int n = arr.size();

        vector<int> prevSmall = prevSmaller(arr);
        vector<int> nextSmall = nextSmaller(arr);

        vector<int> prevGreat = prevGreater(arr);
        vector<int> nextGreat = nextGreater(arr);

        long long minSum = 0;
        long long maxSum = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - prevSmall[i];
            long long right = nextSmall[i] - i;

            minSum += 1LL * arr[i] * left * right;
        }

        for (int i = 0; i < n; i++) {

            long long left = i - prevGreat[i];
            long long right = nextGreat[i] - i;

            maxSum += 1LL * arr[i] * left * right;
        }

        return maxSum - minSum;
    }
};