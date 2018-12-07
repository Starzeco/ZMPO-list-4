cmake_minimum_required(VERSION 3.12)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp CKnapsackProblem.cpp CKnapsackProblem.h CIndividual.cpp CIndividual.h CItem.cpp CItem.h CGeneticAlgorithm.cpp CGeneticAlgorithm.h)