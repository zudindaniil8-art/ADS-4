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
      while (left <= right && arr[left] == left_val) {
        ++left_count;
        ++left;
      }
      while (left <= right && arr[right] == right_val) {
        ++right_count;
        --right;
      }
      count += left_count * right_count;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}

int binarySearch(int *arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    if (i > 0 && arr[i] == arr[i - 1]) {
      continue;
    }
    int target = value - arr[i];
    if (target < arr[i]) {
      continue;
    }
    int index = binarySearch(arr, i + 1, len - 1, target);
    if (index != -1) {
      int cnt_i = 1;
      int cnt_j = 1;
      int k = i + 1;
      while (k < len && arr[k] == arr[i]) {
        ++cnt_i;
        ++k;
      }
      k = index + 1;
      while (k < len && arr[k] == target) {
        ++cnt_j;
        ++k;
      }
      if (arr[i] == target) {
        count += cnt_i * (cnt_i - 1) / 2;
      } else {
        count += cnt_i * cnt_j;
      }
      i += cnt_i - 1;
    }
  }
  return count;
}
