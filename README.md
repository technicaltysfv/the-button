# The Button
 
This button is a little arduino compatible board and a sanwa button in a box.

If you hold down the button whilst plugging it into a PC it also does a little party trick.

The rest of the time it pretends to be a keyboard and presses a single configurable key.

## Configuring the key press

To change which key it presses, you can connect to it over a serial connection using software like putty (Speed 9600) and type the key you want to change it to. If done correctly it should confirm over the serial link.

![putty](https://github.com/user-attachments/assets/ba2d74cd-4c94-4f99-9658-73f7883c4395)


To figure out which port is the correct one, open the device manager and open the section on ports, and it should be there with the name "Arduino Leonardo".

![com port](https://github.com/user-attachments/assets/7ef1c558-dc45-4868-ad4f-74ba2a746098)

The change is saved in the EEPROM, so maybe don't change it 100,000 times just for fun or you might run out of writes.

## Programming

You can also reprogram it to do whatever you like using the Arduino IDE.

Download the source files, and open the-button.ino in the IDE, select the "Leonardo" in the "boards" dropdown, and hit "upload".

It should be pretty easy to get it to show up as a game controller, or type a macro when you hit a button, or anything else you can think of. My time to add stupid unnecessary features was unfortunately cut tragically short so you may have to pick up the torch.


