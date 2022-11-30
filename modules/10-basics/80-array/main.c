int sum(int *arr, int length)
{
  // BEGIN (write your solution here)
  int result = 0;
  for(int i = 0; i < length; i++)
  {
    result += arr[i];
  }
  return result;
  //END
}
