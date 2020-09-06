#include<iostream>
struct A{
int i;
A operator+(int i){std::cout<<"For␣Maccrage␣we␣march"<<std::endl;}
A operator+(A a){std::cout<<"and␣we␣shall␣know␣no␣fear"<<std::endl;}
};
int main(){
int i1;A a1;A a2;
i1+a1+a2;//vous ne pouvez pas changer cette ligne
}
