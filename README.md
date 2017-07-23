          ==========================================================
          A collection of Bjoe-maintained components for Genode
          ==========================================================


This repository hosts Genode components that do not fall in the narrow scope of
the Genode OS Framework (http://genode.org), e.g., ported applications,
libraries, and games.
It is a playground/test repo for some of my ideas/tests/research.

To use it, you first need to obtain a clone of Genode:

! git clone https://github.com/genodelabs/genode.git genode

Now, clone the _genode-playground.git_ repository to _genode/repos/playground_:

! git clone https://github.com/bjoe/genode-playground.git genode/repos/playground

By placing the _playground_ repository under the _repos/_ directory, Genode's tools
will automatically incorporate the ports provided by the _playground_ repository.

For building software of the _playground_ repository, the build-directory
configuration _etc/build.conf_ must be extended with the following line:

! REPOSITORIES += $(GENODE_DIR)/repos/playground


Note of caution
---------------

In contrast to the components found in the mainline Genode repository, the
components within the _playground_ repository are not subjected to Genode Labs.
It is a playground/test repo for some of my ideas/tests/research. Hence, 
problems are to be expected.
