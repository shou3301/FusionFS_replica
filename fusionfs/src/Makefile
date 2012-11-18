FUSEINC=-D_FILE_OFFSET_BITS=64 -I/home/cshou/bin/libfuse/include/fuse
FUSELIB=-pthread -L/home/cshou/bin/libfuse/lib64 -lfuse -lrt -ldl
GBUFLIB=-L/home/cshou/bin/gbuffer/lib64

fusionfs : fusionfs.o util.o log.o replica_util.o
	gcc -g -Wall -o fusionfs fusionfs.o util.o log.o replica_util.o -Lzht/lib -lzht -lstdc++ $(GBUFLIB) -lprotobuf -lpthread -Lffsnet -lffsnet_bridger ${FUSELIB}

fusionfs.o : fusionfs.c log.h params.h util.h replica_util.h
	gcc -g -Wall ${FUSEINC} -c fusionfs.c -L./ffsnet -lffsnet_bridger 
	
util.o : util.c log.h params.h
	gcc -g -Wall ${FUSEINC} -c util.c -L./zht/lib -lzht -lstdc++ -lprotobuf -lpthread	

replica_util.o : replica_util.c replica_util.h log.h
	gcc -g -Wall ${FUSEINC} -c replica_util.c

log.o : log.c log.h params.h
	gcc -g -Wall ${FUSEINC} -c log.c

clean:
	rm -f fusionfs *.o

dist:
	rm -rf fuse-tutorial/
	mkdir fuse-tutorial/
	cp ../*.html fuse-tutorial/
	mkdir fuse-tutorial/example/
	mkdir fuse-tutorial/example/mountdir/
	mkdir fuse-tutorial/example/rootdir/
	echo "a bogus file" > fuse-tutorial/example/rootdir/bogus.txt
	mkdir fuse-tutorial/src
	cp Makefile *.c *.h fuse-tutorial/src/
	tar cvzf ../../fuse-tutorial.tgz fuse-tutorial/
	rm -rf fuse-tutorial/
