import Data.List

type Square = [[Int]] 

printSquare :: Square -> IO ()
printSquare = putStrLn . unlines . map (unwords . map show)       

chop :: Int -> [Int] -> [[Int]]
chop _ [] = []  -- se arrivato alla fine return lista vuota
chop n xs = take n xs:chop n(drop n xs)  -- ricorsione, toglie i primi n elementi dalla lista e prosegue

isMagic :: Square -> Bool
isMagic s = 
    (==1) $ -- check se lista di somme = 1
    length $ 
    nub $ 
    concat [map sum s,  -- righe
            map sum $ transpose s,  -- colonne
            [sum $ map (uncurry (!!)) $ zip s [0..]],  -- diagonale principale
            [sum $ map (uncurry (!!)) $ zip (map reverse s) [0..]]]  -- diagonale secondaria

allMagicBruteForced :: [Square]
allMagicBruteForced = filter isMagic $ map (chop 3) $ permutations [1..9]

distance :: Square -> Square -> Int
distance s1 s2 = sum $ map abs $ zipWith (-) (concat s1) (concat s2)

solve :: Square -> Int
solve s = minimum $ map (distance s) allMagic

magic :: Square
magic = [[8, 1, 6],
         [3, 5, 7],
         [4, 9, 2]]

rot90 :: Square -> Square
rot90 = map reverse . transpose

refl :: Square -> Square
refl = transpose

allMagic :: [Square]
allMagic = concat [ take 4 $ iterate rot90 magic,
                    take 4 $ iterate rot90 $ refl magic ]
                    
getIntList :: IO [Int]
getIntList = fmap read getLine

computeDistance = do
    putStrLn "----------------------------------------------------------------"
    putStrLn "Inserisci la lista di numeri della matrice 3x3 :"
    putStrLn "es. [1,2,3,4,5,6,7,8,9]"
    inputList <- getIntList
    let minDistance = solve $ chop 3 inputList
    putStrLn $ "Minima distanza dal magic square più vicina : " ++ show minDistance
    continueGameOrNot

continueGameOrNot :: IO ()
continueGameOrNot = do
    putStrLn "----------------------------------------------------------------"
    putStrLn "Vuoi calcolare un'altra distanza? [Y/N]: "
    choice <- getLine
    case choice of
        "Y" -> computeDistance
        "Yes" -> computeDistance
        "y" -> computeDistance
        _ -> return ()

main = computeDistance