
#include <bits/stdc++.h>
using namespace std;

// Separate Chaining in Hashing
class Solution{
  public:
    //Complete this function
    //Function to insert elements of array in the hashTable avoiding collisions.
    vector<vector<int>> separateChaining(int hashSize,int arr[],int sizeOfArray)
    {
        vector<vector<int>> hm;
        int maxHash=0;
        for(int i=0;i<sizeOfArray;i++){
           int k=arr[i]%hashSize;
           if(maxHash<k)maxHash=k;
        }
        for(int i=0;i<=maxHash;i++){
                vector<int>v;
                hm.push_back(v);  
        }
      	for(int i=0;i<sizeOfArray;i++){
          int k=arr[i]%hashSize;
          hm[k].push_back(arr[i]);
      	}
       return hm;  
    }
};


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    Solution obj;
	    vector<vector<int>> hashTable;
	    hashTable = obj.separateChaining( hashSize, arr, sizeOfArray);   
	    for(int i=0;i<hashTable.size();i++)
	    {
	        if(hashTable[i].size()>0)
	        {
	            cout<<i<<"->";
	            for(int j=0;j<hashTable[i].size()-1;j++)
	            {
	                cout<<hashTable[i][j]<<"->";
	            }
	            cout<<hashTable[i][hashTable[i].size()-1];
	            cout<<endl;
	        }
	    }    
	}
	return 0;
};