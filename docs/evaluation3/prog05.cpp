/*
// Coding Question: 1.1
    Employee {id, age, name} //id, age, name are value objects
    Employee e1(101,22,"Athira"),e2(102,23,"Bhagya");
    cout << e1 << endl; //101 22 Athira
    cout << e2 << endl; //102 23 Bhagya
    e1.swap(e2);
    cout << e1 << endl; //102 23 Bhagya
    cout << e2 << endl; //101 22 Athira
    //1.2 "id, age, name" as dynamic memory using new and delete
    //1.3 Programmer { string* tasks; int taskCount; } : Employee | tasks is the multiple tasks - array of task
        swap function overloadable
        here, create the dynamic programmer object assigned to employee pointer.
        field 'tasks' is dynamic memoery.
        operator << overloadable, swap is overridden.
    //1.4 replace dynamic fields as smart pointers
        prove that Employee virtual destructor is not needed.
        create the dynamic programmer object assigned to employee smart pointer
    //1.5 construct array of N programmers. read programmers from keyboard.
        cin >> var; // overload operator>> in employee and programmer
*/