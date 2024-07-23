# Audio to text to arudino uno R4 led matrix
<p>This is a program in which python programming and arudno is combined together such that the audio is captured of a specific person by python using audio recognition library.The Google Web Speech API is used in this program which convert audio to text. The Google Web Speech API is a cloud-based speech recognition service provided by Google.After that the audio is processed and further sent to the arduino uno through a 
serial connection with the help of serial library.</p><br>
<br>
<p>
  Now when the audio in the text format is sent to the arudino uno it checks and stores the incoming data by "Serial.available()" and uses "ArduinoGraphics" and 
  "Arduino_LED_Matrix" libraries for displaying the received text onto it's display.
</p>
