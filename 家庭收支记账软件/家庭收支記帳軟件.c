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
		printf("--------�a�x����O�b�n��--------\n");
		printf("\t1. �������\n");
		printf("\t2. �n�O���J\n");
		printf("\t3. �n�O��X\n");
//		printf("\t4. �d�ݤ�X�Φ��J\n");
		printf("\t4. �h  �X\n\n");
		printf("\t�п��(1~4):");
		scanf("%d", &option);

    	if(option == 2 || option == 3){
			if(num_transactions == MAX_TRANSACTIONS){
				printf("�w�F��̤j����ƶq�C\n");
				continue;
			}
			struct Transaction t;
			printf("\n�������J���B: ");
			scanf("%f", &t.amount);
			printf("�������J����: ");
			scanf("%s", t.description);
		
			if (option == 3){
				t.amount = -t.amount; 
				strcpy(t.type, "��X");
			}
			else strcpy(t.type, "���J");
			transactions[num_transactions++] = t;
			printf("\n������\�K�[\n");
			system("pause");
		} 
		
		else if(option == 1){
			if(num_transactions == 0){
				printf("\n��e�S���������...�Ӥ@���a�I\n");
				system("pause");
				continue;
			}

			float total = 0;
			printf("\n����\t\t������B\t�b����B\t��  ��\n");
			printf("-------------------------------------------------------\n");
			for (int i = 0; i < num_transactions; i++) {
				struct Transaction t = transactions[i];
				printf("%s\t\t%.2f\t\t%.2f\t\t%s\n", t.type, t.amount, total + t.amount, t.description);
				total += t.amount;
			}
			printf("-------------------------------------------------------\n");
			printf("�ثe�b����B\t\t\t\t\t%.2f\n", total);
			system("pause");
		}
		
//		else if (option == 4) {
//			if (num_transactions == 0) {
//				printf("\n�S������O���C\n");
//				continue;
//			}
//
//			char type[8];
//			printf("\n�п�J���� (��X/���J): ");
//			scanf("%s", type);
//
//			float total = 0;
//    		printf("\n�y�z\t\t���B\n");
//    		printf("-------------------------------------------------------\n");
//    		for (int i = 0; i < num_transactions; i++) {
//    			struct Transaction t = transactions[i];
//    			if (strcmp(t.type, type) == 0) {
//        			printf("%s\t\t%.2f\n", t.description, t.amount);
//        			total += t.amount;
//				}
//    		}
//    		printf("-------------------------------------------------------\n");
//    		printf("�`%s\t\t\t\t%.2f\n", type, total);
//		}
		
		else if(option == 4){
			printf("\n�A�T�w�n�h�X�ܡH(y/n)");
			scanf(" %c", &ch);
	        if(ch == 'y') break;
	        if(ch == 'n') continue;
    	}
    	
		else printf("\n�ﶵ�L�ġC\n");
		system("pause");
	}
	printf("\n�A���I");
	return 0;
}
