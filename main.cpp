#include <iostream>
#include "GroupLinking.h"

using namespace std;

int main() {
    GroupLinking groupLinking(299,599);
    cout<<"当前栈顶为"<<groupLinking.top()<<endl;
    int num=3;
    while (num--){
        groupLinking.remove(1);
        cout<<"当前栈顶为"<<groupLinking.top()<<endl;
    }
    int ids[5] = {700, 711, 703, 788, 701};
    for (int j = 0; j <5; ++j) {
        groupLinking.insert(ids[j]);
        cout<<"当前栈顶为"<<groupLinking.top()<<endl;
    }
}
