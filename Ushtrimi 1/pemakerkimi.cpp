#include<iostream>
#include<Math.h>
#include<fstream>
using namespace std;
//Deklarojm nje struktur te tipit peme.
  typedef struct peme{
  	string fjala;
  	struct peme *p,*m,*d;
  }peme;
  	
  
  //Funksio qe krijon nyje qe permban qe do permbaj fjale.
  peme *krijoNyje(string fjala){
  	
  	peme *kulm=new peme;
  	kulm->fjala=fjala;
  	kulm->m=NULL;
  	kulm->d=NULL;
  	kulm->p=NULL;
  	return kulm;
  }

 
  
  
  //Funksion qe shton fjalen te pema.

  
  peme *add(peme *T,string fjala){
  	peme *kulm=krijoNyje(fjala);
  	peme *y=NULL;
  	peme *tmp=T;
  	
  	while(tmp!=NULL){
  		y=tmp;
  		if(kulm->fjala.compare(tmp->fjala)<0){
  			tmp=tmp->m;
		  }
  		else if(kulm->fjala.compare(tmp->fjala)>0){
  			tmp=tmp->d;
		  }
		  else{
		  	return T;
		  }
	  }
  	kulm->p=y;
  	if(y==NULL){
  		T=kulm;
  		return T;
	  }
	else if(kulm->fjala.compare(y->fjala)<0){
	  	y->m=kulm;
	  	return T;
	  }
    else{
	  	y->d=kulm;
	  	return T;
	  }
  } 
  
 //Afishimi
  
  void afisho(peme *k){
  	if(k==NULL)
  	return;
  	
  	afisho(k->m);
  	cout<<k->fjala<<" ";
  	afisho(k->d);
  }
  
  
  
  
  

  
  int main(){
  	peme *rr=NULL;	//krijojm nje peme bosh.
  	fstream in;		//Krijojm objektin qe do lexoj skedarin.
	in.open("skedar.txt",ios::in);	//hapja e skedarit.
	int count=0;
	string a;		//krijojm nje variabel te tipit string per te aksesuar fjalet ne skedar.
	while(count<1000000){
		in>>a; //leximi i stringut.
		rr=add(rr,a); //Shtimi i Stringut ne peme.
		count++;
	}

	
	afisho(rr); //Afishimi i pemes te re.
  }
