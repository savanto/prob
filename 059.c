/* XOR decryption.
 * Problem 059
 *
 * Each character on a computer is assigned a unique code and the preferred
 * standard is ASCII (American Standard Code for Information Interchange).
 * For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
 *
 * A modern encryption method is to take a text file, convert the bytes to
 * ASCII, then XOR each byte with a given value, taken from a secret key.
 * The advantage with the XOR function is that using the same encryption key
 * on the cipher text restores the plain text; for example 65 XOR 42 = 107,
 * then 107 XOR 42 = 65.
 *
 * For unbreakable encryption, the key is the same length as the plain text
 * message, and the key is made up of random bytes. The user would keep the
 * encrypted message and the encryption key in different locations, and
 * without both "halves", it is impossible to decrypt the message.
 *
 * Unfortunately, this method is impractical for most users, so the modified
 * method is to use a password as key. If the password is shorter than the
 * message, which is likely, the key is repeated cyclically throughout the
 * message. The balance for this method is using a sufficiently long
 * password key for security, but short enough to be memorable.
 *
 * Your task has been made easy, as the encryption key consists of three
 * lower case characters. Using 059.txt, a file containing the encrypted
 * ASCII codes, and the knowledge that the plain text must contain common
 * English words, decrypt the message and find the sum of the ASCII values
 * in the original text.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define CH 4
#define SEP ','
#define MAX_LEN 10000
#define FILENAME "059.txt"
#define CORPUS "bible.txt"

#define CHAR_SET 256
#define KEY 3

int main() {
  // Read ciphertext file
  FILE* fp = fopen(FILENAME, "r");
  if (fp == NULL) {
    perror("Could not open \"" FILENAME "\" cipertext");
    return 1;
  }
  char ch[CH] = { 0 };
  int len = 0, j = 0;
  int ciphertext[MAX_LEN];
  int c = fgetc(fp);
  while (c != EOF && len < MAX_LEN) {
    if (c == SEP) {
      ciphertext[len++] = atoi(ch);
      for (j = 0; j < CH; ++j)
        ch[j] = 0;
      j = 0;
    }
    else
      ch[j++] = c;
    c = fgetc(fp);
  }
  ciphertext[len++] = atoi(ch);
  fclose(fp);

  // Read corpus file
  fopen(CORPUS, "r");
  if (fp == NULL) {
    perror("Could not open \"" FILENAME "\" corpus text");
    return 1;
  }
  double corpus_freqs[CHAR_SET] = { 0 };
  int corpus_count = 0;
  c = fgetc(fp);
  while (c != EOF) {
    ++corpus_freqs[c];
    ++corpus_count;
    c = fgetc(fp);
  }
  fclose(fp);

  // Calculate corpus freqs
  for (j = 0; j < CHAR_SET; ++j)
    corpus_freqs[j] /= corpus_count;

  // Calculate ciphertext freqs based on key length
  double cipher_freqs[KEY][CHAR_SET] = { { 0 } };
  int k;
  for (k = 0; k < KEY; ++k)
    for (j = k; j < len; j += KEY)
      ++cipher_freqs[k][ciphertext[j]];
  for (k = 0; k < KEY; ++k)
    for (j = 0; j < CHAR_SET; ++j)
      cipher_freqs[k][j] /= len / KEY;

  // xor each cipher_freq with every possible key (0-255)
  // The smallest score is the probable key value
  unsigned char key[KEY];
  double score, best_score;
  for (k = 0; k < KEY; ++k) {
    best_score = 1000;
    key[k] = 0;
    for (c = 0; c < CHAR_SET; ++c) {
      score = 0;
      for (j = 0; j < CHAR_SET; ++j)
        score += fabs(cipher_freqs[k][j^c] - corpus_freqs[j]);
      if (score < best_score) {
        best_score = score;
        key[k] = c;
      }
    }
  }

  // Output key, plaintext, sum of plaintext ASCII values
  printf("Key: %s\n\n", key);
  for (j = 0, k = 0; j < len; ++j) {
    c = ciphertext[j] ^ key[j%KEY];
    k += c;
    printf("%c", c);
  }
  printf("\n\nSum of plaintext ASCII values = %d\n", k);

  return 0;
}
