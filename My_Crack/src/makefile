Compiler = g++
Target   = Patcher
B		 = ../build/
H        = ../headers/
Flags	 = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
#----------------------------------------------------------------------------------

$(Target): $(B)PatcherMain.o $(B)CtorAndDraw.o $(B)Hacking.o $(B)Audio.o
	$(Compiler) $(B)PatcherMain.o $(B)CtorAndDraw.o $(B)Hacking.o $(B)Audio.o  -o $(B)Patcher.out $(Flags)
#----------------------------------------------------------------------------------

$(B)PatcherMain.o :	PatcherMain.cpp			\
					$(H)PatcherConsts.h		\
					$(H)Machine.h			\
					$(H)CtorAndDraw.h
	$(Compiler) -c PatcherMain.cpp -o $(B)PatcherMain.o
#----------------------------------------------------------------------------------

$(B)CtorAndDraw.o :	CtorAndDraw.cpp	  		\
					$(H)PatcherConsts.h		\
					$(H)CtorAndDraw.h
	$(Compiler) -c CtorAndDraw.cpp -o $(B)CtorAndDraw.o
#----------------------------------------------------------------------------------

$(B)Hacking.o : Hacking.cpp    		\
				$(H)PatcherConsts.h \
				$(H)Hacking.h 		
	$(Compiler) -c Hacking.cpp -o $(B)Hacking.o
#----------------------------------------------------------------------------------

$(B)Audio.o : 	Audio.cpp 			\
				$(H)PatcherConsts.h \
				$(H)Audio.h
	$(Compiler) -c Audio.cpp -o $(B)Audio.o
#----------------------------------------------------------------------------------

clean:
	rm -f $(B)*.o  $(B)*.out
#----------------------------------------------------------------------------------
run: 
	../build/Patcher.out
#----------------------------------------------------------------------------------
