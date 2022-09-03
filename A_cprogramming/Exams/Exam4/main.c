/*
The code below doesn’t work as it’s supposed to. Fix the functions so that 
they work as the comments describe and don’t produce compiler errors or warnings, 
nor valgrind errors or memory leaks. The main function has no problems, and 
it cannot be changed. The structures are also defined correctly, and no includes 
are missing. In general, the logic of the code is correct.

The program handles map data, more specifically public transportation stops. The program 
saves them in a Map structure, that holds a location name, a TransportStop linked list. 
The TransportStop structure holds the data for a single Transit stop, and stores 
the name and type of the TransportStop, as well as the location (a latitude-longitude pair) 
of the TransportStop.

There are six mistakes in the program, each of them clearly visible either in 
the compiler errors/warnings or valgrind output. Note that there might be more 
than one error/warning per mistake as a single mistake can create many problems at once.

There is one mistake in the createStop function.
There are two mistakes in the createStops function.
There is one mistake in the createMap function.
There is one mistake in the printStopInfo function.
There is one mistake in the freeMemory function.
*/

// ----------------------------------------------------------------------
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Transit stop structure holds the location
// as latitude-longitude pair, types as an enum value 
// and the identifier and the name of the stop as string
typedef struct transportStop TransportStop;

/**
 * \brief Public transportation stop types are defined using a set of enum values
 * 
 */
typedef enum stopType { ALEPA_BIKE, BUS, METRO, TRAM } StopType;

/**
 * \brief Transport stop structure that is specified by location, identifier, type and 
 * name.
 * 
 */
struct transportStop {
	double location[2];	 //!< The location as a latitude-longitude pair
	char identifier[6];	 //!< The identifier of point of interest as a string
	StopType type;		 //!< The transportation stop type
	char* name;			 //!< The name of the step
	TransportStop* next; //!< The next stop
};

/**
 * \brief A map structure for public tranport stop, which is composed of
 * a linked-list of transport stops and the name of the map 
 * 
 */
typedef struct map {
	TransportStop* stops; //!< A linked-list of transportation stops
	char* locationName;	  //!< The name of the map
} Map;

// Function createStop creates a linked-list member with the given data.
/**
 * \brief Create a public transportation stop linked-list member
 *  
 * \param name The name of the transport stop
 * \param identifier The stop identifier
 * \param type The type of the stop
 * \param location A pair of doubles that have the longitude-latitude of the transportation stops
 * 
 * \return A dynamically allocated and initialized transport stop linked-list member
 */
TransportStop* createStop(const char* name,
						  const char* identifier,
						  StopType type,
						  double location[2]) {

	// Allocate memory for TransportStop
	TransportStop* stop = (TransportStop*)malloc(sizeof(TransportStop));

	// Allocate memory for the stop name and copy it to the structure
	stop->name = malloc((strlen(name) + 1) * sizeof(char));
	strcpy(stop->name, name);

	// Store the id
	strncpy(stop->identifier, identifier, 5);
	stop->identifier[5] = '\0';

	// Store the type
	stop->type = type;

    // Store the location as lat-lon
    stop->location[0] = location[0];
    stop->location[1] = location[1];

    // Set the next pointer
    stop->next = NULL;

    return stop;
}

/**
 * \brief Create a linked-list of public transportation stops
 * 
 * \param stopNames An array of public transportation stop names
 * \param ids An array of public transportation stop identifiers
 * \param types An array of public transportation stop types
 * \param locations An array of pairs of doubles that have the longitude-latitude pairs for each stop
 * \param stopCount The number of public transportation stops
 * \return A dynamically allocated and initialized linked-list of transport stops
 */
TransportStop* createStops(char** stopNames,
						  char** ids,
						  StopType* types,
						  double locations[][2],
						  int stopCount) {

	TransportStop* stop = createStop(stopNames[0], ids[0], types[0], locations[0]);
	
	TransportStop* start = (TransportStop*)malloc(sizeof(TransportStop));
	start = stop;

	// Go through all the given data and store it in the linked list
	for(int i = 1; i < stopCount; i++) {
		stop->next = createStop(stopNames[i], ids[i], types[i], locations[i]);
		stop = stop->next;
	}

	return start; // Return the created stops
}

/**
 * \brief Create a Map object from the arguments
 * 
 * \param locationName The name of the map location
 * \param stopNames An array of public transportation stop names
 * \param ids An array of public transportation stop identifiers
 * \param types An array of public transportation stop types
 * \param locations An array of pairs of doubles that have the longitude-latitude pairs for each stop
 * \param stopCount The number of public transportation stops
 * 
 * \return A dynamically allocated and initialized map object 
 */
Map* createMap(char* locationName,
			   char** stopNames,
			   char** stopIds,
			   StopType* types,
			   double locations[][2],
			   int stopCount) {

	// Allocate memory for the Map structure
	Map* map = malloc(sizeof(Map));

	// Store the location name
	map->locationName = malloc((strlen(locationName) + 1) * sizeof(char));
	strcpy(map->locationName, locationName);

	// Store the public transportation stop information
	map->stops = createStops(stopNames, stopIds, types, locations, stopCount);

	return map;
}

/**
 * \brief Returns a human-readable string for the public transportation stop type
 * 
 * \param type The stop type
 * \return The human readable string of the stop type
 */
const char* getTypeName(StopType type) {
    switch (type)
    {
	case ALEPA_BIKE:
		return "alepa bike";
	case BUS:
		return "bus";
	case METRO:
		return "metro";
	case TRAM:
		return "tram";
	default:
		return "invalid type";
	}
}

/**
 * \brief Prints the content of a Map object 
 * 
 * \details This function prints the content of a Map object in the following
 *          format:
 * 
 *          <place name> has the following public transportation stops:
 *          Stop <name>, ID <identifier> at (latitude, longitude) of type <type>.
 *          ...
 * 
 * \param map The map object to be printed
 */
void printStopInfo(Map* map) {
	printf("%s has the following public transportation stops:\n",
		   map->locationName);

	// Loop through the stops and print their info
	for(TransportStop* curr = map->stops; curr; curr = curr->next) {
		printf("Stop %s, ID %s at (%f, %f) is of type %s.\n",
			   curr->name,
			   curr->identifier,
			   curr->location[0],
			   curr->location[1],
			   getTypeName(curr->type));
	}
}

/**
 * \brief Frees the dynamically allocated memory for a map object
 * 
 * \param map The object to be freed
 */
void freeMemory(Map* map) {
    // Free linked list memory
	for(TransportStop* curr = map->stops; curr != NULL;) {
		TransportStop* del = curr;
		curr = curr->next;
		free(del->name);
		free(del);
	}

	free(map->locationName);
	free(map);
}

/**
 * \brief Main function of the program
 * 
 * \return Returns 0
 */
int main() {
	// Original data for the public transportation stops:
	// Names
	char* names[] = {"Aalto-yliopiston metroasema",
					 "Aalto-yliopisto (M)",
					 "Aalto-yliopisto (M), Korkeakoulunaukio",
					 "Aalto-yliopisto (M), Tietotie",
					 "Jämeräntaival",
					 "Teekkarikylä",
					 "Otaranta"};

	char* identifiers[] =
		{"OTA", "E2230", "541", "539", "547", "E2228", "null"};

	StopType types[] =
		{METRO, BUS, ALEPA_BIKE, ALEPA_BIKE, ALEPA_BIKE, BUS, TRAM};

	// Transit stop location, a latitude-longitude pair
	double locations[][2] = {{60.18448, 24.82358},
							 {60.18369, 24.82812},
							 {60.18431, 24.82666},
							 {60.18498, 24.82013},
							 {60.18812, 24.83505},
							 {60.18743, 24.83388},
							 {60.18021, 24.83468}};

	// Create a map structure based on the data
	Map* map = createMap("Otaniemi", names, identifiers, types, locations, 7);

	// Print map tiles information
	printStopInfo(map);

	// Free the reserved memory
	freeMemory(map);

    return 0;
}
