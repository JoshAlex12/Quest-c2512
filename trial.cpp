#include <iostream>
#include <unistd.h> // For pipe, fork, write, read

int main()
{
    int pipefd1[2], pipefd2[2]; // Two pipes: one for sending and one for receiving
    pid_t pid;

    // Create pipes
    if (pipe(pipefd1) == -1 || pipe(pipefd2) == -1)
    {
        perror("pipe");
        return 1;
    }

    // Fork the process
    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {                      // Child process (Server)
        close(pipefd1[1]); // Close write end of pipe1 (Client to Server)
        close(pipefd2[0]); // Close read end of pipe2 (Server to Client)

        // Read individual integers from the pipe and calculate the sum
        int value, sum = 0;
        while (read(pipefd1[0], &value, sizeof(value)) > 0) // Read until pipe is closed
        {
            std::cout << "Server: Received value: " << value << std::endl;
            sum += value;
        }
        close(pipefd1[0]); // Close read end of pipe1

        std::cout << "Server: Calculated sum = " << sum << std::endl;

        // Send sum back to client
        write(pipefd2[1], &sum, sizeof(sum));
        close(pipefd2[1]); // Close write end of pipe2
    }
    else
    {                      // Parent process (Client)
        close(pipefd1[0]); // Close read end of pipe1 (Client to Server)
        close(pipefd2[1]); // Close write end of pipe2 (Server to Client)

        // Define the array
        int arr[] = {1, 2, 3, 4, 5};
        int arraySize = sizeof(arr) / sizeof(arr[0]);

        // Send individual values to the server
        std::cout << "Client: Sending individual values of the array:" << std::endl;
        for (int i = 0; i < arraySize; ++i)
        {
            std::cout << "Client: Sending value: " << arr[i] << std::endl;
            write(pipefd1[1], &arr[i], sizeof(arr[i]));
        }
        close(pipefd1[1]); // Close write end of pipe1 to indicate end of data

        // Receive the sum from the server
        int sum;
        read(pipefd2[0], &sum, sizeof(sum));
        close(pipefd2[0]); // Close read end of pipe2

        std::cout << "Client: Received sum from server = " << sum << std::endl;

        // Wait for the child process to finish
        // wait(nullptr);
    }

    return 0;
}
