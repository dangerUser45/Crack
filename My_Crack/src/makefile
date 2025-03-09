Compiler = g++
Target   = Patcher
B		 = ../build/
H        = ../headers/
Flags	 = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
#----------------------------------------------------------------------------------

$(Target): $(B)PatcherMain.o $(B)CtorAndDraw.o
	$(Compiler) $(B)PatcherMain.o $(B)CtorAndDraw.o -o $(B)Patcher.out $(Flags)
#----------------------------------------------------------------------------------

$(B)PatcherMain.o :	PatcherMain.cpp		\
					$(H)PatcherConsts.h		\
					$(H)Machine.h			\
					$(H)CtorAndDraw.h
	$(Compiler) -c PatcherMain.cpp -o $(B)PatcherMain.o
#----------------------------------------------------------------------------------

$(B)CtorAndDraw.o :	CtorAndDraw.cpp		\
					$(H)PatcherConsts.h		\
					$(H)CtorAndDraw.h
	$(Compiler) -c CtorAndDraw.cpp -o $(B)CtorAndDraw.o
#----------------------------------------------------------------------------------
clean:
	rm -f $(B)*.o  $(B)*.out
#----------------------------------------------------------------------------------
run: 
	../build/Patcher.out
#----------------------------------------------------------------------------------
