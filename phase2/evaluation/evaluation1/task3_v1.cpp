#include <iostream>
#include <unistd.h> 
#include <vector>

void client(int pipefd11, int pipefd20){                   // client will "write via pipe1" and "read via pipe2"
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int arraySize = arr.size();

    std::cout << "Client: Sending individual values of the vector:" << std::endl;
    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << "Client: Sending value: " << arr[i] << std::endl;
        write(pipefd11, &arr[i], sizeof(arr[i]));
    }
    close(pipefd11); 

    int sum;
    read(pipefd20, &sum, sizeof(sum));
    close(pipefd20); 

    std::cout << "Client: Received sum from server = " << sum << std::endl;
}

void server(int pipefd10, int pipefd21){                    // server will "read via pipe1" and "write via pipe2"
    int value, sum = 0;
    while (read(pipefd10, &value, sizeof(value)) > 0)
    {
        std::cout << "Server: Received value: " << value << std::endl;
        sum += value;
    }
    close(pipefd10); 

    std::cout << "Server: Calculated sum = " << sum << std::endl;

    write(pipefd21, &sum, sizeof(sum));
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
