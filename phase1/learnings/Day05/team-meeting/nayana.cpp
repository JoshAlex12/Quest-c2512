  // sumPrimeAge

    int sumPrimeAge(int [ages], int size){
        int sum = 0;

        for (i = 0; i < size-1; i++){
            if (isPrime(ages[i])){
                sum = sum + ages[i];
            }
        }
        return sum;
    }


// function minimumAge


    int minAge(int ages[], int size){
        int min = 0;

        for (int i = 0; i < (size-1); i++){
            if (ages[i] < min){
                min = ages[i];
            }
        }
        return min;  
    }
