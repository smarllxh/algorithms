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
