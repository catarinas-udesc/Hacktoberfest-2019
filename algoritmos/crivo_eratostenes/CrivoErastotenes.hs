-- Retorna os primos de uma lista.
-- Como usar:
-- crivoEratostenes [2..10000] para os primos entre 2 e 10000
-- crivoEratorstenes [2..] para todos os primos que seu computador aguentar

crivoEratostenes :: [Int] -> [Int]
crivoEratostenes [] = []
crivoEratostenes (x:xs) = x : crivoEratostenes (filter (\y -> y `mod` x /= 0) xs)
