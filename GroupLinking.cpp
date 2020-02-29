//
// Created by Jae Liu on 2020/2/28.
//

#include "GroupLinking.h"
using namespace std;
GroupLinking::GroupLinking(){
    primaryFreeBlockGroup=new FreeBlockGroup();
    primaryFreeBlockGroup->count=0;
    primaryFreeBlockGroup->IDstack.push(0);
    primaryFreeBlockGroup->next=NULL;
}
GroupLinking::GroupLinking(int start, int end) {
    primaryFreeBlockGroup=new FreeBlockGroup();
    primaryFreeBlockGroup->count=0;
    primaryFreeBlockGroup->IDstack.push(0);
    primaryFreeBlockGroup->next=NULL;
    for (int i =end; i>=start; --i) {
        this->insert(i);
    }
}
GroupLinking::~GroupLinking() {
    FreeBlockGroup *tmp=NULL;
    while(primaryFreeBlockGroup->next!=NULL){
        tmp=primaryFreeBlockGroup->next;
        delete primaryFreeBlockGroup;
        primaryFreeBlockGroup=tmp;
    }
    delete primaryFreeBlockGroup;
}
void GroupLinking::insert(int blockId) {
    //空闲盘块好栈满时
    if (isFull()) {
        FreeBlockGroup *tmp = primaryFreeBlockGroup;
        primaryFreeBlockGroup = new FreeBlockGroup();
        primaryFreeBlockGroup->next = tmp;
    }
    primaryFreeBlockGroup->IDstack.push(blockId);
    primaryFreeBlockGroup->count++;
}
bool GroupLinking::remove(int num) {
    while(num--){
        //没有空闲盘块
        if(primaryFreeBlockGroup->IDstack.top()==0)return false;
        //当前空闲盘块栈为空，但有剩余空间
        if(primaryFreeBlockGroup->count==1&&primaryFreeBlockGroup->next!=NULL){
            FreeBlockGroup *tmp=primaryFreeBlockGroup->next;
            cout<<"BlockID:"<<primaryFreeBlockGroup->IDstack.top()<<" 被取用"<<endl;
            delete primaryFreeBlockGroup;
            primaryFreeBlockGroup=tmp;
        }else{
            //当前栈非空
            cout<<"BlockID:"<<primaryFreeBlockGroup->IDstack.top()<<" 被取用"<<endl;
            primaryFreeBlockGroup->IDstack.pop();
            primaryFreeBlockGroup->count--;
        }
    }
    return true;
}