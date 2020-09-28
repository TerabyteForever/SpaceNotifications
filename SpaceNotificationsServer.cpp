#include "SpaceNotificationsMain.hpp"
int main(int argc, char* argv[]){
    SpaceNotifications x;
    int readByServer = 0;

    x.PushNotification(true,"Test Notification 2","SpaceCraft OrangeCat");

    x.ReadNotification(x.getNotificationsCount()-1);



}