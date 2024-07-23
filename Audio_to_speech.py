import speech_recognition as s
import serial


recognizer = s.Recognizer()
sr=serial.Serial("COM3",9600)

def capture_voice_input():
    with s.Microphone() as source:
        print("Listening...")
        audio = recognizer.listen(source)
    return audio
def convert_voice_to_text(audio):
    try:
        text = recognizer.recognize_google(audio)
        print("Here is your text    "
              ""+ text)
    except s.UnknownValueError:
        text = ""
        print("Sorry, I didn't understand")
    except s.RequestError as e:
        print("Error;{0}".format(e))
    return text
def process_voice_command(text):
    if "hello" in text.lower():
        print("Hello! How can I help you?")
    elif "goodbye" in text.lower():
        print("Goodbye! Have a great day!")
        return True
    else:
        print("I didn't understand that command. Please try again.")
    return False
def main():
    end_program = False
    while not end_program:
        audio = capture_voice_input()
        text = convert_voice_to_text(audio)
        ST = (text)
        sr.write(ST.encode())
        if text == "exit":
            print("exiting process")
            break

if __name__ == "__main__":
    main()