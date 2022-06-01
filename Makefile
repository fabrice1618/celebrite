CC=c99
CFLAGS=-W
LDFLAGS=
EXEC=celeb_images_modele_test celeb_pays_modele_test metiers_modele_test celeb_metiers_modele_test celebrites_modele_test pays_modele_test
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
HEADER= $(SRC:.c=.h)
LIB=database.o

all: $(EXEC)

celeb_images_modele_test: celeb_images_modele_test.o celeb_images_modele.o $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS) `mysql_config --libs`

celeb_pays_modele_test: celeb_pays_modele_test.o celeb_pays_modele.o $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS) `mysql_config --libs`

metiers_modele_test: metiers_modele_test.o metiers_modele.o $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS) `mysql_config --libs`

celeb_metiers_modele_test: celeb_metiers_modele_test.o celeb_metiers_modele.o $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS) `mysql_config --libs`

celebrites_modele_test: celebrites_modele_test.o celebrites_modele.o $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS) `mysql_config --libs`

pays_modele_test: pays_modele_test.o pays_modele.o $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS) `mysql_config --libs`

exemple1: exemple1.o $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS) `mysql_config --libs`

exemple2: exemple2.o $(LIB)
	$(CC) -o $@ $^ $(LDFLAGS) `mysql_config --libs`

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) `mysql_config --cflags`

%.o: %.h
	$(CC) -o $@ -c $< $(CFLAGS) `mysql_config --cflags`

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
