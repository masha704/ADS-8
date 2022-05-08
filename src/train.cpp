// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :countOp(0), first(nullptr) {}

Train::Cage *create(bool light) {
  Cage *cage = new Cage;
  cage->light = light;
  cage->next = nullptr;
  cage->prev = nullptr;
  return cage;
}

void Train::addCage(bool light) {
  if (first && last) {
    Cage *temp = create(light);
    temp->prev = first->prev;
    temp->prev->next = temp;
    first->prev = temp;
    first->prev->next = first;
  } else {
    first = create(light);
  }
}

int Train::getLength() {
  Cage *temp = first;
  temp->light = true;
  int step = 0;
  while (temp) {
    temp = temp->next;
    step++;
    countOp++;
    if (temp->light) {
      temp->light = false;
      break;
    }
  }
  for (int i = 0; i < step; i++) {
    temp = temp->prev;
    countOp++;
  }
  if (!(temp->light)) {
    return step;
  }
  return getLength();
}

int Train::getOpCount() {
    return countOp;
}
