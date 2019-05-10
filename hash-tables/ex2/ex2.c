#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));
  // we can build out the whole itenerary first, THEN pass the last one as the current!

  for (int j = 0; j < length; j++)
  {
    //so, let's build out this stuff one by one, and go through all the tickets, and make a train out of them
    hash_table_insert(ht, (*tickets[j]).source, (*tickets[j]).destination);
    //printf("what does the ht look like? : %s \n", ht);
  }
  char *current = "NONE";

  for (int i = 0; i < length; i++)
  {
    // we need to find the first place, the source place. so look for NONE

    // if (strcmp((*tickets[i]).source, "NONE") == 0)
    // {
    //   printf("let's put that into the route[0]\n");
    //   route[i] = hash_table_retrieve(ht, (*tickets[i]).source);
    //   printf("route[%d] is: %s\n", i, route[i]);
    // }
    // this is the only way i know to rebuild the table; wonder if there's another way
    route[i] = hash_table_retrieve(ht, current);
    current = route[i];
  }
  printf("what does tickets look like? : %s \n", *route);

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%s\n", route[i]);
  }
}

#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif
