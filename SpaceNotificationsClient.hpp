//This header is the client side API of the SpaceNotifications. It is designed for the client applications that uses SpaceNotifications.
#include <string>
#include <tuple>
#include <vector>
#include <iostream>
#include <fstream>
#include <exception>
#include <ctime>
#include "include/Colorized.hpp"
//Shared memory support
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/allocators/allocator.hpp>
#include <cstdlib>
#include <algorithm>
#include <utility> 

using namespace boost::interprocess;
struct NotificationType{

        int key;
        std::string title;
        std::string notificationItself;



};
typedef allocator<NotificationType, managed_shared_memory::segment_manager>  ShmemAllocator;
typedef vector<NotificationType, ShmemAllocator> MainVector;    
        managed_shared_memory segment(open_only,"spacenotifications");


     MainVector *notification_holder = segment.find<MainVector>("spaceshared").first;        

        int size = notification_holder->size();


  
                int notificationCounter = 0;  
                int readNotificationCounter = 0;
                        std::ofstream outputFile("SpaceNotificationLog.txt",std::ios::trunc);
 


        

                std::string getDateTime(){

                 struct tm CurTime;
                 char datetime[80];
                 time_t CurrentEpoch = time(NULL);
                 CurTime = *localtime(&CurrentEpoch);
                 strftime(datetime, sizeof(datetime), "%d-%m-%Y %H:%M:%S", &CurTime);

                  return datetime;      

                }




 

        int getNotificationsCount(){

                return notification_holder->size();
                


        }
        int getUnreadNotificationsCount(){

                        
                        return notification_holder->size() - readNotificationCounter;


        }
         void PushNotification(bool isDebug, std::string title, std::string text){

            NotificationType a;
                a.key = notificationCounter;
                a.title = title;
                a.notificationItself = text;

            notification_holder->push_back(a);

 

            
            if(isDebug){

                    
                    
                    outputFile<<"[ "<<getDateTime()<<" ] "<<"Notification has written to the queue "<<notificationCounter<<"."<<std::endl;
                    outputFile.eof();


            }
        

        notificationCounter++;



       }
        void ReadNotification(int elementKey){

        

                try{

                                if(elementKey > notification_holder->size()){

                                                throw std::invalid_argument("Invalid key.");


                                }
                                else{
                                        
                                        std::cout<<std::endl<<std::endl<<WBOLD_YELLOW_COLOR<<notification_holder->at(elementKey).title<<std::endl<<std::endl<<WBOLD_WHITE_COLOR<<notification_holder->at(elementKey).notificationItself<<std::endl;
                                        readNotificationCounter++;
                                }
                        }

                         
                        catch(std::invalid_argument& inv_arg){


                                std::cout<<std::endl<<inv_arg.what()<<std::endl;


                        }
                        


                }



