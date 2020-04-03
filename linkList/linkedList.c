# include <stdio.h>
# include <stdlib.h>
# include "../head/linkedList.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	L = (LinkedList*)malloc(sizeof(LNode)); 
	(*L)->next = NULL ;					//  next to NULL
	if( !((*L)->next) )				//  null so success
		return SUCCESS;
	else							//  else error
		return ERROR;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList *temp = L ;			//	in case remember L
	while( *L ){					
		temp = (*L)->next;			//	move temp 
		free(*L);					//	free L
		L = temp; 					//	so as to move L
	}
	if( !(*L) )
		return SUCCESS;
	else
		return ERROR; 
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	q->next = p->next ;			//	send next to addition one
	p->next = q ;				//	linked to q
	if( p->next==q )			//	check
		return SUCCESS;
	else 
		return ERROR;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	e = p->next->data ;			//	send e back
	LNode *temp = p->next;		//	remember temp 
	p->next = p->next->next;	//	link to next&next
	free( temp );				//	thus to free temp
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	do{							
		visit(L->data);			//	call &visit
		L = L->next;			//	to the next 
	} while( L->next );
}

void visit(ElemType e){
	printf("%d",e);
}
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	do{								
		if( L->data == e)			//	confirm whether equal e
			return SUCCESS;			
		L = L->next ; 				//	continue find e
	}while( L->next );
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if( (*L)->next == NULL)	//如果是空链表则直接返回 
		return SUCCESS;
	LinkedList *p,*c,*nextTemp;		// def pre_ptr&cur_ptr&nextTemp 
	p = NULL;						// initiate p as null to be the last Node
	c = L ;							// make cur_ptr as L 
	while( (*c)->next!=NULL ){			// start loop 
		nextTemp = (*c)->next ;		// remember the nextTemp 
		(*c)->next = p ;				// so next_ptr can be appointed to pre(last to be NULL)  
		p = c ;						// thus pre_ptr go to cur_ptr as next pre_ptr
		c = nextTemp ;				// thus cur_ptr go to nextTemp as cur
	}								// so loop
	L = c; 							// assign L be head_ptr 
	(*L)->next = p;					// L->next  connect to pre 
	return SUCCESS;					// successfully reverse 
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if(L == NULL||L->next == NULL)				//NULL则ERROR 
		return ERROR;							
	LNode *fast,*slow;							//def *slow & *fast
	fast = slow = L;							// both as the head
	fast = fast->next->next;					//Fast go for two Node 
	slow = slow->next;							//slow go for one Node
	while(1){	
		if(!fast||!slow)						//once either is NULL	
			return ERROR;						//error
		if(fast == slow)						//once equal
			return SUCCESS;						//success
		else{									
			fast = fast->next->next;			//else continue to go
			slow = slow->next;	
		}
	}
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {		//	even & odd for exchange 
	if ( L == NULL || (*L)->next == NULL)		//	<2Nodes return L  
		return L;							
	LinkedList* p1 = L;						//	else remember the L(head)
    LinkedList* p2 = (*p1)->next;				//	& the head->next 
    	
	while (p2 != NULL) {					//	even number of nodes
		int tmp = (*p1)->data;					//	
        (*p1)->data = (*p2)->data;					//	swap
        (*p2)->data = tmp;						//
	    
		p1 = (*p2)->next;						//	go to next							
	    p2 = (*p1)->next;						//	go to next
	}
	        return L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	if( L==NULL || (*L)->next==NULL )
		return L;								//	NULL so return L 
	LNode *mid , *fast;							//	def *mid & *fast
	mid = fast = L;								//	equal to head
	while(fast!=NULL){							//	fast not the end
		if(fast->next==NULL)					//	go for two node,
			fast = fast->next;  				//	unless fast->next == NULL 
		else 									
			fast = fast->next->next;			//	two node
		mid=mid->next;							//	mid go for one node;	
	}
	return mid;									// return mid
	

}

