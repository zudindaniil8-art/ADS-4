// Copyright 2021 NNTU-CS

int countPairs1(int *array, int length, int target) {
    int counter = 0;

    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            int currentSum = array[i] + array[j];
            if (currentSum == target) {
                counter += 1;
            }
        }
    }
    return counter;
}

int countPairs2(int *array, int length, int target) {
    int left = 0;
    int right = length - 1;
    int counter = 0;

    while (left < right) {
        int currentSum = array[left] + array[right];

        if (currentSum == target) {
            if (array[left] == array[right]) {
                int amount = right - left + 1;
                counter += amount * (amount - 1) / 2;
                break;
            }

            int leftValue = array[left];
            int rightValue = array[right];

            int leftCount = 0;
            while (left <= right && array[left] == leftValue) {
                ++leftCount;
                ++left;
            }

            int rightCount = 0;
            while (right >= left && array[right] == rightValue) {
                ++rightCount;
                --right;
            }

            counter += leftCount * rightCount;

        } else if (currentSum < target) {
            ++left;
        } else {
            --right;
        }
    }

    return counter;
}

int countPairs3(int *array, int length, int target) {
    int counter = 0;

    for (int i = 0; i < length - 1; ++i) {
        if (i > 0 && array[i] == array[i - 1]) {
            continue;
        }

        int needed = target - array[i];
        if (needed < array[i]) {
            break;
        }

        int low = i + 1;
        int high = length - 1;
        int first = -1;

        while (low <= high) {
            int middle = low + (high - low) / 2;

            if (array[middle] == needed) {
                first = middle;
                high = middle - 1;
            } else if (array[middle] < needed) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }

        if (first == -1) {
            continue;
        }

        int last = first;
        low = first;
        high = length - 1;

        while (low <= high) {
            int middle = low + (high - low) / 2;

            if (array[middle] == needed) {
                last = middle;
                low = middle + 1;
            } else if (array[middle] < needed) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }

        if (array[i] == needed) {
            int segmentLength = last - i + 1;
            counter += segmentLength * (segmentLength - 1) / 2;
            break;
        }

        int leftCount = 1;
        while (i + leftCount < length && array[i + leftCount] == array[i]) {
            ++leftCount;
        }

        counter += leftCount * (last - first + 1);
    }

    return counter;
}
