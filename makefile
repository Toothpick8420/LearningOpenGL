CFLAGS = -std=c++17 -o2
LDFLAGS = -lglfw -lGL

WINFLAGS = -lgdi32 -lopengl32
GLFWINCLUDE = C:\Users\Kidfl\Libraries\glfw-3.4.bin.WIN64\include\GLFW
GLFWLIB = C:\Users\Kidfl\Libraries\glfw-3.4.bin.WIN64\lib-mingw-w64\libglfw3.a

windows: main.cpp 
	g++ $(CFLAGS)  -o app main.cpp -I $(GLFWINCLUDE) $(GLFWLIB) $(WINFLAGS)

windows_run: 
	./app.exe

linux: main.cpp
	g++ $(CFLAGS) -o app main.cpp $(LDFLAGS)

linux_run:
	./app

clean:
	rm app*
