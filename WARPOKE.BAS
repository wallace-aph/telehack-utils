   10  A% = 0
   11  D% = 0
   12  INPUT A%
   20  PRINT A% D%
   22  POKE A%,D%
   23  D% = D% + 1
   24  IF D% > 255 THEN 30
   25  GOTO 20
   30  A% = A% + 1
   31  D% = 0
   40  GOTO 20
