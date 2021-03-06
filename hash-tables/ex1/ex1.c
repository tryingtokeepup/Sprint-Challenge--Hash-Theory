#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  Answer *answer = NULL;

  HashTable *ht = create_hash_table(16);

  for (int i = 0; i < length; i++)
  {

    // Check weights against the limit, by subtracting the weight against the limit - 0 (n) time

    int remainder = limit - weights[i];
    // check remainder and see if its stored somewhere inside the hash table
    int hash_return = hash_table_retrieve(ht, remainder);
    printf("hash_table_retrieve returns: %d\n", hash_return);
    if (hash_return != -1)
    {
      hash_table_insert(ht, weights[i], i);
      answer = malloc(sizeof(Answer));

      answer->index_1 = i;
      printf("index1 = %d\n", i);
      answer->index_2 = hash_return;
      // my argument is that they both work
      printf("index2 = %d\n", answer->index_2);

      destroy_hash_table(ht); //no mem leaks
      return answer;
    }
    else
    {
      hash_table_insert(ht, weights[i], i);
    }
  }
  destroy_hash_table(ht); //no mem leaks
  return answer;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("{%d, %d}\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{

  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1); // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer *answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2); // {1, 0}, {1, 1} edge case, both equal 8

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer *answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3); // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer *answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4); // {6, 2}

  return 0;
}
#endif
