def primes_sieve(limit):
    a = [True] * limit                          # Initialize the primality list
    a[0] = a[1] = False
    primes = []

    for (i, isprime) in enumerate(a):
        if isprime:
            primes.append(i)
            for n in range(i*i, limit, i):     # Mark factors non-prime
                a[n] = False

    return primes


if __name__ == "__main__":
    n, q = [int(x) for x in input().split(" ")]
    ai = [int(x) for x in input().split(" ")]   # Ai


    primes = primes_sieve(10000)

    for i in range(q):
        aip = []    # aip = Ai+1
        bip = []    # bip = Bi+1
        while (ai):
            top = ai.pop()
            if top % primes[i] == 0:
                bip.append(top)
            else: # to Ai+1
                aip.append(top)
        ai = aip
        for i in reversed(bip):
            print(i)

    for i in reversed(aip):
        print(i)