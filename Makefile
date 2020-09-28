GPP_PARAMS = -lrt -lpthread
SERVER_NAME = SpaceNotificationsServer
EXAMPLE_APP_NAME = SpaceNotificationsExample
SERVER_COMMANDS = $(SERVER_NAME).cpp -o $(SERVER_NAME).bin
EXAMPLE_COMMANDS = $(EXAMPLE_APP_NAME).cpp -o $(EXAMPLE_APP_NAME).bin
STANDARD = -std=c++11
all:

	g++ $(SERVER_COMMANDS) $(GPP_PARAMS) $(STANDARD) | g++ $(EXAMPLE_COMMANDS) $(GPP_PARAMS) $(STANDARD)

server:

	g++ $(SERVER_COMMANDS) $(GPP_PARAMS) $(STANDARD)

example:

	g++ $(EXAMPLE_COMMANDS) $(GPP_PARAMS) $(STANDARD)
	