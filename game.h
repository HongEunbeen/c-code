#ifndef __GAME_H_
#define __GAME_H_

enum {SCISSORS = 1, ROCK, PAPER};

int ChoiceOfCom();
int ChoiceOfMe();
void WhoIsWinner(int com, int you);

#endif
