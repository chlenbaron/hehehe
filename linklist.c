# define _CRT_SECURE_NO_WARNINGS 1
#include"linklist.h"



void showtopic(char *topic)
{
	char space[] = "                                       ";
	printf("%s %s\n", space + (strlen(topic) / 2), topic);
}



void Initlist(pList* pplist)
{
	*pplist = NULL;

}



int GetListLength(pList pList)
{
	pNode cur = pList;
	int count = 0;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;
}



void PushBack(pList* pplist, DataType d)
{
	pNode cur = *pplist;
	assert(pplist != NULL);
	if (NULL == *pplist)
	{
		pNode newnode = buy(d);
		*pplist = newnode;
		return;
	}
	pNode newnode = buy(d);
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = newnode;
	return;
}



void PopBack(pList* pplist)
{
	pNode cur = *pplist;
	assert(pplist != NULL);
	if (*pplist == NULL)
	{
		printf("链表为空，删除失败\n");
		return;
	}
	if (cur->next == NULL)
	{
		free(cur);
		*pplist = NULL;
		return;
	}
	while (cur->next->next)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
	printf("删除成功");
	return;
}



void PopFront(pList* pplist)
{
	pNode cur = *pplist;
	assert(pplist != NULL);
	if (*pplist == NULL)
	{
		printf("链表为空，删除失败\n");
		return;
	}
	*pplist = cur->next;
	free(cur);
	printf("删除成功\n");
	return;
}



void PushFront(pList* pplist,DataType d)
{
	pNode cur = *pplist;
	assert(pplist != NULL);
	if (NULL == *pplist)
	{
		pNode newnode = buy(d);
		*pplist = newnode;
		return;
	}
	pNode newnode = buy(d);
	newnode->next = *pplist;
	*pplist = newnode;
	return;
}



void Printlist(pList plist)
{
	pNode cur = plist;
	int count = 1;
	if (plist == NULL)
	{
		printf("链表为空，打印失败\n");
		return;
	}
	while (cur)
	{
		printf("%d  ", count);
		cur = cur->next;
		count++;
	}
	printf("\n");
	cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
	return;
}



pNode Find(pList plist, DataType d)
{
	pNode cur = plist;
	if (plist == NULL)
	{
		printf("查找失败");
		return NULL;
	}
	while (cur)
	{
		if (cur->data == d)
		{
			return cur;
		}
		cur = cur->next;
	}
	printf("没有找到要查找的数据\n");
	return NULL;
}




void Remove(pList* pplist, DataType d)
{	
	pNode cur = *pplist;
	pNode del = *pplist;
	assert(pplist != NULL);
	if (*pplist == NULL)
	{
		printf("查找失败");
		return;
	}
	if (cur->data == d)
	{
		*pplist = cur->next;
		free(cur);
		printf("删除成功\n");
		return;
	}

	while (cur->next)
	{
		if (cur->next->next == NULL)
		{
			free(cur->next);
			cur->next = NULL;
			return;
		}
		if (cur->data == d)
		{
			del = cur;
			cur->next = cur->next->next;
			free(del);
			return;
		}
		cur = cur->next;
	}
	printf("需要删除的数据不存在");
	return;
}



void RemoveALL(pList* pplist, DataType d) //有bug
{
	pNode cur = *pplist;
	pNode arr = *pplist;
	int count = GetListLength(*pplist)-1;
	assert(pplist != NULL);
	if (*pplist == NULL)
	{
		printf("链表为空");
		return;
	}
	if (NULL == (arr = Find(*pplist,d)))
	{
		printf("要删除的数据不存在\n");
		return;
	}
	while (count--)
	{
		Remove(pplist, d);
	}
	return;
}




void Insert(pList* pplist, pNode pos, DataType d)
{
	pNode cur = *pplist;
	assert(pplist != NULL);
	if (cur == NULL)
	{
		printf("链表为空，插入失败");
		return;
	}
			pNode set= buy(d);
			set->next = pos->next;
			pos->next = set;
			printf("插入成功");
	        return;
	
}




void Erase(pList* pplist, pNode pos)
{
	int count = GetListLength(*pplist) - 1;
	pNode cur = *pplist;
	assert(pplist != NULL);
	if (*pplist == NULL)
	{
		printf("链表为空,无法删除");
		return;
	}
	if (0 == count)
	{
		PopBack(pplist);
		return;
	}
	while (count--)
	{
		if (cur->next == pos)
		{
			cur->next = pos->next;
			free(pos);
			printf("删除成功");
			return;
		}
		cur = cur->next;
	}
}



void DestrotList(pList* pplist)
{
	pNode cur = *pplist;
	pNode cur2 = cur->next;
	while (cur)
	{
		cur2 = cur->next;
		free(cur);
		cur = cur2;
	}
	*pplist = NULL;
}



void* buy(DataType d)
{
	pNode p;
	p= (pNode)malloc(sizeof(Node));
	p->next = NULL;
	p->data = d;
	return p;
}


pList Merge(pList l1, pList l2)  //问题
{
	pList tail = NULL;
	pList newlist = NULL;
	if (l1 == NULL && l2 == NULL)
	{
		return NULL;
	}
	if (l1 == NULL&& l2)
	{
		return l2;
	}
	if (l1&&l2 == NULL)
	{
		return l1;
	}
	if (l1->data <= l2->data)
	{
		newlist = l1;
		l1 = l1->next;
	}
	else
	{
		newlist = l2;
		l2 = l2->next;
	}
	tail = newlist;
	while ((l1 != NULL) && (l2!=NULL))
	{
		if (tail->data <= l2->data)
		{
			tail->next = l1;
			tail = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			tail = l2;
			l2 = l2->next;
		}
	}
	if (l1 == NULL)
	{
		tail->next = l2;
	}
	if (l2 == NULL)
	{
		tail->next = l1;
	}
	
	return newlist;
}





void EraseNotTal(pNode pos)
{
	pNode del = NULL;

	assert(pos->next != NULL);
	del = pos->next;
	pos->data = pos->next->data;
	pos->next = pos->next->next;
	free(del);
	return;
}



void InsertFrontNode(pNode pos, DataType d)
{
	pNode new = buy(d);
	DataType tmp = 0;
	if (pos == NULL)
	{
		return;
	}
	new->next = pos->next;
	pos->next = new;
	tmp = new->data;
	new->data = pos->data;
	pos->data = tmp;
}

void ReverseList(pList* pplist)
{
	pList newlist = NULL;
	pNode cur = *pplist;
	pNode tmp = NULL;
	assert(pplist != NULL);
	if ((cur == NULL) || (cur->next == NULL))
	{
		return;
	}
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		tmp->next = newlist;
		newlist = tmp;
	}
	*pplist = newlist;
}

void BubbleSort(pList* pplist)
{
	DataType tmp = 0;
	pNode cur = *pplist;
	pNode tail = cur->next;
	assert(pplist != NULL);
	while (cur->next)
	{
		while (tail->next)
		{
			if (tail->data > tail->next->data)
			{
				tmp = tail->data;
				tail->data = tail->next->data;
				tail->next->data = tmp;
			}
			tail = tail->next;
		}
		cur = cur->next;
	}
}


pNode midlist(pList plist)
{
	pNode fast = plist;
	pNode slow = plist;
	if (plist == NULL)
	{
		printf("链表为空\n");
		return NULL;
	}
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}


void PrintReversely(pList plist)
{
	pNode cur = plist;
	if (plist == NULL)
	{
		return;
	}
	if (cur->next)
	{
		PrintReversely(cur->next);
	}
	printf("%d->", cur->data);
}

pNode DelKNode(pList *pplist, int k)
{
	pNode fast = *pplist;
	pNode slow = *pplist;
	pNode del = NULL;
	assert(pplist);
	if (*pplist == NULL)
	{
		printf("此链表为空\n");
	}
	while (fast->next)
	{
		--k;
		if (k <= 0)
		{
			slow = slow->next;
		}
		fast = fast->next;
	}
	del = slow->next;
	slow->data = slow->next->data;
	slow->next = slow->next->next;
	free(del);
	return NULL;
}


pNode josephCycle(pList* pplist, int num)
{
	pNode cur = *pplist;
	pNode del = *pplist;
	int i = 0;
	assert(pplist);
	if (*pplist == NULL)
	{
		printf("链表为空\n");
		return NULL;
	}
	while (1)
	{
		i = num - 1;
		if (cur->next == cur)
		{
			break;
		}
		while (i--)
		{
			cur = cur->next;
		}
		printf(" kill ->%d\n", cur->data);
		del = cur->next;
		cur->data = cur->next->data;
		cur->next = cur->next->next;
		free(del);
	}
	printf(" win->%d\n", cur->data);
	return cur;
}
pNode checkCylen(pList* pplist)
{
	pNode fast = *pplist;
	pNode slow = *pplist;
	assert(pplist);
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			printf("yes\n");
			return slow;
		}
	}
	printf("no\n");
	return NULL;
}

int GetcircleLength(pNode meet)
{
	pNode cur = meet;
	int count = 0;
	while (1)
	{
		cur = cur->next;
		count++;
		if (cur == meet)
		{
			return count;
		}
	}
}

int checkCross(pList list, pList list2)
{
	pNode cur1 = list;
	pNode cur2 = list2;
	if (NULL == list || NULL == list2)
	{
		return 0;
	}
	if (checkCylen(list) != NULL &&checkCylen(list2) == NULL)//一个带环一个不带环
	{
		return NULL;
	}
	if (checkCylen(list) == NULL &&  checkCylen(list2) != NULL)//一个带环一个不带环
	{
		return NULL;
	}
	if (checkCylen(list) == NULL && checkCylen(list2) == NULL)  //两个都不带环的
	{
		while (cur1->next)
		{
			cur1 = cur1->next;
		}
		while (cur2->next)
		{
			cur2 = cur2->next;
		}
		if (cur1 == cur2)
		{
			return 1;
		}
		return 0;
	}
	/*if (checkCylen(list) != NULL && checkCylen(list2) != NULL)
	两个带环情况下
	{
	if (入口点相同)
	{
	}
	if (入口点不同)
	{
	}
	}*/
}
//pNode GetCycleEntryNode(pList plist, pNode meetNode)
//{
//
//}
//
pcomplexNode clonelist(pcomplexNode list)
{
	pcomplexNode cur = list;
	pcomplexNode prev = NULL;
	pcomplexNode  l1= list;
	pcomplexNode  l2= NULL;
	while (cur)
	{
		prev = buylist2(cur->data);
		prev->next = cur->next;
		cur->next = prev;
		cur = cur->next->next;
	}
	cur = list;

	while (cur)
	{
		cur->next->random = cur->random->next;
		cur = cur->next;
	}

	if (l1->next)
	{
		l2 = l1->next;
	}
	cur = l2;

	while (l2->next)
	{
		l1->next = l2->next;
		l1 = l1->next;
		l2->next = l1->next;
		l2 = l2->next;
	}
	l1->next = NULL;
	
	return cur;
}

pcomplexNode buylist2(DataType d)
{
	pcomplexNode cur = (pcomplexNode)malloc(sizeof(complexNode));
	cur->data = d;
	cur->next = NULL;
	cur->random = NULL;
	return cur;
}


pcomplexNode Printlist2(pcomplexNode plist)
{
	pcomplexNode cur = plist;
	if (plist == NULL)
	{
		printf("链表为空，打印失败\n");
		return;
	}
	printf("\n");
	cur = plist;
	while (cur)
	{
		printf(" %d ->   ", cur->data );
		cur = cur->next;
	}
	printf("NULL\n");
	return;
}
