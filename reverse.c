#include <stdio.h>

typedef int element;

typedef struct ListNode {				//����ü ListNode ����
	element data;						// data ���� ����
	struct ListNode* link;				// �ּҸ� ������ ��ũ ���� ����
}ListNode;

void error(const char* message) {	// ���� �� �� �޽��� ��� �Լ� ����
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {		// ��ũ�� ù ��° ��ġ�� �� �ִ� �Լ� ����
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		// ����ü���� p�� ���� ��, ���� �Ҵ�
	p->data = value;		// value�� ���� p�� data ������ ����
	p->link = head;			// ��� ������ ���� ��, ��� ������ ���� �����Ͽ� ����
	head = p;				// ���� ��带 ��� ������(ù��° ���)�� ����
	return head;
}

ListNode* insert_last(ListNode* head, element value) {		// ��ũ�� ������ ��ġ�� �� �ִ� �Լ� ����
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		// ����ü���� p ������ ���� ��, ���� �Ҵ�
	p = head;					// ���� ��带 ��� ����Ʈ�� ����
	while (p->link != NULL) {   // ������ ��ũ ã��, NULL���� ��ũ�� �ޱ���� �ݺ��Ͽ� ��ũ ����
		p = p->link;
	}
	ListNode* lastnode = (ListNode*)malloc(sizeof(ListNode)); // ����ü���� lastnode ���ο� ������ ���� ��, ���� �Ҵ�
	lastnode->data = value;		// lastnode�� data ������ �� ����
	lastnode->link = p ->link;	// link�� NULL�� �����Ͽ� ��ũ ����Ʈ �ϼ�, p -> link == NULL
	p->link = lastnode;			// p�� ��ũ�� lastnode �ּҰ��� ���� 

	return head;
}

ListNode* delete_last(ListNode* head) { // ������ ��� �����ϴ� �Լ� ���� , 4->3->2->1->0->10->NULL
	ListNode* pre;						// �����ϱ� �� ��� �ּ� ����
	ListNode* removed;					// ���� �� ��� �ּ� ����
	pre = head;
	removed = head;						// removed�� ��� ����Ʈ �� ����
	if (head == NULL) return NULL;		// ����Ʈ�� ��尡 ���� ��� NULL ȣ��
	while (removed->link != NULL) { // ������ ��ũ �ּ� ã��, removed�� ��ũ �ּҰ� NULL�� ���� ������ �ݺ�
			pre = removed;				// ������ ��� - 1 ��ġ, pre�� removed �� ����
			removed = removed->link;	// ���� ��ũ�� �Ѿ�� �ݺ�
		}
		pre->link = NULL;		// pre link�� NULL������ ���� , removed -> link = XX NULL XX
		free(removed);			// ������ ����Ʈ�� removed ����
			
		return head;			// ����� ��ȯ
}

ListNode* search_list(ListNode* head, element value) {		// Ư�� ���� �˻��ϴ� �Լ� ����
	ListNode* p = head;			// ��� ������ �� ����
	while (p != NULL) {			// NULL���� ã�� ������ �ݺ�
		if (p->data == value) {		// p�� ������ ���� value�� ���� ��
			return p;				// p�� ��ȯ
		}
		p = p->link;				// ���� value�� �ٸ� �� ���� ��ũ�� �Ѿ�� �ݺ�
	}
	return NULL;					// �˻� ������ �� NULL�� ��ȯ
}

ListNode* reverse_list(ListNode* head) { // ���� ��� �Լ�, 4->3->2->1->0->NULL
	ListNode* p, * q, * r;		//��ȸ �����͸� p,q,r�� ���
	p = head;		//p �� �������� ���� ������ ����Ʈ, p = ��� ������ �� ����
	q = NULL;		//q �� �������� ���� ������ ���, q = NULL��
	while (p != NULL) {		// p�� NULL���� ã�� ������ �ݺ�
		r = q;		// r �� �������� �� ����Ʈ.
		q = p;		// q = p�� ���� �޴� ���� ���
		p = p->link; // ���� ��ũ�� �ּҸ� ���������� ����
		q->link = r; // q �� ��ũ�� r���� ����Ŵ���ν� ������ �ٲ�
	}
	return q;
}

void print_list(ListNode* head) {		// ���� ����Ʈ�� ���� ����ϴ� ��
	for (ListNode* p = head; p != NULL; p = p->link)  // ���� ����Ʈ�� head���� NULL���� ���� ������ �ݺ��Ͽ� link�� ���� ���� ����Ʈ�� �̵��Ͽ� ���
		printf("%d->", p->data);		// p�� data���� ���
	printf("NULL \n");					// �������� NULL���� ���
}

void start() {
	ListNode* head = NULL;		//����ü head ����, ��尡 �����Ƿ� head�� ���� NULL
	ListNode* head2 = NULL;		//����ü head2 ����, ��尡 �����Ƿ� head2�� ���� NULL
	printf("Insert First !\n");

	for (int i = 0; i < 5; i++) {		// for �ݺ����� �̿��Ͽ� 0���� 5���� insert_first�� �� �ֱ�
		head = insert_first(head, i);
		print_list(head);				// for�� i�� �̿��ؼ� ListNode ����ü ���
	}

	printf("\nInsert Last !\n");
	head = insert_last(head, 10); print_list(head);	// insert_last �Լ��� ȣ���ϰ�, 5���� �Է� �� ���

	printf("\nDelete Last !\n");
	head = delete_last(head); print_list(head);		// delete_last �Լ��� ȣ���ϰ�, ���

	printf("\nSearch !\n");
	if (search_list(head, 0) != NULL)			// search_list �Լ��� ȣ���ϰ�, ����Ʈ���� 0�� ���� �� ����� ���
		printf("����Ʈ���� 0�� ã�ҽ��ϴ�.\n");
	else										// search_list �Լ��� ȣ���ϰ�, ����Ʈ���� 0�� ���� �� ����� ���
		printf("����Ʈ���� 0�� ã�� ���߽��ϴ�.\n");

	printf("\nReverse !\n");
	head2 = reverse_list(head); print_list(head2);	// ����ü head2�� ���� head�� ��������� reverse_list �Լ��� ȣ���� �� ���
}

int main(void) {
	start();
	return 0;
}