metiers_modele_test : metiers_modele_test.c metiers_modele.c metiers_modele.h database.c database.h database_config.h
	c99 metiers_modele_test.c database.c metiers_modele.c -o metiers_modele_test  `mysql_config --cflags --libs`

clean :
	rm metiers_modele_test
