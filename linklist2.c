# define _CRT_SECURE_NO_WARNINGS 1
#include "linklist.h"

int main()
{
	int d = 1;
	int input = 0;
	pList l1 = NULL;
	pList l3 = NULL;
	pList plist = NULL;
	do
	{
		system("cls");
		showtopic("*****************LinkList*****************\n");
		showtopic("******************************************\n");
		showtopic("****PushFrontn->1          PushBack->2****\n");
		showtopic("****PopFront->3             PopBack->4****\n");
		showtopic("****Find->5                  Remove->6****\n");
		showtopic("****RemoveALL-> 7            Erase-> 8****\n");
		showtopic("****Insert-> 9      GetListLength-> 10****\n");
		showtopic("****DestrotList-> 11    Printlist-> 12****\n");
		showtopic("****EraseNotTail->13   ReversrList->14****\n");
		showtopic("****BubbleSort->15 InsertFrontNode->16****\n");
		showtopic("****Merge->17                  EXIT->0****\n");
		showtopic("******************************************\n");
		showtopic("******************************************\n");
		showtopic("******************************************\n");
		scanf("%d", &input);
		fflush(stdin);
		switch (input)
		{
		case 1:
			system("cls");
			showtopic("请输入你需要插入的数据: ");
			scanf("%d", &d);
			PushFront(&plist, d);
			break;
		case 2:
			system("cls");
			showtopic("请输入你需要插入的数据: ");
			scanf("%d", &d);

			PushBack(&plist, d);
			break;
		case 3:
			system("cls");
			PopFront(&plist);
			break;
		case 4:
			system("cls");
			PopBack(&plist);
			break;
		case 5:
			system("cls");
			showtopic("请输入你需要查找的数据: ");
			scanf("%d", &d);
			{
				pNode cur = Find(plist, d);
				if (cur != NULL)
				{
					printf("%d", cur->data);
				}

			}
			break;
		case 6:
			system("cls");
			showtopic("请输入你需要删除的数据: ");
			scanf("%d", &d);
			Remove(&plist, d);
			break;
		case 7:
			system("cls");
			showtopic("请输入你需要删除的数据: ");
			scanf("%d", &d);
			RemoveALL(&plist, d);
			break;
		case 8:
			system("cls");
			if (plist == NULL)
			{
				printf("链表为空，删除失败");
				break;
			}
			Printlist(plist);
			showtopic("请输入你需要删除节点的位置: ");
			{
				int count = 0;
				pNode pos = plist;
				scanf("%d", &count);
				if (count > GetListLength(plist) || (count <= 0))
				{
					printf("删除位置有误\n");
					break;
				}
				count = count - 1;
				while (count--)
				{
					pos = pos->next;
				}
				if (pos != NULL)
				{
					Erase(&plist, pos);
				}
			}
			break;
		case 9:
			system("cls");
			if (plist == NULL)
			{
				printf("链表为空，插入失败");
				break;
			}
			Printlist(plist);
			showtopic("请输入你需要插入的数据以及被插入节点的位置: ");
			{
				int count = 0;
				pNode pos = plist;
				scanf("%d %d", &d, &count);
				if (count > GetListLength(plist))
				{
					printf("插入位置有误\n");
				}
				count = count - 1;
				while (count--)
				{
					pos = pos->next;
				}
				if (pos != NULL)
				{
					Insert(&plist, pos, d);
				}
			}
			break;
		case 10:
			system("cls");
			{
				int count;
				count = GetListLength(plist);
				printf("%d\n", count);
			}
			break;
		case 11:
			system("cls");
			DestrotList(&plist);
			printf("销毁成功");
			break;
		case 12:
			system("cls");
			Printlist(plist);
			showtopic("按任意键继续....");
			getch();
			break;
		case 13:
			system("cls");
			if (plist == NULL)
			{
				printf("链表为空，删除失败");
				break;
			}
			Printlist(plist);
			showtopic("请输入你需要删除节点的位置: ");
			{
				int count = 0;
				pNode pos = plist;
				scanf("%d", &count);
				if (count > GetListLength(plist) || (count <= 0))
				{
					printf("删除位置有误\n");
					break;
				}
				count = count - 1;
				while (count--)
				{
					pos = pos->next;
				}
				if (pos != NULL)
				{
					EraseNotTal(pos);
				}
			}
			break;
		case 14:
			system("cls");
			Printlist(plist);
			ReverseList(&plist);
			showtopic("逆序成功\n");
			Printlist(plist);
			getch();
			break;
		case 15:
			system("cls");
			Printlist(plist);
			BubbleSort(&plist);
			showtopic("排序成功\n");
			Printlist(plist);
			getch();
			break;
		case 16:
			system("cls");
			if (plist == NULL)
			{
				printf("链表为空，插入失败");
				break;
			}
			Printlist(plist);
			showtopic("请输入你需要插入的数据以及被插入节点的位置: ");
			{
				int count = 0;
				pNode pos = plist;
				scanf("%d %d", &d, &count);
				if (count > GetListLength(plist))
				{
					printf("插入位置有误\n");
				}
				count = count - 1;
				while (count--)
				{
					pos = pos->next;
				}
				if (pos != NULL)
				{
					InsertFrontNode(pos, d);
				}
			}
			break;
		case 17:
			system("cls");
			showtopic("请输入第一条有序链表: ");
				while (d)
				{
					showtopic("请输入你需要插入的数据(按0结束录入）: ");
					scanf("%d", &d);
					PushBack(&l1, d);
				}
				Printlist(l1);
				printf("\n");
				d = 2;
				showtopic("请输入第二条有序链表: ");
					while (d)
					{
						showtopic("请输入你需要插入的数据(按0结束录入）: ");
						scanf("%d", &d);
						PushBack(&l3, d);
					}
					Printlist(l3);
				Printlist(Merge(l1, l3));
				getch();
				break;
		default:
			showtopic("输入有误请重新输入\n");
			break;
			}
		} while (input);
		return 0;
	}
