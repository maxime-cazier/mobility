#pragma once
#include <limits>
#include <cmath>
#include <Imagine/Graphics.h>
#include <string>
#include <iostream>
using namespace std;

const double fps = 20.0;

const double tau=1;

const double A_repuls=150;

const double B_repuls=100;

void intersection(double coor[8], double & t, double& u);

double arg(double & x, double & y);

void modify(double coor[8], double a, double b, double c, double d, double e, double f, double g, double h);

double dist(double x1, double y1, double x2, double y2);

class Matrice{
    double* tab;
    int* compteur;
    int nb_lign;
    int nb_col;
public:
    Matrice();
    Matrice(int Nb_ligncol);
    Matrice(int Nb_lign, int Nb_col);
    Matrice(const Matrice& M);
    ~Matrice();

    int get_nb_lign() const;
    int get_nb_col() const;

    void change_tab(double* nouv_tab);
    void destroy();
    void print(string s);
    void operator=(Matrice& A);

    double& operator()(int i, int j);
    double operator()(int i, int j) const;

};

Matrice operator*(const Matrice& A,const Matrice& B);
