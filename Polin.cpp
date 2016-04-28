#include"matrix.hpp"

polinomio::polinomio()
{
	grade=0;
	coef= new float[1];
	coef[0]=0;
}

polinomio::~polinomio()
{
}

polinomio::polinomio(int g)
{
	g=abs(g);
	if(g>=0){
		grade=g;
		coef=new float[grade+1];
		for(int i=0;i<=grade;i++)
			coef[i]=0;
	}
}

polinomio derivada(polinomio& p_poli)
{
	polinomio out_poli(p_poli.grade-1);
	for(int i=0;i<=out_poli.grade;i++)
		out_poli.coef[i]=p_poli.coef[i+1]*(i+1);
	return out_poli;
}

ostream& operator<<(ostream& out, polinomio& p_poli){

    string aux=" +";
	for(int i=p_poli.grade;i>=0;i--){
		if(i>0){
		if(p_poli.coef[i-1]<0)
			aux=" ";
		else
			aux=" +";
		out<<p_poli.coef[i]<<"X^"<<i<<aux;
		}
		else
			
			out<<p_poli.coef[i];
	}
    return out;
}
void polinomio::set_grade(int g){
	g=abs(g);
	grade=g;
}

float polinomio::evaluar(float x){
	float out=0;
	for(int i=0;i<=grade;i++)
		out+=coef[i]*pow(x,i);
	return out;
}

istream& operator>>(istream& in,polinomio& p_poli)
{
	cout<<"introduce el grado del polinomio";
	cin>>p_poli.grade;
	p_poli.coef=new float[p_poli.grade+1];
	for(int i=p_poli.grade;i>=0;i--)
	{
		if(i==0)
		{
			cout<<"Introduzca el termino independiente:";
		}
		else
		{
			cout<<"Introduzca el coeficiente de X^"<<i<<":";
		}
		in>>p_poli.coef[i];
	}
	return in;
}