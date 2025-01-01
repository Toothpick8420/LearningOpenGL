CFLAGS = -std=c++17 -o2
LDFLAGS = -lglfw -lGL

build: main.cpp
	g++ $(CFLAGS) -o app main.cpp $(LDFLAGS)

.PHONY: test clean

run: build
	./app

clean:
	rm -f app
