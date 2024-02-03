from HotelManagementSystem import HotelManagementSystem
from UserManagementSystem import UserManagementSystem
from UserHotelMiddleware import Middleware
class System:
    '''System is the main class which hold the other man objects like user management system , hotel management system and the middleware and them here in this constructor'''
    def __init__(self) -> None:
        self.hotelManager = HotelManagementSystem()
        self.userManager = UserManagementSystem()
        self.userHotelMiddleware = Middleware(self.userManager, self.hotelManager)


        