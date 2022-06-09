// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] >= value / 2) {
            return count;
        }
        for (int j = len - 1; j > i; j--) {
            if (arr[j] > value) {
                j--;
            }
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] >= value / 2) {
            return count;
        } else if (arr[i] < value / 2) {
            int nach = i, kon = len - 1;
            while (nach < kon - 1) {
                int ser = (nach + kon) / 2;
                if (arr[ser] == value - arr[i]) {
                    count += 1;
                    for (int j = ser + 1; arr[j] + arr[i] == value; j++) {
                        if (j < kon) {
                            count += 1;
                        }
                    }
                    for (int h = ser - 1; arr[h] + arr[i] == value; h--) {
                        if (h >= nach) {
                            count += 1;
                        }
                    }
                    break;
                } else if (arr[ser] > value - arr[i]) {
                    kon = ser - 1;
                } else {
                    nach = ser + 1;
                }
            }
        }
    }
    return count;
}
