//
// Created by fred on 20/01/19.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Triangle.h"
#include <iostream>

using ::testing::AtLeast;




struct BankAccount
{
    int balance = 0;

    BankAccount() {}

    BankAccount(int balance) : balance(balance) {}

    void deposit(int amount) {
        balance += amount;
    }

    bool withdraw(int amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }

    }
};

struct BankAccountTest : testing:: Test {
    std::unique_ptr<BankAccount> bankAccount;
    BankAccountTest()
    {
        bankAccount = std::make_unique<BankAccount>();
    }
};

struct account_state {
    int initial_balance;
    int withdraw_amount;
    int final_balance;
    bool success;
};


struct withdrawAccountTest : BankAccountTest, testing::WithParamInterface <account_state> {
    withdrawAccountTest() {
        bankAccount -> balance = GetParam().initial_balance;
    }

};


TEST_F(BankAccountTest,CanDepositMoney) {
    bankAccount -> deposit(100);
    EXPECT_EQ(100, bankAccount->balance);
}

TEST_F(BankAccountTest, BankAccountStartEmpty) {
    EXPECT_EQ(0, bankAccount->balance);
}

TEST_P(withdrawAccountTest, FinalBalance) {
    auto as = GetParam();
    auto success = bankAccount -> withdraw(as.withdraw_amount);
    EXPECT_EQ(as.final_balance, bankAccount->balance);
    EXPECT_EQ(as.success, success);
}


INSTANTIATE_TEST_CASE_P(Default, withdrawAccountTest,
                        testing::Values(
                                account_state{100,50,50,true}
                        ));