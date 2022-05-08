// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
  Cage *temp = new Cage;
  temp->light = light;
  if (!first) {
    temp->next = temp;
    temp->prev = temp;
    first = temp;
    return;
  }
  temp->next = first->next;
  temp->prev = first;
  first->next->prev = temp;
  first->next = temp;
  delete temp;
}

int Train::getLength() {
  int step = 0;
  countOp = 0;
  int i = 0;
  Cage *temp = first;
  first->light = true;
  while (true) {
    step++;
    countOp++;
    temp = temp->next;
    if (temp->light) {
      temp->light = false;
      i = step;
      for (i = step; i > 0; --i) {
        temp = temp->prev;
        countOp++;
      }
      if (!(temp->light)) {
        return step;
      }
      step = i;
    }
  }
}

int Train::getOpCount() {
    return countOp;
}
