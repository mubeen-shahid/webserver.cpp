#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <fstream>

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        std::cerr << "Failed to create socket" << std::endl;
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY; // All IPs
    addr.sin_port = htons(8080); // Port

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
    {
        std::cerr << "Failed to bind socket" << std::endl;
        close(server_fd);
        return 1;
    }

    if (listen(server_fd, 3) == -1)
    {
        std::cerr << "Failed to listen on socket" << std::endl;
        close(server_fd);
        return 1;
    }

    std::cout << "Server listening on http://localhost:8080/" << std::endl;

    std::ifstream file("index.html");
    std::string file_content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    while (true)
    {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_fd == -1)
        {
            std::cerr << "Failed to accept connection" << std::endl;
            continue;
        }

        // Read the HTTP request
        char buffer[1024];
        ssize_t bytes_read = recv(client_fd, buffer, sizeof(buffer), 0);
        if (bytes_read == -1)
        {
            std::cerr << "Failed to read from client" << std::endl;
            close(client_fd);
            continue;
        }

        if (!file.is_open())
        {
            std::cerr << "Failed to open 'index.html'" << std::endl;
            send(client_fd, "HTTP/1.1 404 Not Found\r\n\r\n<h1>File not found</h1>", strlen("HTTP/1.1 404 Not Found\r\n\r\n<h1>File not found</h1>"), 0);
            close(client_fd);
            continue;
        }

        sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n%s", file_content.c_str());
        send(client_fd, buffer, strlen(buffer), 0);

        close(client_fd);
    }

    close(server_fd);

    return 0;
}
