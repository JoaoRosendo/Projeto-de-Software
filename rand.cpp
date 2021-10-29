#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

int main(){

    srand(time(NULL));
    
    int test1 = rand();
    int test2 = rand();
    int test3 = rand();
    cout << test1 << "\n" << test2 << "\n" << test3;
}