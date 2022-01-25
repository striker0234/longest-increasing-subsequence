#include<bits/stdc++.h>
using namespace std;
int lis(int arr[],int n){
    vector<int>seq;
    seq.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(seq.back()<arr[i]){
            seq.push_back(arr[i]);
        }else{
            int index=lower_bound(seq.begin(),seq.end(),arr[i])-seq.begin();
            seq[index]=arr[i];
        }
    }
    return seq.size();
}
int main(){
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lis(arr,n)<<endl;
    }