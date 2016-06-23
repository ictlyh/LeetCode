int majorityElement(vector<int>& nums) {
  sort(nums.begin(),nums.end());
  return nums[nums.size()/2];
}

int majorityElement(vector<int>& nums) {
  int majority = 0;
  for (int counter = 0, i = 0; i < nums.size(); i += 2) {
    if (i + 1 >= nums.size()) {
      if (counter) {
        return majority;
      } else {
        return nums[i];
      }
    }
    if (nums[i] != nums[i + 1]) {
      continue;
    }
    if (!counter) {
      majority = nums[i];
      counter = 1;
      continue;
    }
    if (nums[i] == majority) {
      ++counter;
    } else {
      --counter;
    }
  }
  return majority;
}
int majorityElement(int* nums, int numsSize) {
    int cnt = 1;
    int major = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(nums[i] == major) cnt++;
        else if(cnt == 0){
            major = nums[i];
            cnt++;
       }
       else
           cnt--;
    }
    return major;
}
