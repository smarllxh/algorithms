#define MAX 1000000//计算最大子数组
#include<iostream>
using namespace std;
int cross_max_subbary(int a[],int low, int mid, int high){
  int left_sum=-MAX;
  int right_sum=-MAX;
  int sum=0;
  for(int i=mid;i>=low;i--){
    sum+=a[i];
    if(sum>left_sum) left_sum=sum;
  }
  sum=0;
  for(int j=mid+1;j<=high;j++){
    sum+=a[j];
    if(sum>right_sum) right_sum=sum;
  }
  return left_sum+right_sum;
}
int max_subarray(int a[],int low, int high){
  if(low==high) return a[low];
  else{
    int left_sum=-MAX;
    int right_sum=-MAX;
    int cross_sum=-MAX;
    int mid=(low+high)/2;
    left_sum=max_subarray(a,low,mid);
    right_sum=max_subarray(a,mid+1,high);
    cross_sum=cross_max_subbary(a,low,mid,high);
    int max=left_sum>right_sum? (left_sum>cross_sum?left_sum:cross_sum):(right_sum>cross_sum?right_sum:cross_sum);
    return max;
  }
}


int main(){

  int a[]={12,11,10,9,8,7,6,5,4,9,9,9};
  a[12]=MAX;
  quicksort(a,0,11);
  for(int i=0;i<13;i++){
    cout<<a[i]<<"\n";
  }
  //cout<<partition(a,0,4);
}
