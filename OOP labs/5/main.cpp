#include <iostream>
#include "DateController.h"
#include "Bank.h"

int main() {
  auto dateController = DateController();
  
  auto sberbank = Bank(0.03, 1000, &dateController);
  auto tinkoff = Bank(0, 100000, &dateController);
  
  auto Petya = new User("Petya", "3B");
  auto Vasya = new User("Vasya", "9A", "Kolotushkin st, house n Pushkina", "Усы, лапы и хвост");
  
  auto PetyaDebit = sberbank.getAccountFactory()->createDebitAccount(Petya, 1.5);
  auto PetyaCredit = sberbank.getAccountFactory()->createCreditAccount(Petya, 300);
  auto VasyaDebit = tinkoff.getAccountFactory()->createDebitAccount(Vasya, 3);
  auto VasyaDeposit = tinkoff.getAccountFactory()->createDepositAccount(Vasya, 3, 1000);
  
  auto PetyaDebitAddTransaction = sberbank.createTransactionBuilder()->addAccount(PetyaDebit)->amount(350)->build();
  std::cout << PetyaDebit->getAmount() << std::endl;
  PetyaDebitAddTransaction->tryMake();
  std::cout << PetyaDebit->getAmount() << std::endl;
  
  auto VasyaDebitAddTransaction = tinkoff.createTransactionBuilder()->addAccount(VasyaDebit)->amount(15234)->build();
  std::cout << VasyaDebit->getAmount() << std::endl;
  VasyaDebitAddTransaction->tryMake();
  std::cout << VasyaDebit->getAmount() << std::endl;
  
  auto VasyaDebitPetyaDebitTransaction = sberbank.createTransactionBuilder()->addAccount(PetyaDebit)->amount(135)->decAccount(VasyaDebit)->build();
  VasyaDebitPetyaDebitTransaction->tryMake();
  std::cout << PetyaDebit->getAmount() << std::endl;
  std::cout << VasyaDebit->getAmount() << std::endl;
  
  dateController.endDay();
  dateController.endDay();
  dateController.endDay();
  dateController.endDay();
  dateController.endDay();
  dateController.endDay();
  dateController.endDay();
  dateController.endDay();
  dateController.endDay();
  dateController.endDay();
  dateController.endMonth();
  std::cout << PetyaDebit->getAmount() << std::endl;
}
