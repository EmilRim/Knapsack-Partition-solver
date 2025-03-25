# Particijos Sprendimo Modulis

## Modulio Aprašymas

Šis modulis yra skirtas spręsti du pagrindinius optimizavimo uždavinius:
1. Daikčių krepšelio (Knapsack) problemą
2. Skaičių particijos problemą

## Failų Formato Reikalavimai

### 1. Particijos Problema (Skaičių Padalijimas)

Failas turi turėti tokią struktūrą:
```
n           # Elementų skaičius
w1 w2 w3 ... wn   # Svoriai (sveikieji skaičiai)
```

Pavyzdys (`testas1.txt`):
```
5
10 20 15 5 25
```

### 2. Daikčių Krepšelio Problema (Pasirinktinai)

Failas turi turėti tokią struktūrą:
```
n           # Elementų skaičius
w1 w2 w3 ... wn   # Svoriai
c           # Krepšelio talpa
v1 v2 v3 ... vn   # Verčių sąrašas
```

Pavyzdys (`testas2.txt`):
```
5
10 20 15 5 25
50
2 3 4 5 1
```

## Naudojimo Instrukcijos

### Kompiliavimas

Naudokite `mingw32-make` arba `make` kompiliuoti programą.

### Paleidimas

Programą galima paleisti dviem būdais:

1. Su konkrečiu testu:
```bash
./main.exe testas1.txt
```

2. Su stdin įvestimi:
```bash
./main.exe - < testas1.txt
```

## Išvesties Formatas

### Particijos Problema

Programa pateiks:
- Artimiausią galimą padalijimą
- Dviejų grupių sumas
- Skirtumą tarp grupių

### Daikčių Krepšelio Problema

Programa pateiks maksimalią galimą vertę.

## Apribojimai

- Maksimalus elementų skaičius: 100
- Maksimali krepšelio talpa: 1000

## Klaidos

- Netinkamas failas: Programa praneš apie klaidos pobūdį
- Per dideli skaičiai: Gali sukelti perpildymo klaidą

## Dėmesio

Modulis automatiškai nustato, ar tai particijos, ar krepšelio problema pagal failo formatą.

## Pavyzdžiai

### Particijos Problema Išvestis
```
Closest possible partition found!
Subset 1 (Sum = 50): 10 20 15 
Subset 2 (Sum = 50): 5 25
Difference: 0
```

### Krepšelio Problema Išvestis
```
Maximum Knapsack Value: 14
```

## Kūrėjas

Modulis sukurtas kaip akademinis projektas, skirtas spręsti optimizavimo uždavinius.
