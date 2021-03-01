# What is it?

**calculater-converter**
_is a program divided to two branches. First it can convert from one numerical system to another (2,8,10,16). Second it can collect two numbers (have the same base) together._

>**2** for binary\
>**8** for octal\
>**10** for decimal\
>**16** for hexadecimal\

## Notes
>negative values is not accepted

>fractions is not accepted

>The number mustn't excess 8-digit length

>a valid base is 2,8,10 or 16

>a valid hexadecimal number is CAPITAL chars(e.g 'A' NOT 'a').

>negative values is not accepted.

>if user entered unvalid inputs, Program will be terminated.

# How the program works (user experience)

## Begining 

asks for user name (like mostafa)
>Hello!,Whats your name ?

asks if you wanna convert a number to another system, Or to collect two numbers.
> choose 1 for conversion or 2 for collecting two numbers: 1

## 1 for conversion 

Base of number you wanna convert it(I entered 16 for hexa)
> enter the base of the number: 16

Enter the number(I entered 12A)
> enter the number[8 digits]: 12A

base of desired system you wanna convert TO. (I enterd 10 for decimal)
< Please enter the base of the converted number: 10

final result of convertion
> Decimal: 298

## mid stage 

```
mostafa!, Do you wanna collect the resultant to another number ?
Enter 2 if yes or 1 for no: 2
```

If you entered **1**,The program will return to **beginning** stage.

If **2** entered, The program will start to **collect output** value (in this case is 298) to another value in the **same system** (in this case is Decimal).


## collecting /plus opearation ( 2 Entered )

asks for the second operand 
> enter the second number[8 digits]: 1

I enterd **1** so the output is (in **decimal**) :
> Sum is: 299

## finally

program repeats itself until user exits it

# program alogrithm

## algorithm

it based mainly(without input validation) on **two** functions. one called **sys_dec()**, Which take two arguments number and base for any system (octal, hex, binary) and convert it to **decimal system value**.
second funtion is **dec_sys()**. Which takes **decimal** number and **base of needed system**, Then it convert the decimal number to this disired system.
**now the program can convert** from any system to another by convert the number to decimal first and convert the output of decimal to another system.

**What about collecting feature**
when the user want to collect two numbers withe the same base(system), Program convert **each number** to decimal (as above), Now I got two decimal values, So program collects them normally, And the resultant will be converted to his original system by **dec_sys()**.

## Input Validation

The rest of functions are **three** used to check user input is right or wrong, As **digitsCheck()**, **baseCheck()** or **numLength()**


_digitsCheck()_ is a function used to check **each digit** of number is releted to the base of not(e.i.generally can't enter charachters like **l p k j** or symbols like **+ / # -** )

e.g. if hexa
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


_baseCheck()_ is a function used to check if input base is 2 or 8 or 10 or 16. Any other inputs aren't acceptable.

_numLength()_ is a function used to check length of the number, Becuse it mustn't excess 8-digit length.
e.g.
~~~
123456789  --> unvalid 
1564  --> valid 
12345678910  --> unvalid 
~~~


## <img src="https://upload.wikimedia.org/wikipedia/commons/1/1b/Facebook_icon.svg" alt="drawing" width="30" height="30" /> [Facebook](https://www.facebook.com/profile.php?id=100006473238307)
