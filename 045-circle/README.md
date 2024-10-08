# Circle

For this problem, you will make a `Circle` class, which makes use of
your `Point` class from the previous assignment. Start by copying
point.hpp and point.cpp from the point directory into the current
directory:
```
  cp ../044_point/point.hpp .
  cp ../044_point/point.cpp .
```

Now, write a `circle.hpp` file, which declares the class `Circle`. Your
circle class should have two private fields:
  - A `Point` for the center (remember: `Point` is a type, so we can have
    a field whose type is "Point")
  - A const double for the radius

Your circle should then have three pieces of public functionality:
1. A constructor that takes a Point and a double and initializes the center 
   and radius from them. Note that you should use an initializer list for both fields and will **have to** for the const radius field. 
2. The method:
   ```c++
   void move (double dx, double dy)
   ```
   which moves the circle's center by <dx,dy> (hint: Point already has a move method, delegate
   that behavior to point) 
3. The method
   ```c++
   double intersectionArea(const Circle & otherCircle)
   ```
   which computes the area of the intersection of this circle and otherCircle. 

   To find the formula for this area, search the internet for
   "area of intersection of two circles". If you use existing code, reference that 
   source in comments in your code.


Declare these methods and constructor in your `Circle` class (in
`circle.hpp`) and implement them in `circle.cpp`.

Create a "Makefile," which will compile your code into a program
called "circles." Use the provided `main.cpp``, which has a main function
that reads input from stdin. The input it reads starts with a line 
containing the number of circles to have. The next (ncircles) lines
describe a circle with three doubles: x y radius. After that, there
are 0 or more commands, "i c1 c2" or "m cnum dx dy". The first prints
the area of intersection of circles c1 and c2 (where these are numbers
that specify which circle). The second moves circle cnum by <dx,dy>.

We have provided a sample input (input1.txt) and output (output1.txt).

Once your output matches for the sample input, submit circle.cpp, circle.hpp, point.cpp, point.hpp, and Makefile to Gradescope.

