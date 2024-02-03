from HotelLocation import HotelLocation
class Hotel:
    '''This will hold the schema of the diffeerent hotels'''
    __id = None
    __name = None
    __locations = None
    __facilities = None
    def __init__(self,id, name:str ) -> None:
        
        self.__name = name
        self.__id = id
        self.__locations ={}
    
    def addLocation(self, new_location :HotelLocation):
        '''Add the new location of the hotel'''
        self.__locations[new_location.getId()] = new_location
    
    def getLocations(self):
        '''Get all the locations of that hotel'''
        locations =[]
        for location in self.__locations:
            locations.append((self.__locations[location].getPhoneNumber(), self.__locations[location].getAddress(), self.__locations[location].getRooms()))
        return locations
    
    def getName(self):
        '''Returns the name of the hotel'''
        return self.__name
        
    def getId(self):
        return self.__id
    
    def getLocationObjects(self):
        '''Return the objects of the locations'''
        return self.__locations