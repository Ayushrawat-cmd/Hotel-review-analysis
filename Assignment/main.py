from NormalUser import NormalUser
from Hotel import Hotel
from HotelLocation import HotelLocation
from HotelRoom import HotelRoom
from SearchCatalog import SearchCatalogue
from Admin import Admin
from HotelAgent import HotelAgent

admin = Admin(1,"fsfs",12,"sfsfs",2232,"sfsfsf") # initialise the admin
hotelAgent = HotelAgent(1,"dff",112,"SDfsf",23213,"323fef") #initialise the hotel agent 


user1 = NormalUser(1,"ayush",10, "dads",12313, "dsda")# intialise the user1
user2 = NormalUser(2,"ayushraw",10, "dads",12313, "dsda") #initalise the user2


admin.systemManager.userManager.addUser(user1) #add the user1 in the system by admin
# print(userManager.addUser(user1))
admin.systemManager.userManager.addUser(user2)#add the user2 in the system by admin
user2.modifyDetails(name="Rawat")#modify his own profile
print(admin.systemManager.userManager.displayDetailsOfAllUsers())
admin.systemManager.userManager.deleteUser(user1) # delete the user by admin
print(admin.systemManager.userManager.displayDetailsOfAllUsers())


location1 =HotelLocation(1, "delhi", 121214) # initialise the location 1
room1 = HotelRoom(1, 10) #initialise the room for that location
room2 = HotelRoom(2, 20) #initalise the another room for that location
hotel1 = Hotel( 1,"5 star") # initialise the hotel
hotel1.addLocation(location1) # add new location for that hotel as the same brand hotel could be in many locations

location1.addRoom(room1) # add the room in that location
location1.addRoom(room2)#add another room in that location


#simialry another hotel initialise
hotel2 = Hotel(2, "3 star")
location2 =HotelLocation(2, "delhi",12111)
room3 = HotelRoom(1,20)
location2.addRoom(room3)
hotel2.addLocation(location2)


admin.systemManager.hotelManager.addHotel(hotel1) # add hotel1 in the system
print(admin.systemManager.hotelManager.displayDetailsOfAllHotels())
hotelAgent.addHotel(hotel2)# add hotel2 in the system
print(hotelAgent.getHotels())
print(admin.systemManager.hotelManager.displayDetailsOfAllHotels())
admin.approveHotelsAddByHotelAgent(hotelAgent)
print(admin.systemManager.hotelManager.displayDetailsOfAllHotels())

admin.systemManager.userHotelMiddleware.createBooking(user2,hotel1,1, 12) # booking made by the admin to push in the system
print(admin.systemManager.hotelManager.showDetailsOfBookings())# showing the  details of all the booking in the system

search = SearchCatalogue(admin.systemManager.hotelManager.getHotels()) #search catalogue to search for particular hotel

print(user1.searchHotels( hotelName= "5 star",search_catalogue=search )) # search the hotel by the user