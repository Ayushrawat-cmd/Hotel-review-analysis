from User import User
from HotelRoom import HotelRoom
class RoomBooking:
    '''Room booking is the class to save the details of the booked room'''
    __user = None
    __room  =None
    __checkedInTIme = None
    __checkedOutTime = None
    def __init__(self, user:User, room : HotelRoom, checkedInTime: int, checkOutTime:int) -> None:
        self.__user = user
        self.__room = room
        self.__checkedInTIme= checkedInTime
        self.__checkedOutTime = checkOutTime
    
    def bookingDetail(self):
        '''return booking details'''
        return self.__user.getDetails(), self.__room.displayDetails() , self.__checkedInTIme, self.__checkedOutTime