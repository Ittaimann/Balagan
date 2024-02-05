# current tasks that need to be handled to some degree
1. clean up and expand string class
    A) it currently is a mess and needs to be cleaned up and simplified
    B) get it to work with c++ iterators
    C) theoretically follow how stuff like the eastl works?
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

