//
// Created by Jae Liu on 2020/2/28.
//

#ifndef GROUPLINKINGSIMULATOR_GROUPLINKING_H
#define GROUPLINKINGSIMULATOR_GROUPLINKING_H

#include <iostream>
#include <stack>

using namespace std;

class GroupLinking {
private:
    struct FreeBlockGroup {
        stack<int> IDstack;
        int count;
        FreeBlockGroup *next;

        FreeBlockGroup() {
            this->count = 0;
            this->next = NULL;
        }
    };
    FreeBlockGroup *primaryFreeBlockGroup;//空闲盘块号栈
public:
    GroupLinking();
    GroupLinking(int start,int end);
    ~GroupLinking();

    bool isFull() { return primaryFreeBlockGroup->IDstack.size() == 100; }

    void insert(int blockId);//插入空闲块，释放硬盘空间
    bool remove(int num);//取出空闲块，取用硬盘空间
    int top(){ return primaryFreeBlockGroup->IDstack.top();}
};
#endif //GROUPLINKINGSIMULATOR_GROUPLINKING_H
