# include <stdio.h>
# include <stdlib.h>
# include "../head/linkedList.h"
 
void createlist(LinkedList *h);

int main ()
{	
	LinkedList h=(LinkedList)malloc(sizeof(LNode));
	int number;
	createlist(h);
	printf("��������Ҫִ�еĲ���:\t	\n	\
			1.��ͷ��㴴��\t 	 		\n	\
			2.���ٲ���\t				\n	\
			3.�������\t				\n	\
			4.ɾ������\t 				\n	\
			5.�������� 					\n	\ 
			6.��ѯĳ���Ƿ���������	\t	\n	\
			7.����ת����	\t			\n	\
			8.������ӻ�			\t	\n	\
			9.�ҵ�������м���	\t	\n	\
			����(-1�˳�): ");
	
	scanf("%d",&number);

	if( number >= 1 && number <= 9 )
		while(number!=-1){
			switch (number){
				case 1:
					InitList(&h);
					break;
				case 2:
					DestroyList(&h);
					printf("�������!\n");
					break;
				case 3:
					printf("������Ҫ�ڵ㱻���ڵ�x���ĺ���?������x��\n");
					LNode *p = h;
					LNode *q=(LinkedList )malloc(sizeof(LNode));
					int location,i;
					scanf("%d",&location);
					for( i=0 ; i<location ; i++)
					p=p->next; 
					InsertList(p,q);
					printf("������ɣ�\n");
					break;
				case 4:
					printf("������Ҫɾ���ڼ����ڵ�?,��Ҫ��Ϊͷ�ڵ�,������0\n");
					scanf("%d",&location); 
					p=h;
					ElemType value;
					for( i=0;i<location-1;i++)
					p=p->next;
					DeleteList(p,value);
					printf("ɾ�����!\n");
					break;
				case 5:
					TraverseList(h,value);
					printf("�������!\n");
					break;
				case 6:
					printf("������Ҫ���ҵ���ֵ!\n");
					scanf("%d",&value);
					SearchList(h,value);
					printf("��Ѱ���!\n");
					break;
				case 7:
					ReverseList(&h);
					printf("��ת���!\n");
					break;
				case 8:
					IsLoopList(h);
					break;
				case 9:
					FindMidNode(&h);
					printf("���ҵ��м�ڵ�!\n");
					break;
			}
			scanf("%d",&number);
		}
	else 
		printf("ByeBye"); 
	
}
 
void createlist(LinkedList *h)
{	
	LNode *temp = h;
	printf("������ڵ�ĵ�һ��ֵ���������س�������-1��������");
	int number ;
	scanf("%d",&number);
	if( number==-1 )
		return ;
	if( number!=-1 )
		while( number!=-1 ){
			LNode *p = (LNode*)malloc(sizeof(LNode));
			temp->next = p ;
			p->data = number ;
			p->next = NULL;
			temp = p;
			printf("��������һ���ڵ���ֵ������-1��β��");
			scanf("%d",&number); 
		}
	return ;
}










