int game[3][10][2] = {
  {
    {12, 9},
    {10, 12},
    {12, 7},
    {10, 11},
    {11, 8},
    {7, 11},
    {10, 8},
    {7, 10},
    {9, 7},
    {7, 8}
  }, {
    {11, 12},
    {12, 10},
    {8, 12},
    {11, 10},
    {9, 11},
    {11, 7},
    {9, 10},
    {10, 7},
    {9, 8},
    {8, 7}
  }, {
    {12, 11},
    {9, 12},
    {12, 8},
    {7, 12},
    {11, 9},
    {8, 11},
    {10, 9},
    {8, 10},
    {8, 9},
    {7, 9}
  }
};

void setup() {
  // put your setup code here, to run once:
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
}

void light(int i, int j){
  int a = game[i][j][0];
  int b = game[i][j][1];
  pinMode(a, OUTPUT);
  digitalWrite(a, HIGH);
  pinMode(b, OUTPUT);
  digitalWrite(b, LOW);
  delay(1);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
}

void lightProj(int i, int j){
  if(j >= 0 && j < 11 && i < 3){
    if(j < 10){
      light(i,j);
    } else {
      delay(1);
    }
    if(j > 0) {
      light(i,j - 1);
    } else {
      delay(1);
    }
  } else {
    delay(2);
  }
}

double nbCycles = 1.0;
int cycles = 60;
int cycle = 0;
int score = 0;
int speedUpPeriod = 6;
int cyclesCount = 0;

int projectiles[4][2] = {
  {2, 10}, 
  {0, 13},
  {1, 16},
  {0, 19}
};

void loop() {
  // put your main code here, to run repeatedly:
  for(int k = 0; k < 4; k++){
    if(projectiles[k][1] < 0){
      projectiles[k][0] = (int) random(3);
      projectiles[k][1] = 11;
    }
    lightProj(projectiles[k][0], projectiles[k][1]);
  }
  
  cycle++;
  if(cycle > (cycles - nbCycles)) {
    cycle = 0;
    score++;
    for(int k = 0; k < 4; k++){
      projectiles[k][1]++;
    }

    cyclesCount++;
    if(cyclesCount == speedUpPeriod){
      nbCycles = nbCycles * 1.4;
      cyclesCount = 0;
    }
  }

  if(nbCycles > (cycles - 10)) {nbCycles = 1.0;}//fix vitesse < 0
}
