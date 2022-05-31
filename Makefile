exemple1 : exemple1.c
	c99 exemple1.c -o exemple1  `mysql_config --cflags --libs`

exemple2 : exemple2.c
	c99 exemple2.c -o exemple2  `mysql_config --cflags --libs`

metiers_modele_test : metiers_modele_test.c metiers_modele.c metiers_modele.h database.c database.h database_config.h
	c99 metiers_modele_test.c database.c metiers_modele.c -o metiers_modele_test  `mysql_config --cflags --libs`
	./metiers_modele_test

clean :
	rm exemple1
	rm exemple2
	rm metiers_modele_test
