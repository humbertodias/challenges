def sec(times):
    hours = 0
    minutes = 0
    secs = 0
    for i in xrange(1, len(times)):
        if times[i] == '-:--:--':
            return False
        time = map(int, times[i].split(':'))
        hours += time[0]
        minutes += time[1]
        secs += time[2]

    return (hours * 3600) + (minutes * 60) + secs
    


n, d = map(float, raw_input().split())
while True:
    try:
        times = raw_input().split()
    except EOFError:
        break

    time_sec = sec(times)
    if time_sec != False:
        avg = round(time_sec / d)
        print '%3s:%2d:%02d min/km' % (times[0], avg / 60, avg % 60)
    else:
        print '%3s: -' % times[0]