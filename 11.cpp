class Solution {
public:
    int maxArea(vector<int>& height) {
  int size = height.size();
  int left = 0;
  int right = size-1;
  int result = 0;

  while(left < right)
    {
      result=max(result,(right-left) * min(height[left],height[right]));

      if(height[left] == height[right])
        {
          left++;
          right--;
        }
      else if(height[left] > height[right])
        {
          int temp = height[right];
          while(height[right] <= temp) right--;
        }
      else
        {
          int temp = height[left];
          while(height[left] <= temp) left++;
        }
    }
    return result;
    }
}; 
