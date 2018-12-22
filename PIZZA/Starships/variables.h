#include<iostream>

//constant for a server
double R, RS, RE; //radius of plane, ship and explosion
int commands, matches;

//depending on map

double accs,accr,angacc,maxstartvel,maxstartang; //max accelerations of ships,rockets,anglar acc of rocekts, max start velocity ang abng. acceleration of rockets
int points,launchcool,turns; //points for enemies, cooldown, no of turns

//my vars

bool active[100009];
int arena=1;
