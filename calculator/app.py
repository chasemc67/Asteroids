import argparse
import datetime
import pytz

def pacific_time():
    pacific = pytz.timezone('US/Pacific')
    return datetime.datetime.now(pacific)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Calculator Python Application')
    parser.add_argument('--time', dest='time', action='store_true',
                        help='prints the current timestamp in Pacific Time')
    args = parser.parse_args()
    
    if args.time:
        print(pacific_time())
