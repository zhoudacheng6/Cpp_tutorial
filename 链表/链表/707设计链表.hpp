#include<iostream>
#include <string>
using namespace std;

class MyLinkedList {
public:
	struct ListNode {
		int val;
		ListNode* next;
		//三组构造函数
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}  //前插
	};

    /** Initialize your data structure here. */
    MyLinkedList() {
        _dummyHead = new ListNode(0);// 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
   /* int get(int index) {
        if (index>(_size-1)|| index<0)
        {
            return -1;
        }
        ListNode* temp = _dummyHead->next;
        while (index--)
        {
            temp = temp->next;
        }
        return temp->val;
    }*/
	int get(int index) {
		if (index > (_size - 1) || index < 0) {
			return -1;
		}
        ListNode* cur = _dummyHead->next;
		while (index--) { // 如果--index 就会陷入死循环
			cur = cur->next;
		}
		return cur->val;
	}

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* temp = _dummyHead;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        _size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index >_size )
        {
            return;
        }
        ListNode* newNode = new ListNode(val);
        ListNode* temp = _dummyHead;
        while (index--)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        _size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index>=_size || index<0)
        {
            return;
        }
        ListNode* cur = _dummyHead;
		while (index--) {
			cur = cur->next;
		}
        ListNode* tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		_size--;
    }
private:
	int _size;
	ListNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */