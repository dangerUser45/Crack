Compiler = g++
Target   = patcher
B		 = build/
Flags	 = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

$(Target): $(B)patcher.o 
	$(Compiler) $(B)patcher.o -o $(B)patcher.out $(Flags)

$(B)patcher.o :    patcher.cpp
	$(Compiler) -c patcher.cpp -o $(B)patcher.o

clean:
	rm build/*.o

run: 
	build/patcher.out
