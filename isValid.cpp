/*===================================================
Cobain
===================================================*/

#include<stdio.h>
#include<string.h>
#include <ctype.h>

bool isOperasi(char oper);

bool isValid(char input[]){
	bool stack_braked_static[15];
    short int top = -1;
    
    input[strlen(input)] = NULL;
	for (int i = 0; i < 10; i++){
		stack_braked_static[i] = false;
	}
	for(int i = 0; i < strlen(input);i++){
		if((isdigit(input[i]) || isOperasi(input[i]) || (input[i] == '(') || (input[i] == ')') || (input[i] == '.')) && (input[0] == '-' || !(isOperasi(input[0]) || input[0] == '.'))){
			if(input[i] == '(' && !((i != 0 == (isOperasi(input[i-1]) || input[i-1] == '(')) && ((isOperasi(input[i+1]) && input[i+1] == '-') || input[i+1] == '(') || isdigit(input[i+1]))){
				printf("1");
				return false;
			} else if(input[i] == '('){ //this is push stack but not using module because error pointer
				top += 1;
				stack_braked_static[top] = true;
			} else if((input[i] == ')') && !(isOperasi(input[i+1])) && (input[i+1] != NULL)){
				printf("2");
				return false;
			} else if(input[i] == ')' && top > -1){ //this is pop stack but not using module because error pointer
				stack_braked_static[top] = false;
				top -= 1;
			}
			if((isOperasi(input[i]) && isOperasi(input[i+1]) && isOperasi(input[i+2])) || (isOperasi(input[i]) && (isOperasi(input[i+1]) != (input[i+1] == '-')))){
				printf("3");
				return false;
			}
			if((input[i] == '/' && input[i+1] == '0')){ //pengecekan pembagian tidak boleh 0
				int j = i+1;
				while(j <= strlen(input)){
					if(input[j] != '0' && isdigit(input[j])){
						break;
					} else if(operasi(input[j]) || (j == strlen(input))){
						printf("4");
						return false;
					}
					j += 1;
				}
			}
			if((i == strlen(input) - 1)	&& !(isdigit(input[i]) || input[i] == ')')){
				printf("5");
				return false;
			}
		}else{
			printf("6");
			return false;
		}
	}
	if (!(top == -1 && stack_braked_static[0] == false)){
		printf("7");
		return false;
	}
	printf("true");
	return true;
}

bool isOperasi(char oper){
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
		if ((isdigit(input[i]) \/ isOperasi(input[i]) \/ (input[i] = '(') \/ (input[i] = ')') || (input[i] = '.')) /\  input[0] = '-' \/ ~(isOperasi(input[0]) \/ input[0] = '.'))
		  Then if(input[i] = '(' /\ ~((isOperasi(input[i-1]) \/ input[i-1] = '(') /\ ((isOperasi(input[i+1]) /\ input[i+1] = '-') \/ input[i+1] = '(')))
				 Then -> false
			  	 Else if(input[i] = '(')
				        Then top <- top + 1
				             stack_braked_static[top] <- true;
					    Else if((input[i] = ')') /\ ~(isOperasi(input[i+1])) /\ (input[i+1] <> NULL))
						       Then -> false
							   Else if(input[i] = ')' /\ top > -1)
							          Then stack_braked_static[top] <- false;
									   	   top <- top-1
								    Endif
						     Endif
				      Endif
				Endif
			   if((isOperasi(input[i]) /\ isOperasi(input[i+1]) /\ isOperasi(input[i+2])) \/ (isOperasi(input[i]) /\ (isOperasi(input[i+1]) <> (input[i+1] = '-')))){
			     Then -> false
			   Endif
			   if((input[i] = '/' /\ input[i+1] = '0'))
				Then j : integer
				     j = i+1
				     while(j <= strlen(input))
				     if(input[j] <> '0' /\ isdigit(input[j]))
					   Then break
					   Else if(isOperasi(input[j]) || (j == strlen(input)))
						      Then -> false
							Endif
					 Endif
					 j <- j + 1
				     endwhile
			   endif
		  Else -> false
	endfor
	
	if((isOperasi(input[strlen(input)-1])) || (!(top == -1 && stack_braked_static[0] == false)))
	  Then -> false
	endif
	
	-> true
End
=====================================================*/