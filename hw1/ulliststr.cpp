#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
  if (empty())
  {
    head_ = new Item;
    tail_ = new Item;
    Item *temp = new Item;
    temp->last++;
    temp->val[0] = val;
    temp->next = tail_;
    temp->prev = head_;
    head_->next = temp;
    tail_->prev = temp;
    size_++;
    return;
  }
  if (tail_->prev->last < ARRSIZE)
  {
    tail_->prev->val[tail_->prev->last] = val;
    tail_->prev->last++;
    size_++;
    return;
  }
  Item *temp = new Item;
  temp->val[0] = val;
  temp->last++;
  tail_->prev->next = temp;
  tail_->prev = temp;
  size_++;
}

void ULListStr::pop_back() {
  if (empty())
  {
    throw std::invalid_argument("Bad pop");
  }
  tail_->prev->last--;
  if (tail_->prev->first == tail_->prev->last) {
    Item *temp = tail_->prev;
    tail_->prev = temp->prev;
    delete temp;
  }
  if (head_->next == tail_) {
    delete head_;
    delete tail_;
    head_ = tail_ = NULL;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val) {
  if (empty())
  {
    push_back(val);
    return;
  }
  if (head_->next->first > 0)
  {
    head_->next->first--;
    head_->next->val[head_->next->first] = val;
    size_++;
    return;
  }
  Item *temp = new Item;
  temp->first = ARRSIZE - 1;
  temp->last = ARRSIZE;
  temp->val[temp->first] = val;
  temp->next = head_->next;
  head_->next = temp;
  size_++;
}

void ULListStr::pop_front() {
  if (empty())
  {
    throw std::invalid_argument("Bad pop");
  }
  head_->next->first++;
  if (head_->next->first == head_->next->last) {
    Item *temp = head_->next;
    head_->next = temp->next;
    delete temp;
  }
  if (head_->next == tail_) {
    delete head_;
    delete tail_;
    head_ = tail_ = NULL;
  }
  size_--;
}

std::string const & ULListStr::back() const {
  if (empty())
  {
    throw std::invalid_argument("Bad access");
  }
  return tail_->prev->val[tail_->prev->last-1];
}

std::string const & ULListStr::front() const {
  if (empty())
  {
    throw std::invalid_argument("Bad access");
  }
  return head_->next->val[head_->next->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const 
{
 size_t i = 0;
 Item *temp = head_->next;
 while(temp != tail_){
  for(size_t j = temp->first; j < temp->last; ++j)
  {
    if(i == loc) return &temp->val[j];
    ++i;
  }
  temp = temp->next;
 }
 throw std::invalid_argument("Bad location");
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
