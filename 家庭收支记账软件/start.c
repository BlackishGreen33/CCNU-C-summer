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
    int num_transactions = 0, option;
    char ch;

    while(1){
        system("cls");
        printf("--------家庭收支记账软件--------\n");
        printf("\t1. 收支明细\n");
        printf("\t2. 登记收入\n");
        printf("\t3. 登记支出\n");
        printf("\t4. 退  出\n\n");
        printf("\t请选择(1~4):");
        scanf("%d", &option);

        if(option == 2 || option == 3){
            if(num_transactions == MAX_TRANSACTIONS){
                printf("已达到最大交易数量。\n");
                continue;
            }
            struct Transaction t;
            printf("\n本次金额: ");
            scanf("%f", &t.amount);
            printf("本次说明: ");
            scanf("%s", t.description);

            if(option == 3){
                t.amount = -t.amount; 
                strcpy(t.type, "支出");
                float total = 0;
                for(int i = 0; i < num_transactions; i++){
                    struct Transaction t = transactions[i];
                    total += t.amount;
                }
                if(total + t.amount < 0){
                    printf("\n余额不足，不能记录支出。\n");
                    system("pause");
                    continue;
                }
            }
            else strcpy(t.type, "收入");
            transactions[num_transactions++] = t;
            printf("\n记录成功添加。\n");
            system("pause");
        } 
    
        else if(option == 1){
            if(num_transactions == 0){
                printf("\n当前没有收支记录...来一笔吧！\n");
                system("pause");
                continue;
            }

            float total = 0;
            printf("\n收支\t\t收支金额\t账户金额\t说明\n");
            printf("-------------------------------------------------------\n");
            for (int i = 0; i < num_transactions; i++) {
                struct Transaction t = transactions[i];
                printf("%s\t\t%.2f\t\t%.2f\t\t%s\n", t.type, t.amount, total + t.amount, t.description);
                total += t.amount;
            }
            printf("-------------------------------------------------------\n");
            printf("当前账户金额\t\t\t\t\t%.2f\n", total);
            system("pause");
        }
    
        else if(option == 4){
            printf("\n你确定要退出吗？(y/n)");
            scanf(" %c", &ch);
            if(ch == 'y') break;
            if(ch == 'n') continue;
        }
    
        else{
		    printf("\n选项无效。\n");
		    system("pause");
	    }
    }
    printf("\n再见！");
    return 0;
}
