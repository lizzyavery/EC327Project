GCC = g++

Connect_4: main.o Board.o Player.o AI_Player.o
	$(GCC) main.o Board.o Player.o AI_Player.o -o Connect_4

main.o: main.cpp
	$(GCC) -c main.cpp

Board.o: Board.cpp
	$(GCC) -c Board.cpp

Player.o: Player.cpp
	$(GCC) -c Player.cpp

AI_Player.o: AI_Player.cpp
	$(GCC) -c AI_Player.cpp

clean:
	rm main.o Board.o Player.o AI_Player.o Connect_4