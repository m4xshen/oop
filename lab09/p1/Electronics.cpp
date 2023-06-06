#include "Electronics.h"

Electronics::Electronics(int length, int width)
  : length(length), width(width), usage(false), charging(false) {}

bool Electronics::get_usage() {
  return usage;
}

void Electronics::set_usage(bool flag) {
  usage = flag;
}

bool Electronics::get_charging() {
  return charging;
}

void Electronics::set_charging(bool flag) {
  charging = flag;
}

void Electronics::charge() {
  set_charging(!get_charging());
}

void Electronics::poweroff() {
  set_usage(false);
}
