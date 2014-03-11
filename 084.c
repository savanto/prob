/* Monopoly odds
 * Problem 084
 *
 * In the game Monopoly, the standard board is set up in the following way:
 *
 *    +----+----+----+----+----+----+----+----+----+----+----+
 *    | GO | A1 |CC1 | A2 | T1 | R1 | B1 |CH1 | B2 | B3 |JAIL|
 *    +----+----+----+----+----+----+----+----+----+----+----+
 *    | H2 |                                            | C1 |
 *    +----+                                            +----+
 *    | T2 |                                            | U1 |
 *    +----+                                            +----+
 *    | H1 |                                            | C2 |
 *    +----+                                            +----+
 *    |CH3 |                                            | C3 |
 *    +----+                                            +----+
 *    | R4 |                                            | R2 |
 *    +----+                                            +----+
 *    | G3 |                                            | D1 |
 *    +----+                                            +----+
 *    |CC3 |                                            |CC2 |
 *    +----+                                            +----+
 *    | G2 |                                            | D2 |
 *    +----+                                            +----+
 *    | G1 |                                            | D3 |
 *    +----+----+----+----+----+----+----+----+----+----+----+
 *    |G2J | F3 | U2 | F2 | F1 | R3 | E3 | E2 |CH2 | E1 | FP |
 *    +----+----+----+----+----+----+----+----+----+----+----+
 *
 * A player starts on the GO square and adds the scores on two 6-sided dice
 * to determine the number of squares they advance in a clockwise direction.
 * Without any further rules we would expect to visit each swuare with equal
 * probability: 2.5%. However, landing on G2J (Go To Jain), CC (Community
 * Chest), and CH (Chance) changes this distribution.
 *
 * In addition to G2J, and one card from each each of CC and CH, that orders
 * the player to go directly to jain, if a player rolls three consecutive
 * doubles, they do not advance the result of their 3rd roll. Instead they
 * proceed directly to jain.
 *
 * At the beginning of the game, the CC and CH cards are shuffled. When a 
 * player lands on CC or CH, they take a card from the top of the respective
 * pile and, after following the instructions, it is returned to the bottom
 * of the pile. There are sixteen cards in each pile, but for the purpose
 * of this problem we are only concerned with the cards that order a
 * movement; any instruction not concerned with movement will be ignored
 * and the player will remain on the CC/CH square.
 *
 *    - Communit Chest (2/16 cards):
 *      1. Advance to GO
 *      2. Go to Jail
 *    - Change (10/16 cards):
 *      1. Advance to GO
 *      2. Go to Jail
 *      3. Go to C1
 *      4. Go to E3
 *      5. Go to H2
 *      6. Go to R1
 *      7. Go to next R (railway company)
 *      8. Go to next R
 *      9. Go to next U (utility company)
 *     10. Go back 3 squares.
 *
 * The heart of this problem concerns the likelihood of visiting a
 * particular square. That is, the probability of finishing at that square
 * after a roll. For this reason it should be clear that, with the exception
 * of G2J for which the probability of finishing on it is zero, the CH
 * squares will have the lowest probabilities, as 5/8 request a movment to
 * another square, and it is the final square that the player finishes at on
 * each roll that we are interested in. We shall make no distinction between
 * "Just Visiting" and being sent to JAIL, and we shall also ignore the rule
 * about requiring a double to "get out of jail", assuming that they pay to
 * get out on their next turn.
 *
 * By starting at GO and numbering the squares sequentially from 00 to 39 we
 * can concatenate these two-digit numbers to produce strings that
 * correspond with sets of squares.
 *
 * Statistically it can be shown that the three most popular squares, in
 * order, are JAIL (6.24%) = Square 10, E3 (3.18%) = Square 24, and GO
 * (3.09%) = Square 00. So these three most popular squares can be listed
 * with the six-digit modal strig: 102400
 *
 * If, instead of using two 6-sided dice, two 4-sided dice are used, find
 * the six-digit modal string.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TILES 40
#define TURNS 10000000
#define DICE 4

#define GO 0
#define JAIL 10
#define G2J 30
#define CH1 7
#define CH2 22
#define CH3 36
#define CC1 2
#define CC2 17
#define CC3 33
#define R1 5
#define R2 15
#define R3 25
#define R4 35
#define U1 12
#define U2 28
#define C1 11
#define E3 24
#define H2 39


int main() {

  srand(time(NULL));

  double board[TILES] = { 0.0 };
  int game, turn, pos, doubles, d1, d2, cc, ch;
  // Begin game
  pos = 0;
  doubles = 0;
  cc = rand() % 16;
  ch = rand() % 16;
  for (turn = 0; turn < TURNS; ++turn) {
    // Roll dice
    d1 = rand() % DICE + 1;
    d2 = rand() % DICE + 1;
    if (d1 == d2)
      ++doubles;
    else
      doubles = 0;
    // Go to jail if doubles rolled 3x in a row
    if (doubles == 3) {
      pos = JAIL;
      doubles = 0;
    }
    else {
      // Move
      pos = (pos + d1 + d2) % TILES;
      // Special squares
      switch (pos) {
        // Go to jail
        case G2J:
          pos = JAIL;
//          doubles = 0;
          break;
        // Community chest (FALL-THROUGH)
        case CC1:
        case CC2:
        case CC3:
          switch (cc) {
            // Go
            case 0: 
              pos = GO;
//              doubles = 0;
              break;
            // Jail
            case 1:
              pos = JAIL;
//              doubles = 0;
              break;
          }
          cc = ++cc % 16;
          break;
        // Chance (FALL-THROUGH)
        case CH1:
        case CH2:
        case CH3:
          switch (ch) {
            // Go
            case 0:
              pos = GO;
//              doubles = 0;
              break;
            // Jail
            case 1:
              pos = JAIL;
//              doubles = 0;
              break;
            // C1
            case 2:
              pos = C1;
//              doubles = 0;
              break;
            // E3
            case 3:
              pos = E3;
//              doubles = 0;
              break;
            // H2
            case 4:
              pos = H2;
//              doubles = 0;
              break;
            // R1
            case 5:
              pos = R1;
//              doubles = 0;
              break;
            // Next R (FALL-THROUGH)
            case 6:
            case 7:
              if (pos < R1)
                pos = R1;
              else if (pos < R2)
                pos = R2;
              else if (pos < R3)
                pos = R3;
              else if (pos < R4)
                pos = R4;
              else
                pos = R1;
//              doubles = 0;
              break;
            // Next U
            case 8:
              if (pos < U1)
                pos = U1;
              else if (pos < U2)
                pos = U2;
              else
                pos = U1;
//              doubles = 0;
              break;
            // Go back 3 spaces
            case 9:
//              pos -= 3; // this is safe, no CH at pos = 2 so cannot wrap back
//              doubles = 0;
              break;
          }
          ch = ++ch % 16;
          break;
      }
    }
    // If doubles were rolled, move again.
    if (doubles)
      --turn;
    else  // Otherwise, pos is at final tile for this move.
      ++board[pos]; // Increment counter for this tile.
  }

  // Calculate frequencies
  int pop[3] = { 0 };
  double popf[3] = { 0.0 }, tmp;
  for (pos = 0; pos < TILES; ++pos) {
    tmp = board[pos] / TURNS;
    if (tmp > popf[0]) {
      popf[2] = popf[1];
      popf[1] = popf[0];
      popf[0] = tmp;

      pop[2] = pop[1];
      pop[1] = pop[0];
      pop[0] = pos;
    }
    else if (tmp > popf[1]) {
      popf[2] = popf[1];
      popf[1] = tmp;

      pop[2] = pop[1];
      pop[1] = pos;
    }
    else if (tmp > popf[2]) {
      popf[2] = tmp;

      pop[2] = pos;
    }
  }

  printf("The top squares are:\n");
  for (pos = 0; pos < 3; ++pos)
    printf("Square %.2d: %.2f%%\n", pop[pos], popf[pos] * 100);
  printf("Modal string: %.2d%.2d%.2d\n", pop[0], pop[1], pop[2]);

  return 0;
}
