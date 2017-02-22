bool find(int * matrix,int rows,int columns,int k)
{
  bool found = false;
  if(matrix == NULL || rows == 0 || columns == 0) return found;

  int row =  0;
  int column = columns-1;

  while(row < rows && column >= 0)
    {
      if(matrix[columns * row + column] == k)
        {
          found = true;
          break;
        }
      else if(matrix[columns * row + column ] < k)
        {
          row ++;
        }
      else
        {
          column --;

        }
    }
  return found;
}
