//	--롯데월드 요금체계 적용하기--
//	권종을 입력받는다. (1DAY, AFTER4)
//	주민등록번호를 입력 받는다. (주민번호를 활용하여 나이를 자동계산한다.)
//	주문 개수를 입력받는다.
//	우대사항을 입력받는다. (없음, 장애인, 국가유공자, 다자녀, 임산부)
//	위의 입력을 반복할 것인지 종료할 것인지 물어본다.
//	종료를 하게되면 지금까지 주문 내역이 모두 출력된다.
//	완전 프로그램 종료를 하게 되면 현재까지의 매출 내역을 파일로 저장한다.


#include <stdio.h>

int main() {
	
	// 필요한 변수들 
	int choice, ticket, juminnum_Front, juminnum_Back, OrderCount, Special, BirthYear, BirthDay, Generation_1900, Generation_2000, age, Price, SpecialPrice, Total;
	
	// 입장권 가격을 상수로 선언 
	const int G_1DAY_ADULT_PRICE = 62000, G_1DAY_TEENAGER_PRICE = 54000, G_1DAY_CHILDREN_PRICE = 47000, G_1DAY_BABY_PRICE = 15000;  		// 종합이용권 1DAY
	const int G_AFTER4_ADULT_PRICE = 50000, G_AFTER4_TEENAGER_PRICE = 43000, G_AFTER4_CHILDREN_PRICE = 36000, G_AFTER4_BABY_PRICE = 15000;  // 종합이용권 AFTER4
	const int P_1DAY_ADULT_PRICE = 59000, P_1DAY_TEENAGER_PRICE = 52000, P_1DAY_CHILDREN_PRICE = 46000, P_1DAY_BABY_PRICE = 15000;			// 파크이용권 1DAY 
	const int P_AFTER4_ADULT_PRICE = 47000, P_AFTER4_TEENAGER_PRICE	= 41000, P_AFTER4_CHILDREN_PRICE = 35000, P_AFTER4_BABY_PRICE = 15000;  // 파크이용권 AFTER4
	
	
	// 기본 UI 
	while(1) {
		printf("\n==========================================\n\n");
		printf("구매하실 이용권을 선택해주세요.\n1. 종합이용권(롯데월드 + 민속박물관)\n2. 파크이용권(롯데월드)\n");
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
		printf("\n권종을 선택해주세요.\n1. 1DAY\n2. AFTER4(오후4시 입장)\n");
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
		printf("\n주민등록번호 앞자리 6자리와 뒷자리 1자리를 입력해주세요.\n앞자리(6자리)\n");
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
		printf("\n뒷자리(한 자리)\n");
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
		printf("\n몇 개를 주문하시겠습니까? (최대 10개)\n");
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
		printf("우대사항을 선택하세요.\n1. 없음(나이 우대는 자동처리)\n2. 장애인 우대\n3. 국가유공자 우대\n4. 휴가장병 우대\n5. 임산부 우대\n6. 다둥이 행복카드 우대\n");
		scanf("%d", &Special);
		printf("\n==========================================\n\n");
		
		if(Special == 1 || Special == 2 || Special ==3 || Special == 4 || Special == 5 || Special == 6){
			break;
		} else
		{
			continue;
		}
	} 
	

//	뒷부분 7자리 맨 앞부분은 성별을 나타내는데 1은 남자, 2는 여자이다.
//	1: 1900 ~ 1999년에 태어난 남성
//	2: 1900 ~ 1999년에 태어난 여성
//	3: 2000 ~ 2099년에 태어난 남성
//	4: 2000 ~ 2099년에 태어난 여성
	
	BirthYear = juminnum_Front/10000;  		 // 생년월일에서 연도 출력  
	BirthDay = juminnum_Front - (BirthYear * 10000);
	
	if(juminnum_Back == 1 || juminnum_Back == 2){
		Generation_1900 = BirthYear + 1900;  // 1900년대생 
	} else if(juminnum_Back == 3 || juminnum_Back == 4){
		Generation_2000 = BirthYear + 2000;  // 2000년대생 
	}
	
	 
	if(BirthDay > 516 && Generation_1900 < 2000)
	{     
		age = 2022 - Generation_1900 - 1;  		  // 만나이 
	}
	else if(BirthDay <= 516 && Generation_1900 < 2000)
	{
		age = 2022 - Generation_1900;	
	}
	
	if(BirthDay > 516 && Generation_2000 >= 2000)
	{
		age = 2022 - Generation_2000 - 1;  			// 만나이 
	}
	else if(BirthDay <= 516 && Generation_2000 >= 2000)   // 그 날이 생일인 사람과 2000년에 태어난 사람도 포함시켜줘야 하니까 = 을 써준다
	{
	 	age = 2022 - Generation_2000;	 	
	}
	
	
	switch(choice){
		case 1:   // 종합이용권 선택했을 때 
			switch(ticket){
				case 1:   // 1DAY 선택했을 때 
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
				
				case 2:  // AFTER4 선택했을 때 
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
				case 1:   // 1DAY 선택했을 때 
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
					
				case 2:  // AFTER4 선택했을 때 
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
			printf("다시 입력해주세요.");
			}
		
	
	// 우대사항 가격
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
				SpecialPrice = Price * 0.49;   // 휴가 장병의 경우 종합이용권만 49 % 우대 
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
		printf("가격은 %d 원 입니다.\n감사합니다.", Total);
		
		return 0;
	}   // 괄호 위치 맞추는 거 주의하기! 괄호 위치가 안맞으면 안돌아갈 수 있음 
	
	
