#include <stdlib.h>
#include <nonlibc.h>
#include <binhex.h>
#include <ndebug.h>
#include <stdio.h>
#include "field.h"
#include "packet.h"

/*	init_pkts()
Initializes the ASCII expressed packets into binary blocks.
*/
void init_pkts(char *cpkts[], int npkts, struct pkt **pkts) {
	*pkts = malloc(sizeof(struct pkt) * npkts);

	for (int i = 0; i < npkts; i++) {
		uint16_t slen = strlen(cpkts[i]);

		NB_die_if(slen & 0x1, "odd number of chars in cpkts #%d", i);
		(*pkts)[i].len = slen/2;
		(*pkts)[i].data = malloc((*pkts)[i].len);
		for (int j = 0; j < slen; j+=2) {
			uint8_t c1, c2;
			hex_parse_nibble(&(cpkts[i][j]), &c1);
			hex_parse_nibble(&(cpkts[i][j+1]), &c2);
			uint8_t val = (c1 << 4) | c2;
			(*pkts)[i].data[j/2] = val;
		}
	}

die:
	return;
}

/*	free_pkts()
Initializes the ASCII expressed packets into binary blocks.
*/
void free_pkts(int npkts, struct pkt **pkts) {
	for (int i = 0; i < npkts; i++)
		if ((*pkts)[i].data != NULL) free((*pkts)[i].data);
	free(*pkts);
	pkts = NULL;

	return;
}
