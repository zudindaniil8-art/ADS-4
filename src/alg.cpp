// Copyright 2021 NNTU-CS
#include <algorithm>

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
  // Создаем копию массива и сортируем её
  int *sortedArr = new int[len];
  for (int i = 0; i < len; ++i) {
    sortedArr[i] = arr[i];
  }
  
  // Сортировка пузырьком (простая, но работает)
  for (int i = 0; i < len - 1; ++i) {
    for (int j = 0; j < len - i - 1; ++j) {
      if (sortedArr[j] > sortedArr[j + 1]) {
        int temp = sortedArr[j];
        sortedArr[j] = sortedArr[j + 1];
        sortedArr[j + 1] = temp;
      }
    }
  }
  
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = sortedArr[left] + sortedArr[right];
    if (sum == value) {
      int leftVal = sortedArr[left];
      int rightVal = sortedArr[right];
      if (leftVal == rightVal) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int leftCount = 0;
      int rightCount = 0;
      while (left <= right && sortedArr[left] == leftVal) {
        ++leftCount;
        ++left;
      }
      while (left <= right && sortedArr[right] == rightVal) {
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
  
  delete[] sortedArr;
  return count;
}

int countPairs3(int *arr, int len, int value) {
  // Создаем копию массива и сортируем её
  int *sortedArr = new int[len];
  for (int i = 0; i < len; ++i) {
    sortedArr[i] = arr[i];
  }
  
  // Сортировка пузырьком
  for (int i = 0; i < len - 1; ++i) {
    for (int j = 0; j < len - i - 1; ++j) {
      if (sortedArr[j] > sortedArr[j + 1]) {
        int temp = sortedArr[j];
        sortedArr[j] = sortedArr[j + 1];
        sortedArr[j + 1] = temp;
      }
    }
  }
  
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - sortedArr[i];
    // Бинарный поиск с подсчетом всех вхождений
    int left = i + 1;
    int right = len - 1;
    int firstPos = -1;
    
    // Находим первое вхождение target
    while (left <= right) {
      int mid = (left + right) / 2;
      if (sortedArr[mid] == target) {
        firstPos = mid;
        right = mid - 1;
      } else if (sortedArr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    
    // Если нашли, считаем количество вхождений
    if (firstPos != -1) {
      int lastPos = firstPos;
      while (lastPos + 1 < len && sortedArr[lastPos + 1] == target) {
        ++lastPos;
      }
      count += (lastPos - firstPos + 1);
    }
  }
  
  delete[] sortedArr;
  return count;
}
