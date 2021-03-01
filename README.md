# <img src="https://upload.wikimedia.org/wikipedia/commons/1/1b/Facebook_icon.svg" alt="drawing" width="30" height="30" /> [Facebook Profile](https://www.facebook.com/profile.php?id=100006473238307)

# What is it?

_The required project of first year - first semister - faculty of computers and information FCI - Fayoum universty_

**calculater-converter** _is a program divided into two branches. First, it can convert from one numerical system to another (2,8,10,16). Second, it can collect two numbers (have the same base) together._

>**2** for binary\
>**8** for octal\
>**10** for decimal\
>**16** for hexadecimal\

## Notes
>negative values are not accepted

>fractions are not accepted

>The number mustn't excess 8-digit length

>a valid base is 2,8,10 or 16

>a valid hexadecimal number is CAPITAL chars(e.g 'A' NOT 'a').

>negative values are not accepted.

>if the user entered invalid inputs, Program will be terminated.

# How the program works (user experience)

## Begining 

asks for the user name (like Mostafa)
>Hello!, What's your name?

asks if you wanna convert a number to another system, Or to collect two numbers.
> choose 1 for conversion or 2 for collecting two numbers: 1

## 1 for conversion 

The base of the number you wanna convert it(I entered 16 for Hexa)
> enter the base of the number: 16

Enter the number(I entered 12A)
> enter the number[8 digits]: 12A

the base of the desired system you wanna convert TO. (I entered 10 for decimal)
< Please enter the base of the converted number: 10

the final result of conversion
> Decimal: 298

## mid-stage 

```
Mostafa!, Do you wanna collect the resultant to another number?
Enter 2 if yes or 1 for no: 2
```

If you entered **1**, The program will return to **beginning** stage.

If **2** entered, The program will start to **collect output** value (in this case is 298) to another value in the **same system** (in this case is Decimal).


## collecting /plus opearation ( 2 Entered )

asks for the second operand 
> enter the second number[8 digits]: 1

I entered **1** so the output is (in **decimal**) :
> Sum is: 299

## finally

program repeats itself until the user exits it

# program algorithm (getting inside)

## algorithm

it based mainly(without input validation) on **two** functions. one called **sys_dec()**, Which takes two arguments number and base for any system (octal, hex, binary) and convert it to **decimal system value**.
second funtion is **dec_sys()**. Which takes **decimal** number and **base of needed system**, Then it convert the decimal number to this desired system.
**now the program can convert** from any system to another by converting the number to decimal first and convert the output of decimal to another system.

**What about collecting feature**
when the user wants to collect two numbers with the same base(system), the Program convert **each number** to decimal (as above), Now I got two decimal values, So the program collects them normally, And the resultant will be converted to his original system by **dec_sys()**.

## Input Validation

The rest of functions are **three** used to check user input is right or wrong, As **digitsCheck()**, **baseCheck()** or **numLength()**


_digitsCheck()_ is a function used to check **each digit** of number is releted to the base of not(e.i.generally can't enter charachters like **l p k j** or symbols like **+ / # -** )

e.g. if Hexa
~~~
F   --> valid 
Y   --> unvalid 
A2  --> valid 
2K$ --> unvalid 
123 --> valid 
~~~

e.g. if octal
~~~
1E      --> unvalid 
1534    --> valid 
8       --> unvalid 
1234567 --> valid 
~~~

e.g. if Binary
~~~
2  --> unvalid 
1  --> valid 
0  --> unvalid 
~~~


_baseCheck()_ is a function used to check if the inputted base is 2 or 8 or 10 or 16. Any other inputs aren't acceptable.

_numLength()_ is a function used to check the length of the number Because it mustn't excess 8-digit length.
e.g.
~~~
123456789  --> unvalid 
1564  --> valid 
12345678910  --> unvalid 
~~~


# <img src="https://upload.wikimedia.org/wikipedia/commons/1/1b/Facebook_icon.svg" alt="drawing" width="30" height="30" /> [Facebook Profile](https://www.facebook.com/profile.php?id=100006473238307)
