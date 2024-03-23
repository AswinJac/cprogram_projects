cmake_minimum_required(VERSION 3.27)
project(CLAB C)

set(CMAKE_C_STANDARD 23)

add_executable(CLAB main.c
        hastable.c
        sortingtech.c
        graph.c
        treetravel.c
        polymult.c
        stackquelinked.c
        BinarySearchTree.c
        palindrome.c
        mergelist.c
        circularpriority.c
        infixtopost.c
        stack.c
        sparse.c)
add_executable(hashtable hastable.c)
add_executable(sortingtech sortingtech.c)
add_executable(graph graph.c)
add_executable(treetravel treetravel.c)
add_executable(polymult polymult.c)
add_executable(stackquelinked stackquelinked.c)
add_executable(BST BinarySearchTree.c)
add_executable(palindrome palindrome.c)
add_executable(mergelist mergelist.c)
add_executable(circprio circularpriority.c)
add_executable(inftopos infixtopost.c)
add_executable(stack stack.c)
add_executable(sparse sparse.c)
