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
  for (int x = 0; x < sizeX; x++) {
    for (int y = 0; y < sizeY; y++) {
      heightMap[x][y] = 1;
      waterHeightMap[x][y] = 0; // No water
    }
  }
}

/*
A function that will calculate the movement of water.
Must be called continually.

Currently water will shift to lowest area... No waves.
Future: Take in a time input so the function may catchup.

*/
void Terrain::flowCalculation(float currentHeight, int currentX, int currentY, int tooX, int tooY) {
  float change = (currentHeight - heightMap[currentX][currentY] + waterHeightMap[tooX][tooY])/2;
  if (change < waterHeightMap[currentX][currentY]) {
    waterHeightMap[currentX][currentY] = waterHeightMap[currentX][currentY] - change;
    waterHeightMap[tooX][tooX] = waterHeightMap[tooX][tooY] + change;
  } else {
    waterHeightMap[currentX][currentY] = waterHeightMap[currentX][currentY] - waterHeightMap[currentX][currentY];
    waterHeightMap[tooX][tooY] = waterHeightMap[tooX][tooY] + waterHeightMap[currentX][currentY];
  }
}

void Terrain::calculateWaterFlow() {

  for (int x = 1; x < sizeX -1; x++) {
    for (int y = 1; y < sizeY -1; y++) {
      float currentHeight = heightMap[x][y] + waterHeightMap[x][y];
      if (currentHeight > heightMap[x-1][y-1] + waterHeightMap[x-1][y-1]) {
        flowCalculation(currentHeight, x, y, x-1, y-1);
      } else if (currentHeight > heightMap[x][y-1] + waterHeightMap[x][y-1]) {
        flowCalculation(currentHeight, x, y, x, y-1);
      } else if (currentHeight > heightMap[x+1][y-1] + waterHeightMap[x+1][y-1]) {
        flowCalculation(currentHeight, x, y, x+1, y-1);
      } else if (currentHeight > heightMap[x-1][y] + waterHeightMap[x-1][y]) {
        flowCalculation(currentHeight, x, y, x-1, y);
      } else if (currentHeight > heightMap[x+1][y] + waterHeightMap[x+1][y]) {
        flowCalculation(currentHeight, x, y, x+1, y);
      } else if (currentHeight > heightMap[x-1][y+1] + waterHeightMap[x-1][y+1]) {
        flowCalculation(currentHeight, x, y, x-1, y+1);
      } else if (currentHeight > heightMap[x][y+1] + waterHeightMap[x][y+1]) {
        flowCalculation(currentHeight, x, y, x, y+1);
      } else if (currentHeight > heightMap[x+1][y+1] + waterHeightMap[x+1][y+1]) {
        flowCalculation(currentHeight, x, y, x+1, y+1);
      }
    }
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
