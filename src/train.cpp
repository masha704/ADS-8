// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :countOp(0), first(nullptr) {}

Train::Cage* Train::create(bool light) {
  Cage *cage = new Cage;
  cage->light = light;
  //cage->next = nullptr;
  //cage->prev = nullptr;
  return cage;
}

void Train::addCage(bool light) {
  //if (first != nullptr) {
    //Cage *temp = create(light);
    //temp->prev = first->prev;
    //temp->prev->next = temp;
    //first->prev = temp;
    //first->prev->next = first;
    //temp->next = first->next;
    //temp->prev = first;
    //first->next->prev = temp;
    //first->next = temp;
  //} else {
    //first = create(light);
  //}
  Cage *temp = new Cage;
  temp->light = light;
  if (!first) {
    temp->next = nullptr;
    temp->prev = nullptr;
    first = temp;
    return;
  }
  temp->next = first->next;
  temp->prev = first;
  first->next->prev = temp;
  first->next = temp;
}

int Train::getLength() {
  Cage *temp = first;
  first->light = true;
  int step = 0;
  countOp = 0;
  while (true) {
    step++;
    countOp++;
    temp = temp->next;
    if (temp->light) {
      temp->light = false;
      int i = step;
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
