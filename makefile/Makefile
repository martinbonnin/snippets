VARIABLE="\\\"ma variable\\\""

PROGRAM1="program1"
PROGRAM2=$(shell echo -n " a b ")



ifeq ("a b ", "a b ")
$(warning matches)
else
$(warning does not match)
endif

ifeq (a b , a b )
$(warning matches)
else
$(warning does not match)
endif


ifeq ($(PROGRAM2),  a b )
$(error yes)
else
$(error no)
endif

COMPONENTS=Decoder DRM MBR MP4Parser Receiver Renderer Socket Streamer Transport Utilities
COMPONENTS_DIRS=$(patsubst %,Components/%,$(COMPONENTS))

all:
	echo 'dirs:' $(COMPONENTS_DIRS)
	$(MAKE) -C dir

test:
	echo $(VARIABLE)
	echo "dhcpclassid=" | sed 's/dhcpclassid=.*$$/dhcpclassid=$(VARIABLE)/g'
dhcpclassid="toto";
