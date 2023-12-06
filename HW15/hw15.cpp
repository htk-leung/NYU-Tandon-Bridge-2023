#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


class ListNode {
    string name;
    double paid;
    double should_pay;
    ListNode* prev;
    ListNode* next;
public:
    ListNode() : name(), paid(0.0), should_pay(0.0), 
        prev(nullptr), next(nullptr) {}
    ListNode(string new_name, double the_paid) 
        : name(new_name), paid(the_paid), should_pay(0.0), 
          prev(nullptr), next(nullptr) {}
    ~ListNode() {}
    friend class LList;
    
    double get_paid() {return paid;}
    double get_should_pay() {return should_pay;}
    string get_name() {return name;}
    ListNode* get_prev() {return prev;}
    ListNode* get_next() {return next;}
    void set_should_pay(double amount) {should_pay = amount;}
};


class LList {
    ListNode* head;
    int size;
public:
    LList();
    ~LList();
    ListNode* get_head() {return head;}
    int get_size() {return size;}

    bool is_empty();
    string pop_front();
    void delete_node(ListNode* del_node);
    void clear();
    void push_back(ListNode* new_node);
    double get_average();
    void update_should_pay(double average);
};

LList::LList() {
    head = new ListNode;                        
    head->next = nullptr;
    size = 0;
}

LList::~LList() {
    clear();
    delete head;
}

void LList::clear() {
    while(!is_empty()) 
        pop_front();
}

bool LList::is_empty() {
    return head->next == nullptr;
}

void LList::push_back(ListNode* new_node) {
    ListNode *temp = head;                                      // loop to last node of link
    while(temp->next != nullptr) 
        temp = temp->next;                      
    
    new_node->next = temp->next;                                // new node point to end
    new_node->prev = temp;
    temp->next = new_node;                                      // old node point to new node
    size++;                                                     // update size
}

string LList::pop_front() {
    ListNode* del = head->next;                                 // temp points to head->next
    string name = del->name;
    head->next = head->next->next;                              // head points to head->next->next
    size--;
    delete del;                                                 // delete node
    return name;
}

void LList::delete_node(ListNode* del_node) {
    ListNode* temp = del_node;
    del_node->prev->next = del_node->next;
    del_node->next->prev = del_node->prev;
    delete temp; 
    size--;
}

double LList::get_average() {
    double sum = 0;
    ListNode* temp = head;

    while(temp != nullptr) {
        sum += temp->paid;
        temp = temp->next;
    }
    double average = sum / size;
    average = round(average * 100) / 100;
    cout << "\nAverage payment: " 
        << average
        << endl << endl;
    return average;
}

void LList::update_should_pay(double average) {
    ListNode* temp = head->next;
    while(temp != nullptr) {                                    // go through whole list
        double diff = average - temp->paid;                     // average - paid
        if(diff != 0)                                           // if diff != 0
            temp->set_should_pay(diff);                         // set new should_pay
        temp = temp->next;                                      // adv ptr
    }
}

// function to open input file
void openInputFile(ifstream& inFile) {                             
    string file_name;                                           // ask for name
    cout << "\nPlease enter name of file "
        << "that contains payment record: ";
    cin >> file_name;
    
    inFile.open(file_name);                                     // open file
    while(!inFile) {                                            // keep trying while failing
        cout << "\nWrong file name."                            // report failure, ask for input again
            << "\nPlease provide name again: ";
        cin >> file_name;
        
        inFile.clear();                                         // clear flag in obj
        inFile.open(file_name);                                 // open again
    }
    cout << "Success!" << endl;
}

void InputFileToList(ifstream& inFile, LList* list) {
    string name;
    double paid;

    while(inFile >> paid) {
        inFile.ignore(1000, ' ');
        getline(inFile, name);

        ListNode* person = new ListNode(name, paid);
        list->push_back(person);
    }
}

void NodeDistributePayment(LList* list, ListNode* thisperson, double this_shd_pay) {
    ListNode* otherperson = list->get_head();            
    otherperson = otherperson->get_next();  

    while (this_shd_pay > 0.00001) {                            // while still owing money : should_pay > 0
        double other_shd_pay = otherperson->get_should_pay();

        if(other_shd_pay < 0) {                                 // if other person paid too much : should_pay < 0
            other_shd_pay = -(other_shd_pay);
            double settled = min(this_shd_pay, other_shd_pay);
            cout << thisperson->get_name()                      // cout how much to pay them
                << ", you should give "
                << otherperson->get_name()
                << " $"
                << settled
                << endl;

            this_shd_pay -= settled;                            // update balance
            otherperson->set_should_pay(settled - other_shd_pay);
        }

        otherperson = otherperson->get_next();                  // next person, adv ptr
    }
}

void ListDistributePayment(LList* list) {
    ListNode* listptr = list->get_head();                       // go through each person
    listptr = listptr->get_next();

    while(listptr != nullptr) {
        double should_pay = listptr->get_should_pay();

        if(should_pay == 0) {                                   // if should_pay == 0
            cout << listptr->get_name()                         // cout no need to do anything, move to next person
                << ", you don't need to do anything\n";
            ListNode* temp = listptr;
            listptr = listptr->get_next();
            list->delete_node(temp);                            // delete node 
        }  

        else if(should_pay < 0) {                               // if should_pay < 0
            cout << listptr->get_name()                         // cout no need to do anything, move to next person
                << ", you don't need to do anything\n";
            listptr = listptr->get_next();                      // adv ptr
        }                                
    
        else {                                                  // if should_pay > 0
            NodeDistributePayment(list, listptr, should_pay);   // distribute
            listptr = listptr->get_next();
        }
    }
}


int main() {
    ifstream inFile;                                            // open input file
    openInputFile(inFile);
    
    LList* list = new LList;                                    // create linked list - just the head
    InputFileToList(inFile, list);                              // read data into linked list
    inFile.close();                                             // close file
    
    double average = list->get_average();                       // calculate average
    list->update_should_pay(average);                           // set new should_pay
    ListDistributePayment(list);                                // calculate & output distribution
    cout << "\nThat should settle it!\n\n";

    delete list; 
    return 0;  
}