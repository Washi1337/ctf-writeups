#include <stdio.h>

int verify(int input)
{
    int temp1, temp2, result;

    temp1 = 0x77259243;
    temp1 = temp1 | 0x23;
    temp1 = temp1 & 0x23;
    temp1 = temp1 + 0x843;
    temp1 = temp1 & 0x5466;
    temp1 = temp1 + 0x843;
    temp1 = temp1 | 0x234;
    result = 0;
    temp1 = temp1 + 0x63654;
    temp1 = temp1 & 0x4545;
    temp1 = temp1 | 0x65466;
    temp1 = temp1 - 0x5234;
    temp1 = temp1 - 0x863;
    temp1 = temp1 ^ 0x7;

    if (input == 0x743)
    {
        result = 1;
    }

    temp1 = temp1 + 0x65363;
    temp1 = temp1 & 0x75454;
    temp1 = temp1 | 0x754;
    temp1 = temp1 + 1;
    temp1 = temp1 - 1;
    temp1 = temp1 + 0x711;
    
    if (input == 0x972)
    {
        result = 1;
    }

    temp1 = temp1 + 0x3643;
    temp1 = temp1 + 0x54;
    temp1 = temp1 | 0x54;
    temp1 = temp1 | 0x331;
    temp1 = temp1 | 0x12;
    temp1 = temp1 + 0x321;

    if (input != 0x666)
    {
        result = 1;
    }

    temp1 = temp1 - 0x97;
    temp1 = temp1 + 0x744;
    temp1 = temp1 | 0x54;
    temp1 = temp1 - 0x82;
    temp1 = temp1 | 0x12;
    temp1 = temp1 + 0x223;
    
    if (input != temp1)         // temp1 == 299902 at this point.
    {
        result = 1;
    }

    temp1 = temp1 + 0x7342;
    temp1 = temp1 ^ 0x42;
    temp1 = temp1 ^ 0x744;
    temp2 = 0x7443;
    temp1 = temp1 ^ 0x33;
    temp1 = temp1 | 0x88;
    temp1 = temp1 + 0x764;
    
    if (input != temp2)
    {
        result = 1;
    }
    
    return result;
}

int main()
{
    int input;
    printf("Enter Key: ");
    scanf("%d",&input);
    int iVar1 = verify(input);
    if (iVar1 == 0) {
        puts("Incorrect Key.");
    }
    else {
        puts("Correct Key!");
    }
}