**Average Run Times**

2^20 in C = 2.0ms

2^20 in Assembly = 2.0ms

2^24 in C = 30.6ms

2^24 in Assembly = 32.0ms

2^29 in C = 88481.0ms

2^29 in Assembly = 73143.0ms

**Comparison and Analysis**

2^20: Both C and Assembly took 2.0ms, meaning there is no significant performance difference for small dataset sizes. The overhead from function calls and loop execution in both C and Assembly is negligible for this scale.

2^24: The Assembly implementation is slightly slower (by 1.4ms, about 4.6%). This could be due to additional overhead in the loop control or unoptimized memory access in the Assembly code. For mid-sized datasets, the C compiler generates efficient machine code that rivals handwritten Assembly in performance, especially with optimizations enabled.

2^29: The Assembly implementation is significantly faster (by 15338ms, approximately 17.3%). For large dataset sizes, Assembly performs better because it can be tailored to avoid unnecessary overhead, use registers effectively, and optimize memory access patterns.

**Conclusion**

C is easier to write and maintain, making it suitable for most general-purpose applications, especially when compiled with modern optimizations like -O2 or -O3, which ensure highly efficient performance for mid-sized datasets. On the other hand, Assembly offers the ability to optimize for specific hardware, such as utilizing SIMD instructions like AVX or SSE, and avoids the overhead of higher-level abstractions like function calls or array bounds checking. This makes Assembly particularly advantageous for large datasets where memory and CPU optimization are crucial, providing superior performance in such scenarios.

![image](https://github.com/user-attachments/assets/68283537-d5dd-4fcd-9c42-9db91917d4f9)

