bool isOddAge(int age){
        
    if ((age % 2) == 0){         
        return false;
    }
    return true;
}

bool isTeenage(int age){

    if ((age >= 13) && (age <= 19)){
        return true;
    }
    else{
        return false;
    }
}

int sumOfOddAge(int ages[], int size){
    int sum = 0;

    for(int i = 0; i < size; i++){
        if (isOddAge(ages[i])){
            sum = sum + ages[i];
        }
    }
    return sum;
}