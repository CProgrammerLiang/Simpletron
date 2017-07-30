#include <stdio.h>
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBSTRACT 31
#define DEVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
main(){
	int instructionCounter,operationCode,operand;
	signed accumulator,instructionRegister;
	int  memory[100];
	accumulator=+0000;
	instructionRegister=+0000;
	instructionCounter=00;
	operationCode=00;
	operand=00;
	printf("***WELCOME TO SIMPLETRON***"); 
	for(instructionCounter=0;instructionCounter<=99;instructionCounter++)
	{
		while(operand<=99)
		{
			scanf("%d",&memory[instructionCounter]);
			instructionRegister=memory[instructionCounter];
			operationCode=instructionRegister/100;
			operand=instructionRegister%100;
			switch (operationCode)
			{
				case READ:{
					scanf("%d",&memory[operand]);
					break;
					}	
				case WRITE:{
					printf("%d\n",memory[operand]);	
					break;
					}
				case LOAD:{
					accumulator=memory[operand];
					break;
					}	
				case STORE:{
					memory[operand]=accumulator;
					break;
					}
				case ADD:{
					accumulator+=memory[operand];
					break;
					}
				case SUBSTRACT:{
					accumulator-=memory[operand];
					break;
					}
				case DEVIDE:{
					accumulator*=memory[operand];
					break;
					}
				case MULTIPLY:{
					accumulator/=memory[operand];
					break;
					}
				case BRANCH:{
					operand=instructionCounter;
					break;
					}
				case BRANCHZERO:{
					if (accumulator==0)
					{
						operand=instructionCounter;
					}
					break;
					}	
				case BRANCHNEG:{
					if (accumulator<0)
					{
						operand=instructionCounter;
					}
					break;
					}	
				case -99999:{
					break;
				}
				default:{
	                printf("%s\n","invalid choice");
	                break;
				}											
			}
		}
	}
	printf("%s\n", "program over");
}
