template_rec_func: template_rec_func.cpp
	g++ -Wall -Werror -o $@ $^

clean:
	rm template_rec_func
