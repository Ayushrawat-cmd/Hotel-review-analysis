from User import User
from Hotel import Hotel
from UserManagementSystem import UserManagementSystem
from HotelManagementSystem import HotelManagementSystem
from RoomBooking import RoomBooking
class Middleware:
    '''User and hotel middleware for the interaction between two independent classes. Here will the booking will be created'''
    __userManager = None
    __hotelManager = None

    def __init__(self, userManager: UserManagementSystem, hotelManager: HotelManagementSystem) -> None:
        '''Intialise the objects of hotel management class and user management class'''
        self.__hotelManager = hotelManager
        self.__userManager = userManager

    def createBooking(self, user: User, hotel:Hotel, checkInDate , checkoutDate):
        '''create booking for particular user and the the room of that particular hotel's location'''
        if self.__userManager.isUserAvailaible(user) is False:
            return False
        hotels = self.__hotelManager.getHotels()
        location = hotel.getLocationObjects()[list(hotel.getLocationObjects().keys())[0]] # here i am taking the hotel of sing location for time being
        room = location.getRoomObjects()[list(location.getRoomObjects().keys())[0]]# similarly here i am taking single type of room initially
        roomID = room.getId()
        if hotels.get(hotel.getId()): # is that hotel even present in our system
            feededLocations = hotels[hotel.getId()].getLocationObjects()
            if feededLocations.get(location.getId()): # is that hotel location present in our system
                feededRoom = feededLocations[location.getId()].getRoomObjects()
                if feededRoom.get(roomID) : # is that room present in that particular hotel location and is that room availaible for booking 
                    self.__userManager.checkedIn(user)
                    self.__hotelManager.addBooking(RoomBooking(user,room, checkInDate, checkoutDate)) # for now the time/date is static
                    feededRoom[roomID].occupy()
                    return True
        
        return False