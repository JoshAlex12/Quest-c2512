int findSumOfTeenage(int ages[] , int size){
    int sumOfTeenage = 0;
    for(int i=0 ; i<size ; i++)
    {
        if(isTeenage(ages[i]))
        {
            sumOfTeenage = sumOfTeenage+ages[i];
        }
    }
    return sumOfTeenage;
}
