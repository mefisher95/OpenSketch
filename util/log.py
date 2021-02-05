import datetime

def log(message, file):
    with open(file, 'a') as logging:
        logging.write(str(datetime.datetime.now()) + '\n')
        logging.write(message + '\n')