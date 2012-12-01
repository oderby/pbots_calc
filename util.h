#ifndef __UTIL_H__
#define __UTIL_H__

#include <ctype.h>

#include "enumdefs.h"
#include "poker_defs.h"

typedef struct h_dist h_dist;
// store distribution of pocket cards in ll
typedef struct h_dist {
  StdDeck_CardMask cards;
  h_dist* next;
  h_dist* prev;
} Hand_Dist;

typedef struct {
  Hand_Dist* hand_dist;
  int dist_n;
  int randomized;
} Hand;

typedef struct hand_ll hand_ll;
typedef struct hand_ll {
  Hand* hand;
  hand_ll* next;
  hand_ll* prev;
} Hand_List;

typedef struct {
  Hand_List* hands;
  int size;
} Hands;

static int char2rank(char c) {
  switch(toupper(c)) {
    case '2': return StdDeck_Rank_2;
    case '3': return StdDeck_Rank_3;
    case '4': return StdDeck_Rank_4;
    case '5': return StdDeck_Rank_5;
    case '6': return StdDeck_Rank_6;
    case '7': return StdDeck_Rank_7;
    case '8': return StdDeck_Rank_8;
    case '9': return StdDeck_Rank_9;
    case 'T': return StdDeck_Rank_TEN;
    case 'J': return StdDeck_Rank_JACK;
    case 'Q': return StdDeck_Rank_QUEEN;
    case 'K': return StdDeck_Rank_KING;
    case 'A': return StdDeck_Rank_ACE;
    default: return -1;
  }
}

static int char2suit(char c) {
  switch(toupper(c)) {
    case 'h': return StdDeck_Suit_HEARTS;
    case 'd': return StdDeck_Suit_DIAMONDS;
    case 'c': return StdDeck_Suit_CLUBS;
    case 's': return StdDeck_Suit_SPADES;
    default: return -1;
  }
}

Hand* create_hand(void);
Hands* create_hands(void);
void insert_hand(Hands* hands, Hand* hand);
void insert_hand_dist(Hand* hand, Hand_Dist* h);
void insert_new(StdDeck_CardMask cards, Hand* hand);
void remove_hd(Hand_Dist* h);
void remove_and_free(Hand_Dist* h);

#endif
