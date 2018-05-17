#include <cstdlib>
#include <ctime>
#include <iostream>

/** @todo Inclure les fichiers de définition du problème */
#include "window.hxx" // appel Ocean.h =>
Ocean *ocean;
int mainwindow;

int main(int argc, char** argv) {
  /** @todo Initialiser des paramètres de simulation */
  int nx = 100; // multiple de 2 pour Philips
  int ny = 100; // multiple de 2 pour Philips
  double length = 500.0;
  double width = 500.0;

  /** @todo Initialiser du modèle*/
  if (argc <= 1 || argc > 2)
  {
    throw invalid_argument("./Main_Visualisation doit avoir un argument :"
                           " Gerstner ou Philips");
  }
  char model[10] = "";
  strcpy(model, argv[1]);
  // number of waves (just for GerstnerWave)
  int nbWaves = 1;
  // wind direction
  Dvector windDirection(2, 1);
  // average alignement number in [0, 1]
  double averageAlignment = 0.0;
  // change the speed of the wave (bigger jump for update in time)
  double intensite = 0.4;
  // height of the wave
  double hauteurVague = 6;
  // change the frenquency of the wave based on the amplitude
  double longueurOnde = hauteurVague;

  /** @todo Initialiser du champ de hauteur */
  double hauteur_initiale = 0.0;
  Height tmph(nx, ny, hauteur_initiale, length, width);

  /** @todo Initialiser de l'océan */
  Ocean tmpOcean(nx, ny, length, width, model, windDirection, averageAlignment,
                  intensite, longueurOnde, hauteurVague, tmph, nbWaves);
  /* extern ocean value used in windows.hxx */
  ocean = &tmpOcean;
  /* Initialisation de la fenêtre d'affichage */
  Window::init(WIDTH, HEIGHT, "Houle", argc, argv, "AZERTY", 50, 1);
  /* Execute la simulation */
  Window::launch();
  /* Libère la mémoire */
  Window::quit();
  delete ocean;

  return 0;
}
