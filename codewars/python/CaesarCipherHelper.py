#Write a class that, when given a string, will return an uppercase string with each letter shifted forward in the alphabet by however many spots the cipher was initialized to.

#For example:

#var c = new CaesarCipher(5); // creates a CipherHelper with a shift of five
#c.encode('Codewars'); // returns 'HTIJBFWX'
#c.decode('BFKKQJX'); // returns 'WAFFLES'
#If something in the string is not in the alphabet (e.g. punctuation, spaces), simply leave it as is.
#The shift will always be in range of [1, 26].

lib ='ABCDEFGHIJKLMNOPQRSTUVWXYZ'

class CaesarCipher(object):
    def __init__(self, shift):
        self.shift = shift

    def encode(self, text):
        out = ''
        text = text.upper()
        lib_len = len(lib)
        for sym in text:
            if sym in lib:
                ind = lib.index(sym) + self.shift
                if ind > lib_len - 1:
                    out+=lib[ind - lib_len]
                else:
                    out+=lib[ind]
            else:
                out+=sym
        return out
        
    def decode(self, text):
        out = ''
        text = text.upper()
        lib_len = len(lib)
        for sym in text:
            if sym in lib:
                ind = lib.index(sym) - self.shift
                if ind < 0:
                    out+=lib[ind + lib_len]
                else:
                    out+=lib[ind]
            else:
                out+=sym
        return out
      
