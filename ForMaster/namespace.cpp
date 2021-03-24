#include<iostream>

using namespace std;

namespace one {
    int a = 0;
    int b = 0;
}

namespace two {
    int a = 1;
    int b = 1;
}

using namespace one;
// using namespace two;

int main() {
    using two::a;
    a = -100;
    // cout<<b<<endl;
    cout<<a<<endl;
    cout<<one::a<<endl;
    return 0;
}