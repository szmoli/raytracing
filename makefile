# directory for the header files
inc_dir := inc
# directory for the source files
src_dir := src
# directory for the executable
out_dir := out
# name of the executable
target := raytracing.out
# g++ flags
flags := -Wall -Werror

inc_flags := $(addprefix -I,$(inc_dir))
src_files := $(wildcard $(src_dir)/*.c) $(wildcard $(src_dir)/*.cpp)

# default rule: build the target
$(out_dir)/$(target): $(src_files)
	mkdir -p $(out_dir)
	g++ $(inc_flags) $^ -o $(out_dir)/$(target)

# run the target, if it doesn't exist build it first
run: $(out_dir)/$(target)
	$(out_dir)/$(target)

# delete the out directory
clean:
	rm -r $(out_dir)