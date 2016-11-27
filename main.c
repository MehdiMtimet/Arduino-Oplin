int ledPin = 12;
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
  delay(5);
  pinMode(a, INPUT);
  pinMode(b, INPUT);
}

int c = true;

void loop() {
  // put your main code here, to run repeatedly:
  if(c){
    light(0,0);
    c = false;
  } else {
    light(0,1);
    c = true;
  }
}