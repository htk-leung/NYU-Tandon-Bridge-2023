#include <iostream>
#include <string>
using namespace std;


/////////////////////////  Money Class & Functions  ///////////////////////

class Money{
private:
    double total;
public:
//constructors
    Money(double dollars) {total = dollars;}
    Money( ) {total = 0.0;}
//mutators 
    void set_value(double d) {total = d;}
//accessors
    double get_value( ) const;
//overloading operators
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount);
    friend istream& operator >>(istream& ins, Money& moneytemp);
    friend ostream& operator <<(ostream& outs, Money& moneytemp);
};

double Money::get_value() const{
    return total;
}

ostream& operator <<(ostream& outs, Money& moneytemp){
    outs << moneytemp.total;
    return outs;
}

istream& operator >>(istream& ins, Money& moneytemp){
    ins >> moneytemp.total;
    return ins;
}

Money operator +(const Money& amount1, const Money& amount2){
    Money temp;
    temp.total = amount1.total + amount2.total;
    return temp;
}

Money operator -(const Money& amount1, const Money& amount2){
    Money temp;
    temp.total = amount1.total - amount2.total;
    return temp;
}

Money operator -(const Money& amount){
    Money temp;
    temp.total = -amount.total;
    return temp;
}

Money* enter_deposits(int& deposit_count){
    cout << "\nStep 2: record deposits.\n"
        << "Please enter the number of number you have made since the previous balance: \n";
    cin >> deposit_count;
    Money* deposit_arr = new Money [deposit_count];

    cout << "\nThen enter the amount of each deposit one by one, each on a new line:\n";
    for (int i = 0; i < deposit_count; i++){
        cin >> deposit_arr[i];
    }
    
    return deposit_arr;
}

Money deposits_total(Money* deposit_arr, int deposit_count){
    Money total;
    for (int i = 0; i < deposit_count; i++)
        total = total + deposit_arr[i];

    return total;
}


///////////////////////  Check Class & Functions  /////////////////////////


class Check{
private:
    int number;
    Money amount;
    bool cashed;
public:
// constructors
    Check(int n, double a, bool c);
    Check();
// mutators
    void setNumber(int input) {number = input;}
    void setAmount(double input) {amount.set_value(input);}
    void setCashed(bool input) {number = input;}
// accessors
    int getNumber() const {return number;}
    double getAmount() const {return amount.get_value();}
    bool getCashed() const {return cashed;}
// other
    friend void print_check_lists(Check* check_arr, int check_count);
    friend void sort_check_num(Check* check_arr, int check_count);
    friend istream& operator >>(istream& ins, Check& checktemp); 
};


Check::Check(int n, double a, bool c){
    number = n;
    amount.set_value(a);
    cashed = c;
}

Check::Check(){
    number = 0;
    amount = Money(0);
    cashed = 0;    
}

istream& operator >>(istream& ins, Check& checktemp){
    ins >> checktemp.number >> checktemp.amount >> checktemp.cashed;
    return ins;
}

Check* enter_checks(int& check_count) {

    cout << "Step 1: record checks written. \n"
        << "Please enter the number of check you need to record: \n";
    cin >> check_count;
    cout << endl;
    Check* check_arr = new Check [check_count];

    cout << "Please then enter check number, check amount, and whether it has been cashed.\n"
        << "1 for cashed, 0 for not cashed."
        << "For check number 10, amount 25.52, not cashed, input would be :\n"
        << "10 25.52 0 \n\n";
    string line;
    for (int i = 0; i < check_count; i++)
        cin >> check_arr[i];

    return check_arr;
}

Money check_cashed_total(Check* check_arr, int check_count){
    Money total = 0;
    for (size_t i = 0; i < check_count; i++) 
        if(check_arr[i].getCashed())
            total = total + check_arr[i].getAmount();
    
    return total;
}

void sort_check_num(Check* check_arr, int check_count){
    int count = check_count;
    while(check_count > 0){    
    // find max check num
        int max_num_ind = 0;
        int max_num = check_arr[0].number;
        int i;
        for (i = 0; i < check_count; i++){   
            if(check_arr[i].number > max_num){
                max_num = check_arr[i].number;
                max_num_ind = i;
            }
        }
    // swap max to end
        Check temp = check_arr[check_count - 1];
        check_arr[check_count - 1] = check_arr[max_num_ind];
        check_arr[max_num_ind] = temp;

        check_count--;
    }
}

void print_check_lists(Check* check_arr, int check_count){
    sort_check_num(check_arr, check_count);

    cout << "Checks cashed:\n"
        << "Number\tAmount\n";
    for (int i = 0; i < check_count; i++)
        if(check_arr[i].cashed)
            cout << check_arr[i].number << '\t' << check_arr[i].amount << endl;
    
    cout << "\nChecks not cashed:\n"
        << "Number\tAmount \n";
    for (int i = 0; i < check_count; i++)
        if(!check_arr[i].cashed)
            cout << check_arr[i].number << '\t' << check_arr[i].amount << endl;
}


///////////////////////////////  MAIN  ////////////////////////////////////


int main(){
    cout << "\n--- Check Balancing Program ---\n\n";

// user input for checks
    int check_count;
    Check* check_arr = enter_checks(check_count);
    Money cashed_check_total = check_cashed_total(check_arr, check_count);
    
// user input for deposits
    int deposit_count;
    Money* deposit_arr = enter_deposits(deposit_count);
    Money deposit_total = deposits_total(deposit_arr, deposit_count);

// get balance from use input
    Money old_balance;
    cout << "\nStep 3: Please enter your old balance: \n";
    cin >> old_balance;

// get bank's new balance
    Money new_bank_balance;
    cout << "\nStep 4: Please enter the new balance as printed on your bank statement: \n";
    cin >> new_bank_balance;

// calculate balance
    Money new_holder_balance;
    new_holder_balance = old_balance + deposit_total - cashed_check_total;

// difference between your balance and the bank's
    Money balance_difference;
    balance_difference = new_holder_balance - new_bank_balance;

    cout << "\n----------- Results ------------\n\n";
// 1. total checks cashed
    cout << "Total of checks cashed: \n" << cashed_check_total << endl;  
// 2. total of the deposit         
    cout << "Total of deposits: \n" << deposit_total << endl;        
// 3. new balance
    cout << "Your new balance is: \n" << new_holder_balance << endl;
// 4. how much this figure differs from what the bank says the new balance is
    cout << "Difference between your balance and the bank's\n"          
        << "(your balance) - (bank's balance): \n"
        << balance_difference << endl;
// 5. 2 lists of checks:
    print_check_lists(check_arr, check_count);

    cout << "\n--------------------------------\n\n";

    delete []check_arr;
    delete []deposit_arr;

    return 0;
}