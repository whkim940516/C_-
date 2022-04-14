//	--�Ե����� ���ü�� �����ϱ�--
//	������ �Է¹޴´�. (1DAY, AFTER4)
//	�ֹε�Ϲ�ȣ�� �Է� �޴´�. (�ֹι�ȣ�� Ȱ���Ͽ� ���̸� �ڵ�����Ѵ�.)
//	�ֹ� ������ �Է¹޴´�.
//	�������� �Է¹޴´�. (����, �����, ����������, ���ڳ�, �ӻ��)
//	���� �Է��� �ݺ��� ������ ������ ������ �����.
//	���Ḧ �ϰԵǸ� ���ݱ��� �ֹ� ������ ��� ��µȴ�.
//	���� ���α׷� ���Ḧ �ϰ� �Ǹ� ��������� ���� ������ ���Ϸ� �����Ѵ�.


#include <stdio.h>

int main() {
	
	// �ʿ��� ������ 
	int choice, ticket, juminnum_Front, juminnum_Back, OrderCount, Special, BirthYear, BirthDay, Generation_1900, Generation_2000, age, Price, SpecialPrice, Total;
	
	// ����� ������ ����� ���� 
	const int G_1DAY_ADULT_PRICE = 62000, G_1DAY_TEENAGER_PRICE = 54000, G_1DAY_CHILDREN_PRICE = 47000, G_1DAY_BABY_PRICE = 15000;  		// �����̿�� 1DAY
	const int G_AFTER4_ADULT_PRICE = 50000, G_AFTER4_TEENAGER_PRICE = 43000, G_AFTER4_CHILDREN_PRICE = 36000, G_AFTER4_BABY_PRICE = 15000;  // �����̿�� AFTER4
	const int P_1DAY_ADULT_PRICE = 59000, P_1DAY_TEENAGER_PRICE = 52000, P_1DAY_CHILDREN_PRICE = 46000, P_1DAY_BABY_PRICE = 15000;			// ��ũ�̿�� 1DAY 
	const int P_AFTER4_ADULT_PRICE = 47000, P_AFTER4_TEENAGER_PRICE	= 41000, P_AFTER4_CHILDREN_PRICE = 35000, P_AFTER4_BABY_PRICE = 15000;  // ��ũ�̿�� AFTER4
	
	
	// �⺻ UI 
	while(1) {
		printf("\n==========================================\n\n");
		printf("�����Ͻ� �̿���� �������ּ���.\n1. �����̿��(�Ե����� + �μӹڹ���)\n2. ��ũ�̿��(�Ե�����)\n");
		scanf("%d", &choice);
		printf("\n==========================================\n\n");
		
		if(choice == 1|| choice == 2) {
			break;   
		} else
		{
			continue;   
		}
		printf("\n");
	}
	
	while(1) {
		printf("\n������ �������ּ���.\n1. 1DAY\n2. AFTER4(����4�� ����)\n");
		scanf("%d", &ticket);
		printf("\n==========================================\n\n");
		
		if(ticket == 1 || ticket == 2) {
			break;
		} else
		{
			continue;
		}
		printf("\n");
	}
	
	while(1) {
		printf("\n�ֹε�Ϲ�ȣ ���ڸ� 6�ڸ��� ���ڸ� 1�ڸ��� �Է����ּ���.\n���ڸ�(6�ڸ�)\n");
		scanf("%d", &juminnum_Front);
		printf("\n==========================================\n\n");
		
		if(juminnum_Front > 000001 || juminnum_Front < 999999) {
			break;
		} else
		{
			continue;
		}
		printf("\n");
	}
	
	while(1) {
		printf("\n���ڸ�(�� �ڸ�)\n");
		scanf("%1d", &juminnum_Back);
		printf("\n==========================================\n\n");
		
		if(juminnum_Back == 1|| juminnum_Back ==2 || juminnum_Back == 3|| juminnum_Back == 4) {
			break;
		} else
		{
			continue;
		}
		printf("\n");
	}
	
	while(1) {
		printf("\n�� ���� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
		scanf("%d", &OrderCount);
		printf("\n==========================================\n\n");
		
		if(OrderCount >= 1 || OrderCount < 11) {
			break;
		} else
		{
			continue;
		}
		printf("\n");
	}
	
	while(1) {
		printf("�������� �����ϼ���.\n1. ����(���� ���� �ڵ�ó��)\n2. ����� ���\n3. ���������� ���\n4. �ް��庴 ���\n5. �ӻ�� ���\n6. �ٵ��� �ູī�� ���\n");
		scanf("%d", &Special);
		printf("\n==========================================\n\n");
		
		if(Special == 1 || Special == 2 || Special ==3 || Special == 4 || Special == 5 || Special == 6){
			break;
		} else
		{
			continue;
		}
	} 
	

//	�޺κ� 7�ڸ� �� �պκ��� ������ ��Ÿ���µ� 1�� ����, 2�� �����̴�.
//	1: 1900 ~ 1999�⿡ �¾ ����
//	2: 1900 ~ 1999�⿡ �¾ ����
//	3: 2000 ~ 2099�⿡ �¾ ����
//	4: 2000 ~ 2099�⿡ �¾ ����
	
	BirthYear = juminnum_Front/10000;  		 // ������Ͽ��� ���� ���  
	BirthDay = juminnum_Front - (BirthYear * 10000);
	
	if(juminnum_Back == 1 || juminnum_Back == 2){
		Generation_1900 = BirthYear + 1900;  // 1900���� 
	} else if(juminnum_Back == 3 || juminnum_Back == 4){
		Generation_2000 = BirthYear + 2000;  // 2000���� 
	}
	
	 
	if(BirthDay > 516 && Generation_1900 < 2000)
	{     
		age = 2022 - Generation_1900 - 1;  		  // ������ 
	}
	else if(BirthDay <= 516 && Generation_1900 < 2000)
	{
		age = 2022 - Generation_1900;	
	}
	
	if(BirthDay > 516 && Generation_2000 >= 2000)
	{
		age = 2022 - Generation_2000 - 1;  			// ������ 
	}
	else if(BirthDay <= 516 && Generation_2000 >= 2000)   // �� ���� ������ ����� 2000�⿡ �¾ ����� ���Խ������ �ϴϱ� = �� ���ش�
	{
	 	age = 2022 - Generation_2000;	 	
	}
	
	
	switch(choice){
		case 1:   // �����̿�� �������� �� 
			switch(ticket){
				case 1:   // 1DAY �������� �� 
					if(age <= 3)
					{
						Price = G_1DAY_BABY_PRICE;
					} else if(age > 3 && age <= 12)
					{
						Price = G_1DAY_CHILDREN_PRICE;
					} else if(age > 12 && age <= 18)
					{
						Price = G_1DAY_TEENAGER_PRICE;
					} else if(age > 19 && age < 65)
					{
						Price = G_1DAY_ADULT_PRICE;
					} else if(age >= 65)
					{
						Price = G_1DAY_CHILDREN_PRICE;
					}
					break; 
				
				case 2:  // AFTER4 �������� �� 
					if(age <= 3)
					{
						Price = G_AFTER4_BABY_PRICE;
					} 	else if(age > 3 && age <= 12)
					{
						Price = G_AFTER4_CHILDREN_PRICE;
					}  	else if(age > 12 && age <= 18)
					{
						Price = G_AFTER4_TEENAGER_PRICE;
					}	else if(age > 19 && age < 65)
					{
						Price = G_AFTER4_ADULT_PRICE;
					}	else if(age >= 65)
					{
						Price = G_AFTER4_CHILDREN_PRICE;
					}
					break;	
			}
			break;
			
		case 2:
			switch(ticket){
				case 1:   // 1DAY �������� �� 
					if(age <= 3)
					{
						Price = P_1DAY_BABY_PRICE;
					} else if(age > 3 && age <= 12)
					{
						Price = P_1DAY_CHILDREN_PRICE;
					} else if(age > 12 && age <= 18)
					{
						Price = P_1DAY_TEENAGER_PRICE;
					} else if(age > 19 && age < 65)
					{
						Price = P_1DAY_ADULT_PRICE;
					} else if(age >= 65)
					{
						Price = P_1DAY_CHILDREN_PRICE;
					}
					break;
					
				case 2:  // AFTER4 �������� �� 
					if(age <= 3)
					{
						Price = P_AFTER4_BABY_PRICE;
					} 	else if(age > 3 && age <= 12)
					{
						Price = P_AFTER4_CHILDREN_PRICE;
					}  	else if(age > 12 && age <= 18)
					{
						Price = P_AFTER4_TEENAGER_PRICE;
					}	else if(age > 19 && age < 65)
					{
						Price = P_AFTER4_ADULT_PRICE;
					}	else if(age >= 65)
					{
						Price = P_AFTER4_CHILDREN_PRICE;
					}
					break;	
			}
			break;
			
		default :
			printf("�ٽ� �Է����ּ���.");
			}
		
	
	// ������ ����
	switch(Special) {
		case 1:
			SpecialPrice = Price;
			break;	
		
		case 2:
			SpecialPrice = Price * 0.5;
			break;
		
		case 3:
			SpecialPrice = Price * 0.5;
			break;
		
		case 4:  
			if(choice == 1)
			{
				SpecialPrice = Price * 0.49;   // �ް� �庴�� ��� �����̿�Ǹ� 49 % ��� 
			} else if(choice == 2)
			{
				SpecialPrice = Price;
			}
			break;
		
		case 5:
			if(choice == 1)
			{
				SpecialPrice = Price * 0.5;
			} else if(choice == 2)
			{
				SpecialPrice = Price;
			}
			break;
		
		case 6:
			if(choice == 1)
			{
				SpecialPrice = Price * 0.3;
			} else if(choice == 2)
			{
				SpecialPrice = Price;
			}
			break;
		}
		
		Total = SpecialPrice * OrderCount;
		printf("������ %d �� �Դϴ�.\n�����մϴ�.", Total);
		
		return 0;
	}   // ��ȣ ��ġ ���ߴ� �� �����ϱ�! ��ȣ ��ġ�� �ȸ����� �ȵ��ư� �� ���� 
	
	
