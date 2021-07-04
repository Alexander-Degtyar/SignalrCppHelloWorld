# SignalrCppHelloWorld
## C++ SignalR client sample

Client for the [.Net server sample](https://github.com/seclerp/SignalrHelloWorld "seclerp/SignalrHelloWorld") using [aspnet/SignalR-Client-Cpp](https://github.com/aspnet/SignalR-Client-Cpp "aspnet/SignalR-Client-Cpp")

![image](https://user-images.githubusercontent.com/38611695/124386697-45678b00-dce4-11eb-98da-e620bbebbad9.png)

### Start server in Docker
1. Clone [seclerp/SignalrHelloWorld](https://github.com/seclerp/SignalrHelloWorld "seclerp/SignalrHelloWorld")
2. Open repo
3. Build Docker image: `docker build . --tag signalr-server:latest`
4. Start: `docker run -p 80:80 --name "SignalR_HelloWorld_Server" -d signalr-server`
5. Check status: `docker ps -a`

### Start client on Linux
1. Install [aspnet/SignalR-Client-Cpp](https://github.com/aspnet/SignalR-Client-Cpp "aspnet/SignalR-Client-Cpp") using vcpkg or build from source
2. Clone [Alexander-Degtyar/SignalrCppHelloWorld](https://github.com/Alexander-Degtyar/SignalrCppHelloWorld "Alexander-Degtyar/SignalrCppHelloWorld")
3. Open repo
4. Create build dir: `mkdir build && cd build`
5. Generate build: `cmake ..` (or `cmake -DCMAKE_TOOLCHAIN_FILE=<path to vcpkg.cmake>  ..` if the depencencies installed using vcpkg)
6. Build: `cmake --build .`
7. Start: `./SignalrCppHelloWorld`
