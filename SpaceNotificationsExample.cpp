//This thing is the example app that uses the SpaceNotifications.
#include "SpaceNotificationsMain.hpp"
int main(){
        SpaceNotifications x;
                x.ReadNotification(0);

        x.PushNotification(true,"Lorem ipsum","Lorem ipsum from client!");

                x.ReadNotification(x.getNotificationsCount()-1);




    return 0;
}