#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
        int max = INT_MIN, max2= INT_MIN;
        vector <int> ans;
            
        for (int i=0; i<sizeOfArray; ++i) {
            if (arr[i] > max) 
                max = arr[i];
        }
        ans.push_back(max);
        
        for (int i =1; i< sizeOfArray; ++i) {
            if (arr[i] > max2 && arr[i] < max)
                max2 = arr[i];
        }
        
        if (max2 == INT_MIN)
            ans.push_back(-1);
        else 
            ans.push_back(max2);
        
        return ans;
    }
};

int main() {
    
    int testcases;
    cin >> testcases;

    while(testcases--){
        int sizeOfArray;
        cin >> sizeOfArray;
        
        int arr[sizeOfArray];
        
        for(int index = 0; index < sizeOfArray; index++){
            cin >> arr[index];
        }
        Solution obj;
        vector<int> ans = obj.largestAndSecondLargest(sizeOfArray, arr);
        cout<<ans[0]<<' '<<ans[1]<<endl;
    }
    
    return 0;
}  