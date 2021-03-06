#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};
ListNode* CreatNode(int nValue){
	ListNode* pNode = new ListNode();
	pNode->m_nValue = nValue;
	pNode->m_pNext = NULL;
	return pNode;
}
void ConnectNode(ListNode* node1, ListNode* node2){
	if (node1 == NULL){
		printf("error");
		exit(1);
	}
	node1->m_pNext = node2;
}
void printList(ListNode* node){
	printf("print start\n");
	if (node == NULL){
		return;
	}
	//ListNode* pTestNode = new ListNode();
	//pTestNode->m_nValue = 1;
	//pTestNode->m_pNext = NULL;
	while (node != NULL){
		printf("%d\t", node->m_nValue);
		node = node->m_pNext;
	}
	printf("\n");
}
void Destroy(ListNode* node){
	while (node != NULL){
		ListNode* pNode = node;
		node = node->m_pNext;
		delete pNode;
		pNode = node;
	}
}
ListNode *Test(ListNode* head, unsigned int k){
	if (head==NULL || k==0){
		return 0;
	}
	printList(head);
	ListNode* p1 = head;
	ListNode* p2 = head;
	for (int i = 0; i < k-1; i++){
		if (p2->m_pNext == NULL)
			return 0;
		p2 = p2->m_pNext;
	}
	while (p2->m_pNext != NULL){
		p1 = p1->m_pNext;
		p2 = p2->m_pNext;
	}
	return p1;
	//printList(head);
	//Destroy(*head);
	//printList_iteratively(node);
	//printList_recursively(node);
}
void Test1(){
	printf("test1 is running\n");
	ListNode* node1 = CreatNode(1);
	ListNode* node2 = CreatNode(2);
	ListNode* node3 = CreatNode(3);
	ListNode* node4 = CreatNode(4);
	ListNode* node5 = CreatNode(5);
	ListNode* node6 = CreatNode(6);
	ListNode* node7 = CreatNode(7);
	ConnectNode(node1, node2);
	ConnectNode(node2, node3);
	ConnectNode(node3, node4);
	ConnectNode(node4, node5);
	ConnectNode(node5, node6);
	ConnectNode(node6, node7);
	ListNode *result = Test(node1,7);
	printf("%d\t", result->m_nValue);
	Destroy(node1);
}
int main(int argc, char* argv[]){
	Test1();
	int n;
	cin >> n;
	return 0;
}