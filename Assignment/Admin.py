from User import User
from System import System
from HotelAgent import HotelAgent
class Admin(User):
    '''Admin is the user which having all the ibject of system'''
    def __init__(self, id: int, name: str, age: int, email: str, phone: int, address: str) -> None:
        super().__init__(id, name, age, email, phone, address)
        self.systemManager = System()
    
    def approveHotelsAddByHotelAgent(self, hotelAgent: HotelAgent):
        '''Approve that hotels added by the hotel agent could be push in the system'''
        hotels = hotelAgent.getHotels()
        for hotel in hotels:
            self.systemManager.hotelManager.addHotel(hotels[hotel])
           
