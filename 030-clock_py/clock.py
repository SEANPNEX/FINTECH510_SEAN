class MyClock24:
    """A simple clock"""
    def __init__(self, hours, minutes, seconds):
        """initialize"""
        self.__hours = hours
        self.__minutes = minutes
        self.__seconds = seconds
        if not self.__check_input():
            raise ValueError

    def __check_input(self):
        """check the input"""
        hours = self.__hours
        minutes = self.__minutes
        seconds = self.__seconds
        hours_type_check = ((type(hours) is int) or (type(hours) is float))
        minutes_type_check = (((type(minutes) is int) or (type(minutes) is float)))
        seconds_type_check = ((type(seconds) is int) or (type(seconds) is float))
        hours_range_check = (0 <= hours < 24)
        minutes_range_check = (0 <= minutes < 60)
        seconds_range_check = (0 <= seconds < 60)
        type_check_result = hours_type_check and minutes_type_check and seconds_type_check
        range_check_result = hours_range_check and minutes_range_check and seconds_range_check
        return (type_check_result and range_check_result)
    
    def tick(self):
        """increase second by 1"""
        added = False
        if self.__seconds==59:
            self.__seconds = 0
            self.__minutes += 1
            added =True
        if self.__minutes>59:
            self.__minutes = 0
            self.__hours += 1
        if self.__hours>23:
            self.__hours = 0
        if added:
            return
        self.__seconds += 1
        return
    
    def tickback(self):
        """decrease second by 1"""
        subed = False
        if self.__seconds==0:
            self.__seconds = 59
            self.__minutes -= 1
            subed =True
        if self.__minutes<0:
            self.__minutes = 59
            self.__hours -= 1
        if self.__hours<0:
            self.__hours = 23
        if subed:
            return
        self.__seconds -= 1
        return

    @property
    def hours(self):
        return self.__hours
    
    @property
    def minutes(self):
        return self.__minutes
    
    @property
    def seconds(self):
        return self.__seconds
    
    @hours.setter
    def hours(self, new_hours):
        self.__hours = new_hours

    @minutes.setter
    def minutes(self, new_minutes):
        self.__minutes = new_minutes

    @seconds.setter
    def seconds(self, new_seconds):
        self.__seconds = new_seconds

    def __str__(self) -> str:
        return f"{self.__hours:02d}:{self.__minutes:02d}:{self.__seconds:02d}"
    
    def __repr__(self) -> str:
        return str({'hours': self.__hours, 'minutes': self.__minutes, 'seconds': self.__seconds})
    
    def __eq__(self, other) -> bool:
        if not isinstance(other, MyClock24):
            return NotImplemented
        
        return self.__hours == other.__hours and \
                self.__minutes == other.__minutes and \
                self.__seconds == other.__seconds
    
    def __ne__(self, other) -> bool:
        if not isinstance(other, MyClock24):
            return NotImplemented
        
        return self.__hours != other.__hours or \
                self.__minutes != other.__minutes or \
                self.__seconds != other.__seconds
    
    def __ge__(self, other) -> bool:
        if not isinstance(other, MyClock24):
            return NotImplemented
        
        if self.__hours > other.__hours:
            return True
        if self.__hours < other.__hours:
            return False
        if self.__minutes > other.__minutes:
            return True
        if self.__minutes < other.__minutes:
            return False
        if self.__seconds >= other.__seconds:
            return True
        else:
            return False

    def __gt__(self, other) -> bool:
        if not isinstance(other, MyClock24):
            return NotImplemented
        
        if self.__hours > other.__hours:
            return True
        if self.__hours < other.__hours:
            return False
        if self.__minutes > other.__minutes:
            return True
        if self.__minutes < other.__minutes:
            return False
        if self.__seconds > other.__seconds:
            return True
        else:
            return False

    def __le__(self, other) -> bool:
        if not isinstance(other, MyClock24):
            return NotImplemented
        
        if self.__hours > other.__hours:
            return False
        if self.__hours < other.__hours:
            return True
        if self.__minutes > other.__minutes:
            return False
        if self.__minutes < other.__minutes:
            return True
        if self.__seconds > other.__seconds:
            return False
        else:
            return True
        
    def __lt__(self, other) -> bool:
        if not isinstance(other, MyClock24):
            return NotImplemented
        
        if self.__hours > other.hours:
            return False
        if self.__hours < other.hours:
            return True
        if self.__minutes > other.minutes:
            return False
        if self.__minutes < other.minutes:
            return True
        if self.__seconds >= other.seconds:
            return False
        else:
            return True
        
    def __add__(self, other):
        if not ((isinstance(other, MyClock24)) or (isinstance(other, int))):
            return NotImplemented
        
        if isinstance(other, MyClock24):
            sec = other.seconds
        else:
            sec = other
        for i in range(sec):
            self.tick()
        return self

    def __sub__(self, other):
        if not ((isinstance(other, MyClock24)) or (isinstance(other, int))):
            return NotImplemented
        
        if isinstance(other, MyClock24):
            sec = other.seconds
        else:
            sec = other
        for i in range(sec):
            self.tickback()
        return self