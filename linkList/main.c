# include <stdio.h>
# include <stdlib.h>
# include "../head/linkedList.h"
 
void createlist(LinkedList *h);

int main ()
{	
	LinkedList h=(LinkedList)malloc(sizeof(LNode));
	int number;
	createlist(h);
	printf("请输入你要执行的操作:\t	\n	\
			1.空头结点创建\t 	 		\n	\
			2.销毁操作\t				\n	\
			3.插入操作\t				\n	\
			4.删除操作\t 				\n	\
			5.遍历操作 					\n	\ 
			6.查询某数是否在链表中	\t	\n	\
			7.链表反转逆序	\t			\n	\
			8.给链表加环			\t	\n	\
			9.找到链表的中间结点	\t	\n	\
			操作(-1退出): ");
	
	scanf("%d",&number);

	if( number >= 1 && number <= 9 )
		while(number!=-1){
			switch (number){
				case 1:
					InitList(&h);
					break;
				case 2:
					DestroyList(&h);
					printf("销毁完成!\n");
					break;
				case 3:
					printf("请输入要节点被插在第x个的后面?请输入x！\n");
					LNode *p = h;
					LNode *q=(LinkedList )malloc(sizeof(LNode));
					int location,i;
					scanf("%d",&location);
					for( i=0 ; i<location ; i++)
					p=p->next; 
					InsertList(p,q);
					printf("插入完成！\n");
					break;
				case 4:
					printf("请输入要删除第几个节点?,若要作为头节点,则输入0\n");
					scanf("%d",&location); 
					p=h;
					ElemType value;
					for( i=0;i<location-1;i++)
					p=p->next;
					DeleteList(p,value);
					printf("删除完成!\n");
					break;
				case 5:
					TraverseList(h,value);
					printf("遍历完成!\n");
					break;
				case 6:
					printf("请输入要查找的数值!\n");
					scanf("%d",&value);
					SearchList(h,value);
					printf("搜寻完成!\n");
					break;
				case 7:
					ReverseList(&h);
					printf("反转完成!\n");
					break;
				case 8:
					IsLoopList(h);
					break;
				case 9:
					FindMidNode(&h);
					printf("已找到中间节点!\n");
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
	printf("请输入节点的第一个值（输入后请回车）（以-1结束）：");
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
			printf("请输入下一个节点数值：（以-1结尾）");
			scanf("%d",&number); 
		}
	return ;
}










