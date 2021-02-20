cmake_minimum_required(VERSION 3.17)
project(clion2)

set(CMAKE_CXX_STANDARD 14)

add_executable(clion2 main.cpp AccountSnapshot.cpp DateController.cpp Transaction.cpp User.cpp AccountCreatedListener.h AccountFactory.cpp Bank.cpp Bank.h accounts/CreditAccount.cpp accounts/CreditAccount.h accounts/Account.cpp accounts/DebitAccount.cpp accounts/DebitAccount.h accounts/DepositAccount.cpp accounts/DepositAccount.h)