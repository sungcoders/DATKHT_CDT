import controlP5.*;
import processing.serial.*;
import static javax.swing.JOptionPane.*;

Serial port;
ControlP5 cp5;
PFont font;

boolean  send = false;
final boolean debug = true;
String   msg = "";
String   str = "";
String   mode_print = "";
String   home = "";
String   num_cycle = "";
int      check_cycle = 1;
int      error = 9999;

void setup()
{
  size(500, 500);
  printArray(Serial.list());
  PFont.list();
  check_port();
  //lets add buton to empty window
  cp5 = new ControlP5(this);
  font = createFont("calibri bold", 23);           // custom fonts for buttons and title

  cp5.addButton("UP")     //"red" is the name of button
    .setPosition(300, 130)  //x and y coordinates of upper left corner of button
    .setSize(80, 70)      //(width, height)
    .setFont(font)
    .setColorBackground(color(0, 0, 0))
    ;   

  cp5.addButton("DOWN")     //"yellow" is the name of button
    .setPosition(300, 270)  //x and y coordinates of upper left corner of button
    .setSize(80, 70)      //(width, height)
    .setFont(font)
    .setColorBackground(color(0, 0, 0))
    ;

  cp5.addButton("HOME")     //"blue" is the name of button
    .setPosition(200, 200)  //x and y coordinates of upper left corner of button
    .setSize(80, 70)      //(width, height)
    .setFont(font)
    .setColorBackground(color(0, 0, 0))
    ;

  cp5.addButton("MODE")     //"alloff" is the name of button
    .setPosition(400, 200)  //x and y coordinates of upper left corner of button
    .setSize(80, 70)      //(width, height)
    .setFont(font)
    .setColorBackground(color(0, 0, 0))
    ;
    
  cp5.addButton("MY_COM")     //"alloff" is the name of button
    .setPosition(400, 450)  //x and y coordinates of upper left corner of button
    .setSize(90, 40)      //(width, height)
    .setFont(font)
    .setColorBackground(color(0, 0, 0))
    ;
}

void draw()
{
  background(153, 217, 234);
  textFont(font);
  khung();
  read_serial();
  display();
}

void UP()
{
  port.write('u');
}

void DOWN()
{
  port.write('d');
}

void MODE()
{
  port.write('m');
}

void HOME()
{
  port.write('h');
}

void MY_COM()
{
  setup();
}

void read_serial()
{
    while (port.available()>0)
    {
      if(check_cycle==1){num_cycle="";}
      char val=(char)port.read();
      delay(10);
      switch(val)
      {
        case 'a': { mode_print = "nhanh"; }  break;
        case 'b': { mode_print = "vừa"; }  break;
        case 'c': { mode_print = "chậm"; }  break;
        case 'd': { mode_print = "từng bước"; }  break;
        case 'q': { home = "OK"; }  break;
        default : { num_cycle += val; }  break;
      }
      check_cycle+=1;
    }
    check_cycle=1;
}




void check_port()
{
  String  COMx, COMlist = "";
  try {
    if(debug) printArray(Serial.list());
    int i = Serial.list().length;
    if (i != 0) {
      if (i >= 2) {
        // need to check which port the inst uses -
        // for now we'll just let the user decide
        for (int j = 0; j < i;) {
          COMlist += char(j+'a') + " = " + Serial.list()[j];
          if (++j < i) COMlist += ",  ";
        }
        COMx = showInputDialog("Chọn COM bạn cần kết nối?\n ( Nhập a,b,c... để chọn):\n"+COMlist);
        if (COMx == null) exit();
        if (COMx.isEmpty()) exit();
        i = int(COMx.toLowerCase().charAt(0) - 'a') + 1;
        
      }
      String portName = Serial.list()[i-1];
      msg = "Đã Kết Nối: " + portName;
      if(debug) println(portName);
      port = new Serial(this, portName, 9600); // change baud rate to your liking
      port.bufferUntil('\n'); // buffer until CR/LF appears, but not required..
    }
    else {
      showMessageDialog(frame,"Không có COM nào được kết nối với PC");
      exit();
    }
  }
  catch (Exception e)
  { //Print the type of error
    showMessageDialog(frame,"COM port không tồn tại (có thể đang sử dụng ở chương trình khác)");
    println("Lỗi: ", e);
    exit();
  }
}

void display()
{
  fill(255, 0, 0);
  textFont(font, 30);
  text("BẢNG ĐIỀU KHIỂN", 235, 100);
  textFont(font, 23);
  fill(0, 0, 0);
  text(" XEM THÔNG TIN ",20,27);
  text(msg, 300, 30);                  // đã kết nối COM
  fill(0,0,255);
  text("Vòng quay: " + num_cycle ,10,60);
  text("Chế Độ: " + mode_print,10,90);
  text("SET HOME: " + home, 10,120);
  fill(255,255,255);
  text("SLOW", 400, 235);
  textFont(font, 18);
  fill(0);
  text("ĐỒ ÁN THIẾT KẾ HỆ THỐNG CƠ ĐIỆN TỬ", 30, 465);
  text("ĐẠI HỌC CẦN THƠ", 100, 485);
}

void khung()
{
// khung cho dieu khien
  beginShape();
  fill(0,255,128);
  vertex(190, 120);
  vertex(490, 120);
  vertex(490, 350);
  vertex(190, 350);
  endShape(CLOSE);
// khung cho thong tin
  beginShape();
  fill(255,255,255);
  vertex(5, 40);
  vertex(180, 40);
  vertex(180, 130);
  vertex(5, 130);
  endShape(CLOSE);
// khung cho tieu de thong tin
  beginShape();
  fill(160,170,172);
  vertex(5, 5);
  vertex(210, 5);
  vertex(210, 35);
  vertex(5, 35);
  endShape(CLOSE);
// khung cho tieu de cong COM
  beginShape();
  fill(224, 235, 233);
  vertex(290, 5);
  vertex(498, 5);
  vertex(498, 40);
  vertex(290, 40);
  endShape(CLOSE);
// khung cho dong cuoi cung
  beginShape();
  fill(128,200,255);
  vertex(5, 445);
  vertex(495, 445);
  vertex(495, 495);
  vertex(5, 495);
  endShape(CLOSE);
}
