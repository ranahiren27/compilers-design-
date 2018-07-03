#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
using namespace std;
 
int isKeyword(char buffer[]){
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int i, flag = 0;
    
    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    
    return flag;
}

bool isChar(char ch){

  if(ch == 'a')
    return true;
  else
    return false;

}

char isIdentifier(char buffer[]){
  char ch,flag;

    for(int i=0;i<strlen(buffer);i++){
          if((buffer[0] == '0')||(buffer[0] == '1')||
            (buffer[0] == '2')||(buffer[0] == '3')||
            (buffer[0] == '4')||(buffer[0] == '5')||
            (buffer[0] == '6')||(buffer[0] == '7')||
            (buffer[0] == '8')||(buffer[0] == '9')){
            flag = 'c';
          }else if( i>0 && flag=='n' && isChar(buffer[i]) ){
            return 'f';
          }else{
            flag = 'i';
          }
    }

  return flag;
}
int main(){
    char ch, buffer[15], operators[] = "+-*/%=()  ";
    ifstream fin("program.txt");
    int i,j=0;
    
    if(!fin.is_open()){
        cout<<"error while opening the file\n";
        exit(0);
    }
    
    while(!fin.eof()){

        ch = fin.get();
           
        for(i = 0; i < 8; ++i){
               if(ch == operators[i])
                   cout<<ch<<" is operator\n";
           }
           
           if(isalnum(ch)){
               buffer[j++] = ch;
           //    cout<<buffer<<"checking\n";
           }

           else if((ch == ' ' || ch == '\n') && (j != 0)){
                   buffer[j] = '\0';
                   j = 0;
                                      
                   if(isKeyword(buffer) == 1){
                       cout<<buffer<<" is keyword\n";
                   }else{
                       if(isIdentifier(buffer) == 'c'){
                          cout<<buffer<<" is constant\n";
                       }else if(isIdentifier(buffer) == 'i'){
                          cout<<buffer<<" is identifier\n";
                       }else{
                          cout<<buffer<<" is unvalid tocken\n";
                       }
                   }
           }
           
    }
    
    fin.close();
    
    return 0;
}
