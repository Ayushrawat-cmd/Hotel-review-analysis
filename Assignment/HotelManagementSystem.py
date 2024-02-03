from Hotel import Hotel
from HotelRoom import HotelRoom
from RoomBooking import RoomBooking
class HotelManagementSystem:
    '''Hotel management system is the class which manages all the behaviour of the hotels'''
    __hotels = None
    __roomBookings =None
    def __init__(self) -> None:
        self.__hotels = {}
        self.__roomBookings =[]
    
    def addHotel(self, new_hotel:Hotel):
        '''Add the hotel in the system'''
        id = new_hotel.getId()
        if self.__hotels.get(id):
            return False
        self.__hotels[id] = new_hotel
    
    def deleteHotel(self, old_hotel: Hotel):
        '''delete the hotel from the system'''
        if self.__hotels.get(old_hotel.getId()):    
            self.__hotels.pop(old_hotel.getId())
            return True
        return False
    
    def displayDetailsOfAllHotels(self ):
        '''Display the details of the all the hotels in the system'''
        hotels =[]
        for hotel in self.__hotels:
            hotels.append((self.__hotels[hotel].getName() ,self.__hotels[hotel].getLocations()))
        
        return hotels
    
    def getHotels(self):
        return self.__hotels
    
    def addBooking(self, booking:RoomBooking):
        '''Add booking of the particular in system'''
        self.__roomBookings.append(booking)
    
    def showDetailsOfBookings(self):
        '''Show detail of the booking in the system'''
        details= []

        for booking in self.__roomBookings:
            details.append(booking.bookingDetail())
        return details

