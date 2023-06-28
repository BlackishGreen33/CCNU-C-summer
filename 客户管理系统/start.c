#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CUSTOMERS 100

struct customer{
    int id;
    char name[20];
    char gender[5];
    int age;
    char phone[20];
    char email[50];
};

// 客户列表 
struct customer customerList[MAX_CUSTOMERS];
int numCustomers = 0;
int nextId = 1;

// 显示菜单
void displayMenu(){
    printf("-------客户管理系统-------\n");
    printf("\t1. 添加客户\n");
    printf("\t2. 修改客户\n");
    printf("\t3. 客户列表\n");
    printf("\t4. 删除客户\n");
    printf("\t5. 退出系统\n");
    printf("\n");
}

// 添加客户
void addCustomer(){
    if(numCustomers >= MAX_CUSTOMERS){
        printf("\n客户列表已满，无法添加新客户\n");
        return;
    }

    struct customer newCustomer;

    newCustomer.id = nextId;
	printf("\n---------添加客户---------\n");
	
    printf("姓名：");
    scanf("%s", newCustomer.name);

    printf("性别：");
    scanf("%s", newCustomer.gender);

    printf("年龄：");
    scanf("%d", &newCustomer.age);

    printf("电话：");
    scanf("%s", newCustomer.phone);

    printf("邮箱：");
    scanf("%s", newCustomer.email);

    customerList[numCustomers] = newCustomer;
    numCustomers++;
    nextId++;

    printf("---------添加完成---------\n");
}

// 修改客户
void modifyCustomer(){
	if(numCustomers == 0){
		printf("\n客户列表为空，无法修改客户资料\n");
		return;
	}

    int id;
	printf("\n---------修改客户---------\n");
	printf("请选择待修改客户编号(-1退出)：");
	scanf("%d", &id);
	if(id == -1) return;

	int i;
	for(i = 0; i < numCustomers; i++){
    	if(customerList[i].id == id){
    		printf("姓名(%s)：", customerList[i].name);
        	scanf("%s", customerList[i].name);

        	printf("性别(%s)：", customerList[i].gender);
        	scanf("%s", customerList[i].gender);

        	printf("年龄(%d)：", customerList[i].age);
        	scanf("%d", &customerList[i].age);

        	printf("电话(%s)：", customerList[i].phone);
        	scanf("%s", customerList[i].phone);

        	printf("邮箱(%s)：", customerList[i].email);
        	scanf("%s", customerList[i].email);

        	printf("---------修改完成---------\n");
        	return;
    	}
	}

	printf("未找到客户\n");
}

// 客户列表
void listCustomers() {
    if(numCustomers == 0){
        printf("\n客户列表为空\n");
        return;
    }

	printf("\n--------------------------客户列表--------------------------\n");
    printf("编号\t姓名\t性别\t年龄\t电话\t\t邮箱\n");
    printf("------------------------------------------------------------\n");

    int i;
    for(i = 0; i < numCustomers; i++)
        printf("%d\t%s\t%s\t%d\t%s\t%s\n", customerList[i].id, customerList[i].name, customerList[i].gender, customerList[i].age, customerList[i].phone, customerList[i].email);
	printf("------------------------客户列表完成------------------------\n");
}

// 删除客户 
void deleteCustomer(){
    if(numCustomers == 0){
        printf("客户列表为空，无法删除客户\n");
        return;
    }

    int id;
    printf("\n---------删除客户---------\n");
    printf("请选择待删除客户编号(-1退出)：");
    scanf("%d", &id);
    if(id == -1) return;
    
    char rec;
    printf("确认是否删除(y/n)：");
    scanf(" %c", &rec);
    
    if(rec == 'y'){
    	int i, j;
    	for(i = 0; i < numCustomers; i++)
        	if(customerList[i].id == id){
            	for(j = i; j < numCustomers - 1; j++)
                	customerList[j] = customerList[j + 1];
            	numCustomers--;
            	printf("---------删除完成---------\n");
            	return;
        	}
	}
	if(rec == 'n') return;
}

int main(){
    int choice;

    while(1){
    	system("cls");
        displayMenu();
        printf("\t请选择(1~5)：");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addCustomer();
                system("pause");
                break;
            case 2:
                modifyCustomer();
                system("pause");
                break;
            case 3:
                listCustomers();
                system("pause");
                break;
            case 4:
                deleteCustomer();
                system("pause");
                break;
            case 5:
                printf("\n感谢使用客户管理系统，再见！\n");
                system("pause");
                return 0;
            default:
                printf("\n无效的操作序号，请重新输入\n");
                system("pause");
                break;
        }
    }
    return 0;
}