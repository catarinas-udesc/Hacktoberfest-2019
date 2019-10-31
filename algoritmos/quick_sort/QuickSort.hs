quickSort :: (Ord a) => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = quickSort smaller ++ [x] ++ quickSort bigger where
                     smaller = filter (<= x) xs
                     bigger = filter (>= x) xs
