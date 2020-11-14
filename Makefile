server := cpp
client := swing

all : $(server) $(client)

$(server) $(client):
	$(MAKE) --directory=$@

.PHONY : all clean run $(server) $(client)

clean :
	$(MAKE) --directory=$(server) clean
	$(MAKE) --directory=$(client) clean
