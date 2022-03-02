#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Link{
	char value;
	struct Link *next;
	struct Link *before;
}Link;

void del(Link *list) {
	if(list->before == NULL) return;
	if(list->next == NULL){
		list->before->next = NULL;
		return;
	}
	list->before->next = list->next;
	list->next->before = list->before;
}

void addNew(char ch,Link *list) {
	struct Link *node = malloc(sizeof(Link));
	node->value = ch;
	if(list->next == NULL) {
		list->next = node;
		node->before = list;
	} else {
		list->next->before = node;
		node->next = list->next;
		list->next = node;
		node->before = list;
	}
}

int main() {
	char arr[100001];
	Link linked;
	Link *ptr;
	scanf("%s",arr);
	linked.value = arr[0];
	ptr=&linked;
	int length = strlen(arr);
	for(int i = 0;i<length;i++) {
		addNew(arr[i],ptr);
		ptr=ptr->next;
	}
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++) {
		char com,c;
		scanf(" %c",&com);

		switch (com){
			case 'L':
				if(ptr->before != NULL)
					ptr=ptr->before;
				break;
			case 'D':
				if(ptr->next != NULL)
					ptr=ptr->next;
				break;
			case 'B':
				if(ptr->before != NULL) {
					del(ptr);
					ptr = ptr->before;
					length--;
				}
				break;
			case 'P':
				scanf(" %c",&c);
				addNew(c,ptr);
				ptr = ptr->next;
				length++;
				break;
		}
	}
	Link* target=&linked;
	for(int i = 0;i<length;i++) {
		target=target->next;
		printf("%c",target->value);
	}
	
}