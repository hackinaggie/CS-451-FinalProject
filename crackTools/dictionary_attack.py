# written by Matthew Michel, William Zhao, and Joshua Shin 
# solve the Crackme challenge in CSCE451

# to run: python3 dictionary_attack.py -d <dictionary_fname> -e <exe_name>

import subprocess 
import sys
import getopt

def crack(exe_name, buffered_dictionary):
    plaintext = ""

    # run binary within the same shell. Redirect binary's standard 
    # input to a pipe launched from the current process. We can directly communicate with the
    
    exe_str = './' + exe_name
    proc = subprocess.Popen(exe_str, stdin=subprocess.PIPE)
    try:
        # serialize in unicode format to send via the pipe connection 
        proc.communicate(buffered_dictionary.encode('utf-8'))  
    except:
        pass
    
    # if not found, kill process. We have to start again (unforunately 
    # we cannot use same process due to nature of pipe and io in the binary.
    proc.terminate()

    print("Process terminated. Dictionary attack successful! View stdout for correct password.") 


# dictionary of 1,000,000 elements of size <= 8 each will 
# take a maximum of 57 MB in memory in Python => No memory issues are expected to arise
# from this string construction
def to_string(dictionary):
    stringified_dict = ""

    for e in dictionary:
        stringified_dict += e + '\n'
        stringified_dict += e[0].upper() + e[1:] + '\n'
    
    return stringified_dict


def main():
    argv = sys.argv[1:]

    dictionary = []
    executable = ""
    
    fname_dict = ""
    exe_name   = ""

    try:
        opts, args = getopt.getopt(argv, "d:e:", 
                ["dictionary", "executable"])
    except getopt.GetOptError:
        print("error")
        sys.exit(1)

    for opt, arg in opts:
        if opt in ('-d', '--dictionary'):
            fname_dict = arg

        elif opt in ('-e', '--executable'):
            exe_name = arg
    
    with open(fname_dict) as f:
        dictionary = [e.lower().rstrip() for e in f.readlines()]
    
    # string that is fed to stdin 
    str_dictionary = to_string(dictionary)

    crack(exe_name, str_dictionary)


if __name__ == '__main__':
    main()