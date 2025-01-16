#include <iostream>
#include <unistd.h> 
#include <vector>
#include <future>

int findSum(std::vector<int>& vec, int start, int end){
    int sum = 0;
    for (int i=start; i<end; i++){
        sum += vec[i];
    }
    return sum;
}

void client(int pipefd11, int pipefd20){                   // client will "write via pipe1" and "read via pipe2"
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int vectorSize = vec.size();

    std::cout << "Client: Sending individual values of the vector:" << std::endl;
    for (int i = 0; i < vectorSize; ++i)
    {
        std::cout << "Client: Sending value: " << vec[i] << std::endl;
        write(pipefd11, &vec[i], sizeof(vec[i]));
    }
    close(pipefd11); 

    // read the two sum values from the server and print them
    int sumFirstHalf, sumSecondHalf;
    read(pipefd20, &sumFirstHalf, sizeof(sumFirstHalf));
    read(pipefd20, &sumSecondHalf, sizeof(sumSecondHalf));
    close(pipefd20); 

    std::cout << "Client: Received sum from server" << std::endl;

    std::cout << "Client: Recieved sum if first half: " << sumFirstHalf << std::endl;
    std::cout << "Client: Recieved sum if second half: " << sumSecondHalf << std::endl;
}

void server(int pipefd10, int pipefd21){                    // server will "read via pipe1" and "write via pipe2"
    int value;

    std::vector<int> vec;

    while (read(pipefd10, &value, sizeof(value)) > 0)
    {
        std::cout << "Server: Received value: " << value << std::endl;
        vec.push_back(value);
    }
    close(pipefd10); 

    int vectorSize = vec.size();

    auto future1 = std::async(findSum, std::ref(vec), 0, (int)vectorSize/2);
    int sumFirstHalf = future1.get();

    auto future2 = std::async(findSum, std::ref(vec), (int)vectorSize/2, vectorSize);
    int sumSecondHalf = future2.get();

    write(pipefd21, &sumFirstHalf, sizeof(sumFirstHalf));
    write(pipefd21, &sumSecondHalf, sizeof(sumSecondHalf));
    close(pipefd21); 
}

int main()
{
    int pipefd1[2], pipefd2[2]; 
    pid_t pid;

    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1)
    {
        std::cout << "Error in pipe" << std::endl;
        return 1;
    }
    {
        pid = fork();

        if (pid < 0)
        {
            std::cout << "Error in fork" << std::endl;
            return 1;
        }

        if (pid == 0)
        {                      
            close(pipefd1[1]); 
            close(pipefd2[0]); 

            server(pipefd1[0], pipefd2[1]); // server will "read via pipe1" and "write via pipe2"
        }
        else
        {                    
            close(pipefd1[0]); 
            close(pipefd2[1]); 

            client(pipefd1[1], pipefd2[0]); // client will "write via pipe1" and "read via pipe2"
        }
    }
    return 0;
}
