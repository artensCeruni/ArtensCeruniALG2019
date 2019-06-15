#include<iostream> 
#include<fstream>
#include<Math.h>
using namespace std; 
  
//Deklarimi i struktures
   
typedef struct Peme  
{  
    string fjala;  
    Peme *left;  
    Peme *right;  
    int lartesia;  
}Peme;  
  
  
  
//Funksioni qe kthen lartesine e nje nyje
  
int lartesia(Peme *N)  
{  
    if (N == NULL)  
        return 0;  
    return N->lartesia;  
}  
  
//Funksioni qe kthen max e dy numrave  

int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
//Funksioni qe krijon nyje

Peme* krijoNyje(string fjala)  
{  
    Peme* peme = new Peme();   
 	peme->fjala=fjala;
    peme->left = NULL;  
    peme->right = NULL;  
    peme->lartesia = 1; //Lartesia ne fillim eshte 1 pasi kulmi n fillim vendoset tek gjethja 
    return peme;  
}  
  

//Funksioni qe ben rrotullimin djathtas
 
Peme *rrotulloDjathtas(Peme *y)  
{  
    Peme *x = y->left;  
    Peme *T2 = x->right;    
    x->right = y;  //Behet rrotullimi
    y->left = T2;  
  
    //Behet rregullimi i lartesise
    y->lartesia = max(lartesia(y->left), 
                    lartesia(y->right)) + 1;  
    x->lartesia = max(lartesia(x->left), 
                    lartesia(x->right)) + 1;  
   
    return x;  
}  

  
//Funkioni qe ben rrotullimin majtas
 
Peme *rrotulloMajtas(Peme *x)  
{  
    Peme *y = x->right;  
    Peme *T2 = y->left;  
  
    // Behet rrotullimi 
    y->left = x;  
    x->right = T2;  
  
    // Rregullohet lartesia  
    x->lartesia = max(lartesia(x->left),     
                    lartesia(x->right)) + 1;  
    y->lartesia = max(lartesia(y->left),  
                    lartesia(y->right)) + 1;  
  
    return y;  
}  
  
// Merr balancen e nje kulmi
 
int getBalance(Peme *N)  
{  
    if (N == NULL)  
        return 0;  
    return lartesia(N->left) - lartesia(N->right);  
}  


//Funkioni qe shton nje kulm ne peme

Peme* add(Peme* peme, string fjala)  
{  
    //Behet shtimi normal si nje nje peme kerkimi binar
    
    if (peme == NULL)  
        return(krijoNyje(fjala));  
  
    if (fjala.compare(peme->fjala)<0)  
        peme->left = add(peme->left,fjala);  
    else if (fjala.compare(peme->fjala)>0)  
        peme->right = add(peme->right,fjala);  
    else   
        return peme;  
  
    //Behet rregullimi i lartesive te cdo kulmi
    
    peme->lartesia = 1 + max(lartesia(peme->left),  
                        lartesia(peme->right));  
  
  
    int balance = getBalance(peme); //Merret balanca e kulmit  
  
    //Behet kontrolli i balances dhe ka kater raste kur duhet t bejme ndryshim
  
//Rasti 1 kur fjala qe u shtua ka qene me e vogel se biri i kulmit t pabalancuar dhe me e vogel se nipi i tij
    if (balance > 1 && fjala.compare(peme->left->fjala)<0)  
        return rrotulloDjathtas(peme);  
  
//Rasti 2 kur fjala qe u shtua ka qene me e madhe se biri i kulmit t pabalancuar dhe me e madhe se nipi i tij
 
    if (balance < -1 && fjala.compare(peme->right->fjala)>0)  
        return rrotulloMajtas(peme);  

//Rasti 3 kur fjala qe u shtua ka qene me e vogel se biri i kulmit t pabalancuar dhe me e madhe se nipi i tij

    if (balance > 1 && fjala.compare(peme->left->fjala)>0)  
    {  
        peme->left = rrotulloMajtas(peme->left);  
        return rrotulloDjathtas(peme);  
    }  
  
//Rasti 4 kur fjala qe u shtua ka qene me e madhe se biri i kulmit t pabalancuar dhe me e vogel se nipi i tij

    if (balance < -1 && fjala.compare(peme->right->fjala)<0)  
    {  
        peme->right = rrotulloDjathtas(peme->right);  
        return rrotulloMajtas(peme);  
    }  
  
    
    return peme;  
}  

//afishimi 
void afisho(Peme *root)  
{  
    if(root != NULL)  
    {  
          cout << root->fjala << " ";
        afisho(root->left); 
		 
        afisho(root->right);  
    }  
}  
   
int main()  
{  
    Peme *root = NULL;  
       fstream in;   //Krijimi objektit per t lexuar fjalet ne skedar
	in.open("skedar.txt",ios::in);
	string a;
	int c;
	while(c<1000000){
		in>>a;
		root=add(root,a);
		c++;
	} 
    afisho(root);  //Afishimi
      
    return 0;  
}  
  
