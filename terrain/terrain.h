/*
Purpose: Holds all data to do with the terrain.
*/

#ifndef Terrain_h
#define Terrain_h

class Terrain {

public:
  Terrain();
  Terrain(int x, int y);

  void generateHeightMap();
  void simulateRain();

  /*
  Should be called continuasly in a loop.
  */
  void calculateWaterFlow();

  ~Terrain();

private:
  void flowCalculation(float currentHeight, int currentX, int currentY, int tooX, int tooY);

  int sizeX;
  int sizeY;
  float** heightMap;
  float** waterHeightMap;
};

#endif
