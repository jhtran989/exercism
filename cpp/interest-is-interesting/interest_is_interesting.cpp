// interest_rate returns the interest rate for the provided balance.
double interest_rate(double balance) {
    // TODO: Implement the interest_rate function
    if (balance < 0) {
        return 3.213;
    } else if (balance < 1000) {
        return 0.5;
    } else if (balance < 5000) {
        return 1.621;
    } else {
        return 2.475;
    }
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(double balance) {
    // TODO: Implement the yearly_interest function
    return balance * (0.01 * interest_rate(balance));
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(double balance) {
    // TODO: Implement the annual_balance_update function
    return balance + yearly_interest(balance);
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance) {
    // TODO: Implement the years_until_desired_balance function
    double intermediate_balance = balance;
    int num_years = 0;
    while (intermediate_balance < target_balance) {
        intermediate_balance = annual_balance_update(intermediate_balance);
        num_years++;
    }

    return num_years;
}