/*The new "Avengers" movie has just been released! There are a lot of people at the cinema box office standing in a huge line. Each of them has a single 100, 50 or 25 dollar bill. An "Avengers" ticket costs 25 dollars.

Vasya is currently working as a clerk. He wants to sell a ticket to every single person in this line.

Can Vasya sell a ticket to every person and give change if he initially has no money and sells the tickets strictly in the order people queue?

Return YES, if Vasya can sell a ticket to every person and give change with the bills he has at hand at that moment. Otherwise return NO.
Examples:

tickets({25, 25, 50}) // => YES 
tickets({25, 100}) // => NO. Vasya will not have enough money to give change to 100 dollars
tickets({25, 25, 50, 50, 100}) // => NO. Vasya will not have the right bills to give 75 dollars of change (you can't make two bills of 25 from one of 50)
*/


bool getChange(int price, int paid, std::list<int>& till) {

  till.push_back(paid);
  till.sort([](int a, int b) { return a > b; });

  int left_to_refund = paid - price;

  auto till_iter = till.begin();

  while (left_to_refund > 0 && till_iter != till.end()) {
    int curr_bill = *till_iter;

    if (left_to_refund >= curr_bill) {
      left_to_refund -= curr_bill;
      till_iter = till.erase(till_iter);
    } else {
      ++till_iter;
    }
  }

  return left_to_refund == 0;
}

std::string tickets(const std::vector<int> peopleInLine){

  int price = 25;
  std::list<int> till = {};

  for (int person : peopleInLine) {
    bool success = getChange(price, person, till);
    if (!success) {
      return "NO";
    }
  }

  return "YES";
}
