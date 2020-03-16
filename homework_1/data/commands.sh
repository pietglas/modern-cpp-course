1. count lines data.dat
cat -n data.dat

2. how many lines contain 'dolor' or 'dalor'
grep dolore data.dat | cat -n ; cat -n data.dat | grep dolor ; cat -n data.dat | grep dalor 

3. how many words data.dat
wc -w data.dat

4. how many words in data.dat start with 'mol'
cat -n data.dat | grep mol | wc -w

5. How many files in test_folder are text files
find ./test_folder -name "*.txt" | wc -w 

