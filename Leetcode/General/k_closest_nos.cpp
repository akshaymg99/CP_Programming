/*
Problem link: https://leetcode.com/problems/find-k-closest-elements/
Finding k closest numbers to a given number
*/

class Solution {
private:
    long long int binary_search(vector<int>&arr, long long int l, long long int r, long long int ele) {
        if (r >= l) {
            long long int mid = l + (r-1) /2;
            if(arr[mid] == ele)
                return mid;
            
            if (arr[mid] > ele) 
                return binary_search(arr, l, mid-1, ele);
            else
                return binary_search(arr, mid+1, r, ele);
        }
        return -1;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        long long int n = arr.size();
        if (k >= n)
            return arr; 
        long long int index = binary_search(arr, 0, n-1, x);
        if (index == -1)
            return vector<int> (arr.begin(), arr.begin()+k);
        if (k == 1)
            return vector<int> (arr.begin()+index, arr.begin()+index+1);
        
        long long int left = index-1 >= 0 ? index-1 : 0; 
        long long int right = index+1 < n ? index+1 : n-1;;
        long long int window = right - left + 1;
        
        while (window < k) {
            if (abs(arr[left]-x) < abs(arr[right]-x) || ( abs(arr[left]-x) == abs(arr[right]-x) && arr[left] < arr[right]  ) ) {
                left --; 
            }
            else if (arr[left] > arr[right] || (abs(arr[left]-x) == abs(arr[right]-x) && arr[left] > arr[right]) ) {
                right ++;
            }
            window = right - left + 1;
            
        }
        
        vector<int> ans(arr.begin()+left, arr.begin()+right+1);
        return ans;
        
    }
};