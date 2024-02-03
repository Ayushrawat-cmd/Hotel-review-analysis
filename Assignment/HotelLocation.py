from HotelRoom import HotelRoom

class HotelLocation:
    '''Hotel location is the class which hold the address and phone number of the particular hotel'''
    __id = None
    __address = None
    __phone_number= None
    __rooms=  None
    def __init__(self,id:int, address:str, phone_number : int) -> None:
        self.__id =id
        self.__address  = address
        self.__phone_number =phone_number
        self.__rooms = {}

    def getAddress(self):
        '''Get the address of the hotel where its situated'''
        return self.__address
    
    def getId(self):
        return self.__id
    
    def getPhoneNumber(self):
        return self.__phone_number

    def getRooms(self):
        '''different room stored of the particular hotel's location'''
        rooms = []
        for room in self.__rooms:
            # print(room)
            rooms.append(self.__rooms[room].displayDetails())
        return rooms
    
    def addRoom(self, newRoom: HotelRoom):
        '''Add room in the hotel'''
        self.__rooms[newRoom.getId()] = newRoom
    
    def getRoomObjects(self):
       return  self.__rooms
