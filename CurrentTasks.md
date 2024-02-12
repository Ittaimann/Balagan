# current tasks that need to be handled to some degree

FIGURE OUT WHAT CURSED THING IS HAPPENING WITH ALLOCATIONS IN THE PAIRS STUFF
ITS LITERALLY OVERLAPPING ALLOACTIONS (doing a new string in the same spot as a char?)

1. clean up and expand string class
    A) get it to work with c++ iterators
    B) theoretically follow how stuff like the eastl works?
    C) inline/constexper some of this
    D) Investigate explicit keyword... I'm getting sick of dealing with this

2. container checks
    a) make sure that all containers behave in an optimal way
    b) maybe write copy constructors?

3. xml parser
    A) get the xml parser to deal with the following:
        - attributes
        - comments
        - includes
    B) create an interface for getting values out of the xml parser
    C) validate it?
    D) mass clean up

4. main
    - get the width and height from the xml into the sdl window (dependent on task 2b)
    - get a sprite on screen (may requrire task 4A)
    - create a transform 
5. more files type support
    A) images
        - bmp
        - jpg
        - png
        - others
    B) text
        - JSON
6. Utilities 
    A) Containers
        - hashmap
        - set
        - tree of some kind (steal from xml)
        - expanded array
    B) Logging
        - investigate usage of file descriptors to create logs
    C) Asserts
        - investigate macro style asserts to allow for break points on line
    D) Testing Framework to make sure that my container changes aren't breaking things
7. allocations
    A) kinda in the container work but figure out a good way to allocations lmao
