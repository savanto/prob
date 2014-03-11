/* Disc game prize fund.
 * Problem 121
 *
 * A bag contains one red disc and one blue disc. In a game of chance a
 * player takes a disc at random and its colour is noted. After each turn
 * the disc is returned to the bag, an extra red disc is added, and another
 * disc is taken at random.
 *
 * The player pays $1 to play and wins if they have taken more blue discs
 * than red discs at the end of the game.
 *
 * If the game is played for four turns, the probability of a player winning
 * is exactly 11/120, and so the maximum prize fund the banker should
 * allocate for winning in this game would be $10 before they would expect
 * to incur a loss. Note that any payout will be a whole number of dollars
 * and also includes the original $1 paid to play the game, so in the
 * example given the player actually wins $9.
 *
 * Find the maximum prize fund that should be allocated to a single game in
 * which fifteen turns are played.
 */

#include <stdio.h>

#define TURNS 15

int main() {
  // Discs draws are represented by bit fields with length being TURNS,
  // 1 - blue disc, 0 - red disk.
  // Integers 0 through 2^TURNS represent all possible games, and will be
  // analyzed for wins.
  int max_game = 0, game, turn, blue;
  unsigned long long num = 0, game_num, den = 1;

  // Calculate denominator: (TURNS+1)!
  for (turn = 2; turn <= TURNS+1; ++turn)
    den *= turn;

  // Calculate maximum game (ie. blues were drawn every turn): 2^TURNS
  for (turn = 0; turn < TURNS; ++turn)
    max_game |= 1 << turn;

  // Try each game
  for (game = 0; game <= max_game; ++game) {
    // Check if each game is a winning game, calculating probability of this
    // winning game based on turns on which blues were pulled.
    // If game is a winning one, add probability, otherwise, discard.
    blue = 0;
    game_num = 1;
    for (turn = 0; turn < TURNS; ++turn) {
      if (game & (1 << turn))
        ++blue;
      else
        game_num *= turn + 1;
    }
    if (blue > TURNS / 2)
      num += game_num;
  }

  printf("Probability of winning after %d turns: %llu / %llu\nMax payout: $%llu\n",
      TURNS, num, den, den / num);
  return 0;
}
