#include "Stock.h"

const double Stock::init_price = 57.88;
const double Stock::limit_ratio = 0.1;
double Stock::cur_price = Stock::init_price;
bool Stock::trade_available = true;

Stock::Stock() : ticket_num(0), avg_buy_price(0) {}

Stock::Stock(string name) :
  owner_name(name), ticket_num(0), avg_buy_price(0) {}

Stock::Stock(string name, int n1) :
  owner_name(name), ticket_num(n1), avg_buy_price(0) {}

void Stock::show_current_price() {
  std::cout << "------------------------------------------\n" ;
  std::cout << "current price of the stock: " << cur_price << "\n";
}

void Stock::refresh_current_price() {
  cur_price = cur_price + static_cast<double>(rand() % 500) / 100 - 2.5;
  show_current_price();
}

void Stock::check_trade_is_available() {
  if (!trade_available) {
    std::cout << "trade is not available anymore\n";
    return;
  }

  double dr = abs(cur_price - init_price) / init_price;
  trade_available = dr <= limit_ratio;
  if (!trade_available) {
    std::cout << "trade is not available anymore\n";
  }
}

void Stock::buy() {
  if (!trade_available) {
    std::cout << "The trade is not available today.\n";
    return;
  }
  std::cout << "How many tickets do you want to buy: ";
  int tmp;
  std::cin >> tmp;
  Stock s("", tmp);
  s.avg_buy_price = cur_price;
  (*this) + s;
}

void Stock::sell() {
  if (!trade_available) {
    std::cout << "The trade is not available today.\n";
    return;
  }
  std::cout << "How many tickets do you want to sell: ";
  int tmp;
  std::cin >> tmp;
  if (ticket_num < tmp) {
    std::cout << "you don't have enough stock ticket\n";
    return;
  }
  Stock s("", tmp);
  s.avg_buy_price = cur_price;
  (*this) - s;
}

void Stock::show_stock() {
  std::cout << owner_name << ", you have " << ticket_num <<
    " stocks and the average price is " << avg_buy_price << "\n";
}

void Stock::operator + (const Stock & s) {
  this->avg_buy_price =
    (this->avg_buy_price*this->ticket_num + s.avg_buy_price*s.ticket_num) /
    (this->ticket_num + s.ticket_num);
  this->ticket_num += s.ticket_num;
}


void Stock::operator - (const Stock & s) {
  this->avg_buy_price =
    (this->avg_buy_price*this->ticket_num - s.avg_buy_price*s.ticket_num) /
    (this->ticket_num - s.ticket_num);
  this->ticket_num -= s.ticket_num;
}

string Stock::get_owner_name() const {
  return owner_name;
}
