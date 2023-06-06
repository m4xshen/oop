#pragma once

class Electronics {
 public:
  Electronics(int length, int width);
  bool get_usage();
  void set_usage(bool flag);
  bool get_charging();
  void set_charging(bool flag);
  void charge();
  virtual void poweron() = 0;
  void poweroff();
  virtual void run() = 0;

 protected:
  int length;
  int width;

 private:
  bool usage;
  bool charging;
};
