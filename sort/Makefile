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

MER=ExMergeSort
MER_SRC=MergeSort.cpp

HEA=ExHeapSort
HEA_SRC=HeapSort.cpp

.PHONY:all
all:$(INS) $(BUB) $(SHE) $(MER) $(HEA)

.PHONY:hea
hea:$(HEA)
$(HEA):$(HEA_SRC)
	g++ -o $@ $^

.PHONY:ins
ins:$(INS)
$(INS):$(INS_SRC)
	g++ -o $@ $^
	
.PHONY:bub
bub:$(BUB)
$(BUB):$(BUB_SRC)
	g++ -o $@ $^

.PHONY:qui
qui:$(QUI)
$(QUI):$(QUI_SRC)
	g++ -o $@ $^

.PHONY:she
she:$(SHE)
$(SHE):$(SHE_SRC)
	g++ -o $@ $^
	
.PHONY:mer
mer:$(MER)
$(MER):$(MER_SRC)
	g++ -o $@ $^	
.PHONY:clean
clean:
	rm -rf Ex*
