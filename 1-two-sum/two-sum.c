#include <stdlib.h>

#define SIZE 20011

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* table[SIZE];

int hash(int key) {
    if (key < 0)
        key = -key;
    return key % SIZE;
}

void insert(int key, int value) {
    int idx = hash(key);

    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = table[idx];

    table[idx] = node;
}

Node* find(int key) {
    int idx = hash(key);

    Node* cur = table[idx];

    while (cur) {
        if (cur->key == key)
            return cur;
        cur = cur->next;
    }

    return NULL;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    for(int i=0;i<SIZE;i++)
        table[i]=NULL;

    int* ans = (int*)malloc(sizeof(int)*2);

    for(int i=0;i<numsSize;i++){

        int need = target - nums[i];

        Node* p = find(need);

        if(p){
            ans[0]=p->value;
            ans[1]=i;
            *returnSize=2;
            return ans;
        }

        insert(nums[i],i);
    }

    *returnSize=0;
    return NULL;
}