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

//分治法计算x的n次幂，将O(n)降为O(logn)
long npower(int x,int n){
  long result;
  if(n==1) result=x;
  else{
    if(n%2==0){
      int temp=npower(x,n/2);
      result=temp*temp;
    }
    else {
      int temp=npower(x,(n-1)/2);
      result=temp*temp*x;
    }
}
  return result;
}
void swap(int a[],int m, int n){
  int temp=a[m];
  a[m]=a[n];
  a[n]=temp;
}
int partition(int a[],int low, int high){
     int left=low;
     int right=high;
     while (left<right) {
       while(a[left]<=a[low]) left++;
       while(a[right]>a[low])  right--;
       if(left<right){
       swap(a,left,right);cout<<left<<"left"<<right<<"right"<<"\n";
     }

   }
   swap(a,low,right);
   return right;

}

void quicksort(int a[],int low, int high){

  if(low<high){
    int mid=partition(a,low,high);//cout<<mid;
    quicksort(a,low,mid-1);
    quicksort(a,mid+1,high);
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
