
#include <iostream>
#include <Math.h>
#include <fstream>
using namespace std;
//Deklarojm strukturen e tipit liste.
typedef struct list{
	string celes;
	struct list *pas;
}list;

//Funksion qe kontrollon nqs gjendet nje fjale ne liste.

bool gjendetNeListe(struct list *k,string fjala){
	if(k==NULL){
		return false;
	}
	struct list *tmp=k;
	while(tmp!=NULL){
		if(tmp->celes.compare(fjala)==0){
			return true;
		}
		tmp=tmp->pas;
	}
	return false;
}
 //Funksion qe ben Shtimin e nje fjale ne liste.
  
struct list* shtoNeListe(struct list *k,string vlera){
    if(gjendetNeListe(k,vlera))
    return k;
	struct list *tmp=new list();
	tmp->celes=vlera;
	tmp->pas=k;
	k=tmp;
	return k;
	
}

//Funksion per heqjen e nje fjale nga lista.

struct list* hiqNgaLista(struct list *k,string vlera){
	if(!gjendetNeListe(k,vlera)){
		cout<<"fjala nk gjendet ne list";
		return k;
	}
	if(k==NULL){
		return k;
	}
    if(k->celes.compare(vlera)==0){
    	k=k->pas;
    	return k;
	}
	struct list *tmp=k;
	while(tmp->pas->celes.compare(vlera)!=0){
		tmp=tmp->pas;
	}
	tmp->pas=tmp->pas->pas;
	return k;
	
}


//Gjenerimi i nje fjale ne nje numer(int).


int  celesInt(string fjala){
	
	int  i,s=0;
	for(i=0;i<fjala.length();i++){
		int vl=(int)fjala[i];
	    s+=vl*pow(3,i);
		}
		return s;
}


//Gjen vendodhjen e kodit ne tabel.


int hashCode(int vlera){
	if(vlera<0){
	return vlera%100000*(-1);
	}
	return vlera%100000;
}

//Funskion per shtimin e nje fjale ne tabel.

void shtoElement(struct list *T[],int N,string fjala){
	int pozicioni=hashCode(celesInt(fjala));
	T[pozicioni]=shtoNeListe(T[pozicioni],fjala);
	
}

//Ben kontrollin nqs gjendet fjala ne tabel.

bool gjendetNeHash(struct list *T[],int N,string fjala){
	int pozicioni=hashCode(celesInt(fjala));
	if(gjendetNeListe(T[pozicioni],fjala)){
		return true;
	}
	return false;
	
}

//Funksion per heqjen e nje fjale nga tabela

void hiqElement(struct list *T[],int N,string fjala){
	if(!gjendetNeHash(T,N,fjala)){
		cout<<"Elementi nk gjendet ne Tabelen Hash";
		return;
	}
	int pozicioni=hashCode(celesInt(fjala));
	T[pozicioni]=hiqNgaLista(T[pozicioni],fjala);
}
	//Funksion per afishimin 

void afisho(list *T[],int N){
	for(int i=0;i<N;i++){
	struct list *tmp=T[i];
	while(tmp!=NULL){
		cout<<tmp->celes<<" ";
		tmp=tmp->pas;
	}
}
}


int main(){
	int i;
	struct list *TabeleHash[100000];//deklarimi i tabeles hash
	
//Mbushja ne fillim e tabeles me null

    for(i=0;i<100000;i++){
    	TabeleHash[i]=NULL;
	}

//marrja e fjaleve nga skedari

fstream in;
	in.open("skedar.txt",ios::in);
	string a;
	int c=0;
	while(c<1000000){
		in>>a;
		shtoElement(TabeleHash,100000,a);
		c++;
	}

//Afishimi

afisho(TabeleHash,100000);


	return 0;
}
