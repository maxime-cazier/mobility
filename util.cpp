#include "util.h"
#include <string>
#include <iostream>
using namespace std;


void intersection(double coor[8], double & t, double & u){
    double det = coor[5]*coor[3] - coor[1]*coor[7];
    if(std::abs(det) < 1e-10){
        t = NAN; u = NAN;
    }
    else{
        t = (coor[5]*(coor[6] - coor[2]) + coor[7]*(coor[0] - coor[4]))/det;
        u = (coor[1]*(coor[6] - coor[2]) + coor[3]*(coor[0] - coor[4]))/det;
    }
}


double arg(double & x, double & y){
    if(x < 0 and y == 0) return 3.141592;
    else return -2*std::atan(y/(x+std::sqrt(x*x+y*y)));
}

void modify(double coor[8], double a, double b, double c, double d, double e, double f, double g, double h){
    coor[0] = a; coor[1] = b; coor[2] = c; coor[3] = d; coor[4] = e; coor[5] = f; coor[6] = g; coor[7] = h;
}

double dist(double x1, double y1, double x2, double y2){
    return std::sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}



Matrice::Matrice(){
    compteur=new int;
    *compteur=1;
    nb_lign = 3 ; nb_col = 3 ; tab = new double[nb_lign*nb_col];
}


Matrice::Matrice(int Nb_ligncol){
    compteur=new int;
    *compteur=1;
    nb_lign=Nb_ligncol ; nb_col=Nb_ligncol ; tab= new double[Nb_ligncol*Nb_ligncol];
}


Matrice::Matrice(int Nb_lign, int Nb_col){
    compteur=new int;
    *compteur=1;
    nb_lign = Nb_lign ; nb_col = Nb_col ; tab = new double[nb_lign*nb_col];
}


Matrice::Matrice(const Matrice& M){
    tab=M.tab;
    delete [] compteur;
    compteur=M.compteur;
    *compteur++;
}


double& Matrice::operator ()(int i, int j){
    assert (i<nb_lign && j<nb_col && i>=0 && j>=0);
    return tab[i*nb_col+j];
}

double Matrice::operator ()(int i, int j) const {
    assert (i<nb_lign && j<nb_col && i>=0 && j>=0);
    return tab[i*nb_col+j];
}


Matrice::~Matrice(){
    (*compteur)--;
    if ((*compteur)==0){
        delete [] tab;
        delete compteur; // pas delete [] sinon triangle d'avertissement...
    }
}



int Matrice::get_nb_lign() const{
    return nb_lign;
}

int Matrice::get_nb_col() const{
    return nb_col;
}


void Matrice::change_tab(double* nouv_tab){
    tab=nouv_tab;
}

void Matrice::destroy(){
    delete [] compteur;
}


void Matrice::print(string s){
    cout<< s<< " =" << endl;
    for (int i=0; i<nb_lign; i++){
        for (int j=0; j<nb_col; j++){
            cout << tab[i*nb_col+j]<< ' ';
        }
        cout<<endl;
    }
}

Matrice operator*(const Matrice& A,const Matrice& B){
    assert (A.get_nb_col()==B.get_nb_lign());
    cout<< 77<<endl;
    Matrice C(A.get_nb_lign(),B.get_nb_col());
    for (int i=0; i<C.get_nb_lign(); i++){
        for (int j=0; j<C.get_nb_col(); j++){
            C(i,j)=0;
            for (int k=0; k<A.get_nb_col(); k++){
                C(i,j)+=A(i,k)*B(k,j);
            }
        }
    }
    return C;
}


void Matrice::operator=(Matrice& A){
    delete [] tab;
    nb_lign=A.nb_lign;
    nb_col=A.nb_col;
    tab=A.tab;
    compteur=A.compteur;
}
