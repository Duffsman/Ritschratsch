




void setup()
{
  size(1024,1024);
}



float r = 512.0;

float offs = 0;
void draw() {
  background(0);
  noStroke();
  PVector center = new PVector(width/2, height/2);
  
  
  offs += 0.01;
  for (int i = 0; i < 256; i ++) {
    color c = Wheel(i);

    float start_angle = float(i)* (TWO_PI/256) + PI/6+ offs;
    float end_angle = float(i+2) * (TWO_PI/256)+ PI/6 +offs;

    float sx = r * cos(start_angle) +center.x;
    float sy = r * sin(start_angle)+center.y;

    float ex = r * cos(end_angle)+center.x;
    float ey = r * sin(end_angle)+center.y;

    fill(c);
    beginShape();
    vertex(center.x, center.y);
    vertex(sx, sy);
    vertex(ex, ey);
    vertex(center.x,center.y);
    endShape();
    //stroke(c);
    //line(i*2, 0, i*2, height);
  }
}


color Wheel(int WheelPos)
{
  WheelPos =(255 - WheelPos);
  if (WheelPos < 85)
  {
    return color((255 - WheelPos * 3), 0, (WheelPos * 3));
  }
  if (WheelPos < 170)
  {
    WheelPos -= 85;
    return color(0, (WheelPos * 3), (255 - WheelPos * 3));
  }
  WheelPos -= 170;
  return color((WheelPos * 3), (255 - WheelPos * 3), 0);
}
