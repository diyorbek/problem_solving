cmake_minimum_required(VERSION 3.17)
project(problem_solving)

set(CMAKE_CXX_STANDARD 14)

add_executable(problem_solving
        codeforces/A/orac_and_factors.cpp
        codeforces/A/sum_of_round_nums.cpp
        leet_code/c++/june_challenge/cheapest_flights_within_k_stops.cpp
        leet_code/c++/june_challenge/coin_change_2.cpp
        leet_code/c++/june_challenge/count_complete_tree_nodes.cpp
        leet_code/c++/june_challenge/delete_given_node.cpp
        leet_code/c++/june_challenge/insert_delete_get_random.cpp
        leet_code/c++/june_challenge/is_subset.cpp
        leet_code/c++/june_challenge/largest_divisible_subset.cpp
        leet_code/c++/june_challenge/power_of_2.cpp
        leet_code/c++/june_challenge/queue_reconst_by_height.cpp
        leet_code/c++/june_challenge/random_pick_with_weight.cpp
        leet_code/c++/june_challenge/reverse_string.cpp
        leet_code/c++/june_challenge/search_insert_position.cpp
        leet_code/c++/june_challenge/single_number_2.cpp
        leet_code/c++/june_challenge/two_city_scheduling.cpp
        leet_code/c++/june_challenge/unique_binary_search_trees.cpp
        leet_code/c++/may_challenge/construct_BST_from_preorder_trvs.cpp
        leet_code/c++/may_challenge/counting_bits.cpp
        leet_code/c++/may_challenge/course_schedule.cpp
        leet_code/c++/may_challenge/edit_distance.cpp
        leet_code/c++/may_challenge/find_all_anagrams_in_string.cpp
        leet_code/c++/may_challenge/find_the_town_judge.cpp
        leet_code/c++/may_challenge/first_uniq_char.cpp
        leet_code/c++/may_challenge/flood_fill.cpp
        leet_code/c++/may_challenge/implement_trie.cpp
        leet_code/c++/may_challenge/interval_list_intersections.cpp
        leet_code/c++/may_challenge/k_closest_point.cpp
        leet_code/c++/may_challenge/max_sum_circular_array.cpp
        leet_code/c++/may_challenge/odd_even_linked_list.cpp
        leet_code/c++/may_challenge/posibble_bipartition.cpp
        leet_code/c++/may_challenge/ransom_note.cpp
        leet_code/c++/may_challenge/remove_k_digits.cpp
        leet_code/c++/may_challenge/valid_perfect_square.cpp
        leet_code/c++/2_sum.cpp
        leet_code/c++/3_sum.cpp
        leet_code/c++/buddy_strings.cpp
        leet_code/c++/coin_change.cpp
        leet_code/c++/median_of_2_sorted_arrays.cpp
        leet_code/c++/min_swaps.cpp
        leet_code/c++/number_complement.cpp
        leet_code/c++/recent_ping_counter.cpp
        leet_code/c++/search_in_BT.cpp
        leet_code/c++/self_crossing.v1.cpp
        leet_code/c++/self_crossing.v2.cpp
        leet_code/c++/sliding_window_max.cpp
        leet_code/c++/sort_by_bits.cpp
        leet_code/c++/utils.cpp
        leet_code/c++/valid_anagram.cpp hackerrank/sorting.cpp)

add_executable(sorting hackerrank/sorting.cpp)