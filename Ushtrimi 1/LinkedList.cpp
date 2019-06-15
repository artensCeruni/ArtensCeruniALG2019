#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;
//Deklarojm nje struktur te tipit list qe do ruaj fjalet.
typedef struct list{
	string a; 
	struct list *pas;
}list;


//Deklarojm funksionin qe ben kontrollin ne list per gjetjen e nje fjale,nqs gjendet apo jo.
bool gjendet(list *k,string fjala){
	if(k==NULL){
		return false;
	}
	struct list *tmp=k;
	while(tmp!=NULL){
		if(tmp->a.compare(fjala)==0){
			return true;
		}
		tmp=tmp->pas;
	}
	return false;
}
//Funksion per shtimin e fjales ne liste.
list *add(list *k,string vlera){
    if(gjendet(k,vlera))
    return k;
	struct list *tmp=new list();
	tmp->a=vlera;
	tmp->pas=k;
	k=tmp;
	return k;
}
//Funksion per afishimin e e listes.
void afisho(list *k){
	struct list *tmp=k;
	while(tmp!=NULL){
		
		cout<<tmp->a<<" ";
		tmp=tmp->pas;
		
	}
		
}



int main(){
	
	list *k=NULL;
	fstream in;					//Krijojm objektin qe do lexoj skedarin.
	int count=0;
	in.open("skedar.txt",ios::in);	//hapim skedarin.
	string a;
	while(count <1000000){			//kontrolli neper skedar.
		in>>a;					//leximi skedarit
		k=add(k,a);				//thrrasim funksionin 
		count++;
	}
	
	afisho(k);					//Afishojm listen e bere.
	
	return 0;
}
