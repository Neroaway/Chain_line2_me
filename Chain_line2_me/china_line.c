#include "stdio.h"
#include "stdlib.h"
#include "time.h"


#define True 1
#define False 0
typedef int bool;
typedef int Elemtype;
typedef struct {
	 Elemtype data;
	 struct Node *next;

 }NODE,*Linedlist;

 Linedlist *CreatLine(void);
 bool InsertNum(Linedlist phead,int font,int date);
 bool DelectNum(Linedlist phead,int font);
 void traver_list(Linedlist phead);

 
 Linedlist *CreatLine(void) {
	 int len;
	 int val;
	 Linedlist phead = (Linedlist)malloc(sizeof(NODE));
	 Linedlist ptail = phead;
	 ptail->next = NULL;
	 printf("please input the number of node\n");
	 scanf_s("%d", &len);
	 for (int i = 0; i < len; i++) {
		 
		 printf("The %d st node is ", i);

		 scanf_s("%d", &val);
		 Linedlist pNew = (Linedlist)malloc(sizeof(NODE));
		 pNew->data = val;
		 ptail->next = pNew;
		 pNew->next = NULL;
		 ptail = pNew;
	 }
	 
	 return phead;
 
 }
 void traver_list(Linedlist phead) {
 
	 Linedlist p = phead->next;
	 while (p != NULL) {
		 printf("%d", p->data);
		 p = p->next;
	 
	 }
	 printf("\n");
 }

 bool InsertNum(Linedlist phead, int font, int date) {
	 int i = 0;
	 Linedlist node = phead;
	 
	 if ((font < 1) && node != NULL) {
		 return False;
	 }
	 while (i < font - 1) {
		 node = node->next;
		 ++i;
	 }
	 Linedlist pnew = (Linedlist)malloc(sizeof(NODE));
	 pnew->data = date;
	 pnew->next = node->next;
	 node->next = pnew;

 }
 bool DelectNum(Linedlist phead, int font) {
	 int i = 0;
	 Linedlist node = phead;
	 if ((font < 1) && node != NULL) {
		 return False;
	 }
	 while (i < font - 1) {
		 node = node->next;
		 ++i;
	 }
	 Linedlist pnew = (Linedlist)malloc(sizeof(NODE));
	 pnew = node->next;
	 node->next = pnew->next;
	 free(pnew);
 
 }
 int main(void) {
	 Linedlist phead = NULL;
	 phead = CreatLine();
	 traver_list(phead);
	 int m,n,y;
	 printf("input font and number");
	 scanf_s("%d %d", &m,&n);
	 InsertNum(phead, m, n);
	 traver_list(phead);
	 scanf_s("%d", &y);
	 DelectNum(phead, y);
	 traver_list(phead);
	 system("pause");
	 return 0;
 
 
 
 }

 









