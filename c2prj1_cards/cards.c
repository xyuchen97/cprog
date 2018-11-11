#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  //initialize cardsvalue
  int cv;
  int cvok=0;
  for(cv = 2;cv <= VALUE_ACE; cv++){
    if(c.value==cv){
      cvok=1;
      break;
    }}
    assert(cvok==1);
    //initialize suitvalue
    int sv;
    int svok=0;
    for(sv=0;sv<NUM_SUITS; sv++){
      if(c.suit==sv){
	svok=1;
	break;
      }}
      assert(svok==1);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
break;
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
    break;
  case FULL_HOUSE:
    return "FULL_HOUSE";
    break;
  case FLUSH:
    return "FLUSH";
    break;
  case STRAIGHT:
    return "STRAIGHT";
    break;
  case THREE_OF_A_KIND:
  return "THREE_OF_A_KIND";
  break;
  case TWO_PAIR:
    return "TWO_PAIR";
    break;
  case PAIR:
    return "PAIR";
    break;
  case NOTHING:
    return "NOTHING";
    break;
  default:
    return "INVALID";
  }
}

char value_letter(card_t c) {
  char x;
  if((c.value>=2)&&(c.value<=9)){
    x='0'+c.value;
  }
  else{
    switch(c.value){
    case VALUE_ACE:
      x= 'A';
      break;
    case VALUE_JACK:
      x= 'J';
      break;
    case VALUE_QUEEN:
      x= 'Q';
      break;
    case VALUE_KING:
      x= 'K';
      break;
    case 10:
      x= '0';
      break;
    default:
      x='x';
      break;
    }
  }
  return x;
}


char suit_letter(card_t c) {
  char y;
  switch(c.suit){
  case SPADES:
    y= 's';
    break;
  case HEARTS:
    y= 'h';
    break;
  case DIAMONDS:
    y= 'd';
    break;
  case CLUBS:
    y= 'c';
    break;
  default:
    y='x';
    break;
  }
  return y;
  
}

void print_card(card_t c) {
  char printvalue =value_letter(c);
  char printsuit = suit_letter(c);
  printf("%c%c",printvalue, printsuit);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;if (value_let >= '2' && value_let <= '9') {
    temp.value = value_let - '0'; 
  }
  else if (value_let == '0' || value_let == 'J' || value_let =='Q' 
	   || value_let == 'K' || value_let == 'A') {
    switch (value_let) {
    case '0':
      temp.value = 10;
      break;
    case 'J':
      temp.value = VALUE_JACK;
      break;
    case 'Q':
      temp.value = VALUE_QUEEN;
      break;
    case 'K':
      temp.value = VALUE_KING;
      break;
    case 'A':
      temp.value = VALUE_ACE;
      break;
    default:
      temp.value = 0; 
    } 
  }
  else {
    printf("invalid value\n");
    exit(EXIT_FAILURE); 
  }
  switch (suit_let) {
  case 's':
    temp.suit = SPADES;
    break;
  case 'h':
    temp.suit = HEARTS;
    break;
  case 'd':
    temp.suit = DIAMONDS;
    break;
  case 'c':
    temp.suit = CLUBS;
    break;
  default:
    exit(EXIT_FAILURE);
    
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  unsigned mapsuit=c/13;
  unsigned mapvalue=c%13;
  switch(mapsuit){
  case 0:
    temp.suit=SPADES;
    break;
  case 1:
    temp.suit = HEARTS;
    break;
  case 2:
    temp.suit = DIAMONDS;
    break;
  case 3:
    temp.suit = CLUBS;
    break;
  default:
    exit(EXIT_FAILURE); 
  }
  temp.value = mapvalue + 2;
  return temp;
}
