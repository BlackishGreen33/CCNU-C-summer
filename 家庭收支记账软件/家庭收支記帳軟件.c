#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TRANSACTIONS 1000

struct Transaction{
	char description[51];
	float amount;
	char type[8];
};

int main(){
	struct Transaction transactions[MAX_TRANSACTIONS];
	int num_transactions = 0;
	int option;
	char ch;

	while(1){
		system("cls");
		printf("--------家庭收支記帳軟件--------\n");
		printf("\t1. 收支明細\n");
		printf("\t2. 登記收入\n");
		printf("\t3. 登記支出\n");
//		printf("\t4. 查看支出或收入\n");
		printf("\t4. 退  出\n\n");
		printf("\t請選擇(1~4):");
		scanf("%d", &option);

    	if(option == 2 || option == 3){
			if(num_transactions == MAX_TRANSACTIONS){
				printf("已達到最大交易數量。\n");
				continue;
			}
			struct Transaction t;
			printf("\n本次收入金額: ");
			scanf("%f", &t.amount);
			printf("本次收入說明: ");
			scanf("%s", t.description);
		
			if (option == 3){
				t.amount = -t.amount; 
				strcpy(t.type, "支出");
			}
			else strcpy(t.type, "收入");
			transactions[num_transactions++] = t;
			printf("\n交易成功添加\n");
			system("pause");
		} 
		
		else if(option == 1){
			if(num_transactions == 0){
				printf("\n當前沒有收支紀錄...來一筆吧！\n");
				system("pause");
				continue;
			}

			float total = 0;
			printf("\n收支\t\t收支金額\t帳戶金額\t說  明\n");
			printf("-------------------------------------------------------\n");
			for (int i = 0; i < num_transactions; i++) {
				struct Transaction t = transactions[i];
				printf("%s\t\t%.2f\t\t%.2f\t\t%s\n", t.type, t.amount, total + t.amount, t.description);
				total += t.amount;
			}
			printf("-------------------------------------------------------\n");
			printf("目前帳戶金額\t\t\t\t\t%.2f\n", total);
			system("pause");
		}
		
//		else if (option == 4) {
//			if (num_transactions == 0) {
//				printf("\n沒有交易記錄。\n");
//				continue;
//			}
//
//			char type[8];
//			printf("\n請輸入類型 (支出/收入): ");
//			scanf("%s", type);
//
//			float total = 0;
//    		printf("\n描述\t\t金額\n");
//    		printf("-------------------------------------------------------\n");
//    		for (int i = 0; i < num_transactions; i++) {
//    			struct Transaction t = transactions[i];
//    			if (strcmp(t.type, type) == 0) {
//        			printf("%s\t\t%.2f\n", t.description, t.amount);
//        			total += t.amount;
//				}
//    		}
//    		printf("-------------------------------------------------------\n");
//    		printf("總%s\t\t\t\t%.2f\n", type, total);
//		}
		
		else if(option == 4){
			printf("\n你確定要退出嗎？(y/n)");
			scanf(" %c", &ch);
	        if(ch == 'y') break;
	        if(ch == 'n') continue;
    	}
    	
		else printf("\n選項無效。\n");
		system("pause");
	}
	printf("\n再見！");
	return 0;
}
