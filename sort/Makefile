BUB=ExBubbleSort
BUB_SRC=BubbleSort.cpp

SEL=ExSelectsort
SEL_SRC=Selectsort.cpp

QUI=ExQuickSort
QUI_SRC=QuickSort.cpp

INS=ExInsertSort
INS_SRC=InsertSort.cpp

SHE=ExShellSort
SHE_SRC=ShellSort.cpp


.PHONY:all
all:$(INS) 

$(INS):$(INS_SRC)
	g++ -o $@ $^
	
$(BUB):$(BUB_SRC)
	g++ -o $@ $^

$(QUI):$(QUI_SRC)
	g++ -o $@ $^

$(SHE):$(SHE_SRC)
	g++ -o $@ $^
		
.PHONY:clean
clean:
	rm -rf Ex*
