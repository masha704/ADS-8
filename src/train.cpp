// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :countOp(0), first(nullptr) {}

Train::Cage* Train::create(bool light) {
  Cage *cage = new Cage;
  cage->light = light;
  cage->next = nullptr;
  cage->prev = nullptr;
  return cage;
}

void Train::addCage(bool light) {
  if (first != nullptr) {
    Cage *temp = create(light);
    //temp->prev = first->prev;
    //temp->prev->next = temp;
    //first->prev = temp;
    //first->prev->next = first;
    temp->next = first->next;
    temp->prev = first;
    first->next->prev = temp;
    first->next = temp;
  } else {
    first = create(light);
  }
}

int Train::getLength() {
  Cage *temp = first;
  temp->light = true;
  int step = 0;
  countOp = 0;
  int length = 0;
  while (true) {
    temp = temp->next;
    step++;
    countOp++;
    if (temp->light) {
      temp->light = false;
      for (int i = step; i > 0; i--) {
        temp = temp->prev;
        countOp++;
      }
      if (!(temp->light)) {
        return step;
      }
      step = 0;
    }
  }
  return getLength();
}

int Train::getOpCount() {
    return countOp;
}
