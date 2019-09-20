#!/bin/sh

if [ -z "$1" ]
then
    echo "Build directory is not set"
    exit 1
fi
BUILD_DIR=$1
BASE_DIR="$( cd "$(dirname "$0" )" && pwd )"
export GENODE_DIR=$BASE_DIR/../../../../..
BOOST_DIR=$GENODE_DIR/contrib/boost-$(cat $BASE_DIR/../../../ports/boost.hash)

$GENODE_DIR/tool/ports/prepare_port boost

cd $BOOST_DIR/src/lib/boost

./bootstrap.sh
cp $BASE_DIR/project-config.jam $BOOST_DIR/src/lib/boost
./b2 -a --reconfigure --prefix=$BUILD_DIR --libdir=$BUILD_DIR/var/libcache/boost --includedir=$BOOST_DIR/include -d+2 install

cd $BUILD_DIR/var/libcache/boost


for LIBBOOST in `find . -name "*.a" -print`
do 
     /usr/local/genode-gcc/bin/genode-x86-ar -x $LIBBOOST
done

/usr/local/genode-gcc/bin/genode-x86-ar -qc boost.lib.a *.o

#gcc -shared -o c.so -Wl,--whole-archive a.a b.a -Wl,--no-whole-archive
