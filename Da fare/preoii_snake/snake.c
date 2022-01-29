typedef struct
{
    int riga;
    int colonna;
} cella_t;

typedef enum
{
    SOPRA,
    SOTTO,
    DESTRA,
    SINISTRA
} direzione_t;

cella_t posizione_mela();

void muovi(direzione_t);

void gioca(int R, int C)
{
    cella_t mela = posizione_mela();
    while(1)
    {
        if(mela.riga > mela.colonna)
            muovi(DESTRA);
        else
            muovi(SOTTO);
    }
}
