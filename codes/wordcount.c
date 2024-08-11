#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
	
	char c;
	int wc, nl, nc;
	wc = nl = nc = 0;
	int state = OUT;
	while((c = getchar()) != EOF) {
		if(c == '\n') {
			++nl;
		}
		if(c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
		}
		else if(state == OUT) {
			state = IN;
			++wc;
		}
		++nc;
	}

	printf("%d\t%d\t%d ", wc, nl, nc);
	return 0;
}
