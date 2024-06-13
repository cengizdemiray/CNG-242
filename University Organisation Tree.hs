-- Cengiz Demiray - 2526960
-- I read and accept the submission rules and the extra rules specified in each question. This is my own work that is done by myself only.
data Tree = Empty | Node (String, Int) [Tree] deriving (Show, Eq)
-- buildChild:
-- param1: information array
-- param2: child count array
-- param3: child left
-- param4: current index
-- return: child array
buildChild :: [(String, Int)] -> [Int] -> Int -> Int -> (Int, [Tree]) -- it is used for creating the chidlren array of the given node at the given index and the first value of the return tuple is our current index.
buildChild _ _ 0 i = (i, []) 
buildChild a b n i = ((fstBuildChild a b (n - 1) (fstBuildNode a b i)), (sndBuildNode a b i) : (sndBuildChild a b (n - 1) (fstBuildNode a b i)))

fstBuildChild :: [(String, Int)] -> [Int] -> Int -> Int -> Int  -- to simplify the writing this function is defined as the first value of buildchild function 
fstBuildChild a b c d = (fst (buildChild a b c d))

sndBuildChild :: [(String, Int)] -> [Int] -> Int -> Int -> [Tree] -- to simplify the writing this function is defined as the second value of buildchild function 
sndBuildChild a b c d = (snd (buildChild a b c d))

buildNode :: [(String, Int)] -> [Int] -> Int -> (Int, Tree) -- this function builds the node at the given index of the array
buildNode [] [] _ = (0, Empty) 
buildNode a b i = ((fst (buildChild a b (b !! i) (i + 1))), Node (a !! i) (snd (buildChild a b (b !! i) (i + 1))))

fstBuildNode :: [(String, Int)] -> [Int] -> Int -> Int -- to simplify the writing this function is defined as the first value of buildNode function 
fstBuildNode a b c = (fst (buildNode a b c))

sndBuildNode :: [(String, Int)] -> [Int] -> Int -> Tree -- -- to simplify the writing this function is defined as the second value of buildNode function 
sndBuildNode a b c = (snd (buildNode a b c))

buildTree :: [(String, Int)] -> [Int] -> Tree
buildTree a b = sndBuildNode a b 0 -- it used for just creating tree

unitree = buildTree [("Rectorate", 2), ("General Secretary", 6), ("Social Sciences", 2), ("Economics", 4),("Political Science", 5), ("Education", 2), ("Pre School", 3), ("Foreign Languages", 4),("Engineering", 4), ("Computer Engineering", 10), ("Mechanical Engineering", 5), ("Electrical Engineering", 6)] [3, 0, 3, 0, 0, 2, 0, 0, 3, 0, 0, 0]

findhelper1 :: Tree -> String -> Tree -- for finding the specific node
findhelper1 Empty _ = Empty
findhelper1 (Node (s, x) children) t = if s == t then (Node (s, x) children) else (findhelper2 children t)

findhelper2 :: [Tree] -> String -> Tree -- for finding the children of specific node
findhelper2 [] _ = Empty 
findhelper2 (node : arr) s = if (findhelper1 node s) == Empty then (findhelper2 arr s) else (findhelper1 node s)

findnode :: Tree -> String -> Tree 
findnode tree s = findhelper1 tree s -- it is used for calling findhelper 1 function

sechelper1 :: Tree -> Int
sechelper1 Empty = 0 -- capacity of empty node is 0
sechelper1 (Node (_, x) children) = x + (sechelper2 children) -- capacity of node is the capacity of itself and capacity of children

sechelper2 :: [Tree] -> Int -- for taking the sum of children array of one node
sechelper2 [] = 0
sechelper2 (node : arr) = (sechelper1 node) + (sechelper2 arr)

sectionsize :: Tree -> String -> Int
sectionsize node s = sechelper1 (findhelper1 node s) -- it used for which one should calculated

manhelper1 :: Tree -> String -> Tree -- if the children array contains the given string then return that node else check the children of that node
manhelper1 Empty _ = Empty
manhelper1 (Node (s, x) children) t = if (manhelper2 children t) then (Node (s, x) children) else (manhelper3 children t)

manhelper2 :: [Tree] -> String -> Bool -- checks if the tree contains the node that is given as a string at the second parameter
manhelper2 [] _ = False
manhelper2 ((Node (s, _) _) : arr) t = if s == t then True else (manhelper2 arr t)

manhelper3 :: [Tree] -> String -> Tree -- if the answer is found return answer that is coming manhelper1 function, else check for the remaining array
manhelper3 [] _ = Empty
manhelper3 (node : arr) s = if (manhelper1 node s) == Empty then (manhelper3 arr s) else (manhelper1 node s)

getstring :: Tree -> String
getstring Empty = ""
getstring (Node (s, _) _) = s -- it is used for returning its string

managingentity :: Tree -> String -> String
managingentity node s = getstring (manhelper1 node s) -- it is used for getting the departmant of the result node.

managelist :: Tree -> String -> [String] 
managelist Empty _ = [] -- base case 
managelist node s = if (managingentity node s) == "" then [] else (managingentity node s) : (managelist node (managingentity node s))
-- it is used for if the root is selected for printing managelist return the null list, else managelist of parent of the specified node.