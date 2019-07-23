CC=nvcc
CFLAGS=`pkg-config --libs --cflags opencv`

default: TMatching

TMatching: template_matching.cu
	$(CC) $(CFLAGS) -o TMatching template_matching.cu

clean:
	$(RM) TMatching *.o *~