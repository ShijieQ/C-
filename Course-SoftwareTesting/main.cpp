#include<iostream>

void printMax(int num, int array[]) {
    if (!num) {
        std::cout<<"This is no data."<<std::endl; 
    }
    else {
        int MAX = array[0];
        int ans = 0;
        for (int i = 2; i < num; i++) {
            if (MAX < array[i]) {
                MAX = array[i];
            }
        }
        for (int i = 0; i < num; i++) {
            if (array[i] == MAX) {
                ans++;
            }
        }
        std::cout<<"The maximum number is: "<<ans<<std::endl;
    }
}

int main() {
    int test1[] = {};
    int test2[] = {1, 2, 3};
    int test3[] = {1, 3, 2};
    int test4[] = {1, 2, 1};
    printMax(0, test1);
    printMax(3, test2);
    printMax(3, test3);
    printMax(3, test4);
    return 0;
}