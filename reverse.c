#include <stdio.h>

typedef int element;

typedef struct ListNode {				//구조체 ListNode 정의
	element data;						// data 변수 선언
	struct ListNode* link;				// 주소를 저장할 링크 변수 선언
}ListNode;

void error(const char* message) {	// 에러 날 시 메시지 출력 함수 선언
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {		// 링크의 첫 번째 위치에 값 넣는 함수 선언
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		// 구조체에서 p를 선언 후, 동적 할당
	p->data = value;		// value의 값을 p의 data 변수에 저장
	p->link = head;			// 헤드 포인터 변경 전, 헤드 포인터 값을 복사하여 저장
	head = p;				// 현재 노드를 헤드 포인터(첫번째 노드)로 변경
	return head;
}

ListNode* insert_last(ListNode* head, element value) {		// 링크의 마지막 위치에 값 넣는 함수 선언
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		// 구조체에서 p 변수를 선언 후, 동적 할당
	p = head;					// 현재 노드를 헤드 포인트로 변경
	while (p->link != NULL) {   // 마지막 링크 찾기, NULL값을 링크로 받기까지 반복하여 링크 연결
		p = p->link;
	}
	ListNode* lastnode = (ListNode*)malloc(sizeof(ListNode)); // 구조체에서 lastnode 새로운 변수를 선언 후, 동적 할당
	lastnode->data = value;		// lastnode의 data 변수에 값 저장
	lastnode->link = p ->link;	// link를 NULL에 연결하여 링크 리스트 완성, p -> link == NULL
	p->link = lastnode;			// p의 링크를 lastnode 주소값에 연결 

	return head;
}

ListNode* delete_last(ListNode* head) { // 마지막 노드 삭제하는 함수 선언 , 4->3->2->1->0->10->NULL
	ListNode* pre;						// 삭제하기 전 노드 주소 저장
	ListNode* removed;					// 삭제 할 노드 주소 저장
	pre = head;
	removed = head;						// removed에 헤드 포인트 값 복사
	if (head == NULL) return NULL;		// 리스트에 노드가 없는 경우 NULL 호출
	while (removed->link != NULL) { // 마지막 링크 주소 찾기, removed의 링크 주소가 NULL이 나올 때까지 반복
			pre = removed;				// 마지막 노드 - 1 위치, pre에 removed 값 복사
			removed = removed->link;	// 다음 링크로 넘어가기 반복
		}
		pre->link = NULL;		// pre link를 NULL값으로 설정 , removed -> link = XX NULL XX
		free(removed);			// 마지막 리스트인 removed 삭제
			
		return head;			// 결과값 반환
}

ListNode* search_list(ListNode* head, element value) {		// 특정 값을 검색하는 함수 정의
	ListNode* p = head;			// 헤드 포인터 값 복사
	while (p != NULL) {			// NULL값을 찾을 때까지 반복
		if (p->data == value) {		// p의 데이터 값이 value와 같을 때
			return p;				// p의 반환
		}
		p = p->link;				// 값이 value와 다를 시 다음 링크로 넘어가고 반복
	}
	return NULL;					// 검색 실패할 시 NULL값 반환
}

ListNode* reverse_list(ListNode* head) { // 역순 출력 함수, 4->3->2->1->0->NULL
	ListNode* p, * q, * r;		//순회 포인터를 p,q,r로 사용
	p = head;		//p 는 역순으로 만들 예정인 리스트, p = 헤드 포인터 값 복사
	q = NULL;		//q 는 역순으로 만들 예정인 노드, q = NULL값
	while (p != NULL) {		// p가 NULL값을 찾을 때까지 반복
		r = q;		// r 은 역순으로 된 리스트.
		q = p;		// q = p의 값을 받는 역순 노드
		p = p->link; // 다음 링크의 주소를 순차적으로 따라감
		q->link = r; // q 의 링크가 r값을 가르킴으로써 방향을 바꿈
	}
	return q;
}

void print_list(ListNode* head) {		// 연결 리스트의 값을 출력하는 값
	for (ListNode* p = head; p != NULL; p = p->link)  // 연결 리스트의 head부터 NULL값이 나올 때까지 반복하여 link를 통해 다음 리스트로 이동하여 출력
		printf("%d->", p->data);		// p의 data값을 출력
	printf("NULL \n");					// 마지막에 NULL값을 출력
}

void start() {
	ListNode* head = NULL;		//구조체 head 정의, 노드가 없으므로 head의 값은 NULL
	ListNode* head2 = NULL;		//구조체 head2 정의, 노드가 없으므로 head2의 값은 NULL
	printf("Insert First !\n");

	for (int i = 0; i < 5; i++) {		// for 반복문을 이용하여 0부터 5까지 insert_first에 값 넣기
		head = insert_first(head, i);
		print_list(head);				// for문 i를 이용해서 ListNode 구조체 출력
	}

	printf("\nInsert Last !\n");
	head = insert_last(head, 10); print_list(head);	// insert_last 함수를 호출하고, 5값을 입력 후 출력

	printf("\nDelete Last !\n");
	head = delete_last(head); print_list(head);		// delete_last 함수를 호출하고, 출력

	printf("\nSearch !\n");
	if (search_list(head, 0) != NULL)			// search_list 함수를 호출하고, 리스트에서 0이 있을 시 결과값 출력
		printf("리스트에서 0을 찾았습니다.\n");
	else										// search_list 함수를 호출하고, 리스트에서 0이 없을 시 결과값 출력
		printf("리스트에서 0을 찾지 못했습니다.\n");

	printf("\nReverse !\n");
	head2 = reverse_list(head); print_list(head2);	// 구조체 head2의 값은 head의 결과값에서 reverse_list 함수를 호출한 값 출력
}

int main(void) {
	start();
	return 0;
}