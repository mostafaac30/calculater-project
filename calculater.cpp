#include <iostream>
#include <string>
#include <cstring> //strln..
#include <cmath>

using namespace std;

int sys_dec(int base, char num1[]);  //from line 4 to here is the declaration of the function(instead of #include "header.h")

//a struct have array of chars ,which is the result of conversion ,This struct used to pass/return the result by (dec_sys) function.
struct sum_s
{
    char s[8];
};

sum_s dec_sys(int base, int decimal);

void digitsCheck(int base, char num1[]);

void baseCheck(int base);

int numLength(int length, char num1[]);

int main()
{


    for (int i = 0; i >= 0; i++)
    {
        static string username = "";    //to be fixed >>can not be reintialized or delocated by memory
        if (i == 0)
        {
            cout << "\t\t\tIMPORTANT NOTES" << endl;
            cout << "1. fractions is not accepted." << endl;
            cout << "2. The number mustn't excess 8-digit length."<<endl;
            cout << "3. a valid base is 2,8,10 or 16."<<endl;
            cout << "4. a valid hexadecimal number is CAPITAL chars(e.i. 'A' NOT 'a')."<<endl;
            cout << "5. negative values is not accepted." << endl<<endl;


            cout << "Hello!,Whats your name ?" << endl;
            cin >> username;
            cin.ignore(10000, '\n');
            cin.clear();
            cout << username << "!, It's a cool name, Welcome to our project." << endl;
        }

        if(i == 1)
        {
            cout << endl << "Hello " << username << "!, It seems that you have a lot of work today. I wish program could help you." << endl;
        }

        int decimalInput = 0, base,convertedBase;

        char num1[64], choose = '0';     //"64" to avoid crashing when user enter a huge number
        
        cout << endl << "choose 1 for conversion or 2 for collecting two numbers: ";
        cin >> choose;
        cin.ignore(10000, '\n');
        cin.clear();
        cout << "mm, we assuming that you have entered " << choose << endl;


        if (choose < '1' || choose > '2')
        {
            cout << endl << "Error, Please enter a valid choice" << endl;
            exit(1);

        }
        
        cout << "enter the base of the number: ";
        cin>>base;
        cin.ignore(10000, '\n');
        cin.clear();

        baseCheck (base);

        cout << "mm, we assuming that you have entered "<<base<<endl;

        cout << "\n"<<"enter the number[8 digits]: ";
        cin>>num1;

        cin.ignore(10000, '\n');
        cin.clear();
        cout << "mm, we assuming that you have entered "<<num1<<endl;


        numLength(8,num1);

        digitsCheck(base,num1);

        decimalInput = sys_dec(base,num1);


        if (choose == '1' )
        {
            cout << "Please enter the base of the converted number: ";
            cin>>convertedBase;
            cin.ignore(10000, '\n');
            cin.clear();

            baseCheck (convertedBase);
            cout << "mm, we assuming that you have entered "<<convertedBase<<endl;

        }




        if (choose == '1')  //FOR conversion
            
        {
            sum_s o;    //to store returned value of dec_sys

            if (convertedBase == 10)
            {
                cout << "Decimal: ";

                cout << decimalInput;

                cout << endl;

            }


            else if (convertedBase == 8)
            {
                o = dec_sys(8,decimalInput);

                cout << "Octal: ";
                //if condition to remove intial zeros 00012>>12
                
                //z for removing useless zeros
                int zeros_counter=0;
                for (int z=7;o.s[z]=='0';z--)
                    
                    zeros_counter++;
                    if (zeros_counter == 8)     //if user entered 0 >>to decimal >>00000000 >> zeros_counter"--" to print at least one zero as a result
                        zeros_counter--;

                ///print the final value
                for (int i=7-zeros_counter;i>=0;i--)
                {
                    cout << o.s[i];
                }

                cout << endl;
            }

            else if (convertedBase == 16)
            {
                o = dec_sys(16,decimalInput);

                cout << "Hexadecimal: ";

                //z for removing useless zeros
                int zeros_counter=0;
                for (int z=7;o.s[z]=='0';z--)
                    
                    zeros_counter++;
                    if (zeros_counter == 8)     //if user entered 0 >>to decimal >>00000000 >> zeros_counter"--" to print at least one zero as a result
                        zeros_counter--;


                ///print the final value
                for (int i=7-zeros_counter;i>=0;i--)
                {
                    cout << o.s[i];
                }

                cout << endl;
            }


            else if (convertedBase == 2)
            {
                o = dec_sys(2,decimalInput);

                cout << "Binary: ";

                //z for removing useless zeros
                int zeros_counter=0;
                for (int z=7;o.s[z]=='0';z--)
                    
                    zeros_counter++;
                    if (zeros_counter == 8)     //if user entered 0 >>to decimal >>00000000 >> zeros_counter"--" to print at least one zero as a result
                        zeros_counter--;


                ///print the final value

                if (decimalInput <=255)
                {
                    for (int i=7-zeros_counter;i>=0;i--)
                    {
                        cout << o.s[i];
                    }

                }
                else 
                    cout << "Please enter a number between 0-255 in decimal /FF in hexa / 377 in octal"<<endl;

                cout << endl;
            }

            cout << endl<<username<<"!, Do you wanna collect the resultant to another number ?"<<endl;
            cout << "Enter 2 if yes or 1 for no: ";
            cin.get(choose);
            cin.ignore(10000, '\n');
            cin.clear();

            cout << "mm, we assuming that you have entered "<<choose<<endl;

            if (choose > '2' )
            {
                cout << "Error, Please enter a valid choice"<<endl;
                exit(1);

            }


            else if (choose == '2')
            {
                base = convertedBase;       //becuse user need to collect the resultant number (converted)

            }
            else if (choose =='1'){}

        }
        

        if (choose == '2')
        {

            // convert the secend number, Add it to the converted first number and print the final value of summition

            int decimalInput2=0;
            char num2[64];

            cout << "\n"<<"enter the second number[8 digits]: ";
            cin>>num2;    

            cin.ignore(10000, '\n');
            cin.clear();

            numLength(8,num2);  //8 for number length
            digitsCheck(base,num2);

            cout << "mm, we assuming that you have entered "<<num2<<endl;


            decimalInput2 = sys_dec(base,num2);

            int collect=0;

            collect=decimalInput +decimalInput2 ;
            sum_s finalCollect;
            if (base ==10)
            {
                cout << "Sum is: "<<collect;

            }
            else
            {
            finalCollect= dec_sys(base,collect);    

            //z for removing useless zeros
            int zeros_counter=0;
            for (int z=7;finalCollect.s[z]=='0';z--)
                zeros_counter++;
                    if (zeros_counter == 8)     //if user entered 0 >>to decimal >>00000000 >> zeros_counter"--" to print at least one zero as a result
                        zeros_counter--;


            ///print the final value

            cout << "Sum is: ";
            for (int i=7-zeros_counter;i>=0;i--)
            {
                cout << finalCollect.s[i];
            }

            }

            cout << endl;

        }

    }

    return 0;
}

//a function to check if base is from the 4 systems ,That we dealing with [2,8,10,16].
void baseCheck (int base)
{

    if (base !=2 && base !=8  && base !=10 && base !=16)
    {
        cout << "Error, Please enter a valid base [2,8,10,16]"<<endl;
        exit(1);

    }

}

//a function to check if entered number is correct or not 
void digitsCheck (int base,char num1[])
{



if (base ==16 )
{

    for (int i = 0; num1[i] != '\0'; i++)      
    {

        if (num1[i] !='A' && num1[i] !='B' && num1[i] !='C' && num1[i] !='D' && num1[i] !='E' && num1[i] !='F')
        {
            if (!((int)num1[i] >= 48 && (int)num1[i] <= 57))
            {
                cout << "Error, Please enter a valid hexadecimal number (Capital chars)"<<endl;
                exit(1);
            }
        } 
    }

}


if (base ==10 )
{

    for (int i = 0; num1[i] != '\0'; i++)       //strlen - 1 >> because 8bits ranges 0 to 7 
    {

        if (!((int)num1[i] >= 48 && (int)num1[i] <= 57))
        {
            cout << "Error, Please enter a valid decimal number"<<endl;
            exit(1);
            
        }
    }

}

if (base == 8)
{

    for (int i =0; num1[i] != '\0'; i++)       //strlen - 1 >> because 8bits ranges 0 to 7 
    {

        if (!((int)num1[i] >= 48 && (int)num1[i] < 56))   //(int)num1[i] "< 56" >>> 56 is the representation of 8 in ascii
        {
            cout << "Error, Please enter a valid octal number"<<endl;
            exit(1);
            
        }
    }

}

if (base ==2 )
{

    for (int i = 0; num1[i] != '\0'; i++)       //strlen - 1 >> because 8bits ranges 0 to 7 
    {

        if (!((int)num1[i] >= 48 && (int)num1[i] < 50)) // <50 is the representation of 2 in ascii
        {
            cout << "Error, Please enter a valid binary number"<<endl;
            exit(1);
            
        }
    }

}

}

//a function to pervent user to enter a number with a length more than 8 (length variable)
int numLength(int length,char num1[])
{

for (int i=0;i<=length;i++)
{
    if(num1[i] == '\0')
        return 0;
}

cout << "please good user,The number mustn't excess "<<length<<"-digit length"<<endl;
exit(1);


}



//decimal to any system function

sum_s dec_sys(int base, int decimal)
{


    int actual_num;                         //to store converted char number to numeric num (casting)
    int rest;                               //rest to store queteint without real numbers 12/8 >>1

    //result[8] ..to store result of whole conversion (char to intager) process.. 8 elements becuse of binary 8bits 
    int result[]={0,0,0,0,0,0,0,0};           //intilizing sum arr ..to have zeros not any number 0000014 NOT 5650014.. when items of converted number is less than index of the array >>14 have two items when resualt[] have seven items

    float float_rest=0.0,after_dot=0.0;     //after dot value 0.50 in 10.50 .. float_rest is float queteint

    actual_num=decimal;

    rest=actual_num;
    float_rest=(float)rest;


    for (int i = 0;i<8;i++)                          
    {

        rest = rest /base ;                     // 12/8>> 1 only       
        
        float_rest = float_rest / base;         //12/8>> 1.5 

        after_dot = float_rest - rest;          //1.5 - 1 = 0.5

        result[i] = after_dot * base;           //result of each number >> 0.5*8 = 4
    }


    char s;
    sum_s sum;


    for (int i =7; i>=0;i--)
    {
        s = (char)(result[i]+48);               //converting ineger to string"char edited" >> to dealing with ABCDEF of hexa

        switch (result[i])                      //dealing with hexa last 6 digits
        {
            case 10:
                s = 'A';
                
                break;
            case 11:
                s = 'B';
                
                break;
            case 12:
                s = 'C';
                
                break;
            case 13:
                s = 'D';
                
                break;
            case 14:
                s = 'E';
                
                break;
            case 15:
                s = 'F';
                
                break;
        }

        sum.s[i]=s;
    }


return sum;

    
}

////any system to decimal function

int sys_dec (int base, char num1[])  ////created function ..that will return conversion value.
{

    int actual_num=0;                         //to store converted char number to numeric num (casting)
    int position = 0;                         //index/ the position of number(power what ?)
    int sum = 0;                              //stores result of conversion

//determine last number-index / length of numbers 
int length=0;
for (int i=0;num1[i] !='\0';i++)
{
    length++;
}

if (base ==10)
{

//convert numeric value from char to an integer ..to get decimal number if base is 10 >>without useing sys_dec(will get false number)
for (int i=0;num1[i] != '\0';i++)   //{\0} >>the end of the array of chars
{

    actual_num = (int)num1[i] - 48;  //'9' in ascii is 57 >>-48(zero valactual_num
    sum+=actual_num;    //sum = sum + actual_num
    sum*=10;    //sum = sum * 10
}

sum/=10; //12(orginal)>>120>>12

} 

else if (base != 10 )
{
    for (int i = length-1; i >= 0; i--)       //length - "1" >> because FOR LOOP counts from 0 SO another -1 >> -2
    {
        int conversion = pow(base, position);            //conversion process

        if ( (int)num1[i] >= 48 && (int)num1[i] <= 57 )
        {
            actual_num = (int)num1[i] - 48;  //'9' in ascii is 57 >>-48(zero valactual_num

            sum = actual_num * conversion + sum;              //collect result to previous value of summition
        }


        else
        {    
            switch (num1[i])
            {
            case 'A':
                actual_num = 10;
                break;
            case 'B':
                actual_num = 11;
                break;
            case 'C':
                actual_num = 12;
                break;
            case 'D':
                actual_num = 13;
                break;
            case 'E':
                actual_num = 14;
                break;
            case 'F':
                actual_num = 15;
                break;
            }

        actual_num*=conversion;
        sum = actual_num + sum;

        }

        position++;                         //increasing power by 1 each time
    }

    }


return sum;
}
