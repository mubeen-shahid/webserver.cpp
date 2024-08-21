# webserver.cpp
No-dependency webserver implementation for Linux

**Get up & running**
To get up and running with webserver.cpp, simply download the main.cpp and index.html file from this repo.
After that, 
```bash g++ main.cpp -O3 -o webserver && chmod +x webserver ```
to compile it, and 
```bash ./webserver ```
to start the server.

**To visit you local webpage**
simply open your favorite webbrowser and enter either 
```link
http://localhost:8080/
```
or, if you are on the same network as your server, replace localhost with your server's IP adress.
The result shall look something like this:
![image](https://github.com/user-attachments/assets/23526079-b6b8-4282-a68c-9797c879e36d)
