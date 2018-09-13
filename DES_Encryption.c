//Key = 0001001100110100010101110111100110011011101111001101111111110001

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int PC1[]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,
30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};

int PC2[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,
46,42,50,36,29,32};

int IP[]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,
 59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};

 int IP_inv[]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,
 35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};

int E[]={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,
 28,29,30,31,32,1};

int s1[4][16]=
{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
 0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
 4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
 15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13};

int s2[4][16]=
{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
 3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
 0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
 13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9};

int s3[4][16]=
{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
 13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
 13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
 1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12};

int s4[4][16]=
{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
 13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
 10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
 3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14};

int s5[4][16]=
{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
 14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
 4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
 11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3};

int s6[4][16]=
{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
 10,15,4,2,7,12,9,5,6,1,12,14,0,11,3,8,
 9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
 4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13};

int s7[4][16]=
{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
 13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
 1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
 6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12};

int s8[4][16]=
{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
 1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
 7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
 2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11};

int sb_permutation[]={16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};

int key_shift_amounts[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

void xor(char str1[], char str2[], char output[], int n)
{
	int i;
	for(i=0;i<n;i++)
    	output[i] = ((str1[i]-'0') ^ (str2[i]-'0')) + '0';
    output[i] = '\0';
}

void divide(char text[], int n, char left[], char right[])
{
	int i,j;
	for(i=0;i<n;i++)
		left[i] = text[i];
	left[i] = '\0';

	for(j=0,i=n;j<n,i<2*n;i++,j++)
		right[j] = text[i];
	right[j] = '\0';
}

void merge(char A[], char B[], int n, char combined[])
{
	int i,j;
	for(i=0;i<n;i++)
		combined[i] = A[i];
	for(j=0;j<n;j++)
		combined[i++] = B[j];
	combined[i] = '\0';
}

void permute(char original[], char permuted[], int permute_array[], int n)
{
	int i;
	for(i=0;i<n;i++)
		permuted[i] = original[permute_array[i]-1];
	permuted[i] = '\0';
}

void left_circular_shift(char C[], char D[], char C_[], char D_[], int shift)
{
	int i,j;
	for(i=0,j=shift;i<strlen(C),j<strlen(C);i++,j++)
		C_[i] = C[j];
	for(j=0;j<shift;j++)
		C_[i++] = C[j];
	C_[i] = '\0';

	for(i=0,j=shift;i<strlen(D),j<strlen(D);i++,j++)
		D_[i] = D[j];
	for(j=0;j<shift;j++)
		D_[i++] = D[j];
	D_[i] = '\0';
}

void binary_to_hexa(char input[])
{
	int i,j=0;
	char digit[5];
	char output[17];
	int m=0;
	FILE *off;
	off=fopen("b.txt","a");
	for(i=0;i<65;i++)
	{
		if(i%4 == 0 && i != 0)
		{
			digit[j] = '\0';
			j=0;
			if(digit[0]=='0' && digit[1]=='0' && digit[2]=='0' && digit[3]=='0')
				output[m++]='0';
			if(digit[0]=='0' && digit[1]=='0' && digit[2]=='0' && digit[3]=='1')
				output[m++]='1';
			if(digit[0]=='0' && digit[1]=='0' && digit[2]=='1' && digit[3]=='0')
				output[m++]='2';
			if(digit[0]=='0' && digit[1]=='0' && digit[2]=='1' && digit[3]=='1')
				output[m++]='3';
			if(digit[0]=='0' && digit[1]=='1' && digit[2]=='0' && digit[3]=='0')
				output[m++]='4';
			if(digit[0]=='0' && digit[1]=='1' && digit[2]=='0' && digit[3]=='1')
				output[m++]='5';
			if(digit[0]=='0' && digit[1]=='1' && digit[2]=='1' && digit[3]=='0')
				output[m++]='6';
			if(digit[0]=='0' && digit[1]=='1' && digit[2]=='1' && digit[3]=='1')
				output[m++]='7';
			if(digit[0]=='1' && digit[1]=='0' && digit[2]=='0' && digit[3]=='0')
				output[m++]='8';
			if(digit[0]=='1' && digit[1]=='0' && digit[2]=='0' && digit[3]=='1')
				output[m++]='9';
			if(digit[0]=='1' && digit[1]=='0' && digit[2]=='1' && digit[3]=='0')
				output[m++]='a';
			if(digit[0]=='1' && digit[1]=='0' && digit[2]=='1' && digit[3]=='1')
				output[m++]='b';
			if(digit[0]=='1' && digit[1]=='1' && digit[2]=='0' && digit[3]=='0')
				output[m++]='c';
			if(digit[0]=='1' && digit[1]=='1' && digit[2]=='0' && digit[3]=='1')
				output[m++]='d';
			if(digit[0]=='1' && digit[1]=='1' && digit[2]=='1' && digit[3]=='0')
				output[m++]='e';
			if(digit[0]=='1' && digit[1]=='1' && digit[2]=='1' && digit[3]=='1')
				output[m++]='f';
			digit[j++] = input[i];
		}
		else
			digit[j++] = input[i];
	}
	output[m]='\0';
	for(i=0;i<16;i++)
        fprintf(off,"%c",output[i]);
	//printf("%s",output);
	//printf("\n");
	fclose(off);
}

int binary_to_decimal(char input[],int length)
{
	int multiplier = 0,sum = 0,i;
	for(i=length-1;i>=0;i--)
	{
		int n = pow(2,multiplier++);
		sum += (input[i]-'0')*n;
	}
	return sum;
}

long decimal_to_binary(int num)
{
	long remainder, base = 1, binary = 0;
  	while (num > 0)
    {
    	remainder = num % 2;
        binary = binary + remainder * base;
        num = num / 2;
        base = base * 10;
    }
    return binary;
}

void f(char text[], char key[], char out[])
{
	char temp1[49], temp2[49];
	char B1[7],B2[7],B3[7],B4[7],B5[7],B6[7],B7[7],B8[7];
	char output[33];
	int i,j=0;
	permute(text,temp1,E,48);
	xor(temp1,key,temp2,48);
	//printf("%s\n",temp2);
	for(i=0;i<6;i++)
		B1[i] = temp2[i];
	B1[i] = '\0';
	for(i=6;i<12;i++)
		B2[j++] = temp2[i];
	B2[j] = '\0';
	j=0;
	for(i=12;i<18;i++)
		B3[j++] = temp2[i];
	B3[j] = '\0';
	j=0;
	for(i=18;i<24;i++)
		B4[j++] = temp2[i];
	B4[j] = '\0';
	j=0;
	for(i=24;i<30;i++)
		B5[j++] = temp2[i];
	B5[j] = '\0';
	j=0;
	for(i=30;i<36;i++)
		B6[j++] = temp2[i];
	B6[j] = '\0';
	j=0;
	for(i=36;i<42;i++)
		B7[j++] = temp2[i];
	B7[j] = '\0';
	j=0;
	for(i=42;i<48;i++)
		B8[j++] = temp2[i];
	B8[j] = '\0';

	char row[3], column[5];
	char binoutput[5];
	int r,c,value,binout;
	i=0;

	row[0] = B1[0];row[1] = B1[5];row[2] = '\0';
	column[0] = B1[1];column[1] = B1[2];column[2] = B1[3];column[3] = B1[4];column[4] = '\0';
	//printf("%s\n", B1);
	r = binary_to_decimal(row,2);
	c = binary_to_decimal(column,4);
	//printf("%d %d\n", r,c);
	value = s1[r][c];
	binout = decimal_to_binary(value);
	sprintf(binoutput, "%d", binout);
	//printf("%s\n", binoutput);
	if (value <= 1)
		{output[i++] = '0';output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];}
	else if(value > 1 && value <= 3)
		{output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];}
	else if(value > 3 && value <= 7)
		{output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];}
	else
		{output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];output[i++] = binoutput[3];}
	output[i] = '\0';
	//printf("%s\n\n", output);

	row[0] = B2[0];row[1] = B2[5];row[2] = '\0';
	column[0] = B2[1];column[1] = B2[2];column[2] = B2[3];column[3] = B2[4];column[4] = '\0';
	//printf("%s\n", B2);
	r = binary_to_decimal(row,2);
	c = binary_to_decimal(column,4);
	//printf("%d %d\n", r,c);
	value = s2[r][c];
	binout = decimal_to_binary(value);
	sprintf(binoutput, "%d", binout);
	//printf("%s\n", binoutput);
	if (value <= 1)
		{output[i++] = '0';output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];}
	else if(value > 1 && value <= 3)
		{output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];}
	else if(value > 3 && value <= 7)
		{output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];}
	else
		{output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];output[i++] = binoutput[3];}
	output[i] = '\0';
	//printf("%s\n\n", output);

	row[0] = B3[0];row[1] = B3[5];row[2] = '\0';
	column[0] = B3[1];column[1] = B3[2];column[2] = B3[3];column[3] = B3[4];column[4] = '\0';
	//printf("%s\n", B3);
	r = binary_to_decimal(row,2);
	c = binary_to_decimal(column,4);
	//printf("%d %d\n", r,c);
	value = s3[r][c];
	binout = decimal_to_binary(value);
	sprintf(binoutput, "%d", binout);
	//printf("%s\n", binoutput);
	if (value <= 1)
		{output[i++] = '0';output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];}
	else if(value > 1 && value <= 3)
		{output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];}
	else if(value > 3 && value <= 7)
		{output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];}
	else
		{output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];output[i++] = binoutput[3];}
	output[i] = '\0';
	//printf("%s\n\n", output);

	row[0] = B4[0];row[1] = B4[5];row[2] = '\0';
	column[0] = B4[1];column[1] = B4[2];column[2] = B4[3];column[3] = B4[4];column[4] = '\0';
	//printf("%s\n", B4);
	r = binary_to_decimal(row,2);
	c = binary_to_decimal(column,4);
	//printf("%d %d\n", r,c);
	value = s4[r][c];
	binout = decimal_to_binary(value);
	sprintf(binoutput, "%d", binout);
	//printf("%s\n", binoutput);
	if (value <= 1)
		{output[i++] = '0';output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];}
	else if(value > 1 && value <= 3)
		{output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];}
	else if(value > 3 && value <= 7)
		{output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];}
	else
		{output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];output[i++] = binoutput[3];}
	output[i] = '\0';
	//printf("%s\n\n", output);

	row[0] = B5[0];row[1] = B5[5];row[2] = '\0';
	column[0] = B5[1];column[1] = B5[2];column[2] = B5[3];column[3] = B5[4];column[4] = '\0';
	//printf("%s\n", B5);
	r = binary_to_decimal(row,2);
	c = binary_to_decimal(column,4);
	//printf("%d %d\n", r,c);
	value = s5[r][c];
	binout = decimal_to_binary(value);
	sprintf(binoutput, "%d", binout);
	//printf("%s\n", binoutput);
	if (value <= 1)
		{output[i++] = '0';output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];}
	else if(value > 1 && value <= 3)
		{output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];}
	else if(value > 3 && value <= 7)
		{output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];}
	else
		{output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];output[i++] = binoutput[3];}
	output[i] = '\0';
	//printf("%s\n\n", output);

	row[0] = B6[0];row[1] = B6[5];row[2] = '\0';
	column[0] = B6[1];column[1] = B6[2];column[2] = B6[3];column[3] = B6[4];column[4] = '\0';
	//printf("%s\n", B6);
	r = binary_to_decimal(row,2);
	c = binary_to_decimal(column,4);
	//printf("%d %d\n", r,c);
	value = s6[r][c];
	binout = decimal_to_binary(value);
	sprintf(binoutput, "%d", binout);
	//printf("%s\n", binoutput);
	if (value <= 1)
		{output[i++] = '0';output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];}
	else if(value > 1 && value <= 3)
		{output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];}
	else if(value > 3 && value <= 7)
		{output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];}
	else
		{output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];output[i++] = binoutput[3];}
	output[i] = '\0';
	//printf("%s\n\n", output);

	row[0] = B7[0];row[1] = B7[5];row[2] = '\0';
	column[0] = B7[1];column[1] = B7[2];column[2] = B7[3];column[3] = B7[4];column[4] = '\0';
	//printf("%s\n", B7);
	r = binary_to_decimal(row,2);
	c = binary_to_decimal(column,4);
	//printf("%d %d\n", r,c);
	value = s7[r][c];
	binout = decimal_to_binary(value);
	sprintf(binoutput, "%d", binout);
	//printf("%s\n", binoutput);
	if (value <= 1)
		{output[i++] = '0';output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];}
	else if(value > 1 && value <= 3)
		{output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];}
	else if(value > 3 && value <= 7)
		{output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];}
	else
		{output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];output[i++] = binoutput[3];}
	output[i] = '\0';
	//printf("%s\n\n", output);

	row[0] = B8[0];row[1] = B8[5];row[2] = '\0';
	column[0] = B8[1];column[1] = B8[2];column[2] = B8[3];column[3] = B8[4];column[4] = '\0';
	//printf("%s\n", B8);
	r = binary_to_decimal(row,2);
	c = binary_to_decimal(column,4);
	//printf("%d %d\n", r,c);
	value = s8[r][c];
	binout = decimal_to_binary(value);
	sprintf(binoutput, "%d", binout);
	//printf("%s\n", binoutput);
	if (value <= 1)
		{output[i++] = '0';output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];}
	else if(value > 1 && value <= 3)
		{output[i++] = '0';output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];}
	else if(value > 3 && value <= 7)
		{output[i++] = '0';output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];}
	else
		{output[i++] = binoutput[0];output[i++] = binoutput[1];output[i++] = binoutput[2];output[i++] = binoutput[3];}
	output[i] = '\0';
	//printf("%s\n", output);

	permute(output,out,sb_permutation,32);
	//printf("%s\n", out);
}

int main()
{
	char plaintext[65], permuted_key[57], permuted_plaintext[65],output1[65],output2[65];
	char L0[33],R0[33],L1[33],R1[33],L2[33],R2[33],L3[33],R3[33],L4[33],R4[33],L5[33],R5[33],L6[33],R6[33],L7[33],R7[33],L8[33],R8[33],L9[33],R9[33],L10[33],R10[33],L11[33],R11[33],L12[33],R12[33],L13[33],R13[33],L14[33],R14[33],L15[33],R15[33],L16[33],R16[33];
	char C0[29],D0[29],C1[29],D1[29],C2[29],D2[29],C3[29],D3[29],C4[29],D4[29],C5[29],D5[29],C6[29],D6[29],C7[29],D7[29],C8[29],D8[29],C9[29],D9[29],C10[29],D10[29],C11[29],D11[29],C12[29],D12[29],C13[29],D13[29],C14[29],D14[29],C15[29],D15[29],C16[29],D16[29];
	char CD1[57],CD2[57],CD3[57],CD4[57],CD5[57],CD6[57],CD7[57],CD8[57],CD9[57],CD10[57],CD11[57],CD12[57],CD13[57],CD14[57],CD15[57],CD16[57];
	char K1[49],K2[49],K3[49],K4[49],K5[49],K6[49],K7[49],K8[49],K9[49],K10[49],K11[49],K12[49],K13[49],K14[49],K15[49],K16[49];
	char temp1[33],temp2[33],temp3[33],temp4[33],temp5[33],temp6[33],temp7[33],temp8[33],temp9[33],temp10[33],temp11[33],temp12[33],temp13[33],temp14[33],temp15[33],temp16[33];
    char key[65] = "0001001100110100010101110111100110011011101111001101111111110001";
	char in[16];
	FILE *ff;
	ff=fopen("a.txt","r");
	int i,j,k,c=0;
	char ch;
	int flag=0;
	while(1)
    {
        k=0;
        if(flag==1 && c%2 == 0)
            break;
        for(i=0;i<8;i++)
        {
            if(flag==0)
                ch=fgetc(ff);
            if(ch==EOF)
                flag=1;
            if(flag==0)
                in[i]=ch;
            else
                in[i]=' ';
            for (j = 7; j >= 0; --j)
        		plaintext[k++]= ((in[i] & (1 << j)) ? '1' : '0' );
        }
        c++;
        plaintext[k]='\0';

        permute(key,permuted_key,PC1,56);
        divide(permuted_key, 28, C0, D0);

        left_circular_shift(C0,D0,C1,D1,1);
        left_circular_shift(C1,D1,C2,D2,1);
        left_circular_shift(C2,D2,C3,D3,2);
        left_circular_shift(C3,D3,C4,D4,2);
        left_circular_shift(C4,D4,C5,D5,2);
        left_circular_shift(C5,D5,C6,D6,2);
        left_circular_shift(C6,D6,C7,D7,2);
        left_circular_shift(C7,D7,C8,D8,2);
        left_circular_shift(C8,D8,C9,D9,1);
        left_circular_shift(C9,D9,C10,D10,2);
        left_circular_shift(C10,D10,C11,D11,2);
        left_circular_shift(C11,D11,C12,D12,2);
        left_circular_shift(C12,D12,C13,D13,2);
        left_circular_shift(C13,D13,C14,D14,2);
        left_circular_shift(C14,D14,C15,D15,2);
        left_circular_shift(C15,D15,C16,D16,1);

        merge(C1,D1,28,CD1);
        merge(C2,D2,28,CD2);
        merge(C3,D3,28,CD3);
        merge(C4,D4,28,CD4);
        merge(C5,D5,28,CD5);
        merge(C6,D6,28,CD6);
        merge(C7,D7,28,CD7);
        merge(C8,D8,28,CD8);
        merge(C9,D9,28,CD9);
        merge(C10,D10,28,CD10);
        merge(C11,D11,28,CD11);
        merge(C12,D12,28,CD12);
        merge(C13,D13,28,CD13);
        merge(C14,D14,28,CD14);
        merge(C15,D15,28,CD15);
        merge(C16,D16,28,CD16);

        permute(CD1,K1,PC2,48);
        permute(CD2,K2,PC2,48);
        permute(CD3,K3,PC2,48);
        permute(CD4,K4,PC2,48);
        permute(CD5,K5,PC2,48);
        permute(CD6,K6,PC2,48);
        permute(CD7,K7,PC2,48);
        permute(CD8,K8,PC2,48);
        permute(CD9,K9,PC2,48);
        permute(CD10,K10,PC2,48);
        permute(CD11,K11,PC2,48);
        permute(CD12,K12,PC2,48);
        permute(CD13,K13,PC2,48);
        permute(CD14,K14,PC2,48);
        permute(CD15,K15,PC2,48);
        permute(CD16,K16,PC2,48);

        permute(plaintext,permuted_plaintext,IP,64);
        divide(permuted_plaintext, 32, L0, R0);

        strcpy(L1,R0);
        //printf("L1 = %s\n", L1);
        f(R0,K1,temp1);
        //printf("temp1 = %s\n", temp1);
        xor(L0,temp1,R1,32);
        //printf("R1 = %s\n", R1);

        strcpy(L2,R1);
        //printf("L2 = %s\n", L2);
        f(R1,K2,temp2);
        //printf("R1 = %s\n", R1);
        //printf("K2 = %s\n", K2);
        //printf("temp2 = %s\n", temp2);
        xor(L1,temp2,R2,32);
        //printf("R2 = %s\n", R2);

        strcpy(L3,R2);
        f(R2,K3,temp3);
        xor(L2,temp3,R3,32);

        strcpy(L4,R3);
        f(R3,K4,temp4);
        xor(L3,temp4,R4,32);

        strcpy(L5,R4);
        f(R4,K5,temp5);
        xor(L4,temp5,R5,32);

        strcpy(L6,R5);
        f(R5,K6,temp6);
        xor(L5,temp6,R6,32);

        strcpy(L7,R6);
        f(R6,K7,temp7);
        xor(L6,temp7,R7,32);

        strcpy(L8,R7);
        f(R7,K8,temp8);
        xor(L7,temp8,R8,32);

        strcpy(L9,R8);
        f(R8,K9,temp9);
        xor(L8,temp9,R9,32);

        strcpy(L10,R9);
        f(R9,K10,temp10);
        xor(L9,temp10,R10,32);

        strcpy(L11,R10);
        f(R10,K11,temp11);
        xor(L10,temp11,R11,32);

        strcpy(L12,R11);
        f(R11,K12,temp12);
        xor(L11,temp12,R12,32);

        strcpy(L13,R12);
        f(R12,K13,temp13);
        xor(L12,temp13,R13,32);

        strcpy(L14,R13);
        f(R13,K14,temp14);
        xor(L13,temp14,R14,32);

        strcpy(L15,R14);
        f(R14,K15,temp15);
        xor(L14,temp15,R15,32);

        strcpy(L16,R15);
        f(R15,K16,temp16);
        xor(L15,temp16,R16,32);

        merge(R16,L16,32,output1);
        permute(output1,output2,IP_inv,64);
        //printf("Ciphertext in binary = %s\n", output2);
        //printf("Ciphertext in hexa = ");
        binary_to_hexa(output2);
    }
    fclose(ff);
    return 0;
}
