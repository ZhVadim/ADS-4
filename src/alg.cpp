// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int coup = 0;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (arr[i] + arr[j] == value) {
                    coup += 1;
                }
            }
        }
    return coup;
}
int countPairs2(int* arr, int len, int value) {
    int coup = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] < 0) {
            i++;
        }
        if (arr[i] > value) {
            return coup;
        }
        for (int j = len - 1; j > i; j--) {
            if (arr[j] > value) {
                j--;
            }
            if (arr[i] + arr[j] == value) {
                coup += 1;
            }
        }
    }
    return coup;
}
int binSearch(int* arr, int len, int value, int kr) {
    int par = 0;
    int beg = kr, end = len - 1;
    while (beg < end - 1) {
        int mid = (beg + end) / 2;
        if (arr[mid] == value) {
            par += 1;
            if (arr[mid + 1] == value) {
                for (int i = mid + 1; arr[i] == value; i++) {
                    par += 1;
                }
            }
            if (arr[mid - 1] == value) {
                for (int i = mid - 1; arr[i] == value; i--) {
                    par += 1;
                }
            }
            return par;
        } else if (arr[mid] > value) {
            end = mid;
        } else {
            beg = mid;
        }
    }
    return 0;
}
int countPairs3(int* arr, int len, int value) {
    int coup = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] < 0) {
            i++;
        }
        if (i >= value) {
            return coup;
        } else {
            if (arr[i] <= value / 2) {
                coup += binSearch(arr, len, value - arr[i], i);
            }
        }
    }
    return coup;
}
