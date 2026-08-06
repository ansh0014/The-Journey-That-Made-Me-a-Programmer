// now i am doing the shooping offers
//  i have given a array price[i] is the price of the ith item , and an integer array needs[i] is the number of pieces of the ith item i want to buy
// i have also gven array special[i] is of size n+1 where special[i][j] is the number of peices of the jth item in the ith offer and special[i][n] is the price of it offer
// return the lowest price i have to pay for exactly certain items as given where i could make optimal use of special offers. 
// i are allowed to buy more items than i want even if that would lower the overall price.
// approach i am using the bitmask for the mask of the items and then i will use the dp for the transition of the mask and then i will use the backtracking to find the lowest price i have to pay for exactly certain items as given where i could make optimal use of special offers.
