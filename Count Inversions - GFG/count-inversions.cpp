// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    long long merge(long long arr[], long long temp[], int left, int mid, int right) {
        int i, j, k;
        i = left;
        j = mid;
        k = left;
        long long inv_count = 0;
        while(i <= mid-1 && j <= right) {
            if(arr[i] <= arr[j]) {
                temp[k] = arr[i];
                k++;
                i++;
            }
            else {
                temp[k] = arr[j];
                k++;
                j++;
                inv_count = inv_count + (long long)(mid-i);
            }
        }
        
        while(i  <= mid -1) {
            temp[k] = arr[i];
            k++;
            i++;
        }
        
        while(j <= right) {
            temp[k] = arr[j];
            k++;
            j++;
        }
        
        for(i = left; i <= right; i++)
            arr[i] = temp[i];
            
        return inv_count;
    }
    
   
    long long int _mergeSort(long long arr[], long long temp[], int low, int high) {
        long long inv_count = 0;
        if(low < high) {
        int mid = (low + high)/2;
            inv_count += _mergeSort(arr,temp, low, mid);
            inv_count += _mergeSort(arr, temp, mid+1, high);
            inv_count += merge(arr, temp,low, mid+1, high);
        }
        return inv_count;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        long long int temp[(int)N];
        return _mergeSort(arr, temp, 0, (int)N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends