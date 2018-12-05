import processing.serial.*;
import processing.sound.*;


Serial myPort;  
String serialData; 
ArrayList<Tone> tones = new ArrayList<Tone>();

void setup()
{ 
  tones.add(new Tone(new SoundFile(this, "sample.mp3"), "A"));
  tones.add(new Tone(new SoundFile(this, "sample.mp3"), "B"));
  
  // Match this to the arduino port
  String portName = "COM3"; 
  
  myPort = new Serial(this, portName, 9600);
}

void draw()
{
  if ( myPort.available() > 0) 
  {  
    serialData = myPort.readStringUntil('\n');   
  }
  
  if(serialData != null)
  {
    //println(serialData);
    for(Tone tone: tones){
      if(millis() > tone.file.duration() * 1000 + tone.startTime)
      {
        if(serialData.indexOf("O") != -1)
        {
          println("hoi");
          tone.file.play();
          tone.startTime = millis();
        } 
      }
    }
  }
}

public class Tone {
  public long startTime = -40000;  //TODO: set on minimum value of long    
  public SoundFile file;
  public String listen;
  
  public Tone (SoundFile file, String listen){
    this.file = file;
    this.listen = listen;
  }
}
