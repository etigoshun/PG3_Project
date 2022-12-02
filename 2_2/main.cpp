#include <stdio.h>
#include <stdlib.h>

//単方向リストの構造体の定義
typedef struct cell
{
	int val;
	struct cell* next;
}CELL;

void Create(CELL* currentCell, int val);
void Index(CELL* head);

int main()
{

	int val;

	//先頭のセルを宣言
	CELL head;
	head.next = nullptr;

	while (true)
	{
		printf("数字を入力してください\n");

		scanf_s("%d", &val);

		//最後尾にリストを追加
		Create(&head, val);

		//リスト一覧の表示
		Index(&head);
	}
	return 0;
}


//セルを新規作成する関数
void Create(CELL* currentCell, int val)
{
	CELL* newCell;

	//新規作成するセル分のメモリを確保する
	newCell = (CELL*)malloc(sizeof(CELL));

	if (newCell)
	{
		newCell->val = val;
		newCell->next = nullptr;
	}

	//最後(最新)のセルのアドレスの1つ目の処理は引数から持ってきた
	//リストのうち最初のセルのアドレスが該当する
	while (currentCell->next != nullptr)
	{
		currentCell = currentCell->next;
	}

	currentCell->next = newCell;
}

void Index(CELL* head)
{
	printf("{");
	while(head->next != nullptr)
	{
		head = head->next;
		printf("%d,", head->val);
	}
	printf("}\n\n");
}