#ifndef DT_FECHAHORA
#define DT_FECHAHORA

class DtFechaHora
{
  private:
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;

  public:
    DtFechaHora();
    DtFechaHora(int, int, int, int, int);
    int getd();
    int getmes();	
    int geta();
    int	geth();
    int getm();
};

#endif
