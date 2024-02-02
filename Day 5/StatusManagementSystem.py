from Status import Status
class StatusManagementSystem:
    __statuses = None
    def __init__(self ) -> None:
        self.__statuses = {}
    
    def addStatus(self, new_status: Status):
        '''Add status in the management system'''
        self.__statuses[new_status.getId()]= new_status
    
    def removeStatus(self, old_status:Status):
        '''Remove status from the management system'''
        self.__statuses = self.__statuses.pop(old_status.getId())

    def readStatus(self, status: Status):
        '''Read the status from management system'''
        return self.__statuses[status.getId()]