// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int left_val = arr[left];
      int right_val = arr[right];
      int left_count = 0;
      int right_count = 0;
      int l = left;
      int r = right;
      while (l <= r && arr[l] == left_val) {
        ++left_count;
        ++l;
      }
      while (l <= r && arr[r] == right_val) {
        ++right_count;
        --r;
      }
      count += left_count * right_count;
      left = l;
      right = r;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    int pos = -1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] == target) {
        pos = mid;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (pos != -1) {
      int left_count = 1;
      int j = i + 1;
      while (j < len && arr[j] == arr[i]) {
        ++left_count;
        ++j;
      }
      int right_count = 1;
      j = pos - 1;
      while (j > i && arr[j] == target) {
        ++right_count;
        --j;
      }
      j = pos + 1;
      while (j < len && arr[j] == target) {
        ++right_count;
        ++j;
      }
      if (arr[i] == target) {
        count += left_count * (left_count - 1) / 2;
      } else {
        count += left_count * right_count;
      }
      i += left_count - 1;
    }
  }
  return count;
}
