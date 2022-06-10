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
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; i++) {
        int nach = i; int kon = len;
        while (nach < kon - 1) {
            int sr = (nach + kon) / 2;
            if (arr[i] + arr[sr] == value) {
                count += 1;
                int b = sr + 1;
                while ((arr[i] + arr[b] == value) && (b < kon)) {
                    count += 1;
                    b += 1;
                }
                b = sr - 1;
                while ((arr[i] + arr[b] == value) && (b > nach)) {
                    count += 1;
                    b -= 1;
        }
                break;
    }
            if (arr[i] + arr[sr] > value)
                kon = sr;
            else
                nach = sr;
        }
    }
    return count;
}
