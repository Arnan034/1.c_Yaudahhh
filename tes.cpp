/*===================================================
Cobain
===================================================*/

#include<stdio.h>
#include<string.h>
#include <ctype.h>

bool operasi(char oper);

int main(){
	char input[200];
	scanf("%s", &input);
	bool stack_braked_static[15];
    short int top = -1;
    
    input[strlen(input)] = NULL;
	for (int i = 0; i < 10; i++){
		stack_braked_static[i] = false;
	}
	for(int i = 0; i < strlen(input);i++){
		if(input[i] == '(' && !((operasi(input[i-1]) || input[i-1] == '(') && ((operasi(input[i+1]) && input[i+1] == '-') || input[i+1] == '('))){
			printf("operasi salah");
			return 1;
		} else if(input[i] == '('){ //this is push stack but not using module because error pointer
			top += 1;
			stack_braked_static[top] = true;
		} else if((input[i] == ')') && !(operasi(input[i+1])) && (input[i+1] != NULL)){
			printf("operasi salah");
			return 1;
		} else if(input[i] == ')' && top > -1){ //this is pop stack but not using module because error pointer
			stack_braked_static[top] = false;
			top -= 1;
		}
		if((operasi(input[i]) && operasi(input[i+1]) && operasi(input[i+2])) || (operasi(input[i]) && (operasi(input[i+1]) != (input[i+1] == '-')))){
			printf("Operasi salah");
			return 1;
		}
		if(isalpha(input[i])){//dalam penginputan terdapat angka
			printf("Operasi salah");
			return 1;
		}
		if((input[i] == '/' && input[i+1] == '0')){ //pengecekan pembagian tidak boleh 0
			int j = i+1;
			while(j <= strlen(input)){
				if(input[j] != '0' && isdigit(input[j])){
					break;
				} else if(operasi(input[j]) || (j == strlen(input))){
					printf("operasi salah");
					return 1;
				}
				j += 1;
			}
		}
	}
	if(operasi(input[strlen(input)-1])){
		printf("Operasi Salah");
		return 1;
	}
	if (!(top == -1 && stack_braked_static[0] == false)){
		printf("operasi salah");
		return 1;
	}
	printf("operasi benar");
	return 0;
}

bool operasi(char oper){
	if(oper == '+' || oper == '-' || oper == '*' || oper == '/'){
		return true;
	}
	return false;
}

/*==========Implementasi Psedoucode===========
function isValid(keyboard[] : char) -> boolean
bracked : integer
stack_braked_static : array of boolean 15 element
top : short integer
i : integer
Begin
	top<- -1
	
	for i <- 0 in i < 15 do
		stack_braked_static[i] <- false
	endfor
	
	for i <- 0 in i < strlen(input) do
		if(input[i] = '(' /\ ~((operasi(input[i-1]) \/ input[i-1] = '(') /\ ((operasi(input[i+1]) /\ input[i+1] = '-') \/ input[i+1] = '(')))
		  Then -> false
		  Else if(input[i] = '(')
			     Then top <- top + 1
			          stack_braked_static[top] <- true;
				 Else if((input[i] = ')') /\ ~(operasi(input[i+1])) /\ (input[i+1] <> NULL))
					    Then -> false
						Else if(input[i] = ')' /\ top > -1)
							   Then stack_braked_static[top] <- false;
									top <- top-1
							 Endif
					  Endif
			   Endif
		Endif
		
		if((operasi(input[i]) /\ operasi(input[i+1]) /\ operasi(input[i+2])) \/ (operasi(input[i]) /\ (operasi(input[i+1]) <> (input[i+1] = '-')))){
		  Then -> false
		Endif
		if(isalpha(input[i]))
		  Then -> false
		Endif
		if((input[i] = '/' /\ input[i+1] = '0'))
			j : integer
			j = i+1
			while(j <= strlen(input))
				if(input[j] <> '0' /\ isdigit(input[j]))
				  Then break
				  Else if(operasi(input[j]) || (j == strlen(input)))
					     Then -> false
						Endif
				Endif
				j <- j + 1
			endwhile
		endif
	endfor
	
	if((operasi(input[strlen(input)-1])) || (!(top == -1 && stack_braked_static[0] == false)))
	  Then -> false
	endif
	
	-> true
End
=====================================================*/