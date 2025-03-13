Compiler = g++

Target   = Patcher

B		 = ../build/
H        = ../headers/

Flags	 = 	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio \
		   	-D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

Valgrind_flags = --leak-check=full --track-origins=yes --show-reachable=yes
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

$(Target): 		$(B)MainPatcher.o $(B)CtorPatcher.o $(B)DrawPatcher.o $(B)DtorPatcher.o $(B)HackingPatcher.o $(B)LogicPatcher.o
	$(Compiler) $(B)MainPatcher.o $(B)CtorPatcher.o $(B)DrawPatcher.o $(B)DtorPatcher.o $(B)HackingPatcher.o $(B)LogicPatcher.o -o $(B)Patcher.out $(Flags)
#----------------------------------------------------------------------------------

$(B)MainPatcher.o :	MainPatcher.cpp			\
					$(H)CtorPatcher.h		\
					$(H)LogicPatcher.h		\
					$(H)DrawPatcher.h		\
					$(H)DtorPatcher.h
					
	$(Compiler) -c MainPatcher.cpp -o $(B)MainPatcher.o
#----------------------------------------------------------------------------------

$(B)CtorPatcher.o :	CtorPatcher.cpp	  		\
					$(H)CtorPatcher.h		\
					$(H)ConstsPatcher.h		
					
	$(Compiler) -c CtorPatcher.cpp -o $(B)CtorPatcher.o
#----------------------------------------------------------------------------------

$(B)DrawPatcher.o :	DrawPatcher.cpp	  		\
					$(H)DrawPatcher.h		\
					$(H)ConstsPatcher.h		\
					$(H)CtorPatcher.h		\
					$(H)HackingPatcher.h
					
	$(Compiler) -c DrawPatcher.cpp -o $(B)DrawPatcher.o
#----------------------------------------------------------------------------------

$(B)DtorPatcher.o :	DtorPatcher.cpp	  		\
					$(H)DtorPatcher.h
					
	$(Compiler) -c DtorPatcher.cpp -o $(B)DtorPatcher.o
#----------------------------------------------------------------------------------

$(B)HackingPatcher.o : HackingPatcher.cpp	\
					   $(H)HackingPatcher.h \
					   $(H)ConstsPatcher.h
					
	$(Compiler) -c HackingPatcher.cpp -o $(B)HackingPatcher.o
#----------------------------------------------------------------------------------

$(B)LogicPatcher.o : LogicPatcher.cpp		\
					 $(H)LogicPatcher.h		\
					 $(H)ConstsPatcher.h
					
	$(Compiler) -c LogicPatcher.cpp -o $(B)LogicPatcher.o
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
clean:
	rm -f $(B)*.o  $(B)*.out
#----------------------------------------------------------------------------------
run: 
	$(B)Patcher.out
#----------------------------------------------------------------------------------
valg:
	valgrind $(Valgrind_flags) $(B)Patcher.out
#----------------------------------------------------------------------------------
