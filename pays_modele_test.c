// bastien

int pays_create( char *nom_pays)
{
    INSERT INTO 'pays' VALUES ('pays_id', 'nom_pays');
}

int pays_read(int pays_id, char *nom_pays)
{
    SELECT * FROM 'pays' WHERE 'country_code' = 'pays_id';
}

int pays_update(int pays_id, char *nom_pays)
{
    UPDATE 'pays' SET 'country_code' = 'pays_id', 'country_name' = 'nom_pays';
}

int pays_delete(int pays_id)
{
    DELETE FROM 'pays' WHERE 'pays_id' = '%s';
}

int pays_existe(int pays_id)
{
    SELECT * FROM 'pays' WHERE EXISTS (SELECT 'pays_id' FROM 'pays' WHERE 'pays_id' = 'country_code');
}