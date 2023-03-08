from typing import List

class IObserver:
    def update(self):
        raise NotImplementedError

class ISubject:
    __observers:List[IObserver] = []
    
    def registerObserver(self, ob):
        self.__observers.append(ob)

    def removeObserver(self, ob):
        self.__observers.remove(ob)

    def _notifyObservers(self):
        for ob in self.__observers:
            ob.update()

    def setState(self,num):
        raise NotImplementedError

    def getState(self):
        raise NotImplementedError

class Number(ISubject):
    __number = 0
    def setState(self, num):
        self.__number = num
        self._notifyObservers()
    
    def getState(self):
        return self.__number


class HexObserver(IObserver):
    __subject:ISubject = None
    def __init__(self, sub: ISubject):
        sub.registerObserver(self)
        self.__subject = sub
    def update(self):
        num = self.__subject.getState()
        print("[HexObserver] : " + hex(num))

class BinObserver(IObserver):
    __subject:ISubject = None
    def __init__(self, sub: ISubject):
        sub.registerObserver(self)
        self.__subject = sub
    def update(self):
        num = self.__subject.getState()
        print("[BinObserver] : " + bin(num))

class OctObserver(IObserver):
    __subject:ISubject = None
    def __init__(self, sub: ISubject):
        sub.registerObserver(self)
        self.__subject = sub
    def update(self):
        num = self.__subject.getState()
        print("[OctObserver] : " + oct(num))


def main():
    numberProvider:ISubject = Number()
    # initialise and register Observers
    OHex:IObserver = HexObserver(numberProvider)
    OBin:IObserver = BinObserver(numberProvider)
    OOct:IObserver = OctObserver(numberProvider)

    # set State - This will Notify all the observers
    print("\n[-] Set State to 20")
    numberProvider.setState(20)

    print("\n[-] Removing Oct")
    # Remove one Observer
    numberProvider.removeObserver(OOct)

    print("\n[-] Set State to 10")
    numberProvider.setState(10)

    print("\n[-] Removing Bin")
    #Remove another Observer
    numberProvider.removeObserver(OBin)

    print("\n[-] Set State to 15")
    numberProvider.setState(15)

    print("\n[-] Removing Hex")
    #Remove another Observer
    numberProvider.removeObserver(OHex)

    print("\n[-] Set State to 5")
    numberProvider.setState(5)

    print("\n[-] Registering Bin")
    # Register Observer
    numberProvider.registerObserver(OBin)

    print("\n[-] Set State to 12")
    numberProvider.setState(12)

main()