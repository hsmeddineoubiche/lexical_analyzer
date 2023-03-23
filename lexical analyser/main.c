#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char C[500];
char temp[500];

/***********************
*                                            *
*   functions decalaration *
*                                            *
************************/

bool Operator(char k[]);
bool Operator2(char k[]);
bool Operator3(char k[]);
bool Operator4(char k[]);
bool Q0(char k[]);
bool Q1(char k[]);
bool Q2(char k[]);
bool Q3(char k[]);
bool Q4(char k[]);
bool Q5(char k[]);
bool Q6(char k[]);
bool Q7(char k[]);
bool com0(char k[]);
bool com1(char k[]);
bool com2(char k[]);
bool com3(char k[]);
bool com4(char k[]);
bool com5(char k[]);
bool com6(char k[]);
bool com7(char k[]);
char* nextchar(char C[]);


/*main program*/
int main()
{

    printf("enter a string: ");
    fgets(C,sizeof(C),stdin);
    C[strcspn(C,"\n")] = 0;
    strcpy(temp,C);

    temp[strlen(C)]='\n';
     /* thats to make the string end with new line character to distinguish between space character and new line character
     since we got some problems to implement automata transistions with space character */


    if (Q0(temp))
    {
        printf("Number");
    }
    else if(com0(temp)){
        printf("Commande");
    }
    else if(Operator(temp)){
        printf("Opertor");
    }
    else
    {
        printf("not a lexical unit");
    }
    return 0;
}

/*numbers automata*/

bool Q0(char k[])
{
    if (k[0]=='+'||k[0]=='-')
    {
        return Q1(nextchar(k+1));
    }
    else if (k[0]=='0'||k[0]=='1'||k[0]=='2'||k[0]=='3'||k[0]=='4'||k[0]=='5'||k[0]=='6'||k[0]=='7'||k[0]=='8'||k[0]=='9')
        {
            return Q2(nextchar(k+1));
        }
    else
        {
            return false;
        }

}

bool Q1(char k[])

{

    if (k[0]=='0'||k[0]=='1'||k[0]=='2'||k[0]=='3'||k[0]=='4'||k[0]=='5'||k[0]=='6'||k[0]=='7'||k[0]=='8'||k[0]=='9')
    {
        return Q2(nextchar(k+1));
    }

    else
            {
                return false;
            }

        }


bool Q2(char k[])
{
    if (k[0]=='0'||k[0]=='1'||k[0]=='2'||k[0]=='3'||k[0]=='4'||k[0]=='5'||k[0]=='6'||k[0]=='7'||k[0]=='8'||k[0]=='9')
    {
        return Q2(nextchar(k+1));
    }
    else if (k[0]=='.')
            {
                return Q3(nextchar(k+1));
            }

    else if (k[0]=='\n')
        {
            return true;
        }
    else
            {
                return false;
            }
    }

bool Q3(char k[])
{

    if (k[0]=='0'||k[0]=='1'||k[0]=='2'||k[0]=='3'||k[0]=='4'||k[0]=='5'||k[0]=='6'||k[0]=='7'||k[0]=='8'||k[0]=='9')
        {
            return Q4(nextchar(k+1));
        }

    else
            {
                return false;
            }

}

bool Q4(char k[])
{

    if (k[0]=='0'||k[0]=='1'||k[0]=='2'||k[0]=='3'||k[0]=='4'||k[0]=='5'||k[0]=='6'||k[0]=='7'||k[0]=='8'||k[0]=='9')
        {
            return Q4(nextchar(k+1));
        }
    else if(k[0]=='e'||k[0]=='E'){
        return Q5(nextchar(k+1));
    }
    else if(k[0]=='\n'){
        return true;
    }
    else
            {
                return false;
            }

        }

bool Q5(char k[])
{

    if (k[0]=='0'||k[0]=='1'||k[0]=='2'||k[0]=='3'||k[0]=='4'||k[0]=='5'||k[0]=='6'||k[0]=='7'||k[0]=='8'||k[0]=='9')
        {
            return Q7(nextchar(k+1));
        }
    else if(k[0]=='+'||k[0]=='-'){
        return Q6(nextchar(k+1));
    }
    else
            {
                return false;
            }

}

bool Q6(char k[])
{

    if (k[0]=='0'||k[0]=='1'||k[0]=='2'||k[0]=='3'||k[0]=='4'||k[0]=='5'||k[0]=='6'||k[0]=='7'||k[0]=='8'||k[0]=='9')
        {
            return Q7(nextchar(k+1));
        }

    else
            {
                return false;
            }

        }

bool Q7(char k[])
{

    if (k[0]=='0'||k[0]=='1'||k[0]=='2'||k[0]=='3'||k[0]=='4'||k[0]=='5'||k[0]=='6'||k[0]=='7'||k[0]=='8'||k[0]=='9')
        {
            return Q7(nextchar(k+1));
        }
    else if(k[0]=='\n'){
        return true;
    }
    else
            {
                return false;
            }

        }

/*Commands automata*/

/*we can use uppercase letters in command name and arguments also in options
 and we can use numbers in arguments and command name by adding them to the conditions that belongs to
we have to respect that arguments and command name cannot begin with a number for ex: 8arg /4macom
or put a number in options  for ex: [-8]
*/
bool com0(char k[]){
    if(k[0]>='a' && k[0] <= 'z'){
                    return com1(nextchar(k+1));
    }
    else{
        return false;
    }
}

bool com1(char k[]){
    if(k[0]>='a' && k[0] <= 'z'){
                return com1(nextchar(k+1));
    }

  else if(k[0]==' '){
            return com2(nextchar(k+1));
        }
    else if(k[0]=='\n'){
        return true;
    }
    else{
        return false;
    }
}

bool com2(char k[]){
    if(k[0]>='a' && k[0] <= 'z'){
                    return com7(nextchar(k+1));
    }
    else if(k[0]=='['){
        return com3(nextchar(k+1));
    }
    else if(k[0]=='\n'){
        return true;
    }
    else{
        return false;
    }
}

bool com3(char k[]){
    if(k[0]=='-'){
            return com4(nextchar(k+1));
    }
    else{
        return false;
    }
}
bool com4(char k[]){
    if(k[0]>='a' && k[0] <= 'z'){

                    return com5(nextchar(k+1));
    }
    else{
        return false;
    }
}
bool com5(char k[]){
    if(k[0]==']'){
                    return com6(nextchar(k+1));
    }
    else if(k[0]==','){
        return com3(nextchar(k+1));
    }
    else{
        return false;
    }
}
bool com6(char k[]){
    if(k[0]=='\n'){
            return true;
    }
    else{
        return false;
    }
}

bool com7(char k[]){
    if(k[0]>='a' && k[0] <= 'z'){
                return com7(nextchar(k+1));
    }
    else if(k[0]==' '){
        return com2(nextchar(k+1));
    }
    else if(k[0]=='\n'){
            return true;
    }
    else{
        return false;
    }
}

/*operators automata*/

bool Operator(char k[]) {
    if (k[0]=='<') {
            return Operator2(nextchar(k+1));
    }
    else if(k[0]=='>')
        return Operator3(nextchar(k+1));
    else if(k[0]=='=')
        return Operator4(nextchar(k+1));
    else{
        return false;
    }
}
bool Operator2(char k[]){
    if(k[0]=='='&& k[1]=='\n')
        return true;
    else if(k[0]=='>'&&k[1]=='\n')
        return true;
    else if(k[0]=='\n')
        return true;
    else
        return false;
}
bool Operator3(char k[]){
    if(k[0]=='='&&k[1]=='\n')
        return true;
    else if(k[0]=='\n')
        return true;
    else
        return false;
}
bool Operator4(char k[]){
    if(k[0]=='='&&k[1]=='\n')
        return true;
    else
        return false;
}

/*function that returns the next character in the string*/
char*  nextchar(char *C){
    return C;
}
