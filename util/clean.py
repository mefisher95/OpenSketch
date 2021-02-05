import os
import re
import subprocess
import sys
import getpass

class InvalidFileType(BaseException):
    def __init__(self, ftype):
        self.ftype = ftype
    def __str__(self):
        return 'InvalidFileType: \'%s\'; Input a valdi file type to clean' % self.ftype


SAFETY = True
BASE_DIR = os.getcwd()
x = re.search('^/local_files', BASE_DIR)
ext = '.pyc'
if len(sys.argv) > 1:
    ext = sys.argv[1]
    if re.search('^[.]', ext) is None:
        raise InvalidFileType(ext)

    if len(sys.argv) > 2 and (sys.argv[2].lower() == 'safety=false' \
        or sys.argv[2].lower() == 'safety=off'):
        SAFETY = False


if SAFETY and x is not None:
    print('Valid for Clean up')
elif not SAFETY:
    print('SAFETY OFF: clean with caution')
elif re.search('%s$' % getpass.getuser(), os.getcwd()):
    print('WARNING: Will NOT clean from root directory')
else:
    print('not valid cleaning')
    print('To clean in WindowsOS, turn saftey off')
    raise Exception

def step_dir():
    for item in os.listdir():
        if os.path.isdir(item):
            os.chdir(os.getcwd() + '/' + item)
            step_dir()
        elif (re.search('%s$' % ext, item) is not None) or \
            (re.search('~$', item) is not None):
            print('REMOVING: ', item)
            subprocess.run(['rm', item])

    if BASE_DIR == os.getcwd():
        return
    else:
        os.chdir('..')
        return

step_dir()
