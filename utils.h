#ifndef PROJECT1_UTILS_H
#define PROJECT1_UTILS_H

#include <iostream>
#include <vector>

using namespace std;

class Informacao;
class Funcionario;

vector<string> split(string str, string delimiter);

class GPS{
    float latitude,
          longitude;
public:
    GPS()
    {
        latitude = 0;
        longitude = 0;
    }
    GPS(float lat, float longi)
    {
        if(lat > 90 || lat < -90)
        {
            throw runtime_error("Latitude must be between -90 and 90 degrees");
        }
        if(longi > 180 || longi < -180)
        {
            throw runtime_error("Latitude must be between -90 and 90 degrees");
        }
        this->latitude = lat;
        this->longitude = longi;
    }
    float getLatitude() const {
        return latitude;
    }

    void setLatitude(float latitude) {
        if(latitude > 90 || latitude < -90)
        {
            throw runtime_error("Latitude must be between -90 and 90 degrees");
        }
        GPS::latitude = latitude;
    }

    float getLongitude() const {
        return longitude;
    }

    void setLongitude(float longitude) {
        if(longitude > 180 || longitude < -180)
        {
            throw runtime_error("Latitude must be between -90 and 90 degrees");
        }
        GPS::longitude = longitude;
    }

    friend ostream& operator<<(ostream& os, const GPS& gps){
        os << "(" << gps.latitude << ", " << gps.longitude << ")";
        return os;
    }
};

class Data{
    int dia,
        mes,
        ano;
public:
    Data()
    {
        dia = 1;
        mes = 1;
        ano = 1970;
    }

    Data(int d, int m, int a)
    {
        if(d > 31 || d < 1)
        {
            throw runtime_error("Day must be between 1 and 31");
        }
        if(m > 12 || d < 1)
        {
            throw runtime_error("Month must be between 1 and 12");
        }
        dia = d;
        mes = m;
        ano = a;
    }

    int getDia() const {
        return dia;
    }

    void setDia(int dia) {
        if(dia > 31)
        {
            throw runtime_error("Day must be between 1 and 31");
        }
        Data::dia = dia;
    }

    int getMes() const {
        return mes;
    }

    void setMes(int mes) {
        if(mes > 12)
        {
            throw runtime_error("Month must be between 1 and 12");
        }
        Data::mes = mes;
    }

    int getAno() const {
        return ano;
    }

    void setAno(int ano) {
        Data::ano = ano;
    }

    friend ostream& operator<<(ostream& os, const Data& dt)
    {
        os << dt.dia << "/" << dt.mes << "/" << dt.ano;
        return os;
    }
};

class Hora{
    int hora,
        minuto,
        segundo;
public:
    Hora()
    {
        hora = 0;
        minuto = 0;
        segundo = 0;
    }
    Hora(int h, int m, int s)
    {
        if(h > 24 || h < 0)
        {
            throw runtime_error("Hour must be between 0 and 24");
        }
        if(m > 59 || m < 0)
        {
            throw runtime_error("Minutes must be between 0 and 59");
        }
        if(s > 59 || s < 0)
        {
            throw runtime_error("Seconds must be between 0 and 59");
        }

    }
    int getHora() const {
        return hora;
    }

    void setHora(int hora) {
        Hora::hora = hora;
    }

    int getMinuto() const {
        return minuto;
    }

    void setMinuto(int minuto) {
        Hora::minuto = minuto;
    }

    int getSegundo() const {
        return segundo;
    }

    void setSegundo(int segundo) {
        Hora::segundo = segundo;
    }

    friend ostream& operator<<(ostream& os, const Hora& hr)
    {
        os << hr.hora << ":" << hr.minuto << ":" << hr.segundo;
        return os;
    }
};

class Localizacao{
    string pais;
    string cidade;
    GPS cordenadas;
public:
    Localizacao()= default;

    Localizacao(string pais, string cidade, GPS coord)
    {
        cordenadas = coord;
        this->pais = pais;
        this->cidade = cidade;
    }

    const string &getPais() const {
        return pais;
    }

    void setPais(const string &pais) {
        Localizacao::pais = pais;
    }

    const string &getCidade() const {
        return cidade;
    }

    void setCidade(const string &cidade) {
        Localizacao::cidade = cidade;
    }

    const GPS &getCordenadas() const {
        return cordenadas;
    }

    void setCordenadas(const GPS &cordenadas) {
        Localizacao::cordenadas = cordenadas;
    }

    friend ostream& operator<<(ostream& os, const Localizacao& l)
    {
        os << l.cidade << ", " << l.pais <<  l.cordenadas;
        return os;
    }

};

class Voo{
    Data data;
    Hora hora;
    string destino;
    Informacao* info;
public:
    Voo(Data D, Hora h, string d, Informacao* i)
    {
        data = D;
        hora = h;
        destino = d;
        info = i;
    }

    const Data &getData() const {
        return data;
    }

    void setData(const Data &data) {
        Voo::data = data;
    }

    const Hora &getHora() const {
        return hora;
    }

    void setHora(const Hora &hora) {
        Voo::hora = hora;
    }

    const string &getDestino() const {
        return destino;
    }

    void setDestino(const string &destino) {
        Voo::destino = destino;
    }

    Informacao *getInfo() const {
        return info;
    }

    void setInfo(Informacao *info) {
        Voo::info = info;
    }

    friend ostream& operator<<(ostream& os, const Voo& v)
    {
        os << "Destino: " << v.destino << endl;
        os << "Dia: " << v.hora << endl;
        os << v.hora << "horas" << endl;
        return os;
    }
};

class Informacao{
    Voo* voo;
    Hora hora_prevista;
    Hora hora_real;
    bool cancelado;
public:
    Informacao(Voo* v, Hora hp, Hora hr)
    {
        voo = v;
        hora_prevista = hp;
        hora_real = hr;
    }

    Voo *getVoo() const {
        return voo;
    }

    void setVoo(Voo *voo) {
        Informacao::voo = voo;
    }

    const Hora &getHoraPrevista() const {
        return hora_prevista;
    }

    void setHoraPrevista(const Hora &horaPrevista) {
        hora_prevista = horaPrevista;
    }

    const Hora &getHoraReal() const {
        return hora_real;
    }

    void setHoraReal(const Hora &horaReal) {
        hora_real = horaReal;
    }

    bool isCancelado() const {
        return cancelado;
    }

    void setCancelado(bool cancelado) {
        Informacao::cancelado = cancelado;
    }

    friend ostream& operator<<(ostream& os, const Informacao& i)
    {
        os << "Voo:" << endl;
        os << *i.voo << endl;
        os << "Horario previsto: " << i.hora_prevista << endl;
        os << "Horario real: " << i.hora_real << endl;
        os << (i.cancelado ? "Cancelado" : "A tempo") << endl;
        return os;
    }

};

class Aviao{
    string tipo;
    int capacidade;
    //Escalonamento
    vector<Voo*> voos;
    vector<Funcionario*> tripulacao; //2 pilotos e 2 membros de cabine, talvez valha mais criar a classe tripulacao
    int custo_operacao;
public:
    Aviao(string tipo, int capacidade, vector<Voo*> voos, Funcionario* piloto1, Funcionario* piloto2,Funcionario* membro_cabine1,Funcionario* membro_cabine2, int custo_operacao)
    {
        tripulacao.push_back(piloto1);
        tripulacao.push_back(piloto2);
        tripulacao.push_back(membro_cabine1);
        tripulacao.push_back(membro_cabine2);
        this->tipo = tipo;
        this->capacidade = capacidade;
        this->voos = voos;
        this->tripulacao = tripulacao;
        this->custo_operacao = custo_operacao;
    }

    Aviao(string tipo, int capacidade, vector<Voo*> voos, Funcionario* piloto1, Funcionario* piloto2,Funcionario* membro_cabine1,Funcionario* membro_cabine2,vector<Funcionario*> mais_tripulacao, int custo_operacao)
    {
        tripulacao.push_back(piloto1);
        tripulacao.push_back(piloto2);
        tripulacao.push_back(membro_cabine1);
        tripulacao.push_back(membro_cabine2);
        tripulacao.insert(tripulacao.end(),mais_tripulacao.begin(),mais_tripulacao.end());
        this->tipo = tipo;
        this->capacidade = capacidade;
        this->voos = voos;
        this->tripulacao = tripulacao;
        this->custo_operacao = custo_operacao;
    }

    void adicionarTripulacao(Funcionario* funcionario)
    {
        tripulacao.push_back(funcionario);
    }

    void adicionarVoo(Voo* voo)
    {
        voos.push_back(voo);
    }

    void removerTripulacao(Funcionario* funcionario)
    {
        for(int i = 0; i < tripulacao.size(); i++)
        {
            if(tripulacao.at(i) == funcionario)
            {
                tripulacao.erase(tripulacao.begin()+i);
                break;
            }
        }
    }

    void removerVoo(Voo* voo)
    {
        for(int i = 0; i < voos.size(); i++)
        {
            if(voos.at(i) == voo)
            {
                voos.erase(voos.begin()+i);
                break;
            }
        }
    }

    const string &getTipo() const {
        return tipo;
    }

    void setTipo(const string &tipo) {
        Aviao::tipo = tipo;
    }

    int getCapacidade() const {
        return capacidade;
    }

    void setCapacidade(int capacidade) {
        Aviao::capacidade = capacidade;
    }

    vector<Voo*> getVoos() const{
        return voos;
    }

    void setVoos(const vector<Voo*> voos) {
        Aviao::voos = voos;
    }

    int getCustoOperacao() const {
        return custo_operacao;
    }

    void setCustoOperacao(int custoOperacao) {
        custo_operacao = custoOperacao;
    }

    friend ostream& operator<<(ostream& os, const Aviao& a);
};

#endif //PROJECT1_UTILS_H
