// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
  Cage *temp = new Cage;
  temp->light = light;
  temp->next = nullptr;
  temp->prev = nullptr;
  if (first == nullptr) {
    first = temp;
  } else if (first->next == nullptr) {
    first->next = temp;
    temp->prev = first;
    first->prev = temp;
    temp->next = first;
  } else {
    first->next->prev = temp;
    temp->prev = first->prev;
    first->prev = temp;
    temp->next = first;
  //delete temp;
  }
}

int Train::getLength() {
  int step = 0;
  countOp = 0;
  int i = 0;
  first->light = true;
  Cage *temp = first;
  while (temp) {
    step++;
    countOp++;
    temp = temp->next;
    if (temp->light) {
      temp->light = false;
      i = step;
      for (i; i > 0; i--) {
        temp = temp->prev;
        countOp++;
      }
      if (!(temp->light)) {
        return step;
      }
      step = i;
    }
  }
  return i;
}

int Train::getOpCount() {
    return countOp;
}
