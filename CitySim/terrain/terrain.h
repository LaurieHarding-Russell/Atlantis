/*
Purpose: Holds all data to do with the terrain.
*/

#ifndef Terrain_h
#define Terrain_h

class Terrain {

public:
  Terrain();
  Terrain(int x, int y);
  void simulateRain();
  void setWaterMap();

  ~Terrain();

private:
  int sizeX;
  int sizeY;
  float** heightMap;
  float** waterHeightMap;
};

#endif
