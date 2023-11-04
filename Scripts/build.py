import subprocess
import os
import argparse

GENERATOR_TEXT = "Ninja"

def generate( debug ):
    dir_path = os.path.join( os.path.dirname(os.path.realpath(__file__)), "build")
    if(debug):
        subprocess.run(["cmake", "-DCMAKE_BUILD_TYPE=Debug", "-G", GENERATOR_TEXT,"../.."],cwd=os.path.join(dir_path,"debug")) 
    else:                                                   
        subprocess.run(["cmake","-DCMAKE_BUILD_TYPE=Release", "-G",GENERATOR_TEXT,"../.."],cwd=os.path.join(dir_path,"release")) 

def build( debug ):
    dir_path = os.path.join( os.path.dirname(os.path.realpath(__file__)), "build")
    if(debug):
        subprocess.run(["cmake", "--build","." ],cwd=os.path.join(dir_path,"debug")) 
    else:
        subprocess.run(["cmake", "--build","." ],cwd=os.path.join(dir_path,"release")) 
        
def run( debug ):
    dir_path = os.path.join( os.path.dirname(os.path.realpath(__file__)), "build")
    if(debug):
        dir_path = os.path.join( os.path.dirname(dir_path),"debug")
        exe_path = os.path.join( dir_path, "Balagand")
        subprocess.run(exe_path,cwd=dir_path) 
    else:
        dir_path = os.path.join( dir_path, "release")
        exe_path = os.path.join( dir_path, "Balagan")
        subprocess.run(exe_path,cwd=dir_path) 

def runDebug( ):
    dir_path = os.path.join( os.path.dirname(os.path.realpath(__file__)), "build")
    subprocess.run(["lldb", "Balagand"],cwd=os.path.join(dir_path,"debug")) 

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Short cuts for the build')

    parser.add_argument('-g', dest="regen", action="store_true", help='regenerate project with files with the original generator')
    parser.add_argument('-b', dest="build", action="store_true", help='builds project')
    parser.add_argument('-r', dest="run", action="store_true", help='runs project')
    parser.add_argument('-d', dest="debug", action="store_true", help='sets for debug')
    parser.add_argument('-rd', dest="runDebug", action="store_true", help='runs project in lldb')

    args = parser.parse_args()
    debug = False

    if(args.debug):
        debug = True

    if(args.regen):
        generate( debug )
    if(args.build):
        build( debug )
    if(args.run):
        run( debug )
    if(args.runDebug):
        runDebug() 
