#include "replica_util.h"

#define random(x) (rand()%x)

NeighborList *pNeighborList;

int replica_init() {
	int count = 0;
	FILE *frf = fopen ("neighbors.txt", "rt");
	char *line;
	while(fgets(line, 128, frf) != NULL)
	{
		count++;
	}
   	fclose(frf);

   	pNeighborList->numOfNeighbors = count;
   	pNeighborList->neighbor = (Neighbor *) malloc (count * sizeof(Neighbor));

   	FILE *frs = fopen ("neighbors.txt", "rt");
   	int i = 0;
	while(fgets(line, 128, frs) != NULL)
	{
		memcpy(pNeighborList->neighbor[i].addr, line, strlen(line));
		i++;
	}
   	fclose(frs);

   	return 0;
}

char* generateNextAddr(const char *addr) {
	int mod = pNeighborList->numOfNeighbors;
	char *replica_addr;

	if (pNeighborList->numOfNeighbors == 1) {
		strcpy(replica_addr, "NULL");
		return replica_addr;
	}

	do {
		replica_addr = pNeighborList->neighbor[random(mod)].addr;
	} while (strcmp(replica_addr, addr));

	return replica_addr;
}

int getNumOfReplicas() {
	return 1;
}

int removeNeighbor(char *addr) {
	return 0;
}

int addNeighbor(char *addr) {
	return 0;
}