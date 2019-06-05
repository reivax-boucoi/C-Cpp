#ifndef MENU_H_
#define MENU_H_

class Menu{
public:
    int (*fptr)(int);
    Menu* parent;
	Menu** subs;
	int nbSubs;
	int currentsub=0;
	char name[5];
};


#endif /* MENU_H_ */
