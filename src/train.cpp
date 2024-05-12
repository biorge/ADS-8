// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
  Cage *newCage = new Cage;
  newCage->light = light;
  newCage->next = nullptr;
  newCage->prev = nullptr;

  if (!first) {
    first = newCage;
    first->next = first;
    first->prev = first;
  } else {
    Cage *lastCage = first->prev;
    lastCage->next = newCage;
    newCage->prev = lastCage;
    newCage->next = first;
    first->prev = newCage;
  }
}

int Train::getLength() {
  if (!first) return 0;

  int length = 0;
  Cage *current = first;
  do {
    length++;
    current = current->next;
  } while (current != first);
  return length;
}

int Train::getOpCount() { return countOp; }
