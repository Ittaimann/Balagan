# current tasks that need to be handled to some degree
1. clean up and expand string class
    A) get it to work with c++ iterators
    B) theoretically follow how stuff like the eastl works?
    C) inline/constexper some of this

2. xml parser
    A) get the xml parser to deal with the following:
        - attributes
        - comments
        - includes
    B) create an interface for getting values out of the xml parser
    C) validate it?

3. main
    - get the width and height from the xml into the sdl window (dependent on task 2b)
    - get a sprite on screen (may requrire task 4A)
    - create a transform 
4. more files type support
    A) images
        - bmp
        - jpg
        - png
        - others
    B) text
        - JSON
5. Utilities 
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
