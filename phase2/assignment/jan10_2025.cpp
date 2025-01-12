// Quick sort | client server 

#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_CONNS 5

void server(int port);
void serveClient(int &);
void client(std::string server_ip, int port);
void requestServer(int &);
void quickSort(std::vector<double> &, int low, int high);
int partition(std::vector<double> &, int low, int high);

void server(int port)
{
    int server_socket_fd;
    // Create socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    sockaddr_in address;

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_socket_fd, (sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket_fd, MAX_CONNS) < 0)
    {
        perror("Listen failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    // Accept a connection
    int client_socket_fd;
    int addrlen = sizeof(address);
    if ((client_socket_fd = accept(server_socket_fd, (sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("Accept failed");
        close(server_socket_fd);
        exit(EXIT_FAILURE);
    }

    // Serve the client
    serveClient(client_socket_fd);

    // Close server socket
    close(server_socket_fd);
}

void serveClient(int &client_socket_fd)
{
    char buffer[BUFFER_SIZE];

    // Receive the size of the array
    read(client_socket_fd, buffer, BUFFER_SIZE);
    int size = atoi(buffer);

    // Receive the array
    std::vector<double> arr(size);
    for (int i = 0; i < size; ++i)
    {
        read(client_socket_fd, buffer, BUFFER_SIZE);
        arr[i] = atof(buffer);
    }

    // Sort the array
    quickSort(arr, 0, size - 1);

    // Send the sorted array back
    for (const auto &num : arr)
    {
        std::string numStr = std::to_string(num);
        strcpy(buffer, numStr.c_str());
        write(client_socket_fd, buffer, BUFFER_SIZE);
    }

    std::cout << "Array sorted and sent to client." << std::endl;

    // Close client socket
    close(client_socket_fd);
}

void client(std::string server_ip, int port)
{
    int client_socket_fd = 0;
    // Create socket
    if ((client_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Specify server address
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip.c_str(), &server_address.sin_addr) <= 0)
    {
        perror("Invalid address or address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(client_socket_fd, (sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Request the server
    requestServer(client_socket_fd);

    // Close client socket
    close(client_socket_fd);
}

void requestServer(int &client_socket_fd)
{
    char buffer[BUFFER_SIZE];

    // Input the array
    int size;
    std::cout << "Enter size of array: ";
    std::cin >> size;

    std::vector<double> arr(size);
    std::cout << "Enter elements of the array: \n";
    for (int i = 0; i < size; ++i)
    {
        std::cout << "index[" << i << "]: ";
        std::cin >> arr[i];
    }

    // Send the size of the array
    std::string sizeStr = std::to_string(size);
    strcpy(buffer, sizeStr.c_str());
    write(client_socket_fd, buffer, BUFFER_SIZE);

    // Send the array
    for (const auto &num : arr)
    {
        std::string numStr = std::to_string(num);
        strcpy(buffer, numStr.c_str());
        write(client_socket_fd, buffer, BUFFER_SIZE);
    }

    // Receive the sorted array
    std::cout << "Received from server\nSorted array : ";
    for (int i = 0; i < size; ++i)
    {
        read(client_socket_fd, buffer, BUFFER_SIZE);
        std::cout << atof(buffer) << " ";
    }
    std::cout << std::endl;
}

// -------------------------------------------------------------------

int partition(std::vector<double> &vec, int low, int high)
{

    int pivot = vec[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (vec[j] <= pivot)
        {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }

    std::swap(vec[i + 1], vec[high]);

    return (i + 1);
}

void quickSort(std::vector<double> &vec, int low, int high)
{
    if (low < high)
    {

        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}
// ---------------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        std::cout << "usage:\n\t./quickSortServerApp.out server 8080" << std::endl;
        std::cout << "\t./quickSortServerApp.out client 127.0.0.1 8080" << std::endl;
        return EXIT_FAILURE;
    }

    if (!(
            (strcmp(argv[1], "client") == 0 && argc == 4) ||
            (strcmp(argv[1], "server") == 0 && argc == 3)))
    {
        std::cout << "usage:\n\t./quickSortServerApp.out server 8080" << std::endl;
        std::cout << "\t./quickSortServerApp.out client 127.0.0.1 8080" << std::endl;
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "client") == 0)
    {
        std::cout << "Client [to server `" << argv[2] << ":" << argv[3] << "`]" << std::endl;
        client(argv[2], atoi(argv[3]));
    }
    if (strcmp(argv[1], "server") == 0)
    {
        std::cout << "Server [port:`" << argv[2] << "`]" << std::endl;
        server(atoi(argv[2]));
    }

    return EXIT_SUCCESS;
}