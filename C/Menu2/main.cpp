#include "Menu.h"
#include <iostream>
#include <string.h>
using namespace std;


Menu* root;
Menu* cMenu;
Menu* subs[4];
Menu* l[4];

int testFunc(int i){
	return i+2;
}
void displayM(Menu* m,int d){
	cout << m->name << " ("<<m->nbSubs<<")";
	if(m->fptr != nullptr)cout <<" : "<<m->fptr(d);
	cout <<endl;
	if(m->nbSubs>0){
		for(int i=0;i<m->nbSubs;i++){
			for(int dd=0;dd<d;dd++)cout << "\t";
			displayM(m->subs[i],d+1);
		}
	}
}


int main(void){
	root=(Menu*)malloc(sizeof(Menu));
	root->fptr=nullptr;
	for(int i=0;i<4;i++){
		subs[i]=(Menu*)malloc(sizeof(Menu));
		strcpy(subs[i]->name,"sub0");
		subs[i]->name[3]=i+'1';
		subs[i]->parent=root;
		subs[i]->nbSubs=0;
		subs[i]->fptr=nullptr;
		
	}
	
	for(int i=0;i<4;i++){
		l[i]=(Menu*)malloc(sizeof(Menu));
		strcpy(l[i]->name,"lea0");
		l[i]->name[3]=i+'1';
		l[i]->parent=subs[0];
		l[i]->nbSubs=0;
		l[i]->fptr=&testFunc;
		
	}
	strcpy(root->name,"root");
	
	root->subs=subs;
	root->nbSubs=4;
	
	subs[0]->subs=l;
	subs[0]->nbSubs=4;
	
	cMenu=root;
	displayM(root,1);
	return 0;
}