from MessageManagementSystem import MessageManagementSystem
from UserManagementSystem import UserManagementSystem
from StatusManagementSystem import StatusManagementSystem
from UserMessageMiddleware import UserMessageMiddleware
from UserStatusMiddleware import UserStatusMiddleware
class WhatsappManagementSystem:
    '''
    Whatsapp management system handles all the other management system like usermanagement system, status management system, message management system
    '''
    def __init__(self,messageManager : MessageManagementSystem, userManager: UserManagementSystem, statusManager: StatusManagementSystem) -> None:
        self.messageManager = messageManager
        self.userManager = userManager
        self.statusManager = statusManager
        self.UserMessageMiddleware = UserMessageMiddleware()
        self.UserStatusMiddleware = UserStatusMiddleware()