/*
* MSSV: 19110482
* Ho va ten: Huynh Thi Bao Tran
* Assignment: thuc hanh 1
* Create at: 14/11/2021
* IDE: Microsoft Visual Studio 2019
*/

#include<stdio.h>
#include<math.h>
#define MAX_BINARY_LEN 32


int* decimalToBinary(int num) {
	int binaryNumber[MAX_BINARY_LEN] = {0};
	int i = 0;
	while (num > 0) {
		binaryNumber[i] = num % 2;
		i++;
		num /= 2;
	}
	return binaryNumber;
}

void writeLine(int p, int q, int calculation) {
	if (p == 0) {
		printf("\t\tF");
	}
	else {
		printf("\t\tT");
	}
	if (q == 0) {
		printf("\t\tF");
	}
	else {
		printf("\t\tT");
	}
	if (calculation == 0) {
		printf("\t\tF");
	}
	else {
		printf("\t\tT");
	}
	printf("\n");
}

int negationFunc(int p) {
	// phep Phu dinh: ~
	if (p == 1) {
		return 0;
	}
	else
		return 1;
}

int disjunctionFunc(int p, int q) {
	// phep Hay (Hoac): v
	if (p == 0 && q == 0) {
		return 0;
	}
	else
		return 1;
}

int conjuctionFunc(int p, int q) {
	// phep Va: ^
	if (p == 1 && q == 1) {
		return 1;
	}
	else
		return 0;
}

 int biconditionalFunc(int p, int q) {
	 // phep keo theo hai chieu: <->
	if ((p == 1 && q == 1) || (p == 0 && q == 0)) {
		return 1;
	}
	else
		return 0;
}

 int condStatementFunc(int p, int q) {
	 // phep keo theo mot chieu: ->
	 if (p == 1 && q == 0) {
		 return 0;
	 }
	 else
		 return 1;
 }

 void printTable(char key) {
	 int p, q;
	 char osp[5][100] = { "The Truth Table for the Negation of a Proposition", "The Truth Table for the Disjunctions of Two Propositions", "The Truth Table for the Conjunction of Two Propositions", "The Truth Table for the Biconditional p <-> q", "The Truth Table for the Conditional Statement p -> q" };
	 printf("%s \n", osp[key-1]);
	 int opp = 0;
	 switch (key) {
	 case 1:
		 printf("\t\tP \t\tQ \t\t~P \n");
		 break;
	 case 2:
		 printf("\t\tP \t\tQ \t       PvQ \n");
		 break;
	 case 3:
		 printf("\t\tP \t\tQ \t       P^Q \n");
		 break;
	 case 4:
		 printf("\t\tP \t\tQ \t      P<->Q \n");
		 break;
	 case 5:
		 printf("\t\tP \t\tQ \t       P->Q \n");
		 break;
	 }
	 for (int i = 0; i < 4; i++) {
		 int* temp = decimalToBinary(i);
		 p = *temp;
		 q = *(temp + 1);
		 int opp = 0;
		 switch (key) {
		 case 1:
			 opp = negationFunc(p);
			 break;
		 case 2:
			 opp = disjunctionFunc(p, q);
			 break;
		 case 3:
			 opp = conjuctionFunc(p, q);
			 break;
		 case 4:
			 opp = biconditionalFunc(p, q);
			 break;
		 case 5:
			 opp = condStatementFunc(p, q);
			 break;
		 }
		 writeLine(p, q, opp);
	 }
	 printf("\n");
 }

 void check() {
	 int key1, key2;
	 printf("\n Choose:\n 0 is one of the Truth Tables\n 1 is 5 the Truth Tables\n Input: ");
	 scanf_s("%d", &key1);
	 if (key1 == 1) {
		 printf("5 the Truth Tables \n");
		 for (int i = 1; i < 6; i++) {
			 printTable(i);
		 }
	 }
	 else {
		 printf("0 is one of the Truth Tables \n");
		 if (key1 == 0) {
			 int check = 0;
			 while (check == 0) {
				 printf("\n Choose:\n");
				 char osp[5][200] = { "The Truth Table for the Negation of a Proposition", "The Truth Table for the Disjunctions of Two Propositions", "The Truth Table for the Conjunction of Two Propositions", "The Truth Table for the Biconditional p <-> q", "The Truth Table for the Conditional Statement p -> q" };
				 for (int i = 0; i < 5; i++) {
					 printf(" %d is %s\n", i + 1, osp[i]);
				 }
				 printf(" 0 is done\n Input: ");
				 scanf_s("%d", &key2);
				 if (key2 > 0 && key2 < 6) {
					 printTable(key2);
				 }
				 else {
					 if (key2 == 0) {
						 check = 1;
					 }
					 else {
						 printf(" Invalid");
					 }
				 }
			 }
		 }
		 else {
			 printf(" Invalid");
		 }
	 }
 }

int main() {
	printf(" The Truth Table \n");
	check();
	system("pause");
}