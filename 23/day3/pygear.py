def main():
    file_path = 'values.txt'
    one = None
    two = None
    with open(file_path, 'r') as file: 
        for entry in file:
            one = two
            two = entry
            if(one != None and two != None):
                #returns if the list contains a no.
                check(one)

def check(arg):
    chck = None
    if arg != list():
        return chck
    for i in range(len(arg)):
        if(int(arg[i]) != None):
            chck['th'] = 
    return chck
