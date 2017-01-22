#include "terrain.h"

Terrain::Terrain() {
  Terrain(500,500);
}

Terrain::Terrain(int x, int y) {
  sizeX = x;
  sizeY = y;
  heightMap = new float*[sizeX];
  waterHeightMap = new float*[sizeX];

  for(int i = 0; i < sizeX; i++) {
    heightMap[i] = new float[sizeY];
    waterHeightMap[i] = new float[sizeY];
  }
}

Terrain::~Terrain() {
  for(int i = 0; i < sizeX; i++) {
    delete heightMap[i];
    delete waterHeightMap[i];
  }
  delete heightMap;
  delete waterHeightMap;
}
