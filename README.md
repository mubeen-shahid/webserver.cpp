# webserver.cpp
No-dependency webserver implementation for Linux

**Get up & running**
To get up and running with webserver.cpp, simply download the main.cpp and index.html file from this repo.
After that, 
```bash
g++ main.cpp -O3 -o webserver && chmod +x webserver
```
to compile it, and 
```bash ./webserver ```
to start the server.

**To visit you local webpage**
simply open your favorite webbrowser and enter either 
```link
http://localhost:8080/
```
or, if you want to view it on your network (the client and server have to be connected to the same network for this to work), replace localhost with your server's IP adress.
