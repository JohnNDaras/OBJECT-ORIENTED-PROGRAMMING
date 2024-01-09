#include "Potion.h"

Potion::Potion():Item(){
	statistic = "-";
	amount = 0;
}

Potion::Potion(string s, double p, int l, string st, double a):Item(s,p,l){
	statistic = st;
	amount = a;
}

void Potion::setStatistic(string stat){
	statistic = stat;
}
void Potion::setAmount(double a){
	amount = a;
}
string Potion::getStatistic(){
	return statistic;
}
double Potion::getAmount(){
	return amount;
}


