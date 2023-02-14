import Data.List

type Square = [[Int]]  -- ogni magic square è una lista di liste di Int

-- posso generare tutte le possibili magic square ruotando quella in input e specchiandola
-- ruota di 90 gradi la magic square
rot90 :: Square -> Square
-- transpose -> righe diventano colonne
-- map reverse -> inverte ogni riga
rot90 = map reverse . transpose

-- specchia la magic square orizzontalmente
refl :: Square -> Square
-- transpose riflette la matrice sulla diagonale
refl = transpose

-- stampa la magic square non in linea(default)
pp :: Square -> IO ()
-- mappo ogni riga, poi all'interno mappo ogni elemento rendendolo una stringa
-- unisco ogni stringa separandole con uno spazio
-- separo le stringhe
pp = putStrLn . unlines . map (unwords . map show)  

-- scelgo di generare tutte le possibili magic square partendo da una effettiva
magic :: Square
magic = [[8, 1, 6],
         [3, 5, 7],
         [4, 9, 2]]

-- tutte le possibili magic square 3x3 con numeri da 1 a 9
allMagic :: [Square]
-- filter -> considera solo elementi che rispecchiano la condizione isMagic
-- chop n -> taglia una lista ogni n elementi 
-- permutations -> tutte le possibili permutazioni di una lista
allMagic = filter isMagic $ map (chop 3) $ permutations [1..9]

-- obiettivo del programma: 
    -- brute force di tutte le possibili magic square derivabili dall'originale
    -- calcolare la distanza tra l'originale e tutte le 8 possibili derivate
    -- considerare quella con la minor distanza (somma dei valori assoluti delle distanze tra il valore di un numero nell'originale e nella magic square finale)

distance :: Square -> Square -> Int
-- concat -> rende una lista di liste una lista unica
-- zipWith (-) -> fa la sottrazione elemento per elemento
-- abs -> valore assoluto
-- map -> rimappa la lista usando abs
-- sum -> sommatoria di tutti i valori assoluti delle differenze
distance s1 s2 = sum $ map abs $ zipWith (-) (concat s1) (concat s2)

solve :: Square -> Int
-- map (distance s) allMagic -> calcola tutte le possibili distanze dalla matrice originale alle possibili magic square
-- minimum -> prende la distanza minore
solve s = minimum $ map (distance s) allMagic

chop :: Int -> [Int] -> [[Int]]
-- opposto di concat, da una lista di int a una matrice
chop _ [] = []  -- se arrivato alla fine return lista vuota
chop n xs = take n xs:chop n(drop n xs)  -- ricorsione, toglie i primi n eleemtni dalla lista e prosegue

isMagic :: Square -> Bool -- true se tutti e quattro i valori calcolati sono uguali
-- transpose -> ogni riga diventa colonna
-- !! -> permette di scegliere la posizione del valore della lista da estrarre
-- zip [0 .. ] -> unisce due liste, con [0..] lista infinta a partire da 0, avrò delle coppie (numero, riga matrice)
-- uncurry -> converte una funzione di modo che accetti delle coppie di elementi
-- nub -> rimuove gli elementi duplicati di una lista

-- map sum s -> somma dei numeri delle righe
-- map sum $ transpose s -> somma dei numeri sulle colonne 
-- sum $ map (uncurry (!!)) $ zip s [0..] -> somma elementi diagonale principale
-- sum $ map (uncurry (!!)) $ zip (map reverse s) [0..] -> somma elementi diagonale secondaria
isMagic s = 
    (==1) $ -- check se lista di somme = 1
    length $ 
    nub $ 
    concat [map sum s,  -- somma dei numeri delle righe
            map sum $ transpose s,  -- somma dei numeri sulle colonne (ogni riga diventa colonna)
            [sum $ map (uncurry (!!)) $ zip s [0..]],  -- somma elementi diagonale principale
            [sum $ map (uncurry (!!)) $ zip (map reverse s) [0..]]]  -- somma elementi diagonale secondaria
    
-----------------------------------------------

-- la matrice in input deve essere separata in righe e poi per ogni elemento
-- lines -> divide le righe
-- words -> separara gli elementi
-- read -> converte in numeri gli elementi 
-- map (map read . words) . lines -> crea una lista di liste di numeri
-- show -> converte da int a string

getIntList :: IO [Int]
getIntList = fmap read getLine

calcola = do
    putStrLn "----------------------------------------------------------------"
    putStrLn "Inserisci la lista di numeri della matrice 3x3:: "
    inputList <- getIntList
    let result = solve $ chop 3 inputList
    print(result)

main = calcola