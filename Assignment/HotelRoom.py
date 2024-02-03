class HotelRoom:
    '''Futher it could have feature of different types of room like regular room , deluxe room etc'''
    __id = None
    __num_of_rooms=  None
    __occupy = None
    def __init__(self, id:int, num_of_rooms:int) -> None:
        self.__id =id
        self.__num_of_rooms = num_of_rooms
        self.__occupy = 0
    
    def numberOfRooms(self):
        '''Return the number of rooms'''
        return self.__num_of_rooms
    
    def getId(self):
        return self.__id
    
    def isRoomAvailaible(self):
        '''Is room availaible or not'''
        return self.__occupy ==0

    def occupy(self):
        '''Occupy the room'''
        if self.isRoomAvailaible():
            self.__occupy =1
            return True
        return False
    
    def unOccupy(self):
        self.__occupy = 0
        return True
    
    def displayDetails(self):
        return self.__num_of_rooms, self.__occupy
