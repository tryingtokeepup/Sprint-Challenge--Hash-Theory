#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));
  for (int i = 0; i < length; i++)
  {
    route[i] = tickets[i]->destination;
  }
  printf("what does tickets look like? : %s", route);
  //   # If we've used up all the flights, we're done
  //   if not flights:
  //       return current_itinerary
  //   last_stop = current_itinerary[-1]
  //   for i, (origin, destination) in flights:
  //       # Make a copy of flights without the current one to mark it as used
  //       flights_minus_current = flights[:i] + flights[i + 1:]
  //       current_itinerary.append(destination)
  //       if origin == last_stop:
  //           return get_itinerary(flights_minus_current, current_itinerary)
  //       current_itinerary.pop()
  //   return None
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
