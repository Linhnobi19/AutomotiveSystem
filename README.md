This project is simply simulate the screen IVI in car. It's just 4 apps include app home to control and open other apps.
1. App home view
This is Home's view 
![image](https://github.com/user-attachments/assets/5c762794-5caa-43a2-b448-1466a3af579d)
When the setting is not running, the time doesn't show, the language is set to default. It's swipeView contains 3 apps: music, video, setting
![image](https://github.com/user-attachments/assets/8b73cf33-e775-4ccb-961d-827c39178125)
When setting is running, all information from setting will be sent to other apps that register listener following observer design pattern. Each app running on seperate process so they can communicate through dbus connection
When press to other apps on home, it will hide home and open other app if this app is running, if this app is not running, the home is still visible.
![image](https://github.com/user-attachments/assets/594c9bfd-c584-4bc0-902f-f8ac01d020d2)
And each time the media is played, it will send data to app home. And the media player is playing will allow the scrolling text also.
2. App Setting view
![image](https://github.com/user-attachments/assets/66ea92b1-5cee-4445-9a1e-4fa600b58337)
This is Setting's view
It's the controller that control language, volume, date time on other app. Each time 4 of data changed, it will be sent to other app through dbus and be sent to all apps that register dbus.
![image](https://github.com/user-attachments/assets/c9452327-d058-4950-b16b-101e80297abb)
This is date time screen. If it not customize, User cannot flick or interact with 6 paths of time view.
![image](https://github.com/user-attachments/assets/9c7de498-3f8f-412e-b95b-e8c20c471de0)
If press customize, user can change the date time that want to change. And when press save the new time is set and store in QSettings, so the next time you running setting app, it will update base on this customize time
3. App music view
This is Music's view
![image](https://github.com/user-attachments/assets/b6ee5200-9edd-4744-a992-b2c7d9bcefb0)
This app is also using QSettings to store the last song, position was played.
4. App video view
This is Video's view
![image](https://github.com/user-attachments/assets/aa7d6156-72ab-4567-a0b4-4149b6a003b1)
All data on status bar was sent from setting apps


When app setting, music or video are closed, it's also will return to home and visualize home app. But when home is closed it quit all other apps that register dbus
