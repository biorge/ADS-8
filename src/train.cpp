// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCage(bool light) {
  Cage* newCage = new Cage;
  newCage->light = light;
  if (first == nullptr) {
    first = newCage;
    first->next = first;
    first->prev = first;
  } else {
    newCage->next = first;
    newCage->prev = first->prev;
    first->prev->next = newCage;
    first->prev = newCage;
    countOp += 2;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;
  int length = 0;
  Cage* current = first;
  do {
    length++;
    current = current->next;
  } while (current != first);
  return length;
}

int Train::getOpCount() { return countOp; }
