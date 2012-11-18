#ifndef FUSION_FS_REPLICA
#define FUSION_FS_REPLICA

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Neighbor {
	
	char addr[128];

}Neighbor;

typedef struct NeighborList
{
	int numOfNeighbors;
	Neighbor *neighbor;

}NeighborList;

int replica_init();

char* generateNextAddr(const char *addr);

int removeNeighbor(char *addr);

int addNeighbor(char *addr);

int getNumOfReplicas();

#endif