from User import User
from Hotel import Hotel
from SearchCatalog import SearchCatalogue
class NormalUser(User):
    '''Normal user or the guest in our system'''
    __roomsOccupy = None
    # __Search_catalogue = None
    def __init__(self,id, name,age, email,phone, address):
        super().__init__(id, name, age, email, phone, address)
        self.__roomsOccupy = 0
        # self.__search_catalogue = search_catalogue
    
    def getBookings(self):
        '''Return all the number of booked rooms by the user'''
        return self.__roomsOccupy
    
    def occupyRoom(self):
        '''Occupy the certain room'''
        self.__roomsOccupy+=1

    def searchHotels(self, hotelName:str= None, address:str=None, search_catalogue= None):
        return search_catalogue.search(hotelName, address)