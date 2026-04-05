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
      int leftVal = arr[left];
      int rightVal = arr[right];
      if (leftVal == rightVal) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int leftCount = 0;
      int rightCount = 0;
      while (left <= right && arr[left] == leftVal) {
        ++leftCount;
        ++left;
      }
      while (left <= right && arr[right] == rightVal) {
        ++rightCount;
        --right;
      }
      count += leftCount * rightCount;
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
    // Бинарный поиск только для элементов после i
    int low = i + 1;
    int high = len - 1;
    int first = -1;
    // Находим первое вхождение target
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == target) {
        first = mid;
        high = mid - 1;
      } else if (arr[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    if (first != -1) {
      // Находим последнее вхождение target
      low = first;
      high = len - 1;
      int last = first;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
          last = mid;
          low = mid + 1;
        } else if (arr[mid] < target) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      count += (last - first + 1);
      i = last; // Пропускаем обработанные элементы
    }
  }
  return count;
}
