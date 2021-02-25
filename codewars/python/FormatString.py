#Given: an array containing hashes of names

#Return: a string formatted as a list of names separated by commas except for the last two names, which should be separated by an ampersand.

#Example:

#list([ {name: 'Bart'}, {name: 'Lisa'}, {name: 'Maggie'} ])
# returns 'Bart, Lisa & Maggie'
#list([ {name: 'Bart'}, {name: 'Lisa'} ])
# returns 'Bart & Lisa'
#list([ {name: 'Bart'} ])
# returns 'Bart'
#list([])
# returns ''
#Note: all the hashes are pre-validated and will only contain A-Z, a-z, '-' and '.'.

def namelist(names):
    if not names:
        return ''
    elif len(names) < 2:
        return str(names[0]['name'])
    tmp = []
    for n in names:
        tmp.append(n['name'])
    return ', '.join(tmp[:len(tmp) - 1]) + ' & ' + tmp[len(tmp) - 1]
  
