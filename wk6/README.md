# Run Instructions
1. Compile with `make`.
2. Generate a file with Items using either `./randItems` (randomly sorted items) or `writeItems` (2 sorted subsequences). Data gets written to `inFile` - to read the generated data run `./readItems inFile`. 

* `./q1` (merge only) automatically reads from `inFile` and outputs the merged data in `outFile`. To read the output, run `./readItems outFile`. 
* `./q2` (sort using mergesort) on the other hand reads data from stdin, so you need to run it as so: `./q2 < inFile`. It will automatically print out the sorted data, so there is no need to run `./readItems`. 
