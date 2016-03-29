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
