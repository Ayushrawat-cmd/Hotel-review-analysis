from Hotel import Hotel
from User import User
class HotelAgent(User):
    '''Hotel agent is the type of user who can add hotel in the system and can modify his only own details'''
    __hotels = None
    def __init__(self, id: int, name: str, age: int, email: str, phone: int, address: str) -> None:
        super().__init__(id, name, age, email, phone, address)
        self.__hotels = {}
    
    def addHotel(self, new_hotel:Hotel):
        '''Add the hotel by the hotel agent only'''
        print(new_hotel.getId())
        if self.__hotels.get(new_hotel.getId()):
            return False
        self.__hotels[new_hotel.getId()] = new_hotel
    
    def getHotels(self):
        return self.__hotels