# ContextSwitching

We chose 65535 to be our maximum T as the maximum sum we can get is 32 bits, the sum of 1 to 65535 is 2147450880, which is close to the biggest 32 bits number

We incremented NPROC from 10 to 50, by 10 each time to see the change in execution time

The number we kept constant for NPROC is 10, which was chosen randomly

We chose 1000, 24000, 36000, 48000 and 60000 for T in order to obtain relatively high execution rates (approaching the maximum with 60000)
