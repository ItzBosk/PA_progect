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

-- tutte le possibili magic square
allMagic :: [Square]
-- take 4 $ iterate rot90 magic -> 4 rotazioni della magic square originale
-- take 4 $ iterate rot90 $ refl magic -> 4 rotazioni della magic square riflessa
-- ottengo 8 magic square
allMagic = concat [take 4 $ iterate rot90 magic,
                    take 4 $ iterate rot90 $ refl magic]

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

main :: IO ()
main = 

