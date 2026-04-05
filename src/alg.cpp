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
      } else {
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
      }
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}

int binary_search(int *arr, int left, int right, int target) {
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
    int pos = binary_search(arr, i + 1, len - 1, target);
    if (pos != -1) {
      int left_count = 1;
      int right_count = 1;
      int j = i + 1;
      while (j < len && arr[j] == arr[i]) {
        ++left_count;
        ++j;
      }
      j = pos;
      while (j - 1 > i && arr[j - 1] == target) {
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
        i += left_count - 1;
      } else {
        count += left_count * right_count;
      }
    }
  }
  return count;
}
