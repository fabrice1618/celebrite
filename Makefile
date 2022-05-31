exemple1 : exemple1.c
	c99 exemple1.c -o exemple1  `mysql_config --cflags --libs`

exemple2 : exemple2.c
	c99 exemple2.c -o exemple2  `mysql_config --cflags --libs`

celebrites_modele_test : celebrites_modele_test.c celebrites_modele.c celebrites_modele.h database.c database.h database_config.h
	c99 celebrites_modele_test.c database.c celebrites_modele.c -o celebrites_modele_test  `mysql_config --cflags --libs`
	./celebrites_modele_test

clean :
	rm exemple1
	rm exemple2
