#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int thirdLargest(int arr[], int n)
    {
        int index = 0;
         if (n < 3) {
             return -1;
         }
         else {
             int max;
             
             for (int times=0; times<3; times++) {
                 for (int i=0; i<n; ++i) {
                     if (arr[i] > arr[index]) {
                         max = arr[i];
                         index = i;
                      }
                 }  
                arr[index] = -1;
             }
             
             return max;
         }
    }

};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin > >n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
       Solution obj;
        cout << obj.thirdLargest(a,n)<< endl;
    }
}    