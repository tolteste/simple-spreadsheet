GCC    = g++
CFLAGS = -Wall -pedantic -Wno-long-long -O0 -ggdb -MMD -lm -lncurses

BUILD = build
DOC   = doc
SRC   = src

HDRS  = $(wildcard $(SRC)/*.h)
SRCS  = $(wildcard $(SRC)/*.cpp)
OBJS  = $(patsubst $(SRC)/%,$(BUILD)/%,$(SRCS:.cpp=.o))
DEPS  = $(OBJS:.o=.d)

NAME  = tolteste


all: compile doc

-include $(DEPS)

compile: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $^ $(CFLAGS) -o $@

$(BUILD)/%.o: $(SRC)/%.cpp | $(BUILD)
	$(GCC) $(CFLAGS) -c $< -o $@

$(BUILD):
	mkdir $(BUILD)

$(DOC): $(HDRS)
	mkdir -p $(DOC)
	doxygen

run: $(NAME)
	./$(NAME)

clean:
	rm -rf $(BUILD) $(DOC)
	rm -f $(NAME)

l:
	wc -l $(SRCS) $(HDRS)

.PHONY: all compile clean l run

