from Hotel import Hotel
class SearchCatalogue:
    '''search catalogues is the class which helos the user in searching operations'''
    __hotels = None
    def __init__(self, hotels:[Hotel]) -> None:
        self.__hotels = hotels
        pass

    def search(self, name:str=None, address:str= None):
        hotels = []
        # print(self.__hotels)
        for hotel in self.__hotels:
            if self.__hotels[hotel].getName() == name:
                hotels.append((self.__hotels[hotel].getName(), self.__hotels[hotel].getLocations()))
        
        for hotel in self.__hotels:
            for locations in self.__hotels[hotel].getLocationObjects():
                if self.__hotels[hotel].getLocationObjects()[locations].getAddress() == address:
                    hotels+=(self.__hotels[hotel].getName(), self.__hotels[hotel].getLocations())
        
        return hotels
        