# webserver.cpp
No-dependency webserver implementation for Linux

**To get up & running**
with webserver.cpp, simply download the main.cpp and index.html file from this repo.
After that, 
```bash g++ main.cpp -O3 -o webserver && chmod +x webserver```
to compile it, and 
```bash ./webserver```
to start the server.

**To visit your local webpage**
simply open your favorite webbrowser and enter either 
```link
http://localhost:8080/
```
or, if you are on the same network as your server, replace localhost with your server's IP adress.
The result shall look something like this:

![image](https://github.com/user-attachments/assets/dab11cca-a20f-458f-a64e-0ba1a78663c5)
