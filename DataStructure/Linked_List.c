#include <stdio.h>
#include <stdlib.h>

/* 链表节点结构 */
typedef struct ListNode {
    /*--------------数据域------------*/
    void * data             /* 数据域 */
    /*-------------指针域-------------*/
    struct ListNode *next; /* 指向下一个节点的指针 */
} ListNode;

/* 链表结构 */
typedef struct List {
    /* 节点信息 */
    ListNode *head; /* 头节点 */
    ListNode *tail; /* 尾节点 */
    int size; /* 节点大小 */
}

/* 初始化链表 */
void ListInit(ListNode *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/* 判断链表是否为空 */
bool ListIsEmpty(const List *list)
{
    return list->size;
}

/* 在链表头部插入一个节点 */
void ListPushFront(List *list, void *data) 
{
    /* 定义一个结构体指针,用malloc()赋予结构大小的内存的地址 */
    ListNode * node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    node->next = list->head; /* 将新节点的指域指向原链表中的第一个节点 */
    list->head = node; /* 将链表的head更新为新加入到头部的node的地址 */
    /* 如果这个链表一开始没有节点,则新加入的那个节点也是链表的最后一个节点,所以更新tail */
    if (list->tail == NULL) {
        list->tail = node; 
    }
    list->size++; /* 链表中的节点数量加一 */ 
}

/* 在链表尾部插入一个节点 */
void ListPushBack(List *list,void *data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL; /* 链表最尾部的节点的next指向NULL */
    /* 如果原先链表中没有一个节点，则把在链表的tail指向尾部插入的新节点的地址 */
    if (list->tail ==  NULL) {
        list->head = node;
    } else {
        list->tail->next = node; /* 把原链表最后一个节点的next指向尾部新插入的节点 */
    }
}

/* 删除链表头部的节点 */
void ListPopFront(List *list) {
    /* 判断链表是否没有节点 */
    if(ListIsEmpty(list)) {
        return;
    }

    ListNode *node = list->head; /*定义一个指针变量node,存放原先list的第一个节点的地址 */
    list->head = node->next; /* 把原先链表第二个节点的地址给链表的head */
    /* 如果原链表只有一个节点，则删除后head为NULL */
    if (list->head == NULL) {
        list->tail = NULL;
    }
    free(node); /* 把删除后的节点占用的内存释放掉 */
    list->size--; /* 链表节点数量减一 */
}

/* 删除链表尾部节点 */
void ListPopBack(List *list) {
    /* 判断链表是否没有节点 */
    if (ListIsEmpty(list)) {
        return;
    }
    /* 如果链表中只有一个节点 */
    if(list->head == list->tail) {
        ListPopFront(list);
        return;
    }
    /* 设置一个指针变量，先指向链表的第一个节点 */
    ListNode *prev = list->head;
    /* 进行迭代，是prev指针变量指向倒数第二个节点 */
    while (prev->next != list->tail) {
        prev = prev->next;
    }
    /* 使用free()释放掉最后一个节点所占用的内存 */
    free(list->tail);
    /* 链表的tail设置为倒数第二个节点 */
    list->tail = prev;
    /* 原链表倒数第二个节点的指针域设置为NULL */
    prev->next = NULL;
    /* 链表节点数量减少 */
    list->size--;
}

/* 在链表中查找指定数据的节点 */
ListNode *ListFind(const List *list, void *data) {
    /* list为需要查找的节点所在的链表的地址，data为要查找的数据的地址 */
    /* 定义一个指针变量，用于存放要查找的节点的地址 */
    ListNode *node = list->head;
    /* 从头开始查找，直到链表的末尾,如果找到就返回地址 */
    while (node != NULL) {
        if (node->data == data) {
            return node;
        }
        node = node->next; /* 迭代到下一个节点*/
    }
    /* list中没找到对应的节点 */
    return NULL;
}

/* 在链表中删除指定数据的节点 */
void ListRemove(List *list,void *data)
{   
    /* 设置指针变量node为链表节点第一个节点的地址 */
    ListNode *node = list->head;
    ListNode *prev = NULL;
    while (node != NULL) {
        if (node->data == data) {
            /* 如果链表只有一个节点，且为要查找的节点 */
            if (prev == NULL) {
                ListPopFront(list);
                return;
            }  else {
                /* 将要删除的节点的上一个节点的next指向要删除的节点的下一个节点 */
                prev->next = node->next;
                /* 如果删除的节点是链表的最后一个节点，则需要更新链表的tail */
                if (node == list->tail) {
                    list->tail = prev;
                }
            }
        }
        /* 如果没找到，则继续迭代，查看一下个节点 */
        prev = node;
        node = node->next;
    }
}

/* 释放链表 */
void ListDestroy(List *list)
{
    /* 如果链表中有节点，则进行释放 */
    while (!ListIsEmpty(list)) {
        ListPopFront(list);
    }
}
int main()
{
    /* 清屏 */
    system("cls");
    return 0;
}

