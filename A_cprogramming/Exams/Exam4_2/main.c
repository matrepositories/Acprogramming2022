/*
The code below doesn’t work as it is supposed to. Fix the functions so that they work as 
the comments describe and they don’t produce compiler warnings/errors or valgrind errors. 
You can make the following assumptions:
- The main function has no problems, and it cannot be changed.
- The structures are defined correctly. 
- No includes are missing.
- In general, the logic of the code is correct.

The program handles map data, more specifically points of interest. The program 
saves them in a ``Map`` structure, that holds a location name, a POI array and the number 
of points of interest in the array. The ``POI`` structure holds the data for a 
single point of interest, and stores the name and type of the POI, as well as 
the location (a latitude-longitude pair) of the POI.

There are six mistakes in the program:

- There are two mistakes in the ``createPOIs`` function.
- There are two mistakes in the ``createMap`` function.
- There is one mistake in the ``printPoiInfo`` function.
- There is one mistake in the ``freeMemory`` function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief A point of interest structure which specifies
 * a point of interest as a location, type and a name.
 * 
 */
typedef struct pointOfInterest {
	double location[2]; //!< The location as a latitude-longitude pair
	char type[15];		//!< The type of point of interest as a string
	char* name;			//!< The name of the point of interest
} POI;

/**
 * \brief A map structure for point of interests, which is composed of
 * an array of point interests and the name of the map
 * 
 */
typedef struct map {
	POI* pointsOfInterest; //!< an array of point of interests
	int poiCount;		   //!< The number of point of interests in the map
	char* locationName;	   //!< The name of the map
} Map;

/**
 * \brief Creates an array of point of interests from the arguments
 * 
 * \param poiNames An array point of interest names
 * \param poiTypes An array of point of interest types
 * \param locations An array of pairs of doubles that have the longitude-latitude pairs for each point of interest
 * \param poiCount The number of point of inetests
 * 
 * \return A dynamically allocated array of point of interests created using the specfied arguments 
 */
POI* createPOIs(char** poiNames,
				char** poiTypes,
				double locations[][2],
				int poiCount) {

	// Allocate memory for points of interest, based on the given poiCount
	POI* pois = (POI*)malloc(sizeof(POI) * poiCount);

	// Go through all the given data and store it in the array
	for(int i = 0; i < poiCount; i++) {
		// Allocate memory for the name based on its length
		// and copy it to the structure
		pois[i].name = malloc((strlen(poiNames[i]) + 1) * sizeof(char)); //fix
		strcpy(pois[i].name, poiNames[i]);

		// Store the type
		
		strcpy(pois[i].type, poiTypes[i]); //fix

		// Store the location, as lat-lon (from lon-lat)
		pois[i].location[0] = locations[i][1];
		pois[i].location[1] = locations[i][0];
	}

	return pois;
}

/**
 * \brief Create a Map object from the arguments
 * 
 * \param locationName The name of the location
 * \param poiNames An array of point of interest names
 * \param poiTypes An array of point of ineterest types
 * \param locations An array of pairs of doubles that have the longitude-latitude pairs for each point of interest locations
 * \param poiCount The number of point of interests
 * 
 * \return A dynamically allocated and initialized Map object
 */
Map* createMap(char* locationName,
			   char** poiNames,
			   char** poiTypes,
			   double locations[][2],
			   int poiCount) {

	// Allocate memory for the Map structure
	Map* map = malloc(sizeof(Map));

	// Store the points of interest amount
	map->poiCount = poiCount;				//fix

	// Store the location name
	map->locationName = malloc((strlen(locationName) + 1) * sizeof(char));
	strcpy(map->locationName, locationName); //fix

	// Store the points of interest information
	map->pointsOfInterest = createPOIs(poiNames, poiTypes, locations, poiCount);

	return map;
}

/**
 * \brief Prints the content of a Map object 
 * 
 * \details This function prints the content of a Map object in the following
 *          format:
 * 
 *          <place name> has the following points of interest:
 *          Point of interest <name> at (latitude, longitude) if of type <type>.
 *          ...
 * 
 * \param map The map object to be printed
 */
void printPoiInfo(Map* map) {
	printf("%s has the following points of interest:\n", map->locationName);

	// Loop through the points of interest and print their info
	for(int i = 0; i < map->poiCount; i++) {
		printf("Point of interest %s at (%f, %f) is of type %s.\n",
			   map->pointsOfInterest[i].name,	//fix
			   map->pointsOfInterest[i].location[0],
			   map->pointsOfInterest[i].location[1],
			   map->pointsOfInterest[i].type);
	}
}

/**
 * \brief Frees the dynamically allocated memory for a map object
 * 
 * \param map The object to be freed
 */
void freeMemory(Map* map) {
	// Free the array member's memory
	for(int i = 0; i < map->poiCount; i++) {
		free(map->pointsOfInterest[i].name);
		//free(map->pointsOfInterest[i].type); fix?
	}

	// Free the array
	free(map->pointsOfInterest);

	free(map->locationName);
	free(map);
}

/**
 * \brief Main function of the program
 * 
 * \return Returns 0
 */
int main() {
	// Original data for the points of interests:
	// Names
	char* names[] = {"Aalto Maarintalo",
					 "Sodexo: Kvarkki",
					 "Ossinlammen viljelypalstat",
					 "Subway",
					 "Sodexo: T-talo",
					 "Kipsari",
					 "Ravintola Fat Lizard",
					 "Aalto-yliopisto Kandidaattikeskus",
					 "Amfi",
					 "Aalto-yliopisto Harald Herlin -oppimiskeskus",
					 "Alvarin aukio",
					 "Täffä"};

	char* types[] = {"building",
					 "restaurant",
					 "allotment",
					 "restaurant",
					 "restaurant",
					 "restaurant",
					 "restaurant",
					 "building",
					 "amphitheatre",
					 "building",
					 "park",
					 "restaurant"};

	// Point of interest location, a longitude-latitude pair
	double locations[][2] = {{24.826246351003647, 60.1892566863454},
							 {24.83001083135605, 60.18825326911869},
							 {24.833179861307144, 60.188098586791284},
							 {24.821400940418243, 60.18700578872486},
							 {24.82165038585663, 60.186972450811226},
							 {24.824374169111252, 60.18569358288761},
							 {24.820403158664703, 60.1855755618042},
							 {24.828090369701385, 60.18630368511285},
							 {24.827543199062347, 60.185673579343984},
							 {24.827739000320435, 60.18472339698474},
							 {24.82895404100418, 60.184864092387755},
							 {24.833138287067413, 60.18608164922176}};

	// Create a map structure based on the data
	Map* map = createMap("Otaniemi", names, types, locations, 12);

	// Print map tiles information
	printPoiInfo(map);

	// Free the reserved memory
	freeMemory(map);

	return 0;
}